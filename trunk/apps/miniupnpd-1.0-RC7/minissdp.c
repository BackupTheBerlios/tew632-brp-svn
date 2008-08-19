/* $Id: minissdp.c,v 1.3 2008/06/30 07:29:46 geoffrey Exp $ */
/* MiniUPnP project
 * http://miniupnp.free.fr/ or http://miniupnp.tuxfamily.org/
 * (c) 2006 Thomas Bernard
 * This software is subject to the conditions detailed
 * in the LICENCE file provided within the distribution */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <syslog.h>
#include "config.h"
#include "upnpdescstrings.h"
#include "miniupnpdpath.h"
#include "upnphttp.h"
#include "upnpglobalvars.h"
#include "minissdp.h"

/* SSDP ip/port */
#define SSDP_PORT (1900)
#define SSDP_MCAST_ADDR ("239.255.255.250")

static int
AddMulticastMembership(int s, const char * ifaddr)
{
	struct ip_mreq imr;	/* Ip multicast membership */

    /* setting up imr structure */
    imr.imr_multiaddr.s_addr = inet_addr(SSDP_MCAST_ADDR);
    /*imr.imr_interface.s_addr = htonl(INADDR_ANY);*/
    imr.imr_interface.s_addr = inet_addr(ifaddr);
	
	if (setsockopt(s, IPPROTO_IP, IP_ADD_MEMBERSHIP, (void *)&imr, sizeof(struct ip_mreq)) < 0)
	{
        if(debug_flag)syslog(LOG_ERR, "setsockopt(udp, IP_ADD_MEMBERSHIP): %m");
		return -1;
    }

	return 0;
}

int
OpenAndConfSSDPReceiveSocket(const char * ifaddr,
                             int n_add_listen_addr,
							 const char * * add_listen_addr)
{
	int s;
	struct sockaddr_in sockname;
	
	if( (s = socket(PF_INET, SOCK_DGRAM, 0)) < 0)
	{
		if(debug_flag)syslog(LOG_ERR, "socket(udp): %m");
		return -1;
	}	
	
	memset(&sockname, 0, sizeof(struct sockaddr_in));
    sockname.sin_family = AF_INET;
    sockname.sin_port = htons(SSDP_PORT);
	/* NOTE : it seems it doesnt work when binding on the specific address */
    /*sockname.sin_addr.s_addr = inet_addr(UPNP_MCAST_ADDR);*/
    sockname.sin_addr.s_addr = htonl(INADDR_ANY);
    /*sockname.sin_addr.s_addr = inet_addr(ifaddr);*/

    if(bind(s, (struct sockaddr *)&sockname, sizeof(struct sockaddr_in)) < 0)
	{
		if(debug_flag)syslog(LOG_ERR, "bind(udp): %m");
		close(s);
		return -1;
    }

	if(AddMulticastMembership(s, ifaddr) < 0)
	{
		close(s);
		return -1;
	}
	while(n_add_listen_addr>0)
	{
		n_add_listen_addr--;
		if(AddMulticastMembership(s, add_listen_addr[n_add_listen_addr]) < 0)
		{
			if(debug_flag)syslog(LOG_WARNING, "Failed to add membership for address %s. EXITING", 
			       add_listen_addr[n_add_listen_addr] );
		}
	}

	return s;
}

/* open the UDP socket used to send SSDP notifications to
 * the multicast group reserved for them */
