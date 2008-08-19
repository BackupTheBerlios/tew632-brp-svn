/* $Id: miniupnpd.c,v 1.2 2008/07/29 02:35:41 ken_chiang Exp $ */
/* MiniUPnP project
 * http://miniupnp.free.fr/ or http://miniupnp.tuxfamily.org/
 * (c) 2006 Thomas Bernard
 * This software is subject to the conditions detailed
 * in the LICENCE file provided within the distribution */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/file.h>
#include <syslog.h>
#include <sys/time.h>
#include <time.h>
#include <signal.h>
/* for BSD's sysctl */
#include <sys/param.h>
#include <sys/sysctl.h>

/* unix sockets */
/*#define USE_MINIUPNPDCTL*/
#include "config.h"
#ifdef USE_MINIUPNPDCTL
#include <sys/un.h>
#endif

#include "upnpglobalvars.h"
#include "upnphttp.h"
#include "upnpdescgen.h"
#include "miniupnpdpath.h"
#include "getifaddr.h"
#include "daemonize.h"
#include "upnpsoap.h"
#include "options.h"
#include "minissdp.h"

#if 0
#define DEBUG_MSG(fmt, arg...)       printf(fmt, ##arg)
#else
#define DEBUG_MSG(fmt, arg...) 
#endif

#ifdef USE_MINIUPNPDCTL
struct ctlelem {
	int socket;
	LIST_ENTRY(ctlelem) entries;
};
#endif

/* MAX_ADD_LISTEN_ADDR : maximum number of interfaces
 * to listen to SSDP traffic */
#define MAX_ADD_LISTEN_ADDR (4)

static volatile int quitting = 0;
int debug_flag = 0;
extern known_service_types[];
/* OpenAndConfHTTPSocket() :
 * setup the socket used to handle incoming HTTP connections. */
static int
OpenAndConfHTTPSocket(const char * addr, unsigned short port)
{
	int s;
	int i = 1;
	struct sockaddr_in listenname;

	if( (s = socket(PF_INET, SOCK_STREAM, 0)) < 0)
	{
		if(debug_flag)syslog(LOG_ERR, "socket(http): %m");
		return -1;
	}

	if(setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &i, sizeof(i)) < 0)
	{
		if(debug_flag)syslog(LOG_WARNING, "setsockopt(http, SO_REUSEADDR): %m");
	}

	memset(&listenname, 0, sizeof(struct sockaddr_in));
	listenname.sin_family = AF_INET;
	listenname.sin_port = htons(port);
	listenname.sin_addr.s_addr = htonl(INADDR_ANY);

	if(bind(s, (struct sockaddr *)&listenname, sizeof(struct sockaddr_in)) < 0)
	{
		if(debug_flag)syslog(LOG_ERR, "bind(http): %m");
		close(s);
		return -1;
	}

	if(listen(s, 6) < 0)
	{
		if(debug_flag)syslog(LOG_ERR, "listen(http): %m");
		close(s);
		return -1;
	}

	return s;
}

/* Functions used to communicate with miniupnpdctl */
#ifdef USE_MINIUPNPDCTL
static int
OpenAndConfCtlUnixSocket(const char * path)
{
	struct sockaddr_un localun;
	int s;
	s = socket(AF_UNIX, SOCK_STREAM, 0);
	localun.sun_family = AF_UNIX;
	strlcpy(localun.sun_path, path,
	          sizeof(localun.sun_path));
	if(bind(s, (struct sockaddr *)&localun,
	        sizeof(struct sockaddr_un)) < 0)
	{
		if(debug_flag)syslog(LOG_ERR, "bind(sctl): %m");
		close(s);
		s = -1;
	}
	else if(listen(s, 5) < 0)
	{
		if(debug_flag)syslog(LOG_ERR, "listen(sctl): %m");
		close(s);
		s = -1;
	}
	return s;
}

