/* $Id: minissdp.h,v 1.1 2007/09/13 09:04:45 ken_chiang Exp $ */
/* MiniUPnP project
 * http://miniupnp.free.fr/ or http://miniupnp.tuxfamily.org/
 * (c) 2006 Thomas Bernard
 * This software is subject to the conditions detailed
 * in the LICENCE file provided within the distribution */
#ifndef __MINISSDP_H__
#define __MINISSDP_H__

int
OpenAndConfSSDPReceiveSocket(const char * ifaddr,
                             int n_add_listen_addr,
							 const char * * add_listen_addr);
int
OpenAndConfSSDPNotifySocket(const char * addr);

void
SendSSDPNotifies(int s, const char * host, unsigned short port);

void
ProcessSSDPRequest(int s, const char * host, unsigned short port);

int
SendSSDPGoodbye(int s);

#endif