int
OpenAndConfSSDPNotifySocket(const char * addr)
{
	int s;
	unsigned char loopchar = 0;
	int bcast = 1;
	struct in_addr mc_if;
	struct sockaddr_in sockname;
	
	if( (s = socket(PF_INET, SOCK_DGRAM, 0)) < 0)
	{
		if(debug_flag)syslog(LOG_ERR, "socket(udp_notify): %m");
		return -1;
	}

	mc_if.s_addr = inet_addr(addr);

	if(setsockopt(s, IPPROTO_IP, IP_MULTICAST_LOOP, (char *)&loopchar, sizeof(loopchar)) < 0)
	{
		if(debug_flag)syslog(LOG_ERR, "setsockopt(udp_notify, IP_MULTICAST_LOOP): %m");
		close(s);
		return -1;
	}

	if(setsockopt(s, IPPROTO_IP, IP_MULTICAST_IF, (char *)&mc_if, sizeof(mc_if)) < 0)
	{
		if(debug_flag)syslog(LOG_ERR, "setsockopt(udp_notify, IP_MULTICAST_IF): %m");
		close(s);
		return -1;
	}
	
	if(setsockopt(s, SOL_SOCKET, SO_BROADCAST, &bcast, sizeof(bcast)) < 0)
	{
		if(debug_flag)syslog(LOG_ERR, "setsockopt(udp_notify, SO_BROADCAST): %m");
		close(s);
		return -1;
	}

	memset(&sockname, 0, sizeof(struct sockaddr_in));
    sockname.sin_family = AF_INET;
    sockname.sin_addr.s_addr = inet_addr(addr);

    if (bind(s, (struct sockaddr *)&sockname, sizeof(struct sockaddr_in)) < 0)
	{
		if(debug_flag)syslog(LOG_ERR, "bind(udp_notify): %m");
		close(s);
		return -1;
    }

	return s;
}

/* Chun add for WPS-COMPATIBLE */
void GetUUIDValue(const char * st,char **uuid_value)
{
	if( strcmp(st,"urn:schemas-upnp-org:device:WANDevice:")==0 ||
	 		strcmp(st,"urn:schemas-upnp-org:service:WANCommonInterfaceConfig:")==0 )
	{
		*uuid_value=uuidvalue_2;
	}
	else if( strcmp(st,"urn:schemas-upnp-org:device:WANConnectionDevice:")==0 ||
	 		strcmp(st,"urn:schemas-upnp-org:service:WANPPPConnection:")==0 ||
	 		strcmp(st,"urn:schemas-upnp-org:service:WANIPConnection:")==0 )
	{
		*uuid_value=uuidvalue_3;
	}
	else if( strcmp(st,"urn:schemas-wifialliance-org:device:WFADevice:")==0 ||
	 		strcmp(st,"urn:schemas-wifialliance-org:service:WFAWLANConfig:")==0 )
	{
		*uuid_value=uuidvalue_4;
	}
	else  //rootdevice
	{
		*uuid_value=uuidvalue_1;
	}
}
/* Chun end */
/*
 * response from a LiveBox (Wanadoo)
HTTP/1.1 200 OK
CACHE-CONTROL: max-age=1800
DATE: Thu, 01 Jan 1970 04:03:23 GMT
EXT:
LOCATION: http://192.168.0.1:49152/gatedesc.xml
SERVER: Linux/2.4.17, UPnP/1.0, Intel SDK for UPnP devices /1.2
ST: upnp:rootdevice
USN: uuid:75802409-bccb-40e7-8e6c-fa095ecce13e::upnp:rootdevice

 * response from a Linksys 802.11b :
HTTP/1.1 200 OK
Cache-Control:max-age=120
Location:http://192.168.5.1:5678/rootDesc.xml
Server:NT/5.0 UPnP/1.0
ST:upnp:rootdevice
USN:uuid:upnp-InternetGatewayDevice-1_0-0090a2777777::upnp:rootdevice
EXT:
 */

/* not really an SSDP "announce" as it is the response
 * to a SSDP "M-SEARCH" */