static void
write_upnphttp_details(int fd, struct upnphttp * e)
{
	char buffer[256];
	int len;
	while(e)
	{
		len = snprintf(buffer, sizeof(buffer),
		               "%d %d %s req_buf=%p(%dbytes) res_buf=%p(%dbytes alloc)\n",
		               e->socket, e->state, e->HttpVer,
		               e->req_buf, e->req_buflen,
		               e->res_buf, e->res_buf_alloclen);
		write(fd, buffer, len);
		e = e->entries.le_next;
	}
}

static void
write_ctlsockets_list(int fd, struct ctlelem * e)
{
	char buffer[256];
	int len;
	while(e)
	{
		len = snprintf(buffer, sizeof(buffer),
		               "struct ctlelem: socket=%d\n", e->socket);
		write(fd, buffer, len);
		e = e->entries.le_next;
	}
}

static void
write_option_list(int fd)
{
	char buffer[256];
	int len;
	int i;
	for(i=0; i<num_options; i++)
	{
		len = snprintf(buffer, sizeof(buffer),
		               "opt=%02d %s\n",
		               ary_options[i].id, ary_options[i].value);
		write(fd, buffer, len);
	}
}

#endif

/* Handler for the SIGTERM signal (kill) */
static void
sigterm(int sig)
{
	/*int save_errno = errno;*/
	signal(sig, SIG_IGN);

	if(debug_flag)syslog(LOG_NOTICE, "received signal %d, good-bye", sig);

	quitting = 1;
	/*errno = save_errno;*/
}

/* record the startup time, for returning uptime */
static void
set_startup_time(int sysuptime)
{
	startup_time = time(NULL);
	if(sysuptime)
	{
		/* use system uptime instead of daemon uptime */
#if defined(__linux__)
		char buff[64];
		int uptime, fd;
		fd = open("/proc/uptime", O_RDONLY);
		if(fd < 0)
		{
			if(debug_flag)syslog(LOG_ERR, "open(\"/proc/uptime\" : %m");
		}
		else
		{
			memset(buff, 0, sizeof(buff));
			read(fd, buff, sizeof(buff) - 1);
			uptime = atoi(buff);
			if(debug_flag)syslog(LOG_INFO, "system uptime is %d seconds", uptime);
			close(fd);
			startup_time -= uptime;
		}
#else
		struct timeval boottime;
		size_t size = sizeof(boottime);
		int name[2] = { CTL_KERN, KERN_BOOTTIME };
		if(sysctl(name, 2, &boottime, &size, NULL, 0) < 0)
		{
			if(debug_flag)syslog(LOG_ERR, "sysctl(\"kern.boottime\") failed");
		}
		else
		{
			startup_time = boottime.tv_sec;
		}
#endif
	}
}

/* structure containing variables used during "main loop"
 * that are filled during the init */
struct runtime_vars {
	int n_add_listen_addr;
	const char * add_listen_addr[MAX_ADD_LISTEN_ADDR];
	int port;	/* HTTP Port */
	int notify_interval;	/* seconds between SSDP announces */
};


/* init phase :
 * 1) read configuration file
 * 2) read command line arguments
 * 3) daemonize
 * 4) open syslog
 * 5) check and write pid file
 * 6) set startup time stamp
 * 7) compute presentation URL
 * 8) set signal handlers */
