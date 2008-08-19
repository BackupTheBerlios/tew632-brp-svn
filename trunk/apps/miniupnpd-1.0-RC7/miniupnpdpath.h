/* $Id: miniupnpdpath.h,v 1.1 2007/09/13 09:04:45 ken_chiang Exp $ */
/* MiniUPnP project
 * http://miniupnp.free.fr/ or http://miniupnp.tuxfamily.org/
 * (c) 2006 Thomas Bernard
 * This software is subject to the conditions detailed
 * in the LICENCE file provided within the distribution */

#ifndef __MINIUPNPDPATH_H__
#define __MINIUPNPDPATH_H__

/* Paths and other URLs in the miniupnpd http server */

#define ROOTDESC_PATH 		"/rootDesc.xml"

#define DUMMY_PATH			"/dummy.xml"

#define WANCFG_PATH			"/WANCfg.xml"
#define WANCFG_CONTROLURL	"/ctl/CmnIfCfg"
#define WANCFG_EVENTURL		"/evt/CmnIfCfg"

#define WANIPC_PATH			"/WANIPCn.xml"
#define WANIPC_CONTROLURL	"/ctl/IPConn"
#define WANIPC_EVENTURL		"/evt/IPConn"

#define WFA_PATH			"http://192.168.0.1:60001/WFAWLANConfig/scpd.xml"
#define WFA_CONTROLURL		"http://192.168.0.1:60001/WFAWLANConfig/control"
#define WFA_EVENTURL		"http://192.168.0.1:60001/WFAWLANConfig/event"

#endif