static void
SendSSDPAnnounce2(int s, struct sockaddr_in sockname,
                  const char * st, int st_len, const char * suffix,
                  const char * host, unsigned short port)
{
	int l, n;
	char buf[512];
	char *tmp_uuid_value=NULL;/* Chun add for WPS-COMPATIBLE */
	/* TODO :
	 * follow guideline from document "UPnP Device Architecture 1.0"
	 * put in uppercase.
	 * DATE: is recommended
	 * SERVER: OS/ver UPnP/1.0 miniupnpd/1.0
	 * - check what to put in the 'Cache-Control' header 
	 * */
	/* Chun add for WPS-COMPATIBLE */
//if(debug_flag)syslog(LOG_INFO, "111 SendSSDPAnnounce2 suffix=%s uuidvalue=%s st=%s", suffix, uuidvalue, st);	
	GetUUIDValue(st,&tmp_uuid_value); 
#if 0	
	l = snprintf(buf, sizeof(buf), "HTTP/1.1 200 OK\r\n"
		"Cache-Control: max-age=120\r\n"
		"ST: %.*s%s\r\n"
		"USN: %s::%.*s%s\r\n"
		"EXT:\r\n"
		"Server: " MINIUPNPD_SERVER_STRING "\r\n"
		"Location: http://%s:%u" ROOTDESC_PATH "\r\n"
		"\r\n",
		st_len, st, suffix,
		tmp_uuid_value, st_len, st, suffix,
		host, (unsigned int)port);	
#else
	l = snprintf(buf, sizeof(buf), "HTTP/1.1 200 OK\r\n"
		"Cache-Control: max-age=120\r\n"
		"EXT:\r\n"
		"Location: http://%s:%u" ROOTDESC_PATH "\r\n"
		"Server: " MINIUPNPD_SERVER_STRING "\r\n"
		"ST: %.*s\r\n"
		"USN: %s::%.*s\r\n"
		"\r\n",
		host, (unsigned int)port,
		st_len, st,
		tmp_uuid_value, st_len, st
		);	
#endif		
	n = sendto(s, buf, l, 0,
	           (struct sockaddr *)&sockname, sizeof(struct sockaddr_in) );
	if(n < 0)
	{
		if(debug_flag)syslog(LOG_ERR, "sendto(udp): %m");
	}
}


/* Chun modify for WPS-COMPATIBLE */
/* Chun comment*/
//static const char * const known_service_types[] =
//{
//	"upnp:rootdevice",
//	"urn:schemas-upnp-org:device:InternetGatewayDevice:",
//	"urn:schemas-upnp-org:device:WANConnectionDevice:",
//	"urn:schemas-upnp-org:device:WANDevice:",
//	"urn:schemas-upnp-org:service:WANCommonInterfaceConfig:",
//	"urn:schemas-upnp-org:service:WANIPConnection:",
//	"urn:schemas-upnp-org:service:WANPPPConnection:",
//	"urn:schemas-upnp-org:service:Layer3Forwarding:",
//	"urn:schemas-wifialliance-org:device:WFADevice:",//Chun
//	"urn:schemas-wifialliance-org:service:WFAWLANConfig:",//Chun	
//	0
//};
/**/
/* Chun add  */
char *known_service_types[11] =
{
	"upnp:rootdevice",
	"urn:schemas-upnp-org:device:InternetGatewayDevice:",
	"urn:schemas-upnp-org:device:WANDevice:",
	"urn:schemas-upnp-org:service:WANCommonInterfaceConfig:",
	"urn:schemas-upnp-org:device:WANConnectionDevice:",
	"urn:schemas-upnp-org:service:WANPPPConnection:",
	"urn:schemas-upnp-org:service:WANIPConnection:",
	"urn:schemas-upnp-org:service:Layer3Forwarding:",	
	0,//"urn:schemas-wifialliance-org:device:WFADevice:",//Chun
	0,//"urn:schemas-wifialliance-org:service:WFAWLANConfig:",//Chun
	0
};
/* Chun end*/

