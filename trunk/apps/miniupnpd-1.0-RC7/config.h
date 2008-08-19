/* $Id: config.h,v 1.1 2007/09/13 09:04:45 ken_chiang Exp $ */
/* MiniUPnP Project
 * http:///miniupnp.free.fr
 * (c) 2006 Thomas Bernard
 */
#ifndef __CONFIG_H__
#define __CONFIG_H__

#define UPNP_VERSION	"20070228"
#define OS_NAME	"D-Link"
#define OS_VERSION	"Linux/2.4.22-1.2115.nptl"
/* Chun comment out for INFO-FROM-NVRAM */
//#define OS_URL	"http://www.D-Link.com/"

/* Chun add for INFO-FROM-NVRAM */
#define MANU_URL	"http://www.D-Link.com/"
#define MODEL_URL	"http://www.D-Link.com/"
#define MODEL_NUMBER	"1234"
#define SERIAL_NUMBER	"5678"
#define UPC				"0001"
/* Chun end */

/* OS/version */
#define OS_URL	"http://openwrt.org/"

#define LOG_MINIUPNPD	LOG_DAEMON

#endif