static int
init(int argc, char * * argv, struct runtime_vars * v)
{
	int i;
	int pid;

	int options_flag = 0;
	int openlog_option;
	struct sigaction sa;
	/*const char * logfilename = 0;*/
	const char * presurl = 0;
	const char * optionsfile = "/var/etc/miniupnpd.conf";
	const char * nvram_friendlyname = 0;	
	
	
/* Chun comment: 
 * We don't pass the location of miniupnpd.conf from argumant.
 * It's hard code!(see shvar.h)
 */
//	/* first check if "-f" option is used */
//	for(i=2; i<argc; i++)
//	{
//		if(0 == strcmp(argv[i-1], "-f"))
//		{
//			optionsfile = argv[i];
//			options_flag = 1;
//			break;
//		}
//	}

	/* set initial values */
	v->n_add_listen_addr = 0;
	//albert modify
	//v->port = -1;
	//v->notify_interval = 30;	/* seconds between SSDP announces */	
	  v->port = 65535;
	  v->notify_interval = 20;	/* seconds between SSDP announces */ 
	//albert modify end


	/* read options file first since
	 * command line arguments have final say */
	 
	if(readoptionsfile(optionsfile) < 0)
	{
		/* only error if file exists or using -f */
		if(access(optionsfile, F_OK) == 0 || options_flag)
			fprintf(stderr, "Error reading configuration file %s\n", optionsfile);
	}
	else
	{
		for(i=0; i<num_options; i++)
		{
			switch(ary_options[i].id)
			{
			case UPNPEXT_IFNAME:
				ext_if_name = ary_options[i].value;			
				break;
			case UPNPEXT_IP:
				use_ext_ip_addr = ary_options[i].value;		
				break;
			case UPNPLISTENING_IP:
				if(listen_addr)
				{
					if(v->n_add_listen_addr < MAX_ADD_LISTEN_ADDR)
					{
						v->add_listen_addr[v->n_add_listen_addr++] = ary_options[i].value;					
					}
					else
					{
						fprintf(stderr, "Too many listening ips (max: %d), ignoring %s\n",
				    		    MAX_ADD_LISTEN_ADDR, ary_options[i].value);
					}
				}
				else
					listen_addr = ary_options[i].value;
				break;
			case UPNPPORT:
				v->port = atoi(ary_options[i].value);
				break;
			case UPNPBITRATE_UP:
				upstream_bitrate = strtoul(ary_options[i].value, 0, 0);
				break;
			case UPNPBITRATE_DOWN:
				downstream_bitrate = strtoul(ary_options[i].value, 0, 0);
				break;
			case UPNPPRESENTATIONURL:
				presurl = ary_options[i].value;
				break;
			case UPNPNOTIFY_INTERVAL:
				v->notify_interval = atoi(ary_options[i].value);
				break;
			case UPNPSYSTEM_UPTIME:
				if(strcmp(ary_options[i].value, "yes") == 0)
					sysuptime = 1;
				break;
			case UPNPPACKET_LOG:
				if(strcmp(ary_options[i].value, "yes") == 0)
					logpackets = 1;
				break;
			case UPNPUUID:
				strncpy(uuidvalue+5, ary_options[i].value,
				        strlen(uuidvalue+5) + 1);
				break;
			case UPNPSERIAL:
				strncpy(serialnumber, ary_options[i].value, SERIALNUMBER_MAX_LEN);
				serialnumber[SERIALNUMBER_MAX_LEN-1] = '\0';
				break;				
			case UPNPMODEL_NUMBER:
				strncpy(modelnumber, ary_options[i].value, MODELNUMBER_MAX_LEN);
				modelnumber[MODELNUMBER_MAX_LEN-1] = '\0';
				break;
			case UPNPWPS_ENABLE:
				strncpy(wpsenable, ary_options[i].value, WPSENABLE_MAX_LEN);
				wpsenable[WPSENABLE_MAX_LEN-1] = '\0';
				break;
			case UPNPFRIENDLY_NAME:
				strncpy(friendlyname, ary_options[i].value, FRIENDLYNAME_MAX_LEN);
				friendlyname[FRIENDLYNAME_MAX_LEN-1] = '\0';
				break;
			case UPNPMANUFACTURER_NAME:
				strncpy(manufacturername, ary_options[i].value, MANUFACTURERNAME_MAX_LEN);
				manufacturername[FRIENDLYNAME_MAX_LEN-1] = '\0';
				break;
			case UPNPMANUFACTURER_URL:
				strncpy(manufacturerurl, ary_options[i].value, MANUFACTURERURL_MAX_LEN);
				manufacturerurl[MANUFACTURERURL_MAX_LEN-1] = '\0';
				break;
			case UPNPMODEL_NAME:
				strncpy(modelname, ary_options[i].value, MODELNAME_MAX_LEN);
				modelname[MODELNAME_MAX_LEN-1] = '\0';
				break;
			case UPNPMODEL_URL:
				strncpy(modelurl, ary_options[i].value, MODELURL_MAX_LEN);
				modelurl[MODELURL_MAX_LEN-1] = '\0';
				break;
			default:
				fprintf(stderr, "Unknown option in file %s\n",
				        optionsfile);
			}
		}
	}

	/* command line arguments processing */
	for(i=1; i<argc; i++)
	{
		if(argv[i][0]!='-')
		{
			fprintf(stderr, "Unknown option: %s\n", argv[i]);
		}
		else switch(argv[i][1])
		{
		case 'o':
			use_ext_ip_addr = argv[++i];
			break;
		case 't':
			v->notify_interval = atoi(argv[++i]);
			break;
		case 'u':
			strncpy(uuidvalue+5, argv[++i], strlen(uuidvalue+5) + 1);
			break;
		case 's':
			strncpy(serialnumber, argv[++i], SERIALNUMBER_MAX_LEN);
			serialnumber[SERIALNUMBER_MAX_LEN-1] = '\0';
			break;
		case 'M':
			strncpy(modelnumber, argv[++i], MODELNUMBER_MAX_LEN);
			modelnumber[MODELNUMBER_MAX_LEN-1] = '\0';
			break;			
		case 'U':
			sysuptime = 1;
			break;
		/*case 'l':
			logfilename = argv[++i];
			break;*/
		case 'L':
			logpackets = 1;
			break;
		case 'i':
			ext_if_name = argv[++i];
			break;
		case 'p':
			v->port = atoi(argv[++i]);
			break;
		case 'P':
			pidfilename = argv[++i];
			break;
		case 'd':
			debug_flag = 1;
			break;
		case 'w':
			presurl = argv[++i];
			break;
		case 'B':
			downstream_bitrate = strtoul(argv[++i], 0, 0);
			upstream_bitrate = strtoul(argv[++i], 0, 0);
			break;
		case 'a':
			i++;
			if(listen_addr)
			{
				int address_already_there = 0;
				int j;
				if(0 != strcmp(listen_addr, argv[i]))
					break;
				for(j=0; j<v->n_add_listen_addr; j++)
				{
					if(0 == strcmp(v->add_listen_addr[j], argv[i]))
						address_already_there = 1;
				}
				if(address_already_there)
					break;
				if(v->n_add_listen_addr < MAX_ADD_LISTEN_ADDR)
				{
					v->add_listen_addr[v->n_add_listen_addr++] = argv[i];
				}
				else
				{
					fprintf(stderr, "Too many listening ips (max: %d), ignoring %s\n",
				    	    MAX_ADD_LISTEN_ADDR, argv[i]);
				}
			}
			else
				listen_addr = argv[i];
			break;
		case 'f':
			nvram_friendlyname = argv[++i];
			break;
		default:
			fprintf(stderr, "Unknown option: %s\n", argv[i]);
		}
	}
#if 0	
	if(!ext_if_name || !listen_addr/* || v->port<=0*/)
	{
		fprintf(stderr, "Usage:\n\t"
		        "%s [-f config_file] [-i ext_ifname] [-o ext_ip]\n"
				"\t\t[-a listening_ip] [-p port] [-d] [-L] [-U]\n"
				/*"[-l logfile] " not functionnal */
				"\t\t[-u uuid] [-s serial] [-m model_number] \n"
				"\t\t[-t notify_interval] [-P pid_filename]\n"
				"\t\t[-B down up] [-w url]\n"
		        "\nNotes:\n\tThere can be one or several listening_ips.\n"
		        "\tNotify interval is in seconds. Default is 30 seconds.\n"
				"\tDefault pid file is %s.\n"
				"\tWith -d miniupnpd will run as a standard program.\n"
				"\t-L sets packet log in pf on.\n"
				"\t-U causes miniupnpd to report system uptime instead "
				"of daemon uptime.\n"
				"\t-B sets bitrates reported by daemon in bits per second.\n"
				"\t-w sets the presentation url. Default is http address on port 80\n",
		        argv[0], pidfilename);
		return 1;
	}
#endif
	if(debug_flag)
	{
		pid = getpid();
	}
	else
	{
		pid = daemonize();
	}

	openlog_option = LOG_PID|LOG_CONS;
	if(debug_flag)
	{
		openlog_option |= LOG_PERROR;	/* also log on stderr */
	}

	openlog("miniupnpd", openlog_option, LOG_MINIUPNPD);

	if(!debug_flag)
	{
		/* speed things up and ignore LOG_INFO and LOG_DEBUG */
		setlogmask(LOG_UPTO(LOG_NOTICE));
	}

	if(checkforrunning(pidfilename) < 0)
	{
		if(debug_flag)syslog(LOG_ERR, "MiniUPnPd is already running. EXITING");
		return 1;
	}	

	writepidfile(pidfilename, pid);

	set_startup_time(sysuptime);
	
	/* Chun add for WPS-COMPATIBLE */
	/* use different xml file according to if wps enable or not */
	if( !strcmp(wpsenable, "1")  ) {
		if(debug_flag)syslog(LOG_ERR, "wps_enable ");
		known_service_types[8]="urn:schemas-wifialliance-org:device:WFADevice:";
		known_service_types[9]="urn:schemas-wifialliance-org:service:WFAWLANConfig:";
		wps_enable_set(1);
	}
	else
	{
		if(debug_flag) syslog(LOG_ERR, "wps_disable");
		wps_enable_set(0);
	}	

/* Chun add for WFA-XML-IP */
	if(listen_addr)
	{
		sprintf(wfadev_path, "http://%s:60001/WFAWLANConfig/scpd.xml", listen_addr);
		sprintf(wfadev_control, "http://%s:60001/WFAWLANConfig/control", listen_addr);
		sprintf(wfadev_eventual, "http://%s:60001/WFAWLANConfig/event", listen_addr);
	}
/*Chun end*/
	/* presentation url */
	if(presurl)
	{
		strncpy(presentationurl, presurl, PRESENTATIONURL_MAX_LEN);
		presentationurl[PRESENTATIONURL_MAX_LEN-1] = '\0';
	}
	else
	{
		snprintf(presentationurl, PRESENTATIONURL_MAX_LEN,
		         "http://%s:%d/", listen_addr, 80);
	}

	/* set signal handler */
	memset(&sa, 0, sizeof(struct sigaction));
	sa.sa_handler = sigterm;

	if (sigaction(SIGTERM, &sa, NULL))
	{
		if(debug_flag)syslog(LOG_ERR, "Failed to set SIGTERM handler. EXITING");
		return 1;
	}
	if (sigaction(SIGINT, &sa, NULL))
	{
		if(debug_flag)syslog(LOG_ERR, "Failed to set SIGTERM handler. EXITING");
		return 1;
	}

	return 0;
}