void
SendSSDPNotifies(int s, const char * host, unsigned short port)
{
	struct sockaddr_in sockname;
	int n, i=0;
	char bufr[512];
	char *uuid_value = NULL;/* Chun add for WPS-COMPATIBLE */

	memset(&sockname, 0, sizeof(struct sockaddr_in));
	sockname.sin_family = AF_INET;
	sockname.sin_port = htons(SSDP_PORT);
	sockname.sin_addr.s_addr = inet_addr(SSDP_MCAST_ADDR);

	while(known_service_types[i])
	{
		/* Chun add for WPS-COMPATIBLE */
		GetUUIDValue(known_service_types[i],&uuid_value); 
		//if(debug_flag)syslog(LOG_ERR, "RABBIT uuid_value=%s",uuid_value);
	
		snprintf(bufr, sizeof(bufr), 
				"NOTIFY * HTTP/1.1\r\n"
				"HOST:%s:%d\r\n"
				"Cache-Control:max-age=120\r\n"
				"Location:http://%s:%d" ROOTDESC_PATH"\r\n"
				/*"Server:miniupnpd/1.0 UPnP/1.0\r\n"*/
				"Server: " MINIUPNPD_SERVER_STRING "\r\n"
				"NT:%s%s\r\n"
				"USN:%s::%s%s\r\n"
				"NTS:ssdp:alive\r\n"
				"\r\n",
				SSDP_MCAST_ADDR, SSDP_PORT,
				host, port,
				known_service_types[i], (i==0?"":"1"),
				uuid_value, known_service_types[i], (i==0?"":"1") );/* Chun add for WPS-COMPATIBLE */
				
		
		n = sendto(s, bufr, strlen(bufr), 0,
			(struct sockaddr *)&sockname, sizeof(struct sockaddr_in) );
		if(n < 0)
		{
			if(debug_flag)syslog(LOG_ERR, "sendto(udp_notify): %m");
		}
		i++;
	}
}

/* ProcessSSDPRequest()
 * process SSDP M-SEARCH requests and responds to them */
void
ProcessSSDPRequest(int s, const char * host, unsigned short port)
{
	int n;
	char bufr[1500];
	socklen_t len_r;
	struct sockaddr_in sendername;
	int i, l;
	char * st = 0;
	int st_len = 0;
	len_r = sizeof(struct sockaddr_in);

	n = recvfrom(s, bufr, sizeof(bufr), 0,
	             (struct sockaddr *)&sendername, &len_r);
	if(n < 0)
	{
		if(debug_flag)syslog(LOG_ERR, "recvfrom(udp): %m");
		return;
	}

	if(memcmp(bufr, "NOTIFY", 6) == 0)
	{
		/* ignore NOTIFY packets. We could log the sender and device type */
		return;
	}
	else if(memcmp(bufr, "M-SEARCH", 8) == 0)
	{
		i = 0;
		while(i < n)
		{
			while(bufr[i] != '\r' || bufr[i+1] != '\n')
				i++;
			i += 2;
			if(strncasecmp(bufr+i, "st:", 3) == 0)
			{
				st = bufr+i+3;
				st_len = 0;
				while(*st == ' ' || *st == '\t') st++;
				while(st[st_len]!='\r' && st[st_len]!='\n') st_len++;
				/*if(debug_flag)syslog(LOG_INFO, "ST: %.*s", st_len, st);*/
				/*j = 0;*/
				/*while(bufr[i+j]!='\r') j++;*/
				/*if(debug_flag)syslog(LOG_INFO, "%.*s", j, bufr+i);*/
			}
		}
		/*if(debug_flag)syslog(LOG_INFO, "SSDP M-SEARCH packet received from %s:%d",
	           inet_ntoa(sendername.sin_addr),
	           ntohs(sendername.sin_port) );*/
		if(st)
		{
			/* TODO : doesnt answer at once but wait for a random time */
			if(debug_flag)syslog(LOG_INFO, "SSDP M-SEARCH from %s:%d ST: %.*s",
	        	   inet_ntoa(sendername.sin_addr),
	           	   ntohs(sendername.sin_port),
				   st_len, st);
			/* Responds to request with a device as ST header */
			for(i = 0; known_service_types[i]; i++)
			{
				l = (int)strlen(known_service_types[i]);				
				if(l<=st_len && (0 == memcmp(st, known_service_types[i], l)))
				{
					if(debug_flag)syslog(LOG_INFO, "111 SSDP M-SEARCH ");
					SendSSDPAnnounce2(s, sendername,
					                  st, st_len, "", host, port);
					break;
				}
				/* Chun comment: for CD_ROUTER 
				 * It shouldn't i++ here. 
				 */
				//i++; 
			}
			/* Responds to request with ST: ssdp:all */
			/* strlen("ssdp:all") == 8 */
			if(st_len==8 && (0 == memcmp(st, "ssdp:all", 8)))
			{
				if(debug_flag)syslog(LOG_INFO, "222 SSDP M-SEARCH ");
				for(i=0; known_service_types[i]; i++)
				{
					l = (int)strlen(known_service_types[i]);
					SendSSDPAnnounce2(s, sendername,
					                  known_service_types[i], l, i==0?"":"1",
					                  host, port);
				}
			}	
			/* Chun modify for WPS-COMPATIBLE */
			/* Chun comment 
			l = (int)strlen(uuidvalue);
			if(l==st_len && (0 == memcmp(st, uuidvalue, l)))
			{
				SendSSDPAnnounce2(s, sendername, st, st_len, host, port);
			}*/
			/* Chun add : process the icon request to surf web page*/					
			l = (int)strlen(uuidvalue_1);
			if(l==st_len && (0 == memcmp(st, uuidvalue_1, l)))
			{	
			if(debug_flag)syslog(LOG_INFO, "333 SSDP M-SEARCH ");		
				SendSSDPAnnounce2(s, sendername, st, st_len, "", host, port);
			}
			/* Chun end */			
		}
		else
		{
			if(debug_flag)syslog(LOG_INFO, "Invalid SSDP M-SEARCH from %s:%d",
	        	   inet_ntoa(sendername.sin_addr), ntohs(sendername.sin_port));
		}
	}
	else
	{
		if(debug_flag)syslog(LOG_NOTICE, "Unknown udp packet received from %s:%d",
		       inet_ntoa(sendername.sin_addr), ntohs(sendername.sin_port));
	}
}

