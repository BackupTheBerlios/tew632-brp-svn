#include <stdio.h>
#include <string.h>
#include <linux_vct.h>

#ifndef NOVCT
#include <vct.h>
#endif

/* the linux_vct would check vct.c which in platform's vct driver
  * the vct.c must include three function and some define
  *	1. int setPortSpeed(char *ifname, int  portspeed);
  *	2. int getPortConnectState(char *ifname, int portNum);
  *	3. int getPortSpeedState(char *ifname, int portNum, char *portSpeed, char *duplexMode);
  *	4. define VCTSETPORTSPEED_AUTO, VCTSETPORTSPEED_10HALF ...
  */

#ifdef NOVCT
int VCTSetPortSpeed(char *ifname, char *portspeed)
{
	return 0;
}

int VCTGetPortConnectState(char *ifname, int portNum, char *connect_state)
{
	strcpy(connect_state,"connect");
	return 0;
}

int VCTGetPortSpeedState(char *ifname, int portNum, char *portSpeed, char *duplexMode)
{
	strcpy(portSpeed, "100");
	strcpy(duplexMode, "full");		
	return 0;
}

#else
int VCTSetPortSpeed(char *ifname, char *portspeed)
{
	int ret=0;
	int speedmode= -1;

	if( !strcmp(portspeed, "auto"))
		speedmode =  VCTSETPORTSPEED_AUTO;
	if( !strcmp(portspeed, "10half"))
		speedmode =  VCTSETPORTSPEED_10HALF;
	if( !strcmp(portspeed, "10full"))
		speedmode =  VCTSETPORTSPEED_10FULL;
	if( !strcmp(portspeed, "100half"))
		speedmode =  VCTSETPORTSPEED_100HALF;
	if( !strcmp(portspeed, "100full"))
		speedmode =  VCTSETPORTSPEED_100FULL;
	if( !strcmp(portspeed, "giga"))
		speedmode =  VCTSETPORTSPEED_1000FULL;

	if( speedmode >=0)
		ret = setPortSpeed(ifname, speedmode);	
	return ret;
}

int VCTGetPortConnectState(char *ifname, int portNum, char *connect_state)
{
	int state;
	int port=0;

	switch(portNum){
		case VCTWANPORT0:
			port = WAN_PORT;
			break;
		case VCTLANPORT0:
			port = LAN_PORT0;
			break;
		case VCTLANPORT1:
			port = LAN_PORT1;
			break;
		case VCTLANPORT2:
			port = LAN_PORT2;
			break;
		case VCTLANPORT3:
			port = LAN_PORT3;
			break;

	}
	
	state = getPortConnectState(ifname, port);

	if(state == 1)
		strcpy(connect_state,"connect");
	else 
		strcpy(connect_state,"disconnect");

	return 0;
}

int VCTGetPortSpeedState(char *ifname, int portNum, char *portSpeed, char *duplexMode)
{
	int port=0;
	switch(portNum){
		case VCTWANPORT0:
			port = WAN_PORT;
			break;
		case VCTLANPORT0:
			port = LAN_PORT0;
			break;
		case VCTLANPORT1:
			port = LAN_PORT1;
			break;
		case VCTLANPORT2:
			port = LAN_PORT2;
			break;
		case VCTLANPORT3:
			port = LAN_PORT3;
			break;

	}
	return getPortSpeedState(ifname, port, portSpeed, duplexMode);
}
#endif