/* === main === */
/* process HTTP or SSDP requests */
int
main(int argc, char * * argv)
{
	int i;
	int sudp, shttpl, snotify;
	LIST_HEAD(httplisthead, upnphttp) upnphttphead;
	struct upnphttp * e = 0;
	struct upnphttp * next;
	fd_set readset;	/* for select() */
	struct timeval timeout, timeofday, lasttimeofday = {0, 0};
#ifdef USE_MINIUPNPDCTL
	int sctl;
	LIST_HEAD(ctlstructhead, ctlelem) ctllisthead;
	struct ctlelem * ectl;
	struct ctlelem * ectlnext;
#endif
	struct runtime_vars v;

	if(init(argc, argv, &v) != 0)
		return 1;

	LIST_INIT(&upnphttphead);
#ifdef USE_MINIUPNPDCTL
	LIST_INIT(&ctllisthead);
#endif

	/* open socket for SSDP connections */
	sudp = OpenAndConfSSDPReceiveSocket(listen_addr, v.n_add_listen_addr,
	                                    v.add_listen_addr);
	if(sudp < 0)
	{
		if(debug_flag)syslog(LOG_ERR, "Failed to open socket for receiving SSDP. EXITING");
		return 1;
	}
	/* open socket for HTTP connections */
	shttpl = OpenAndConfHTTPSocket(listen_addr, v.port);
	if(shttpl < 0)
	{
		if(debug_flag)syslog(LOG_ERR, "Failed to open socket for HTTP. EXITING");
		return 1;
	}
	if(debug_flag)syslog(LOG_NOTICE, "listening on %s:%d", listen_addr, v.port);

	/* open socket for sending notifications */
	snotify = OpenAndConfSSDPNotifySocket(listen_addr);
	if(snotify < 0)
	{
		if(debug_flag)syslog(LOG_ERR, "Failed to open socket for sending SSDP notify "
		                "messages. EXITING");
		return 1;
	}

	/* for miniupnpdctl */
#ifdef USE_MINIUPNPDCTL
	sctl = OpenAndConfCtlUnixSocket("/var/run/miniupnpd.ctl");
#endif

	/* main loop */
	while(!quitting)
	{
		/* Check if we need to send SSDP NOTIFY messages and do it if
		 * needed */
		if(gettimeofday(&timeofday, 0) < 0)
		{
			if(debug_flag)syslog(LOG_ERR, "gettimeofday(): %m");
			timeout.tv_sec = v.notify_interval;
			timeout.tv_usec = 0;
		}
		else
		{
			/* the comparaison is not very precise but who cares ? */
			if(timeofday.tv_sec >= (lasttimeofday.tv_sec + v.notify_interval))
			{
				SendSSDPNotifies(snotify, listen_addr, (unsigned short)v.port);
				memcpy(&lasttimeofday, &timeofday, sizeof(struct timeval));
				timeout.tv_sec = v.notify_interval;
				timeout.tv_usec = 0;
			}
			else
			{
				timeout.tv_sec = lasttimeofday.tv_sec + v.notify_interval
				                 - timeofday.tv_sec;
				if(timeofday.tv_usec > lasttimeofday.tv_usec)
				{
					timeout.tv_usec = 1000000 + lasttimeofday.tv_usec
					                  - timeofday.tv_usec;
					timeout.tv_sec--;
				}
				else
				{
					timeout.tv_usec = lasttimeofday.tv_usec - timeofday.tv_usec;
				}
			}
		}
		/* select open sockets (SSDP, HTTP listen, and all HTTP soap sockets) */
		FD_ZERO(&readset);
		FD_SET(sudp, &readset);
		FD_SET(shttpl, &readset);
		i = 0;	/* active HTTP connections count */
		for(e = upnphttphead.lh_first; e != NULL; e = e->entries.le_next)
		{
			if((e->socket >= 0) && (e->state <= 2))
			{
				FD_SET(e->socket, &readset);
				i++;
			}
		}
		/* for debug */
#ifdef DEBUG
		if(i > 1)
		{
			if(debug_flag)syslog(LOG_DEBUG, "%d active incoming HTTP connections", i);
		}
#endif
#ifdef USE_MINIUPNPDCTL
		if(sctl >= 0)
			FD_SET(sctl, &readset);
		for(ectl = ctllisthead.lh_first; ectl; ectl = ectl->entries.le_next)
		{
			if(ectl->socket >= 0)
				FD_SET(ectl->socket, &readset);
		}
#endif
		if(select(FD_SETSIZE, &readset, 0, 0, &timeout) < 0)
		{
			if(quitting) goto shutdown;
			if(debug_flag)syslog(LOG_ERR, "select(all): %m");
			if(debug_flag)syslog(LOG_ERR, "Failed to select open sockets. EXITING");
			return 1;	/* very serious cause of error */
		}
#ifdef USE_MINIUPNPDCTL
		for(ectl = ctllisthead.lh_first; ectl;)
		{
			ectlnext =  ectl->entries.le_next;
			if((ectl->socket >= 0) && FD_ISSET(ectl->socket, &readset))
			{
				char buf[256];
				int l;
				l = read(ectl->socket, buf, sizeof(buf));
				if(l > 0)
				{
					/*write(ectl->socket, buf, l);*/
					write_option_list(ectl->socket);
					write_permlist(ectl->socket, upnppermlist, num_upnpperm);
					write_upnphttp_details(ectl->socket, upnphttphead.lh_first);
					write_ctlsockets_list(ectl->socket, ctllisthead.lh_first);
					/* close the socket */
					close(ectl->socket);
					ectl->socket = -1;
				}
				else
				{
					close(ectl->socket);
					ectl->socket = -1;
				}
			}
			if(ectl->socket < 0)
			{
				LIST_REMOVE(ectl, entries);
				free(ectl);
			}
			ectl = ectlnext;
		}
		if(FD_ISSET(sctl, &readset))
		{
			int s;
			struct sockaddr_un clientname;
			struct ctlelem * tmp;
			socklen_t clientnamelen;
			if(debug_flag)syslog(LOG_DEBUG, "sctl!");
			s = accept(sctl, (struct sockaddr *)&clientname,
			           &clientnamelen);
			tmp = malloc(sizeof(struct ctlelem));
			tmp->socket = s;
			LIST_INSERT_HEAD(&ctllisthead, tmp, entries);
		}
#endif
		/* process SSDP packets */
		if(FD_ISSET(sudp, &readset))
		{
			/*if(debug_flag)syslog(LOG_INFO, "Received UDP Packet");*/
			ProcessSSDPRequest(sudp, listen_addr, (unsigned short)v.port);
		}
		/* process active HTTP connections */
		/* LIST_FOREACH is not available under linux */
		for(e = upnphttphead.lh_first; e != NULL; e = e->entries.le_next)
		{
			if(  (e->socket >= 0) && (e->state <= 2)
				&&(FD_ISSET(e->socket, &readset)) )
			{
				Process_upnphttp(e);
			}
		}
		/* process incoming HTTP connections */
		if(FD_ISSET(shttpl, &readset))
		{
			int shttp;
			socklen_t clientnamelen;
			struct sockaddr_in clientname;
			clientnamelen = sizeof(struct sockaddr_in);
			shttp = accept(shttpl, (struct sockaddr *)&clientname, &clientnamelen);
			if(shttp<0)
			{
				if(debug_flag)syslog(LOG_ERR, "accept(http): %m");
			}
			else
			{
				struct upnphttp * tmp = 0;
				if(debug_flag)syslog(LOG_INFO, "HTTP connection from %s:%d",
					inet_ntoa(clientname.sin_addr),
					ntohs(clientname.sin_port) );
				/*if (fcntl(shttp, F_SETFL, O_NONBLOCK) < 0) {
					if(debug_flag)syslog(LOG_ERR, "fcntl F_SETFL, O_NONBLOCK");
				}*/
				/* Create a new upnphttp object and add it to
				 * the active upnphttp object list */
				tmp = New_upnphttp(shttp);
				if(tmp)
				{
					LIST_INSERT_HEAD(&upnphttphead, tmp, entries);
				}
				else
				{
					if(debug_flag)syslog(LOG_ERR, "New_upnphttp() failed");
					close(shttp);
				}
			}
		}
		/* delete finished HTTP connections */
		for(e = upnphttphead.lh_first; e != NULL; )
		{
			next = e->entries.le_next;
			if(e->state >= 100)
			{
				LIST_REMOVE(e, entries);
				Delete_upnphttp(e);
			}
			e = next;
		}
	}

shutdown:
	/* close out open sockets */
	while(upnphttphead.lh_first != NULL)
	{
		e = upnphttphead.lh_first;
		LIST_REMOVE(e, entries);
		Delete_upnphttp(e);
	}
	close(sudp);
	close(shttpl);
#ifdef USE_MINIUPNPDCTL
	close(sctl);
	if(unlink("/var/run/miniupnpd.ctl") < 0)
	{
		if(debug_flag)syslog(LOG_ERR, "unlink() %m");
	}
#endif
	
	if(SendSSDPGoodbye(snotify) < 0)
	{
		if(debug_flag)syslog(LOG_ERR, "Failed to broadcast good-bye notifications");
	}
	close(snotify);

	if(unlink(pidfilename) < 0)
	{
		if(debug_flag)syslog(LOG_ERR, "Failed to remove pidfile %s: %m", pidfilename);
	}

	closelog();	
	freeoptions();
	
	return 0;
}