/* This will broadcast ssdp:byebye notifications to inform 
 * the network that UPnP is going down. */
int
SendSSDPGoodbye(int s)
{
	struct sockaddr_in sockname;
	int n;
	int i=0;
	char bufr[512];
	char *tmp_uuid_value=NULL; /* Chun modify for WPS-COMPATIBLE */

    memset(&sockname, 0, sizeof(struct sockaddr_in));
    sockname.sin_family = AF_INET;
    sockname.sin_port = htons(SSDP_PORT);
    sockname.sin_addr.s_addr = inet_addr(SSDP_MCAST_ADDR);

    while(known_service_types[i])
    {
		/* Chun modify for WPS-COMPATIBLE */
		GetUUIDValue(known_service_types[i],&tmp_uuid_value); 
		//if(debug_flag)syslog(LOG_ERR, "RABBIT uuid_value=%s",uuid_value);
    	
        snprintf(bufr, sizeof(bufr),
                 "NOTIFY * HTTP/1.1\r\n"
                 "HOST:%s:%d\r\n"
                 "NT:%s%s\r\n"
                 "USN:%s::%s%s\r\n"
                 "NTS:ssdp:byebye\r\n"
                 "\r\n",
                 SSDP_MCAST_ADDR, SSDP_PORT,
				 known_service_types[i], (i==0?"":"1"),
                 //uuidvalue, known_service_types[i], (i==0?"":"1"));
                 tmp_uuid_value, known_service_types[i], (i==0?"":"1"));/* Chun modify for WPS-COMPATIBLE */
        
        n = sendto(s, bufr, strlen(bufr), 0,
                   (struct sockaddr *)&sockname, sizeof(struct sockaddr_in) );
		if(n < 0)
		{
			if(debug_flag)syslog(LOG_ERR, "sendto(udp_shutdown): %m");
			return -1;
		}
        i++;
    }
	return 0;
}

