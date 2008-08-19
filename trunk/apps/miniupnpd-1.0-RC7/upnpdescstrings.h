/* $Id: upnpdescstrings.h,v 1.1 2007/09/13 09:04:45 ken_chiang Exp $ */
/* miniupnp project
 * http://miniupnp.free.fr/ or http://miniupnp.tuxfamily.org/
 * (c) 2006 Thomas Bernard
 * This software is subject to the coditions detailed in
 * the LICENCE file provided within the distribution */
#ifndef __UPNPDESCSTRINGS_H__
#define __UPNPDESCSTRINGS_H__

#include "config.h"

/* strings used in the root device xml description */
/* Chun modify for INFO-FROM-NVRAM */
#define ROOTDEV_FRIENDLYNAME 		"Router"
#define ROOTDEV_MANUFACTURER		ROOTDEV_FRIENDLYNAME
#define ROOTDEV_MANUFACTURERURL		MANU_URL
#define ROOTDEV_MODELNAME			"Router"
#define ROOTDEV_MODELURL			MODEL_URL
#define ROOTDEV_SERIALNUMBER		SERIAL_NUMBER
#define ROOTDEV_MODELNUMBER			MODEL_NUMBER

#define WANDEV_FRIENDLYNAME			"WANDevice"
#define WANDEV_MANUFACTURER			ROOTDEV_FRIENDLYNAME
#define WANDEV_MANUFACTURERURL		MANU_URL
#define WANDEV_MODELNAME			"WAN Device"
#define WANDEV_MODEDESCRIPTION		"Internet Access Router"
#define WANDEV_MODELNUMBER			MODEL_NUMBER
#define WANDEV_MODELURL				MODEL_URL
#define WANDEV_SERIALNUMBER			SERIAL_NUMBER
#define WANDEV_UPC					UPC

#define WANCDEV_FRIENDLYNAME		"WANConnectionDevice"
#define WANCDEV_MANUFACTURER		ROOTDEV_FRIENDLYNAME
#define WANCDEV_MANUFACTURERURL		MANU_URL
#define WANCDEV_MODELNAME			"WANConnectionDevice"
#define WANCDEV_MODELDESCRIPTION	"WANConnectionDevice"
#define	WANCDEV_MODELNUMBER			MODEL_NUMBER
#define WANCDEV_MODELURL			MODEL_URL
#define WANCDEV_SERIALNUMBER		SERIAL_NUMBER
#define WANCDEV_UPC					UPC

#define WFA_FRIENDLYNAME			"WFADevice"
#define WFA_MANUFACTURER			ROOTDEV_FRIENDLYNAME
#define WFA_MANUFACTURERURL			MANU_URL
#define WFA_MODELNAME				"WFADevice"
#define WFA_MODELDESCRIPTION		"WFADevice"
#define	WFA_MODELNUMBER				MODEL_NUMBER
#define WFA_MODELURL				MODEL_URL
#define WFA_SERIALNUMBER			SERIAL_NUMBER
#define WFA_UPC						UPC

#endif

