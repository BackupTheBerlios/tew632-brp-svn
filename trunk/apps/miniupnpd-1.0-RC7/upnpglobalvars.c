/* $Id: upnpglobalvars.c,v 1.1 2007/09/13 09:04:45 ken_chiang Exp $ */
/* MiniUPnP project
 * http://miniupnp.free.fr/ or http://miniupnp.tuxfamily.org/
 * (c) 2006 Thomas Bernard 
 * This software is subject to the conditions detailed
 * in the LICENCE file provided within the distribution */

#include <sys/types.h>
#include <netinet/in.h>

#include "upnpglobalvars.h"

/* network interface for internet */
const char * ext_if_name = 0;

/* forced ip address to use for this interface
 * when NULL, getifaddr() is used */
const char * use_ext_ip_addr = 0;

/* LAN address */
const char * listen_addr = 0;

unsigned long downstream_bitrate = 0;
unsigned long upstream_bitrate = 0;

/* startup time */
time_t startup_time = 0;

/* use system uptime */
int sysuptime = 0;

/* log packets flag */
int logpackets = 0;

const char * pidfilename = "/var/run/miniupnpd.pid";

char uuidvalue[] = "uuid:00000000-0000-0000-0000-000000000000";
char serialnumber[SERIALNUMBER_MAX_LEN] = "00000000";
/* Chun mofigy for WPS-COMPATIBLE */
char uuidvalue_1[] = "uuid:11111111-1111-1111-1111-111111111111";//InternetGatewayDevice
char uuidvalue_2[] = "uuid:22222222-2222-2222-2222-222222222222";//WANDevice
char uuidvalue_3[] = "uuid:33333333-3333-3333-3333-333333333333";//WANConnectionDevice
char uuidvalue_4[] = "uuid:565aa949-67c1-4c0e-aa8f-f349e6f59311";//WFADevice

/* chun add for XBOX-TEST */
//int rc_need_restart=0;

char modelnumber[MODELNUMBER_MAX_LEN] = "1";

char wpsenable[WPSENABLE_MAX_LEN] = "0";

/* presentation url :
 * http://nnn.nnn.nnn.nnn:ppppp/  => max 30 bytes including terminating 0 */
char presentationurl[PRESENTATIONURL_MAX_LEN];

/* UPnP permission rules : */
struct upnpperm * upnppermlist = 0;
unsigned int num_upnpperm = 0;

