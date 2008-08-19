const unsigned char __CAMEO_ATHEROS_VERSION__[] = "2.0";
const unsigned char __CAMEO_ATHEROS_BUILD__[] = "0399";
const unsigned char __CAMEO_ATHEROS_BUILD_DATE__[] = "Wed, 06, Aug, 2008";

#if 0
/*
NOTICE:Please make sure the code has no problem before you commit to CVS server.
Name        : Albert Chen
Type        : Apps
Version     : 1.0.0, build 0399
Tag         : Ath-M-2008-08-06-0399
Description : Fixed DCC get channel will return null issue.
Detail      : 1. apps/DCC/dcc.c

Name        : Jimmy Huang
Type        : Apps
Version     : 1.0.0, build 0398
Tag         : Ath-M-2008-08-06-0398
Description : Vista Logo Test (DTM) bugs fix
			  1. WCN Wireless Registrar Discovery
			  2. WCN Wireless Missing Attribute M4 Message Type
Detail      : 1. apps/wps_ath/wsc/src/common/StateMachine/EnrolleeSM.cpp
			  2. apps/wps_ath/wsc/src/common/StateMachine/StateMachine.cpp

Name        : Cosmo Chang
Type        : Apps
Version     : 1.0.0, build 0397
Tag         : Ath-M-2008-08-05-0397
Description : fix hostapd startup error              
Detail      : 1.Modify apps/rc/wlan_ath.c	
		
Name        : Cosmo Chang
Type        : Apps
Version     : 1.0.0, build 0396
Tag         : Ath-M-2008-08-05-0396
Description : fix calling error of wpa_sup_config(...) in wlan_ath.c              
Detail      : 1.Modify apps/rc/wlan_ath.c	
	
Name        : Bing Chou
Type        : Apps
Version     : 1.0.0, build 0395
Tag         : Ath-M-2008-08-01-0395
Description : Modify to support 11N only mode on 5GHz band
              
Detail      : 1.Modify apps/httpd/wlan_ath.c
              
              
Name        : Chase Cheng
Type        : Apps
Version     : 1.0.0, build 0394
Tag         : Ath-M-2008-08-01-0394
Description : Add CONF_SNMP_TRAP flag
              Fixed that start_snmpd write empty ip to trap session
              Fixed that the set_basic_api ignored snmp_trap_receiver_*=0.0.0.0
Detail      : 1.Modify apps/httpd/cmobasicapi.c
              2.Modify apps/config/Config
              3.Modify apps/rc/app.c

Name        : Albert Chen
Type        : Apps
Version     : 1.0.0, build 0393
Tag         : Ath-M-2008-07-31-0393
Description : Fixed get channel list will crash for differnet cross-compiler
Detail      : 1.Modify apps/sutil/sutil.c

Name        : Jackey Chen
Type        : Apps
Version     : 1.0.0, build 0392
Tag         : Ath-M-2008-07-31-0392
Description : Fixed wizard crash in httpd for TEW-670APB
Detail      : 1.Modify apps/httpd/core.c

Name        : Albert Chen
Type        : Apps
Version     : 1.0.0, build 0391
Tag         : Ath-M-2008-07-31-0391
Description : 1.Modify dhcp clinet get null point will crash
Detail      : 1.Modify apps/udhcp/script.c

Name        : Albert Chen
Type        : Apps
Version     : 1.0.0, build 0390
Tag         : Ath-M-2008-07-30-0390
Description : 1.Modify Makefile for stormlink (arm cpu )using
	      2.Modify udhcp code for little endian cpu type using.
Detail      : 1.Modify Makefile
	      2.Modify apps/busybox-1.01/Makefile
	      3.Modify apps/busybox-1.01/defconfig-pb44
	      4.Modify apps/nvram/nvram.h
	      5.Modify apps/rc/mtd.c
	      6.Modify apps/rc/wlan_ath.c
	      7.Modify apps/sutil/sutil.c
	      8.Modify apps/udhcp/dhcpd.c
	      9.Modify apps/udhcp/serverpacket.c
	      10.Modify apps/wps_ath/hostapd-0.4.8/Makefile
	      11.Modify apps/wps_ath/hostapd-0.4.8/defconfig
	      
Name        : Jackey Chen
Type        : Apps
Version     : 1.0.0, build 0389
Tag         : Ath-M-2008-07-30-0389
Description : Fixed WPS fails for TEW-670APB with Intel 4965 
Detail      : 1.Modify apps/httpd/httpd_util.c
	      2.Modify apps/sutil/sutil.c
	      3.Modify apps/rc/rc.c

Name        : Rock Chen
Type        : Apps
Version     : 1.0.0, build 0388
Tag         : Ath-M-2008-07-30-0388
Description : Modify the MD5 for SNMP. 
Detail      : 1.Modify apps/openssl/Makefile
	      	
Name        : Jackey Chen
Type        : Apps
Version     : 1.0.0, build 0387
Tag         : Ath-M-2008-07-30-0387
Description : Setup security with wpa2_psk and cipher with aes for TEW-670APB after WPS is done. 
Detail      : 1.Modify apps/wps_ath/wsc/src/common/MasterControl/Info.cpp
	      2.Modify apps/wps_ath/wsc/src/linux/Makefile

Name        : Jackey Chen
Type        : Apps
Version     : 1.0.0, build 0386
Tag         : Ath-M-2008-07-29-0386
Description : WPS supports HEX mode SSID both in 5 and 2.4 GHz
Detail      : 1.Modify apps/wps_ath/wsc/src/common/MasterControl/Info.cpp
	      2.Modify apps/wps_ath/wsc/src/linux/Makefile 

Name        : Ken Chiang
Type        : Apps
Version     : 1.0.0, build 0385
Tag         : Ath-M-2008-07-29-0385
Description : 1.setup LED gpio used bsp.h for different model.              
Detail      : 1.added apps/gpio/bsp.h and Modify $(WWW_PATH)/bsp.h
              2.Modify apps/Makefile
              3.Modify apps/gpio/gpio.c
              
Name        : Cosmo Chang
Type        : Apps
Version     : 1.0.0, build 0384
Tag         : Ath-M-2008-07-29-0384
Description : 1.fix countdown page wouldn't work while lan setting was modified in TEW-670APB model
Detail      : 1.added apps/httpd/core.c              
              	
Name        : Ken Chiang
Type        : Apps
Version     : 1.0.0, build 0383
Tag         : Ath-M-2008-07-29-0383Description : 1.setup wireless LED gpio used bsp.h for different model.              
Detail      : 1.added apps/rc/bsp.h and Modify $(WWW_PATH)/bsp.h
              2.Modify apps/Makefile
              3.Modify apps/rc/wlan_ath.c 
              
Name        : Chase Cheng
Type        : Apps
Version     : 1.0.0, build 0382
Tag         : Ath-M-2008-07-25-0382
Description : Add define to make POWER_LED on TEW-670
Detail      : Modify apps/rc.c

Name        : Norp Huang
Type        : Apps
Version     : 1.0.0, build 0381
Tag         : Ath-M-2008-07-25-0381
Description : 1.reduce syslog buffer size from 16k(default) to 4k(minimax)
              2.set ip_conntrack_tcp_timeout_established 120 for FASTNAT mode(DIR-400)
	      3.do some null pointer checking and file operation in apps/httpd/core.c apps/httpd/httpd_util.c apps/nvram/nvram.c apps/sutil/sutil.c
Detail      : 1.Modify apps/busybox-1.00-pre10/defconfig-AR531X
              2.Modify apps/rc/firewall.c
              3.Modify apps/httpd/core.c
                       apps/httpd/httpd_util.c
                       apps/nvram/nvram.c
                       apps/sutil/sutil.c

Name        : Cosmo Chang
Type        : Apps
Version     : 1.0.0, build 0380
Tag         : Ath-M-2008-07-25-0380
Description : 1.fix wlan_ath.c source path of model TEW-670APB	
Detail      : 1.apps\Makefile
		
Name        : Jimmy Huang
Type        : Apps
Version     : 1.0.0, build 0379
Tag         : Ath-M-2008-07-25-0379
Description : 1.Delay o.1 secs before response GetTotalBytesSent to pass Vista Logo Test
Detail      : 1.apps\miniupnpd-1.0-RC7\upnpsoap.c
				
Name        : Jimmy Huang
Type        : Apps
Version     : 1.0.0, build 0378
Tag         : Ath-M-2008-07-25-0378
Description : 1.Modified the variable declaration in nvram_init(), to let some compiler happy
			    (use array instead of dynamic allocate memory with pointer)
Detail      : 1.apps\nvram\nvram.c

Name        : Jimmy Huang
Type        : Apps
Version     : 1.0.0, build 0377
Tag         : Ath-M-2008-07-25-0377
Description : 1.Fixed the bug that when reading local netbios info, if wins server is NULL
			    will cause udhcpc segmentation fault
Detail      : 1.apps\udhcpc\script.c

Name        : Jimmy Huang
Type        : Apps
Version     : 1.0.0, build 0376
Tag         : Ath-M-2008-07-25-0376
Description : 1.Fixed the bug that when UI clean log, it doesn't work
			  2.Fixed the bug when syslogd restore older messages, will generate duplicate logs
Detail      : 1.apps\busybox-1.01\sysklogd\syslogd.c
			  2.apps\busybox-1.00-pre10\sysklogd\syslogd.c
			  3.apps\httpd\cmobasicapi.c

Name        : Jackey Chen
Type        : Apps
Version     : 1.0.0, build 0375
Tag         : Ath-M-2008-07-24-0375
Description : Remove WAN MAC from chklst.txt with AP model
Detail	    : 1.Modify apps/httpd/core.c

Name        : Cosmo Chang
Type        : Apps
Version     : 1.0.0, build 0374
Tag         : Ath-M-2008-07-24-0374
Description : 1.fix(wpa-psk kernel panic in repeater mode) 
	              and merge the wireless 5Ghz
              2.move the GetChannelList to sutil from httpd              
Detail      : 1.modify apps/rc/wlan_ath.c
              2.modify apps/sutil/sutil.c sutil.h
              3.modify apps/httpd/httpd_util.c httpd_util.h
	
Name        : Roy Tseng
Type        : Apps
Version     : 1.0.0, build 0373
Tag         : Ath-M-2008-07-23-0373
Description : 1.fix wpa(2)-psk authentication fail, since "iwpriv ath0 wpa 1" command would cause error occured.
Detail      : 1.apps/rc/wlan_ath.c

Name        : Chase Cheng
Type        : Apps
Version     : 1.0.0, build 0372
Tag         : Ath-M-2008-07-23-0372
Description : 1.Fixed the bug that httpd crashed while user type http://ip/login.cgi
Detail      : 1.apps\httpd\httpd.c

Name        : Jimmy Huang
Type        : Apps
Version     : 1.0.0, build 0371
Tag         : Ath-M-2008-07-23-0371
Description : 1.Fixed the bug of freeing non-dynamic allocate memory
Detail      : 1.apps\httpd\httpd.c

Name        : Jimmy Huang
Type        : Apps
Version     : 1.0.0, build 0370
Tag         : Ath-M-2008-07-23-0370
Description : 1.Fixed the bug that in some situation, reset button misjudge the reset timeing
Detail      : 1.apps\gpio\gpio.c

Name        : Jimmy Huang
Type        : Apps
Version     : 1.0.0, build 0369
Tag         : Ath-M-2008-07-22-0369
Description : 1.Add iptables to deny invalid TCP ACK packet when SPI is disable
Detail      : 1.apps\rc\firewall.c
				
Name        : Roy Tseng
Type        : Apps
Version     : 1.0.0, build 0368
Tag         : Ath-M-2008-07-22-0368
Description : 1.modify the call-up order of ath0 and ath1 for fixing wpa(2)-psk fail of wds repeater mode
Detail      : 1.apps/rc/wlan_ath.c

Name        : Jimmy Huang
Type        : Apps
Version     : 1.0.0, build 0367
Tag         : Ath-M-2008-07-22-0367
Description : 1.Modified that when wan is disconnect, UI doesn't show
			    "router is measuring bandwidth now..."
Detail      : 1.apps\httpd\httpd_utli.c

Name        : Roy Tseng
Type        : Apps
Version     : 1.0.0, build 0366
Tag         : Ath-M-2008-07-22-0366
Description : 1.add SSID_HEX_MODE flag for the hex format of ssid.
Detail      : 1.apps/rc/wlan_ath.c, apps/sutil/sutil.c

Name        : Jimmy Huang
Type        : Apps
Version     : 1.0.0, build 0365
Tag         : Ath-M-2008-07-21-0365
Description : 1.Add dns support for l2tp dialing
Detail      : 1.apps\rc\wan.c

Name        : Jimmy Huang
Type        : Apps
Version     : 1.0.0, build 0364
Tag         : Ath-M-2008-07-21-0364
Description : 1.Fixed the bug when apply url_filter, wl apply empty souce ip or souce mac
				and that cause all lan pc were limited by url_filter
			  2.Fixed SSID and hostname special character support ~`!@#$%^&*()_-+={[]}|\:;"'<,>.?/
Detail      : 1.apps\rc\firewall.c
			  2.apps\httpd\cmobasicapi.c

Name        : Jackey Chen
Type        : Apps
Version     : 1.0.0, build 0363
Tag         : Ath-M-2008-07-21-0363
Description : SSID support HEX mode
Detail      : 1.Modify config/Config
	      2.Modify Makefile
	      3.Modify apps/httpd/cmobasicapi.c

Name        : Nick Chou
Type        : Apps
Version     : 1.0.0, build 0362
Tag         : Ath-M-2008-07-21-0362
Description : 1.in order to reduce memory cost for run BT, so i change fwqd from a deamon to a exe.
Detail      : 1.apps\fw_query\main.c
                apps\rc\app.c
                apps\httpd\cmobasicapi.c

Name        : Roy Tseng
Type        : Apps
Version     : 1.0.0, build 0361
Tag         : Ath-M-2008-07-21-0361
Description : 1.add wpa-psk, wpa2-psk authentication for WDS ap, bridge, repeater mode.
              2.add CONFIG_WL_ATH_WDS flag for WDS feature choiced.
Detail      : 1.Modify apps/config/Config, apps/rc/wlan_ath.c, apps/rc/Makefile, apps/sutil/sutil.c

Name        : Jimmy Huang
Type        : Apps
Version     : 1.0.0, build 0360
Tag         : Ath-M-2008-07-21-0360
Description : Modified that L2TP doesn't append physical dns when connected
Detail      : 1.apps\udhcp\script.c
			  2.apps\ppp\pppd\ipcp.c
				
Name        : Jimmy Huang
Type        : Apps
Version     : 1.0.0, build 0359
Tag         : Ath-M-2008-07-18-0359
Description : Fixed the bug Ath-M-2008-07-18-0358 miss a definition to
                seperate Netbios releated function
Detail      : 1.Modify apps\udhcp\dhcpc.c

Name        : Jimmy Huang
Type        : Apps
Version     : 1.0.0, build 0358
Tag         : Ath-M-2008-07-18-0358
Description : Fixed the bug Ath-M-2008-07-18-0357 miss a definition to 
				seperate Netbios releated function
Detail      : 1.Modify apps\udhcp\dhcpc.c

Name        : Jimmy Huang
Type        : Apps
Version     : 1.0.0, build 0357
Tag         : Ath-M-2008-07-18-0357
Description : Fixed the bug when wan ip is not change but NetBios info changes,
				dhcpd doesn't restart
Detail      : 1.Modify apps\udhcp\dhcpc.c
	          2.Modify apps\udhcp\script.c
											
Name        : Nick Chou
Type        : Apps
Version     : 1.0.0, build 0356
Tag         : Ath-M-2008-07-18-0356
Description : When RUSSIA PPTP(PPPOE) disconnect, 
              we can recovery WAN Physical DNS (get from DHCP server) from RUSSIA_PHY_RESOLVFILE.
	      So WEB GUI would not show PPP DNS if RUSSIA PPTP(PPPOE) disconnect.
Detail      : 1.Modify apps\udhcp\samples\sample.russia-bound-dns
	      2.Modify apps\sutil\shvar.h
	      3.Modify apps\rc\wan.c

Name        : Jackey chen
Type        : Apps
Version     : 1.0.0, build 0355
Tag         : Ath-M-2008-07-17-0355
Description : Add Ath_5GHZ flag
Detail      : 1.Modify apps/httpd/cmobasicapi.c
	      2.Modify apps/config/Config
	      3.Modify apps/Makefile

Name        : Albert Chen
Type        : Apps
Version     : 1.0.0, build 0354
Tag         : Ath-M-2008-07-17-0354
Description : fixed NHAP support unknown call
	      fixed if model not support configuration "wlan0_op_mode", the device will not set ssid to wireless driver
Detail      : 1.httpd/httpd_util.c 
	      2.httpd/pure.c
	      3.httpd/pure.h
	      4.httpd/pure_xml.c
	      5.rc/wlan_ath.c

Name        : Nick Chou
Type        : Apps
Version     : 1.0.0, build 0353
Tag         : Ath-M-2008-07-17-0353
Description : fixed make error in timer.c (add define CONFIG_IP_LOOKUP)
Detail      : 1.Modify apps/timer/timer.c

Name        : Jackey chen
Type        : Apps
Version     : 1.0.0, build 0352
Tag         : Ath-M-2008-07-17-0352
Description : Mac filter supports 5GHz configuration.
Detail      : 1.Modify apps/rc/wlan_ath.c

Name        : Jackey chen
Type        : Apps
Version     : 1.0.0, build 0351
Tag         : Ath-M-2008-07-17-0351
Description : Add wlan1_mac_filter_type and wlan1_mac_filter_XX in httpd
Detail      : 1.Modify apps/httpd/cmobasicapi.c

Name        : Jackey chen
Type        : Apps
Version     : 1.0.0, build 0350
Tag         : Ath-M-2008-07-17-0350
Description : Add wlan1_op_mode in httpd
Detail      : 1.Modify apps/httpd/cmobasicapi.c

Name        : Tina Tsao
Type        : Apps
Version     : 1.0.0, build 0349
Tag         : Ath-M-2008-07-17-0349
Description : 1.Fixed wep Ascii not transfer to Hex in 5G mode.
	      2.Fixed not show ssid in 5G mode.
Detail      : 1.Modify apps/httpd/httpd_util.c
	      2.Modify apps/httpd/cmobasicapi.c
	      3.Modify apps/rc/wlan_ath.c

Name        : Jackey chen
Type        : Apps
Version     : 1.0.0, build 0348
Tag         : Ath-M-2008-07-16-0348
Description : Fixed parse error in httpd for clearing packet information.
Detail      : 1.Modufy apps/httpd/httpd_util.c

Name        : Nick Chou
Type        : Apps
Version     : 1.0.0, build 0347
Tag         : Ath-M-2008-07-16-0347
Description : Using timer deamon to run arpping function every 180 sec
Detail      : 1.Modufy \apps\timer\timer.c

Name        : Jackey chen
Type        : Apps
Version     : 1.0.0, build 0346
Tag         : Ath-M-2008-07-15-0346
Description : Fixed parse error in httpd for packet information.
Detail      : 1.Modufy apps/httpd/httpd_util.c

Name        : Norp Huang
Type        : Apps
Version     : 1.0.0, build 0345
Tag         : Ath-M-2008-07-15-0345
Description : 1.rollback FASTNAT definition in apps/rc/Makefile
Detail      : 1.Modify apps/rc/Makefile

Name        : Nick Chou
Type        : Apps
Version     : 1.0.0, build 0344
Tag         : Ath-M-2008-07-15-0344
Description : 1. fixed that Deny WAN hosts ping router's LAN IP.
Detail      : 1.Modify apps\rc\firewall.c
                       apps\rc\wan.c

Name        : Nick Chou
Type        : Apps
Version     : 1.0.0, build 0343
Tag         : Ath-M-2008-07-15-0343
Description : 1. fixed that Deny WAN hosts ping router's LAN IP.
              2. fixed that PPTP(RUSSIA PPTP) firewall NAT Tables may fail if 
                 device don't get WAN Physical IP
Detail      : 1.Modify apps\rc\firewall.c

Name        : Norp Huang
Type        : Apps
Version     : 1.0.0, build 0342
Tag         : Ath-M-2008-07-15-0342
Description : fix no receive "rc restart" in FASTNAT mode(DIR-400)
Detail      : 1.Modify apps/rc/rc.c

Name        : Roy Tseng
Type        : Apps
Version     : 1.0.0, build 0341
Tag         : Ath-M-2008-07-14-0341
Description : Modify the name of wds mac from wlan0_wds_br_mac to wlan0_wds_remote_mac
Detail      : 1.Modify apps/rc/wlan_ath.c

Name        : Jackey chen
Type        : Apps
Version     : 1.0.0, build 0340
Tag         : Ath-M-2008-07-14-0340
Description : Modify nvram value in httpd
Detail      : 1.Modify apps/httpd/cmobasicapi.c

Name        : Roy Tseng
Type        : Apps
Version     : 1.0.0, build 0339
Tag         : Ath-M-2008-07-14-0339
Description : Add Atheros WDS ap, WDS bridge and WDS repeater feature.
              Add define flag for 3 wds modes.
Detail      : 1.Modify apps/rc/wlan_ath.c
	      2.Modify apps/rc/Makefile

Name        : Jackey chen
Type        : Apps
Version     : 1.0.0, build 0338
Tag         : Ath-M-2008-07-14-0338
Description : Add WDS flags for Atheros
Detail      : 1.Modify apps/config/Config
	      2.Modify apps/Makefile

Name        : Jackey chen
Type        : Apps
Version     : 1.0.0, build 0337
Tag         : Ath-M-2008-07-11-0337
Description : Add token(:) in mac
Detail      : 1.Modify apps/rc/wlan_ath.c
	      2.Modify apps/sutil/sutil.c

Name        : Jackey chen
Type        : Apps
Version     : 1.0.0, build 0336
Tag         : Ath-M-2008-07-11-0336
Description : Modify wlan to support WDS mode(br & rpt)
Detail      : 1.Modify apps/rc/wlan_ath.c

Name        : Chase Cheng
Type        : Apps
Version     : 1.0.0, build 0335
Tag         : Ath-M-2008-07-11-0335
Description : Remove redundant nvram name - dhcpd_enable
Detail      : 1. apps/httpd/cmobasic.c

Name        : Jimmy Huang
Type        : Apps
Version     : 1.0.0, build 0334
Tag         : Ath-M-2008-07-11-0334
Description : Modified the metric value from 0 to 1 for dhcp option 33,121,249
Detail      : 1. apps/udhcp/dhcpc.c
							 
Name        : Norp Huang
Type        : Apps
Version     : 1.0.0, build 0333
Tag         : Ath-M-2008-07-10-0333
Description : 1.Busybox uses vmalloc in FASTNAT mode(DIR-400)
              2.Modify "line" size in httpd when FASTNAT(DIR-400) 
Detail      : 1.Modify apps/busybox-1.00-pre10/defconfig-AR531X
	      2.Modify apps/httpd/httpd.c

Name        : Jackey chen
Type        : Apps
Version     : 1.0.0, build 0332
Tag         : Ath-M-2008-07-10-0332
Description : Add wds configurations in httpd
Detail      : 1.Modify apps/httpd/cmobasicapi.c

Name        : Rock Chen
Type        : Apps
Version     : 1.0.0, build 0331
Tag         : Ath-M-2008-07-10-0331
Description : Enable the SNNP system mib for TEW-670APB
Detail      : 1.Modify apps/snmp/Makefile
	
Name        : Jackey chen
Type        : Apps
Version     : 1.0.0, build 0330
Tag         : Ath-M-2008-07-10-0330
Description : Modify wlan0_cts_enable to wlan0_cts
Detail      : 1.Modify apps/httpd/cmobasicapi.c

Name        : Nick Chou
Type        : Apps
Version     : 1.0.0, build 0329
Tag         : Ath-M-2008-07-10-0329
Description : 1.improve issue => [WAN PC] PING [LAN Device IP] and Device will send PING_REPLY with WAN MAC
Detail	    : 1.Modify apps/rc/wan.c

Name        : Joe Lin
Type        : Apps
Version     : 1.0.0, build 0328
Tag         : Ath-M-2008-07-10-0328
Description : 1.fixed Error String "Sucess"->"Succes"
Detail	    : 1.Modify apps/httpd/core.c


Name        : Norp Huang
Type        : Apps
Version     : 1.0.0, build 0327
Tag         : Ath-M-2008-07-09-0327
Description : 1. reduce memory size after boot-up(for DIR-400)
              2. ip_conntrack_max 512 for DIR-400
Detail	    : 1.Modify apps/rc/Makefile
              2.Modify apps/rc/rc.c
              3.Modify apps/rc/firewall.c

Name        : Rock Chen
Type        : Apps
Version     : 1.0.0, build 0326
Tag         : Ath-M-2008-07-09-0326
Description : Update the test folder of OpenSSL 
Detail	    : 1.Modify apps/openssl/test
							2.Add the apps/openssl/apps/md4.c
							3.Modify apps/snmp/Makefile
	
Name        : Jackey Chen
Type        : Apps
Version     : 1.0.0, build 0325
Tag         : Ath-M-2008-07-09-0325
Description : 1.Sutil support wpa_supplicant parse
Detail	    : 1.Modify apps/sutil/sutil.c

Name        : Jimmy Huang
Type        : Apps
Version     : 1.0.0, build 0324
Tag         : Ath-M-2008-07-09-0324
Description : Disable the account name checking for DIR-400
              (Only check admin_account)
               (Related tag: Ath-M-2008-06-30-0293, Ath-M-2008-07-07-0321)
Detail      : 1. apps/rc/qos.c
							  
Name        : Rock Chen
Type        : Apps
Version     : 1.0.0, build 0323
Tag         : Ath-M-2008-07-09-0323
Description : Enable the SNMP functionality for TEW-670APB
Detail      : 
	      1. apps/Makefile
	      2. apps/openssl/Makefile
	      3. apps/openssl/include/openssl/opensslconf.h
	      4. apps/openssl/crypto/opensslconf.h
	      5. apps/openssl/crypto/bio/bss_file.c
	      6. apps/snmp/Makefile
	      7. apps/rc/app.c
	      	

Name        : Jimmy Huang
Type        : Apps
Version     : 1.0.0, build 0322
Tag         : Ath-M-2008-07-09-0322
Description : Fixed the bug that when disable Qos, Qos still limited the uplink bandwidth
			  (DIR-615_C1, bug list item 47)
                (Related tag: Ath-M-2008-06-30-0293)
Detail      : 1. apps/rc/qos.c

Name        : Jimmy Huang
Type        : Apps
Version     : 1.0.0, build 0321
Tag         : Ath-M-2008-07-07-0321
Description : Disable the account name checking for DIR-400
				(Related tag: Ath-M-2008-06-30-0293)
Detail      : 1. apps/httpd/core.c
							
Name        : Ken Chiang
Type        : Apps
Version     : 1.0.0, build 0320
Tag         : Ath-M-2008-07-07-0320
Description : Modify for wps support 5G band.
Detail      : 1. \apps\rc\wlan_ath.c.
              2. \apps\wps_ath\wsc\src\common\MasterControl\Info.cpp,Info.h,MasterControl.cpp.
              3. \apps\wps_ath\wsc\src\common\WscCmd\WscCmd.cpp

Name        : Chase Cheng
Type        : Apps
Version     : 1.0.0, build 0319
Tag         : Ath-M-2008-07-07-0319
Description : Modify Makefiles in dhcpv6 and flex
Detail      : 1. \apps\flex\Makefile
                 \apps\dhcpv6\Makefile

Name        : Nick Chou
Type        : Apps
Version     : 1.0.0, build 0318
Tag         : Ath-M-2008-07-04-0318
Description : support upgrade bootloader in run-time web GUI
Detail      : 1. \apps\rc\mtd.c
                 \apps\httpd\core.c
                 \apps\sutil\shvar.h

Name        : Chase Cheng
Type        : Apps
Version     : 1.0.0, build 0317
Tag         : Ath-M-2008-07-04-0317
Description : Add default gateway with flag AP_NOWAN_HASBRIDGE
Detail      : 1.Modify apps/rc/wan.c

Name        : Jackey Chen
Type        : Apps
Version     : 1.0.0, build 0316
Tag         : Ath-M-2008-07-04-0316
Description : Add CmoGetStatus(ap_udhcpc_lan_ip_info) in httpd(It is useful for ap mode in status page)
Detail      : 1.Modify apps/httpd/cmobasicapi.c
	      2.Modify apps/httpd/cmoapi.h
	      3.Modify apps/httpd/http_util.c

Name        : Jackey Chen
Type        : Apps
Version     : 1.0.0, build 0315
Tag         : Ath-M-2008-07-04-0315
Description : udhcpc support ap mode for TEW-670APB.
Detail      : 1.modify apps/rc/wan.c

Name        : Chase Cheng
Type        : Apps
Version     : 1.0.0, build 0314
Tag         : Ath-M-2008-07-04-0314
Description : Enable Ath MAC filter (309 added wrong file)
Detail      : 1.Modify apps/rc/wlan_ath.c

Name        : Jackey Chen
Type        : Apps
Version     : 1.0.0, build 0313
Tag         : Ath-M-2008-07-04-0313
Description : TEW-670APB does not run firewall in rc
Detail	    : 1.Modify apps/rc/rc.c
	      2.Modify apps/rc/firewall.c

Name        : Chase Cheng
Type        : Apps
Version     : 1.0.0, build 0312
Tag         : Ath-M-2008-07-04-0312
Description : Modify the include problem on different platform
Detail      : 1.Modify apps/wps_ath/wpa_supplicant-0.5.5/.config

Name        : Jackey Chen
Type        : Apps
Version     : 1.0.0, build 0311
Tag         : Ath-M-2008-07-03-0311
Description : Modify the radius option of pure/owera to avoid daemon crusing.(It should not happen 
	      except TEW-670APB.)
Detail      : 1.Modify apps/httpd/pure.c
	      2.Modify apps/owera/src/app/src/client_oscf.c

Name        : Jackey Chen
Type        : Apps
Version     : 1.0.0, build 0310
Tag         : Ath-M-2008-07-03-0310
Description : Modify the radius option of hostapd configuration to avoid snmpd crusing. 
Detail      : 1.Modify apps/rc/wlan_ath.c

Name        : Chase Cheng
Type        : Apps
Version     : 1.0.0, build 0309
Tag         : Ath-M-2008-07-03-0309
Description : Enable Ath MAC filter
Detail      : 1.Modify apps/rc/wlan.c

Name        : Jackey Chen
Type        : Apps
Version     : 1.0.0, build 0308
Tag         : Ath-M-2008-07-03-0308
Description : Support MAC Filter for Atheros solution in AP mode.
Detail	    : 1.Modify config/Config
	      2.Modify Makefile
	      3.Modify apps/rc/rc.c

Name        : Jimmy Huang
Type        : Apps
Version     : 1.0.0, build 0307
Tag         : Ath-M-2008-07-03-0307
Description : Fixed dtrack HQ20080703000004, wan interface will response the arp
				request that target IP belongs to lan interface
Detail      : 1. rc/firewall.c
							
Name        : Chase Cheng
Type        : Apps
Version     : 1.0.0, build 0306
Tag         : Ath-M-2008-07-03-0306
Description : Remove set ip in lan.c
Detail      : 1. apps/rc/lan.c

Name        : Chase Cheng
Type        : Apps
Version     : 1.0.0, build 0305
Tag         : Ath-M-2008-07-03-0305
Description : Add a dhcpc behavior while the device is an AP with switch, the flag be defined as AP_NOWAN_HASBRIDGE
	      Add behavior in start_dhcpd with the flag be defined as AP_NOWAN_HASBRIDGE
Detail      : 1. apps/rc/lan.c
              2. apps/rc/wan.c
	      3. apps/rc/app.c


Name        : Jimmy Huang
Type        : Apps
Version     : 1.0.0, build 0304
Tag         : Ath-M-2008-07-03-0304
Description : Fixed the bug that when wan proto is dhcpc, after change wan's connection 
			  to another dhcp server, dns server list in router will be append
			  (should be replaced)
Detail      : 1. udhcp/script.c

Name        : Cosmo Chang
Type        : Apps
Version     : 1.0.0, build 0303
Tag         : Ath-M-2008-07-03-0303
Description : Add New SnmpV3 Paramenter
Detail      : 1. /httpd/cmobasicapi.c
	
Name        : Jimmy Huang
Type        : Apps
Version     : 1.0.0, build 0301
Tag         : Ath-M-2008-07-03-0301
Description : Fixed the bug that "IPROUTE2 -- iproute2 package" can't show up when make menuconfig
Detail      : 1. apps/config/Config

Name        : Albert Chen
Type        : Apps
Version     : 1.0.0, build 0300
Tag         : Ath-M-2008-07-02-0300
Description : Add show ping display result on wed function
Detail      : 1. /httpd/cmoapi.h
	      2. /httpd/cmobasicapi.c
	      3. /httpd/httpd_util.c
	      4. /httpd/httpd_util.h

Name        : Jimmy Huang
Type        : Apps
Version     : 1.0.0, build 0299
Tag         : Ath-M-2008-07-02-0299
Description : Add default selection for CONFIG_WLAN_GUEST_ZONE in busybox-1.01
Detail      : 1. busybox-1.01/defconfig-pb42

Name        : Jackey Chen
Type        : Apps
Version     : 1.0.0, build 0298
Tag         : Ath-M-2008-07-02-0298
Description : Move syslogd to the bottom of the applicants.(It will cause error for TEW-670APB)
Detail      : 1.Modify apps/rc/app.c

Name        : Jimmy Huang
Type        : Apps
Version     : 1.0.0, build 0297
Tag         : Ath-M-2008-07-01-0297
Description : Modified syslogd to meet the requirement that when
			  syslogd restart, old logs in shared memory will be saved
			  and reload.
Detail      : 1. busybox-1.00-pre10/sysklogd/syslogd.c
			  2. busybox-1.01/syslogd/syslogd.c

Name        : Jimmy Huang
Type        : Apps
Version     : 1.0.0, build 0296
Tag         : Ath-M-2008-07-01-0296
Description : Fixed the bug in busybox-1.000-pre10/sysklogd/logread.c
Detail      : 1. busybox-1.000-pre10/sysklogd/logread.c

Name        : NickChou
Type        : Apps
Version     : 1.0.0, build 0295
Tag         : Ath-M-2008-07-01-0295
Description : 1. Add "brctl setguestzone" for support wireless guest zone 
Detail      : 1.apps\busybox-1.01\Makefile
                apps\busybox-1.01\defconfig-ap94
                apps\busybox-1.01\networking\Config.in
                apps\busybox-1.01\networking\brctl.c
                apps\busybox-1.01\networking\libbridge\libbridge_devif.c
                apps\busybox-1.01\networking\libbridge\libbridge.h
                apps\busybox-1.01\include\usage.h
                

Name        : Jackey Chen
Type        : Apps
Version     : 1.0.0, build 0294
Tag         : Ath-M-2008-07-01-0294
Description : Support client ping for WPS 
Detail      : 1.Modify apps/httpd/core.c

Name        : Jimmy Huang
Type        : Apps
Version     : 1.0.0, build 0293
Tag         : Ath-M-2008-06-30-0293
Description : Disable the account name checking for DIR-400
Detail      : 1. apps/httpd/core.c


Name        : Jackey Chen
Type        : Apps
Version     : 1.0.0, build 0292
Tag         : Ath-M-2008-06-30-0292
Description : Fixed making error for wpa_supplicant of Atheros solution.
Detail      : 1.Modify apps/Makefile
	      2.Modify apps/wpa/wpa_supplicant-0.5.5/Makefile
	      3.Modify apps/wpa/wpa_supplicant-0.5.5/.config

Name        : Jackey Chen
Type        : Apps
Version     : 1.0.0, build 0291
Tag         : Ath-M-2008-06-30-0291
Description : Add wpa_supplicant support for Atheros solution.
Detail      : 1.Modify apps/config/Config
	      2.Modify apps/Makefile
	      3.Add apps/wps_ath/wpa_supplicant-0.5.5/

Name        : Jimmy Huang
Type        : Apps
Version     : 1.0.0, build 0290
Tag         : Ath-M-2008-06-30-0290
Description : Fixed the compile warning msg in httpd/cmobasicapi.c
			  function return_internet_session_table(), too more %s
				websWrite(wp,"%s/%s/%s/%s/%s/%s/%s/%s/%s,",\ ...
Detail		: 1. httpd/cmobasicapi.

Name        : Jimmy Huang
Type        : Apps
Version     : 1.0.0, build 0289
Tag         : Ath-M-2008-06-30-0289
Description :   1. Modify syslogd's format to "Last Log First Show" mode for (DIR-400) busybox-1.00-pre10
Detail		:	1. busybox-1.00-pre10/include/usage.h
				2. busybox-1.00-pre10/sysklogd/logread.c
				3. busybox-1.00-pre10/sysklogd/syslogd.c

Name        : Jimmy Huang
Type        : Apps
Version     : 1.0.0, build 0288
Tag         : Ath-M-2008-06-30-0288
Description : 	1. Modify syslogd's format to "Last Log First Show" mode
				2. system messages now print out in "Last Log First Show" mode
				3. system messages now send out in "Last Log First Show" mode
				5. running syslogd with "syslogd -C size", logged messages in a shared memory
				6. using "logread" or "logread -r" to show messages
				7. LOG_FILE ("/var/log/FW_log")
					- not modify it, so if it's enabled, it's not in "Last Log First Show" order !!
				8. Ignore booting messages
				9. Replace save2file(LOG_FILE_HTTP) with syslog()
Detail      : 	1. busybox-1.01/include/usage.h
				2. busybox-1.01/sysklogd/logread.c
				3. busybox-1.01/sysklogd/syslogd.c
				4. httpd/log.c
				5. httpd/cmobasicapi.c
				6. mail_client/src/smtp.c
				7. mail_client/src/net.c
				8. mail_client/src/msmtp.c
				9. Mail-On-Schedule/main.c
				10.rc/app.c
				11.rc/rc.c

Name        : Albert Chen
Type        : Apps
Version     : 1.0.0, build 0287
Tag         : Ath-M-2008-06-25-0287
Description : Add define for non A band model
Detail      : 1.Modify apps/rc/wlah_ath.c

Name        : Norp Huang
Type        : Apps
Version     : 1.0.0, build 0286
Tag         : Ath-M-2008-06-25-0286
Description : ip_conntrack_max 1024 for non-AR9100 platform(DIR-400)
Detail      : 1.Modify apps/rc/firewall.c

Name        : Albert Chen
Type        : Apps
Version     : 1.0.0, build 0285
Tag         : Ath-M-2008-06-25-0285
Description : Fixed the wireless set security will cause wireless crash
Detail      : 1.Modify apps/rc/wlan_ath.c

	      
Name        : Jackey Chen
Type        : Apps
Version     : 1.0.0, build 0284
Tag         : Ath-M-2008-06-23-0284
Description : Fixed the bug that httpd and nvram do not sync at IPv6 page
Detail      : 1.Modify apps/httpd/core.c
	      2.Modify apps/timer/timer.c

Name        : Jimmy
Type        : Apps
Version     : 1.0.0, build 0283
Tag         : Ath-M-2008-06-23-0283
Description : Fixed the bug that hostname doen't work (gateway name,nmbd)
			  Fixed the bug if the last line of nvram.default isn't ended with
			  '\n', sometimes nvram related functions will take the last line as
			  useless data.
Detail      : 1.apps/app.c
          	  2.apps/nvram/nvram.c
		  
Name        : Jackey Chen
Type        : Apps
Version     : 1.0.0, build 0282
Tag         : Ath-M-2008-06-20-0282
Description : Fixed TSD BUG no.55 for IPv6
Detail      : 1.Modify apps/rc/rc.c
	      2.Modify apps/timer/timer.c

Name        : Albert Chen
Type        : Apps
Version     : 1.0.0, build 0281
Tag         : Ath-M-2008-06-20-0281
Description : Fixed the dhcp server always broadcast option fail issue.
Detail      : apps/udhcp/serverpacket.c

Name        : Jimmy Huang
Type        : Apps
Version     : 1.0.0, build 0280
Tag         : Ath-M-2008-06-20-0280
Description : Fixed the bug that setting PPPoE's MTU not works
Detail      : apps/ppp/pppd/lcp.c
												
Name        : Albert Chen
Type        : Apps
Version     : 1.0.0, build 0279
Tag         : Ath-M-2008-06-20-0279
Description : Modify wirelss led control for AG switchable project
Detail      : 1.Modify apps/rc/wlan_ath.c
	      
Name        : Jimmy Huang
Type        : Apps
Version     : 1.0.0, build 0278
Tag         : Ath-M-2008-06-18-0278
Description :  Unmarked the code when enable Netmetting in virtual server (1720)
				now also open port 1503, refer to 
				Ath-M-2008-06-18-0272
				Ath-M-2008-05-15-0240
Detail      : apps/firewall.c
				
Name        : Jackey Chen
Type        : Apps
Version     : 1.0.0, build 0277
Tag         : Ath-M-2008-06-18-0277
Description : Fixed dhcp always broadcast bootp option error issue
Detail      : 1.Modify Modify apps/udhcp/packet.c

	      
Name        : Jackey Chen
Type        : Apps
Version     : 1.0.0, build 0276
Tag         : Ath-M-2008-06-18-0276
Description : Fixed the bug for scan list.
Detail      : 1.Modify Modify apps/httpd/cmobasicapi.c
	      2.Modify Modify apps/sutil/sutil.c

Name        : Albert Chen
Type        : Apps
Version     : 1.0.0, build 0275
Tag         : Ath-M-2008-06-18-0275
Description : Modify wirelss code for A band
Detail      : 1.Modify apps/httpd/http_util.c
	      2.Modify apps/rc/wlan_ath.c

Name        : Jimmy Huang
Type        : Apps
Version     : 1.0.0, build 0274
Tag         : Ath-M-2008-06-18-0274
Description :  Fixed the bug that schedule start_time, end_time can't
				be parsed correctly (in schedule2iptables())
Detail      : apps/firewall.c
				
Name        : Jackey Chen
Type        : Apps
Version     : 1.0.0, build 0273
Tag         : Ath-M-2008-06-18-0273
Description : Httpd supports scan list for ap.
Detail      : 1.Modify apps/httpd/cmoapi.h
	      2.Modify apps/httpd/cmobasicapi.c
	      3.Modify apps/sutil/shvar.h

Name        : Jimmy Huang
Type        : Apps
Version     : 1.0.0, build 0272
Tag         : Ath-M-2008-06-18-0272
Description : Mofify the bug that H.323 port 1720 not open 
				refer to tag Ath-M-2008-05-15-0240
Detail		: apps/firewall.c

Name        : Chase Cheng
Type        : Apps
Version     : 1.0.0, build 0271
Tag         : Ath-M-2008-06-17-0271
Description : Modify url parser in do_upload_post
Detail      : 1.Modify apps/httpd/core.c

Name        : Jackey Chen
Type        : Apps
Version     : 1.0.0, build 0270
Tag         : Ath-M-2008-06-16-0270
Description : Add nvram value -> wireless_band in httpd
Detail      : 1.Modify apps/httpd/cmobasicapi.c

Name        : Albert Chen
Type        : Apps
Version     : 1.0.0, build 0269
Tag         : Ath-M-2008-06-12-0269
Description : Modify get channel list and wirelss start up in 5G Band
Detail      : 	1. apps/httpd/httpd_util.c
		1. apps/httpd/cmobasicapi.c
		2. apps/rc/wlan_ath.c
				
Name        : Jimmy Huang
Type        : Apps
Version     : 1.0.0, build 0268
Tag         : Ath-M-2008-06-12-0268
Description : Mofify dnsmasq to achive the function
			  - Russia mode:
				- runs with option -o, always querys in strict-order mode,
				- only when dns response code is 0 (NOERROR) or 
					all avaliable dns servers have been queried 
					the dnsmasq ends the resend action, then send the response
					to client
				- Not integrate into IPv6
			  - Non-Russia:
				- runs without option -o (strict-order) 
				- fit cdrouter dns fail-over test 45,46 scenario
					(only do the fail-over when response code is 2 SERVFAIL or 4 NOTIMP or 5 REFUSED)
Detail      : 	1. apps/dnsmasq-2.41/src/forward.c
				2. apps/dnsmasq-2.41/src/dnsmasq.h
				3. apps/dnsmasq-2.41/src/dnsmasq.c
				4. apps/rc/app.c

Name        : Jimmy Huang
Type        : Apps
Version     : 1.0.0, build 0267
Tag         : Ath-M-2008-06-06-0267
Description : Fixed the bug that handling dhcp 249 option with subnet 255.255.0.0
							failed
Detail      : 1.apps/udhcpc/dhcpc.c
	      
Name        : Jackey Chen
Type        : Apps
Version     : 1.0.0, build 0266
Tag         : Ath-M-2008-06-05-0266
Description : Fixed the bug that UI can not save nvram value at rc init with IPv6 support
Detail      : 1.Modify apps/timer/timer.c
	      2.Modify apps/rc/app.c
	      3.Modify apps/rc/rc.c

Name        : Albert Chen
Type        : Apps
Version     : 1.0.0, build 0265
Tag         : Ath-M-2008-06-05-0265
Description : 1. Modify WPS in unconfig mode the auto channel should be disable
	      2. Modify finished the WPS process, restart the wireless driver for linking rate issue
Detail      : 1. /apps/wpa/wsc/src/common/MasterControl/MasterControl.cpp
	      2. /apps/wpa/wsc/src/common/MasterControl/Info.h
	      
Name        : Albert Chen
Tyep        : Apps
Version     : 1.00, build 0264
Tag         : Ath-M-2008-06-04-0264
Description : 1. Change WPS default cipher to AES
Detail      : 1. apps/wps_ath/wsc/src/common/WscCmd/WscCmd.cpp

Name        : Jimmy Huang
Tyep        : Apps
Version     : 1.00, build 0263
Tag         : Ath-M-2008-06-03-0263
Description : 1. remove the symlink for /var/sbin/mbandwidth, due to it's useless
Detail      : 1. apps/rc/rc.c
			  
Name        : Jimmy Huang
Tyep        : Apps
Version     : 1.00, build 0262
Tag         : Ath-M-2008-06-03-0262
Description : 1. seperate the functionality "measure bandwidth" from rc
				 to another module "mbandwidth"
Detail      : 1. apps/rc/qos.c
			  2. apps/rc/rc.c
			  3. apps/rc/rc.h
			  4. apps/rc/wan.c
			  5. apps/Makefile
			  6. apps/config/Config
			  7. apps/mbandwidth/*
			  
Name        : Jimmy Huang
Tyep        : Apps
Version     : 1.00, build 0261
Tag         : Ath-M-2008-06-02-0261
Description : 1. fixed the bug enable acces control with block some access,
				 and enable web access logging, logging doen't work.
Detail      : 1. apps/rc/firewall.c

Name        : Ken Chiang
Tyep        : Apps
Version     : 1.00, build 0260
Tag         : Ath-M-2008-05-29-0260
Description : 1. fixed wrong source IP for PPTP / L2TP / Russia PPTP / Russia PPPoE when Dynamic IP chang to Static IP.
Detail      : 1. apps/rc/wan.c,ppp.c

Name        : Jimmy Huang
Tyep        : Apps
Version     : 1.00, build 0259
Tag         : Ath-M-2008-05-28-0259
Description : 1. fixed the bug when change dhcpd ip range, dhcpd start too quickly
			     thus it do not get new ip
Detail      : 1. apps/rc/lan.c

Name        : Jimmy Huang
Tyep        : Apps
Version     : 1.00, build 0258
Tag         : Ath-M-2008-05-28-0258
Description : 1. fixed the bug for dhcpd ip range start_ip and end_ip
Detail      : 1. apps/rc/app.c

Name        : Ken Chiang
Tyep        : Apps
Version     : 1.00, build 0257
Tag         : Ath-M-2008-05-28-0257
Description : 1. fixed Protocol Filter for DNS rule
Detail      : 1. \apps\rc\firewall.c

Name        : Nick Chou
Tyep        : Apps
Version     : 1.00, build 0256
Tag         : Ath-M-2008-05-27-0256
Description : 1. fixed Ath-M-2008-05-20-0246 bug when ($(PLATFORM) = AthSDK_AP61
Detail      : 1. \apps\wps_ath\wsc\lib\openssl-0.9.8a\Makefile
                 apps\wps_ath\wsc\src\linux\Makefile

Name        : Nick Chou
Tyep        : Apps
Version     : 1.00, build 0255
Tag         : Ath-M-2008-05-27-0255
Description : 1. Add SMTP Serever Port(log_email_server_port) support in log email
Detail      : 1. \apps\httpd\cmobasicapi.c
                 \apps\httpd\httpd_util.c
                 \apps\rc\app.c

Name        : Nick Chou
Tyep        : Apps
Version     : 1.00, build 0254
Tag         : Ath-M-2008-05-26-0254
Description : 1. Fixed log email bug when using GUI without schedule button (TEW-632BRP)
Detail      : 1. apps/Mail-On-Schedule/main.c

Name        : Jimmy Huang
Tyep        : Apps
Version     : 1.00, build 0253
Tag         : Ath-M-2008-05-26-0253
Description : 1. modify the bug when set netbios, dhcpd won't start after rc restart
				 refert to Nick's modification (Ath-M-2008-05-23-0249)
Detail      : 1. apps/rc/lan.c
	
Name        : Albert Chen
Tyep        : Apps
Version     : 1.00, build 0252
Tag         : Ath-M-2008-05-26-0252
Description : 1. Add ip look up feature.
	      2. modified hostapd for play station 3 in wpa mode
Detail      : 1. config/Config
	      2. /httpd/comoapi.h
	      3. /httpd/combasicapi.c
	      4. /rc/app.c
	      5. /wps_ath/hostapd-0.4.8/wpa.c
	      6. /ip_lookup/arpping.c
	      7. /ip_lookup/arpping.h
	      8. /ip_lookup/ip_lookup.h
              9  /ip_lookup/Makefile

Name        : Jimmy Huang
Tyep        : Apps
Version     : 1.00, build 0251
Tag         : Ath-M-2008-05-26-0251
Description : 1. let udhcpc use default.russia-xxx shell what ever Russia mode enables or not
			  2. modified sample.russia-bound-dns, to prevent "grep" error message
Detail      : 1. apps/udhcp/script.c
			  2. apps/udhcp/samples/sample.russia-bound-dns

Name        : Jimmy Huang
Tyep        : Apps
Version     : 1.00, build 0250
Tag         : Ath-M-2008-05-23-0250
Description : 1. do not ask httpd to reget nvram data, because now we
				 do not save option 33,121,249 to nvram
			  2. fixed the bug when dhcpc crashed after receiving
			  	 option 249
Detail      : 1. apps/udhcp/udhcpc.c
			  2. apps/udhcp/script.c
			
Name        : Nick Chou
Tyep        : Apps
Version     : 1.00, build 0249
Tag         : Ath-M-2008-05-23-0249
Description : 1. fixed ddns update status bug
              2. move start_dhcpd from app.c to lan.c 
                 => hope get ip more fast 
Detail      : 1. \apps\noip2\rc_noip.c
                 \apps\httpd\cmobasicapi.c
                 \apps\timer\timer.c
                 \apps\rc\app.c
              2. \apps\rc\app.c
                 \apps\rc\lan.c

Name        : Jimmy Huang
Tyep        : Apps
Version     : 1.00, build 0248
Tag         : Ath-M-2008-05-20-0248
Description : 1. fixed variable "f_resovr" didn't declare
Detail      : 1. apps/ppp/pppd/ipcp.c

Name        : Jimmy Huang
Tyep        : Apps
Version     : 1.00, build 0247
Tag         : Ath-M-2008-05-20-0247
Description : 1. add the function in non-Russia mode that when PPTP is connected,
		 use PPTP's dns server as primary dns, and dhcp's dns server as 
		 secondary dns server.
Detail      : 1. apps/ppp/pppd/ipcp.c

Name        : Cosmo Chang
Type        : Apps
Version     : 1.00, build 0246
Tag         : Ath-M-2008-05-20-0246
Description : 1. modify the environment "PATH" of wps_ath to 
                 make the process of building code more flexible
Detail      : 1. apps\wps_ath\wsc\src\linux\Makefile
              2. apps\wps_ath\wsc\lib\openssl-0.9.8a\Makefile	
	
Name        : Jimmy Huang
Tyep        : Apps
Version     : 1.00, build 0245
Tag         : Ath-M-2008-05-20-0245
Description : 1. remove the function "save dhcp option 33,121,249 to nvram" in udhcpc
Detail      : 1. apps/udhcp/udhcpc.c

	      
Name        : Ken Chiang
Tyep        : Apps
Version     : 1.00, build 0244
Tag         : Ath-M-2008-05-16-0244
Description : 1. Added wlan0_radio_mode value check to select run 2.4G(bgn)mode or 5G(an)mode.
Detail      : 1. apps/rc/wlan_ath.c	      		
	      
Name        : Jimmy Huang
Tyep        : Apps
Version     : 1.00, build 0243
Tag         : Ath-M-2008-05-16-0243
Description : 1. fixed L2TP routing isseu (add one more default gw)
Detail      : 1. apps/udhcp/samples/sample.bound-dns
	      2. apps/udhcp/samples/sample.bound-nodns

Name        : Chase Cheng
Tyep        : Apps
Version     : 1.00, build 0242
Tag         : Ath-M-2008-05-16-0242
Description : 1. Modify Makefile in dhcpv6.
Detail      : 1.apps/dhcpv6/Makefile apps/dhcpv6/client/Makefile apps/dhcpv6/server/Makefile 
		apps/dhcpv6/common/Makefile apps/dhcpv6/dhcpctl/Makefile apps/dhcpv6/dst/Makefile	 	    apps/dhcpv6/includes/Makefile apps/dhcpv6/omapip/Makefile 
		apps/dhcpv6/minires/Makefile apps/dhcpv6/relay/Makefile

Name        : Albert Chen
Tyep        : Apps
Version     : 1.00, build 0241
Tag         : Ath-M-2008-05-15-0241
Description : 1. fixed mac filter when user select allow or deny, pc should be access to device.
Detail      : 1.apps/rc/firewall.c

Name        : Albert Chen
Tyep        : Apps
Version     : 1.00, build 0240
Tag         : Ath-M-2008-05-15-0240
Description : 1. fixed virtual in pptp and h.323 mode fail issue
Detail      : 1.apps/rc/firewall.c

							
Name        : Jimmy Huang
Tyep        : Apps
Version     : 1.00, build 0239
Tag         : Ath-M-2008-05-14-0239
Description : 1. replace dnsmasq with newer version dnsmasq-2.41
							2. marked pppoe in rp-pppoe, to reduce code size
							3. marked pppoe-discovet in ppp/pppd/plugins/rp-pppoe
Detail      : 1. dnsmasq-2.41
								 apps/Makefile
							2. rp-pppoe/Makefile
							3. ppp/pppd/plugins/rp-pppoe/Makefile
							
Name        : Ken Chiang
Tyep        : Apps
Version     : 1.00, build 0238
Tag         : Ath-M-2008-05-14-0238
Description : 1.modify for insmod art modules(art_ap.ko).
			  2.the wireless Makefile and AP81 or AP83 must to update for build art_ap.ko. 
Detail      : 1. apps\tftp\tftp.c

Name        : Albert Chen
Tyep        : Apps
Version     : 1.00, build 0237
Tag         : Ath-M-2008-05-13-0237
Description : 1. fixed network magic get wan ip error issue
Detail      : 1. apps\httpd\pure.c

Name        : Albert Chen
Tyep        : Apps
Version     : 1.00, build 0236
Tag         : Ath-M-2008-05-13-0236
Description : 1. fixed syslog_server will show undefined issue
Detail      : 1. apps\rc\app.c

Name        : Albert Chen
Tyep        : Apps
Version     : 1.00, build 0235
Tag         : Ath-M-2008-05-08-0235
Description : 1. fixed pppoe through in kernel 2.4.25 
Detail      : 1. apps\rc\wan.c

Name        : Chun Lin
Tyep        : Apps
Version     : 1.00, build 0234
Tag         : Ath-M-2008-05-08-0234
Description : 1. fix pure network addportmapping fail
Detail      : 1. apps\httpd\pure.c

Name        : Albert Chen
Tyep        : Apps
Version     : 1.00, build 0233
Tag         : Ath-M-2008-05-07-0233
Description : 1. Fixed pppoe dial on demand fail when wan monitor could not get wan timer pid.
Detail      : 1. apps\rc\ppp.c

Name        : Chun Lin
Tyep        : Apps
Version     : 1.00, build 0232
Tag         : Ath-M-2008-05-07-0232
Description : 1. put start_wlan() berfore start_app()
Detail      : 1. apps\rc\rc.c

Name        : Albert Chen
Tyep        : Apps
Version     : 1.00, build 0231
Tag         : Ath-M-2008-05-06-0231
Description : 1. In Russia mode, if pptp connect then disconnect, the gateway should be the phyical interface gw
Detail      : 1. apps\pppd\ipcp.c

Name        : Chun Lin
Tyep        : Apps
Version     : 1.00, build 0230
Tag         : Ath-M-2008-05-06-0230
Description : 1. In Russia mode, DNS offered by ppp server will be the first in resolve.conf
			     and static DNS will be the second one.
Detail      : 1. apps\sutil\sutil.c
		 
Name        : Jimmy Huang
Tyep        : Apps
Version     : 1.00, build 0229
Tag         : Ath-M-2008-05-06-0229
Description : 1. enable CONFIG_FEATURE_FANCY_ECHO in busybox for udhcpc
		 shell script used (-n)
Detail      : 1. apps/busybox-1.01/.config
		 apps/busybox-1.01/defconfig-pb42

Name        : Jimmy Huang
Tyep        : Apps
Version     : 1.00, build 0228
Tag         : Ath-M-2008-05-05-0228
Description : 1. fixed the bug that udhcpc get incorrect domain value
	      2. Close useless msg in httpd_util.c
Detail      : 1. apps/udhcp/dhcpc.c
		 apps/udhcp/options.c
	      2. apps/httpd/httpd_util.c

Name        : Albert Chen
Tyep        : Apps
Version     : 1.00, build 0227
Tag         : Ath-M-2008-05-05-0227
Description : 1. modify pptp hook script for accel pptp
Detail      : 1.apps/rc/wan.c

	      			
Name        : Jimmy Huang
Tyep        : Apps
Version     : 1.00, build 0226
Tag         : Ath-M-2008-05-02-0226
Description : 1. add accel-pptp-0.7.12 to replace original pptp package 
	         to improve pptp performance
Detail      : 1.apps/accel-pptp-0.7.12
	      2.apps/Makefile

[Release Note]
Name        : Chun Lin
Tyep        : Apps
Version     : 1.00, build 0225
Tag         : Ath-M-2008-04-30-0225
Description : 1. Linux 2.4 still use pppoe plugin with pty, or it will crash
Detail      : 1.apps\rc\wan.c

	      
Name        : Jimmy Huang
Tyep        : Apps
Version     : 1.00, build 0224
Tag         : Ath-M-2008-04-30-0224
Description : 1. add nvram_commit(), _system("killall -SIGUSR2 httpd") to sync with httpd
	      2. add function definition void nvram_flag_reset(void) ;in nvram.h
Detail      : 1.apps/udhcp/udhcpc.c
	      2.apps/nvram/nvram.c
	      3.apps/nvram/nvram.h

Name        : Chun Lin
Tyep        : Apps
Version     : 1.00, build 0223
Tag         : Ath-M-2008-04-30-0223
Description : 1. Fix pppoe plugin with pty will result in low throughput.
Detail      : 1.apps\rc\wan.c


Name        : Jimmy Huang
Tyep        : Apps
Version     : 1.00, build 0222
Tag         : Ath-M-2008-04-29-0222
Description : 1. nvram_flag_reset() to sync with httpd
Detail      : 1.apps/udhcp/udhcpc.c

Name        : Jimmy Huang
Tyep        : Apps
Version     : 1.00, build 0221
Tag         : Ath-M-2008-04-28-0221
Description : 1. add support for dhcpc option 33, 249 
	      2. with option 33 or 121 or 249, it will check if need to save records to nvram
	      3. Modify some return value within dhcp_discover() to let compiler happy
	      4. add one more empty line to apps/nvram.h to let compiler happy
	      5. add menu in app's menuconfig for option 33,121,249
Detail      : 1.apps/udhcp/udhcpc.c
		apps/udhcp/dhcpd.h
		apps/udhcp/options.c
		apps/udhcp/Makefile
	      4.apps/nvram/nvram.h
	      5.apps/config/Config
		apps/Makefile
		/www/DIR-615_C1/config/DIR-615_C1.apps_eagle.config

Name        : Chun Lin 
Tyep        : Apps
Version     : 1.00, build 0220
Tag         : Ath-M-2008-04-24-0220
Description : 1. In Russia mode, igmpproxy always use physical interface as upstream.
			  2. In Russia mode, DNS offered by ppp server will be the first in resolve.conf
			     and DNS offered by dhcp server will be the second one.
Detail      : 1.apps\igmpproxy\config.c
			    apps\igmpproxy\defs.h
			    apps\igmpproxy\rttable.c
			    apps\rc\app.c
			  2.apps\rc\wan.c
			    apps\ppp\pppd\ipcp.c
			    apps\httpd\httpd_util.c
                
                
Name        : Albert Chen 
Tyep        : Apps
Version     : 1.00, build 0219
Tag         : Ath-M-2008-04-22-0219
Description : 1.Fixed when wan set Russia PPTP, if virtual iface PPP have not get ip, the dhcp client don't set gateway
		ip to default ip. 
Detail      : 1.\apps\udhcp\samples\sample.russia-bound-dns
                \apps\udhcp\samples\sample.russia-bound-nodns
                
Name        : Tina Tsao 
Tyep        : Apps
Version     : 1.00, build 0218
Tag         : Ath-M-2008-04-17-0218
Description : 1.When wan set Russia PPTP, wan port will send out UPnP packet. 
Detail      : 1.\apps\wps_ath\wsc\src\common\UPnPCpLib\ILibSSDPClient.c
                \apps\wps_ath\wsc\src\common\UPnPDevLib\UPnPMicroStack.c


Name        : Albert 
Tyep        : Apps
Version     : 1.00, build 0217
Tag         : Ath-M-2008-04-17-0217
Description : 1.Modify when pptp server ip different phyical ip, need add route rule using system code. 
Detail      : 1.\apps\rc\wan.c

Name        : Jimmy Huang
Tyep        : Apps
Version     : 1.00, build 0216
Tag         : Ath-M-2008-04-16-0216
Description : 1.Modify option length 208 to 308, in case dhcpd 
	      offer 590 bytes response
Detail      : 1.\apps\udhcp\packet.h

Name        : Chase Cheng
Tyep        : Apps
Version     : 1.00, build 0215
Tag         : Ath-M-2008-04-16-0215
Description : 1.Modify ipv6_6to4_lan_prefix_diagnose
Detail      : 1.apps\rc\app.c

Name        : Chase Cheng
Tyep        : Apps
Version     : 1.00, build 0214
Tag         : Ath-M-2008-04-16-0214
Description : 1.Modify 6to4/v6pppoe not assign IP to br0 while WAN IP is NULL.
Detail      : 1.apps\rc\app.c

Name        : Chun Lin
Tyep        : Apps
Version     : 1.00, build 0213
Tag         : Ath-M-2008-04-15-0213
Description : 1.Modify syn with ntp server by 2 packets.     
Detail      : 1.apps\timer\timer.c
				
Name        : Chun Lin
Tyep        : Apps
Version     : 1.00, build 0212
Tag         : Ath-M-2008-04-15-0212
Description : 1.Fix UI doesn't redirect to please_wait page because wan IP is obtained later.        
Detail      : 1.apps\httpd\cmoapi.h
				apps\httpd\cmobasicapi.c
				apps\httpd\httpd_util.c

Name        : Jimmy Huang
Tyep        : Apps
Version     : 1.00, build 0211
Tag         : Ath-M-2008-04-15-0211
Description : 1. Modify some codes in dhcpc option 121 with definition UDHCPC_CLASSLESS_STATIC_ROUTE
	         (The location of removing shell static_route_del.sh,static_route_add.sh)
Detail      : 1.\apps\udhcp\dhcpc.c

Name        : Chun Lin
Tyep        : Apps
Version     : 1.00, build 0209
Tag         : Ath-M-2008-04-14-0210
Description : 1. After syn with ntp server by 3 packets, daylight saving is performed.
	      	  2. When dhcpc get the same IP, we copy the old bandwidth file instead of calculating a new one.

Detail      : 1.apps\ntpclient\ntpclient.c
				apps\timer\timer.c
			  2.apps\udhcp\dhcpc.c
			    apps\rc\wan.c
				apps\rc\wantimer.c
	      
Name        : Jimmy Huang
Tyep        : Apps
Version     : 1.00, build 0209
Tag         : Ath-M-2008-04-11-0209
Description : 1.add support for dhcpc option 121 with definition UDHCPC_CLASSLESS_STATIC_ROUTE
	      2. add menu in app's menuconfig for UDHCPC_CLASSLESS_STATIC_ROUTE
	      3. fixed apps\sutil\sutil.c, line 216, missing ,
Detail      : 1.\apps\udhcp\dhcpc.c
		\apps\udhcp\dhcpd.h
		\apps\udhcp\option.c
	      2.\apps\config\Config
		\apps\Makefile
	      3.\apps\sutil\sutil.c

Name        : Albert Chen
Tyep        : Apps
Version     : 1.00, build 0208
Tag         : Ath-M-2008-04-10-0208
Description : 1.fix: add pppoe options
		"nopcomp"  Disable protocol filed compression
		"noaccomp" Disable address/control compression
		"-am" 	   Disable asyncmap negotiation
Detail      : 1.\apps\sutil\sutil.c
			  
Name        : Ken Ching
Tyep        : Apps
Version     : 1.00, build 0207
Tag         : Ath-M-2008-04-09-0207
Description : 1.fix: sometime do nvram setting will clear ImgCheckSum nvram value.
Detail      : 1.\apps\httpd\core.c				
			  2.\apps\sutil\sutil.c

Name        : Nick Chou
Tyep        : Apps
Version     : 1.00, build 0206
Tag         : Ath-M-2008-04-09-0206
Description : 1.fix: email log pending too long (using button on GUI)
				=> using mailosd to send (SIGUSR1)
			  2.fix: pptp server name resolve in RUSSIA
			  3.add mru in PPPOE/PPTP/L2TP option file
Detail      : 1.\apps\httpd\core.c
				\apps\rc\app.c
                \apps\mail-on-schedule\main.c
			  2.\apps\rc\wan.c
			  3.\apps\sutil\sutil.c

Name        : Chun Lin
Tyep        : Apps
Version     : 1.00, build 0205
Tag         : Ath-M-2008-04-07-0205
Description : 1.fix: NetBIOS learn from WAN fail
				=> Only when both dhcpd_netbios_enable and dhcpd_netbios_learn are enabled, dhcpc deamon starts with "-N"
			  2.put start_app() berfore start_wlan(), so client can get dhcp IP soon.
			  3.fix access_control doesn't work
Detail      : 1.apps\rc\app.c
				apps\rc\wan.c
			  2.apps\rc\rc.c
			  3.apps\rc\firewall.c

Name        : Nick Chou
Tyep        : Apps
Version     : 1.00, build 0204
Tag         : Ath-M-2008-04-02-0204
Description : Fixed that MTU < 600, DHCPC can't send out packet
              => dhcpMessage options[308] to dhcpMessage options[208]
Detail      : 1.\apps\udhcp\packet.h

Name        : Jimmy Huang
Tyep        : Apps
Version     : 1.00, build 0203
Tag         : Ath-M-2008-04-02-0203
Description : Fixed the cdrouter mcast 51
Detail      : 1.apps/igmpproxy/defs.h
              Modified INTERVAL_QUERY_RESPONSE from 10 to 5

Name        : Jackey Chen
Tyep        : Apps
Version     : 1.00, build 0202
Tag         : Ath-M-2008-04-02-0202
Description : Fixed the issue of nvram to support different model
Detail      : 1.Modify apps/Makefile

Name        : Tina Tsao
Tyep        : Apps
Version     : 1.00, build 0201
Tag	        : Ath-M-2008-04-01-0201
Description : Fixed: WAN- Russia-PPPoE : can't get pppoe DNS when setting fix DNS on "WAN PHYSICAL SETTING". 
Detail      : 1.rc/wan.c
              2.sutil/sutil.c


Name        : Jimmy Huang
Tyep        : Apps
Version     : 1.00, build 0200
Tag	        : Ath-M-2008-04-01-0200
Description : Add version.txt to support Dlink Hidden Page V1.01 
Detail      : 1.httpd/core.c
              2.httpd/httpd.c

Name        : Jackey Chen
Tyep        : Apps
Version     : 1.00, build 0199
Tag	    : Ath-M-2008-04-01-0199
Description : Modify Makefile to fix the issue for nvram.default and not cp $WWW/version.c_ipv6 
Detail      : 1.Modify apps/Makefile

Name 	    : Chun Lin
Tyep        : Apps
Version     : 1.00, build 0198
Tag	        : Ath-M-2008-04-01-0198
Description : 1. ajax support wan_connection_status
Detail      : 1. apps\httpd\ajax.c

Name 	    : Nick Chou
Tyep        : Apps
Version     : 1.00, build 0197
Tag	        : Ath-M-2008-03-31-0197
Description : 1. Ath. 11N wireless driver can support RTS and Frag. setting
                 (wierless version : ap81-7.1.3.38b0035)
Detail      : 1. \apps\rc\wlan_ath.c

Name 	    : Albert Chen
Tyep        : Apps
Version     : 1.00, build 0196
Tag	        : Ath-M-2008-03-28-0196
Description : 1. add "shutdown" type in reboot_type
Detail      : 1. apps\httpd\core.c
 
Name        : Chun Lin
Type        : Apps
Version     : 1.0.0, build 0195
Tag         : Ath-M-2008-03-27-0195
Description : 1. add AJAX optionin menuconfig
Detail      : 1. apps\httpd\ajax.c
                 apps\config\Config

                 
Name        : Nick Chou
Type        : Apps
Version     : 1.0.0, build 0194
Tag         : Ath-M-2008-03-27-0194
Description : 1. using gmtime() to get system time (not usig date > )
              2. when dhcpc release/renew from GUI, we don't remove_bandwidth_file()
                 (when dhcpc get new ip would remove it in dhcpc.c)
              3. modify _system(route add) to route_add()
              4. WAN = PPTP => using fopen (w) to add dns in resolv.conf
                     = RUSSIA PPTP => using fopen (a) to add dns in resolv.conf
Detail      : 1. modify \apps\httpd\cmobasicapi.c
              2. \apps\httpd\core.c
                 \apps\udhcp\Makefile
                 \apps\udhcp\dhcpc.c
                 \apps\rc\wantimer.c
              3. apps\rc\wan.c
                 \apps\rc\app.c
              4. \apps\ppp\pppd\Makefile
                 \apps\ppp\pppd\ipcp.c

Name        : Chun Lin
Type        : Apps
Version     : 1.0.0, build 0193
Tag         : Ath-M-2008-03-27-0194
Description : 1.add ajax files
Detail      : 1. modify
				apps\httpd\core.c
			    apps\httpd\httpd.c
			    apps\httpd\httpd_util.c
			    apps\httpd\Makefile
			    apps\Makefile
			  2. add  
			  	apps\httpd\ajax.c
			  	apps\httpd\ajax.h
			  	
Name        : Chase Cheng
Type        : Apps
Version     : 1.0.0, build 0193
Tag         : Ath-M-2008-03-27-0193
Description : 1.Fix memory issue in flash_get_checksum()
Detail      : 1.\apps\sutil\sutil.c

Name        : Nick Chou
Type        : Apps
Version     : 1.0.0, build 0192
Tag         : Ath-M-2008-03-24-0192
Description : 1.GUI using ioctl to get wlan channel(no parse file)
              2.modify apps/httpd include file (cmoapi.h include httpd, httpd_util.h include cmoapi.h)
Detail      : 1.\apps\httpd\cmobasicapi.c
                \apps\httpd\httpd_util.c
                \apps\httpd\httpd_util.h
              2.\apps\httpd\core.c
                \apps\httpd\httpd.c
                \apps\httpd\pure.c
                \apps\httpd\pure.h
                \apps\httpd\widget.c

Name        : Tina Tsao
Type        : Apps
Version     : 1.0.0, build 0191
Tag         : Ath-M-2008-03-21-0191
Description : 1.Modify some pointer array to array.
Detail      : 1.apps\http\widget.c


Name        : Nick Chou
Type        : Apps
Version     : 1.0.0, build 0190
Tag         : Ath-M-2008-03-21-0190
Description : 1.Modify "rm -f" to unlink() in rc
	          2.Fixed dhcpd client list bug (rm udhcpd.leases at stop_dhcpd) 
Detail      :1.\apps\rc\wantimer.c
               \apps\rc\qos.c
		     2.\apps\rc\rc.c

NName        : Albert Chen
Type        : Apps
Version     : 1.0.0, build 0189
Tag         : Ath-M-2008-03-19-0189
Description : 1.Modify mail_client Makefile for take off build info to device.
	      2.Modify check list form 
Detail      :1.apps\mail_client\Makefile
		2.apps\httpd\core.c

Name        : Joe Lin
Type        : Apps
Version     : 1.0.0, build 0188
Tag         : Ath-M-2008-03-19-0188
Description : 1.Fixed that chklist can't show checksum 
Detail      :1.apps\.config
                

Name        : Chun Lin
Type        : Apps
Version     : 1.0.0, build 0187
Tag         : Ath-M-2008-03-19-0187
Description : 1.Fix bug in AP mode 
				a)with static IP, status page always shows gateway IP as "0.0.0.0".
			  	b)with dynamic IP and specify DNS, status page always shows DNS offered by DHCP server.
			  	c)with dynamic IP, status page always shows DHCP client disconnected even router has obtained IP.
			  	d)with dynamic IP and DHCP server in LAN, status page always shows empty information.
			  
Detail      : 1.\apps\httpd\httpd_util.c
                \apps\rc\wan.c
                
Name        : Joe Lin
Type        : Apps
Version     : 1.0.0, build 0186
Tag         : Ath-M-2008-03-19-0186
Description : 1.Fixed that GUI get dns bug 
Detail      :1.\apps\httpd\httpd_util.c
                \apps\rc\wan.c


Name        : Nick Chou
Type        : Apps
Version     : 1.0.0, build 0185
Tag         : Ath-M-2008-03-19-0185
Description : 1.Modify PPPoE/PPTP/L2TP dial and disconnect process => more fsst
	          2.Fixed that when unauth, user can download config.bin or logfile
	          3.Fixed that GUI get dns bug
              4.Modify when RUSSIA PPPoE/PPTP, (dhcp lease time = 1 Min)
                1. only dhcp-domain change, we need to re-init resolv.conf
                2. if dhcp-offer-dns exist in resolv.conf, we don't add it  
Detail      : 1.\apps\httpd\core.c
	          2.\apps\httpd\httpd.c
                \apps\httpd\httpd.h
	          3.\apps\httpd\httpd_util.c
                \apps\rc\wan.c
              4.\apps\udhcp\samples\sample.russia-bound-dns

Name        : Albert Chen
Type        : Apps
Version     : 1.0.0, build 0184
Tag         : Ath-M-2008-03-19-0184
Description : 1.Modify make error in widget
	      2.Modify makefile for take off ppp plugin
	      3.modify busybox config.
Detail      : 1.apps\ttp\widget.c
	      2.ppp\pppd\plugins\Makefile
	      3.apps\busybox-1.00-pre10\defconfig-AR531X
	      
Name        : Albert Chen
Type        : Apps
Version     : 1.0.0, build 0183
Tag         : Ath-M-2008-03-18-0183
Description : 1.Take off un-use debug messages.
	      2.Modify check sum.
Detail      : 1.apps\http\widget.c
	      2.apps\sutil\sutil.c

Name        : Joe Lin
Type        : Apps
Version     : 1.0.0, build 0182
Tag         : Ath-M-2008-03-18-0182
Description : 1.Fix bug and schedule xml.
Detail      : 1.apps\http\widget.c

Name        : Albert Chen
Type        : Apps
Version     : 1.0.0, build 0181
Tag         : Ath-M-2008-03-18-0181
Description : 1.Fix bug wireless xml and schedule xml.
Detail      : 1.apps\http\widget.c


Name        : Chun Lin
Type        : Apps
Version     : 1.0.0, build 0180
Tag         : Ath-M-2008-03-18-0180
Description : 1.Fix bug switching to ap mode will crash.
				a) There is no need to restart httpd when ip is changed
				b) udhcpc doesn't "ifconfig br0 0.0.0.0" in ap mode
	          2.add rc reboot_type=wlanapp for enable/disable wps need to restart upnp
Detail      : 1.apps\udhcp\dhcpc.h
				apps\udhcp\dhcpc.c
				apps\rc\wan.c
				apps\rc\lan.c
				apps\rc\app.c
				
			  2.apps\httpd\core.c
			    apps\rc\rc.c
			
Name        : Albert Chen
Type        : Apps
Version     : 1.0.0, build 0179
Tag         : Ath-M-2008-03-18-0179
Description : 1.update XML for widget when wlan disable cause http crash
	      2.Modify noip2 for widget
Detail      : 1.Modify apps\httpd\widget.c
			2.Modify apps\httpd\http_util.c
			
Name        : Albert Chen
Type        : Apps
Version     : 1.0.0, build 0178
Tag         : Ath-M-2008-03-18-0178
Description : 1.Modify XML for widget
	      2.Modify noip2 for widget
Detail      : 1.Modify apps\httpd\widget.c
			2.Modify apps\noip2\noip.c

Name        : Nick Chou
Type        : Apps
Version     : 1.0.0, build 0177
Tag         : Ath-M-2008-03-14-0177
Description : 1.Modify make menuconfig
Detail      : 1.Modify apps\config\Config

Name        : Albert Chen
Type        : Apps
Version     : 1.0.0, build 0176
Tag         : Ath-M-2008-03-14-0176
Description : 1.Modify xml agent for widget faster
Detail      : 1.Modify \apps\httpd\widget.c
                       \apps\httpd\widget.h

                       
Name        : Nick Chou
Type        : Apps
Version     : 1.0.0, build 0175
Tag         : Ath-M-2008-03-14-0175
Description : 1.Check dial on demand mode
              2.modify mailosd when user don't set any smtp info 
Detail      : 1.Modify \apps\rc\wantimer.c
                       \apps\rc\wan.c
                       \apps\rc\ppp.c
              2.Modify \apps\rc\app.c
                       \apps\httpd\httpd_util.c

Name        : Albert Chen
Type        : Apps
Version     : 1.0.0, build 0174
Tag         : Ath-M-2008-03-14-0174
Description : 1.Modify xml for widget 
Detail      : 1.Modify \apps\httpd\widget.c


					   
Name        : Albert Chen
Type        : Apps
Version     : 1.0.0, build 0173
Tag         : Ath-M-2008-03-14-0173
Description : 1.Modify xml for widget 
              2.add CONFIG_HTTP_TIMEOUT for support httpd timeout will jump to login page feature.

Detail      : 1.Modify \apps\httpd\widget.c
		       			   \apps\httpd\widget.h
		       			   \apps\httpd\http.c
					   \apps\config\Config
					   \apps\Makefile
					   \apps\rc\app.c
					   
Name        : Chun Lin
Type        : Apps
Version     : 1.0.0, build 0172
Tag         : Ath-M-2008-03-13-0172
Description : 1.Modify igmpproxy to support Russia with physical and virtual interface
              2.Replace "rm -rf" with "unlink"

Detail      : 1.Modify \apps\igmpproxy\config.c
					   \apps\igmpproxy\defs.h
					   \apps\igmpproxy\igmpproxy.c
					   \apps\igmpproxy\Makefile
					   \apps\igmpproxy\rttable.c
					   \apps\rc\app.c
              2.Modify \apps\httpd\cmobasicapi.c
					   \apps\httpd\core.c
					   \apps\httpd\httpd_util.c
  

Name        : Nick Chou
Type        : Apps
Version     : 1.0.0, build 0171
Tag         : Ath-M-2008-03-12-0171
Description : 1.Modify wantimer for improving performace
              2.Add #ifdef CONFIG_ZEBRA for route function
              3.Modify get_dns() for GUI
              4.Modify AppServices[] order and we don't need to stop_app in start_app.
              5.Modify redial deamon (wan in always on mode using redial deamon to dialup)
              6.Modify firewall setting process.
              (if wan ip no change and firewall rule no change, firewall don't need restart)
              7.when upgrade firmware, we need keep wlan0_domain value
Detail      : 1.Modify \apps\rc\wantimer.c
              2.Modify \apps\rc\route.c
              3.Modify \apps\rc\network.c
                       \apps\rc\wan.c
              4.Modify \apps\rc\app.c
              5.Modify \apps\rc\ppp.c
                       \apps\rc\wan.c
              6.Modify \apps\rc\firewall.c
              7.Modify \apps\nvram\nvram.c
                        
Name        : Joe Lin
Type        : Apps
Version     : 1.0.0, build 0170
Tag         : Ath-M-2008-03-12-0170
Description : Modify XML with V1.6 spec.
Detail      : 1.Modify \apps\httpd\widget.c

Name        : Tina Tsao
Type        : Apps
Version     : 1.0.0, build 0169
Tag         : Ath-M-2008-03-12-0169
Description : 1.Fixed PPPoE connect on demand can't work.
Detail      : 1. \apps\rc\ppp.c

Name        : Chase Cheng
Type        : Apps
Version     : 1.0.0, build 0168
Tag         : Ath-M-2008-03-12-0168
Description : 1.Modify ip prefix of stateful range while WAN IPv4 address changed in 6to4/v6pppoe mode
Detail      : 1. \apps\rc\app.c

Name        : Albert Chen
Type        : Apps
Version     : 1.0.0, build 0167
Tag         : Ath-M-2008-03-11-0167
Description : 1.Modify calcute checksum code
Detail      : 1. \apps\sutil\sutil.c

Name        : Chase Cheng
Type        : Apps
Version     : 1.0.0, build 0166
Tag         : Ath-M-2008-03-10-0166
Description : 1.Fix ipv6_6to4_lan_prefix_diagnose
Detail      : 1. \apps\rc\app.c

Name        : Chase Cheng
Type        : Apps
Version     : 1.0.0, build 0165
Tag         : Ath-M-2008-03-10-0165
Description : 1.Modify return_6to4_lan_address return value while WAN not ready.              
Detail      : 1. \apps\httpd\cmobasic.c

Name        : Albert Chen
Type        : Apps
Version     : 1.0.0, build 0164
Tag         : Ath-M-2008-03-07-0164
Description : 1.Modify checksum function just calcute Kernel size.
	      2.Modify rc_action in filter mode for rc can update nvram.
Detail	    : 1. \apps\httpd\core.c
	      2. \apps\sutil\sutil.c

Name        : Chase Cheng
Type        : Apps
Version     : 1.0.0, build 0163
Tag         : Ath-M-2008-03-07-0163
Description : Take off unused define for 6to4 test
Detail	    : 1. Modify \apps\rc\app.c

Name        : Chase Cheng
Type        : Apps
Version     : 1.0.0, build 0162
Tag         : Ath-M-2008-03-07-0162
Description : 1. Add diagnose mechanism for 6to4 IP changed by IPv4
	      2. Fix Delete old IPv6 IP function by httpd
	      3. Take off unused variables in tunnel
Detail      : 1. Modify \apps\rc\app.c \apps\rc\lan.c
	      2. Modify \apps\httpd\core.c
	      3. Modify \apps\rc\tunnel.c

Name        : Joe Lin
Type        : Apps
Version     : 1.0.0, build 0161
Tag         : Ath-M-2008-03-06-0161
Description : Modify XML with V1.6 spec.
Detail      : 1.Modify \apps\httpd\widget.c

Name        : Nick Chou
Type        : Apps
Version     : 1.0.0, build 0160
Tag         : Ath-M-2008-03-06-0160
Description : 1. fixed remote mangerment add inboung filter deny rule fail 
Detail      : 1. \apps\rc\firewall.c

Name        : Nick Chou
Type        : Apps
Version     : 1.0.0, build 0159
Tag         : Ath-M-2008-03-06-0159
Description : 1. accelerate nvram_get and nvram_set
Detail      : 1. \apps\nvram\nvram.c

Name        : Tina Tsao
Type        : Apps
Version     : 1.0.0, build 0158
Tag         : Ath-M-2008-03-06-0158
Description : 1.Fixed DUT login name still display default "admin" in WEB UI. Whatever user changed login name to other. 
Detail      : 1. apps\httpd\cmobasicapi.c


Name        : Albert Chen
Type        : Apps
Version     : 1.0.0, build 0157
Tag         : Ath-M-2008-03-05-0157
Description : 1.modify check list for non dlink model 
	      2. take off debug message for checksum.
Detail      : 1. apps\httpd\core.c
	      2. apps\sutil\sutil.c
              
Name        : Chun Lin
Type        : Apps
Version     : 1.0.0, build 0156
Tag         : Ath-M-2008-03-05-0156
Description : 1.Fix active session deosn't show any session in russia mode
              2.Fix only one allowed sta can get IP from router when mac filter is ALLOW 
              3.Remove miniupnp debug msg
Detail      : 1.Modify httpd\httpd_util.c
              2.Modify rc\firewall.c
              3.Modify miniupnpd-1.0-RC7\linux\getifstats.c
              
Name        : Nick Chou
Type        : Apps
Version     : 1.0.0, build 0155
Tag         : Ath-M-2008-03-05-0155
Description : 1.Modify RUSSIA PPTP in ipcp record for different platform
              2.Modify firewall for prevent LAN IP passthrough to WAN
              3.whatever in RUSSIA PPTP or pure PPTP, only pptp server and WAN Eth not in same subnet
                => add host gateway
              4.when using RUSSIA PPTP => udhcpc run RUSSIA_DHCPC_NODNS_SCRIPT 
              5.when wan proto = dhcp => if wan ip don't change, rc don't need to restart
              6.if device is not dlink model => chklst delete some item  
Detail      : 1.Modify \apps\ppp\pppd\ipcp.c
                       \apps\ppp\pppd\Makefile
              2.Modify \apps\rc\firewall.c
              3.Modify \apps\rc\wan.c    
              4.Modify \apps\udhcp\script.c
                       \apps\udhcp\dhcpc.h 
                       \apps\udhcp\Makefile
                Add    \apps\udhcp\samples\sample.russia-bound-nodns
                       \apps\udhcp\samples\sample.russia-bound-dns
              5.Modify \apps\udhcp\dhcpc.c        
              6.Modify \apps\httpd\core.c

Name        : Tina Tsao
Type        : Apps
Version     : 1.0.0, build 0154
Tag         : Ath-M-2008-03-04-0154
Description : Modify XML with V1.6 spec.
Detail      : 1.Modify \apps\httpd\widget.c

Name        : Albert Chen
Type        : Apps
Version     : 1.0.0, build 0153
Tag         : Ath-M-2008-03-03-0153
Description : 1.modify nvram_init to avoid nvram crash.	  
Detail      : 1.Modify \apps\nvram\nvram.c


Name        : Ken Chiang
Type        : Apps
Version     : 1.0.0, build 0152
Tag         : Ath-M-2008-03-03-0152
Description : 1.modify flash_get_checksum to rc init for if rc restart run flash_get_checksum again.
			  2.modify get checksum from nvram.			  
Detail      : 1.Modify \apps\httpd\http.c
	          2.Modify \apps\httpd\core.c
	          3.apps\httpd\core.c
			  4.apps\sutil\sutil.c,sutil.h
	          
Name        : Ken Chiang
Type        : Apps
Version     : 1.0.0, build 0151
Tag         : Ath-M-2008-02-29-0151
Description : 1.fixed pure set dns can't show in status page.
			  2.fixed pure set dns is null web UI show fail.
			  3.fixed secondary dns show loss some addrs in status page.
Detail      : 1.Modify \apps\httpd\pure.c
	          2.Modify \apps\httpd\httpd_util.c

Name        : Albert Chen
Type        : Apps
Version     : 1.0.0, build 0150
Tag         : Ath-M-2008-02-29-0150
Description : Add checksum feature in config and apps Makefile
Detail      : 1.Modify \apps\Makefile
	      2.Modify \apps\config\Config

Name        : Rock Chen
Type        : Apps
Version     : 1.0.0, build 0149
Tag         : Ath-M-2008-02-29-0149
Description : Merage IPv6 Page to DIR-615_C1 (change the ipv6 version to version.c)
Detail      : 1.Modify \apps\Makefile

Name        : Tina Tsao
Type        : Apps
Version     : 1.0.0, build 0148
Tag         : Ath-M-2008-02-29-0148
Description : Modify XML with V1.6 spec.
Detail      : 1.Modify \apps\httpd\widget.c

Name        : Rock Chen
Type        : Apps
Version     : 1.0.0, build 0147
Tag         : Ath-M-2008-02-29-0147
Description : Merage IPv6 Page to DIR-615_C1
Detail      : 1.Modify \apps\Makefile
							2.Modify \apps\httpd\ej.c
	
Name        : Chase Cheng
Type        : Apps
Version     : 1.0.0, build 0146
Tag         : Ath-M-2008-02-27-0146
Description : 1.Add description of Ath-M-2008-02-27-0145's bug
Detail      : 1.Modify \apps\rc\app.c

Name        : Chase Cheng
Type        : Apps
Version     : 1.0.0, build 0145
Tag         : Ath-M-2008-02-27-0145
Description : 1.Modify loading sequence of radvd for brdige up too late
Detail      : 1.Modify \apps\rc\app.c

Name        : Albert Chen
Type        : Apps
Version     : 1.0.0, build 0144
Tag         : Ath-M-2008-02-27-0144
Description : 1.Modify Makefile for optimize 
Detail      : 1.Modify \apps\pptp\Makefile

Name        : Chase Cheng
Type        : Apps
Version     : 1.0.0, build 0143
Tag         : Ath-M-2008-02-27-0143
Description : 1.Fill Makefile changed for the reason with tag Ath-M-2008-02-26-0140
Detail      : 1.Modify \apps\dhcpv6\Makefile

Name        : Chase Cheng
Type        : Apps
Version     : 1.0.0, build 0142
Tag         : Ath-M-2008-02-27-0142
Description : 1.Modify Define for IP in IPROUTE2
Detail      : 1.Modify apps/Makefile apps/config/Config apps/iproute2/Makefile

Name        : Chase Cheng
Type        : Apps
Version     : 1.0.0, build 0141
Tag         : Ath-M-2008-02-26-0141
Description : 1.Add Define for IP in IPROUTE2 
Detail      : 1.Modify apps/Makefile apps/config/Config apps/iproute2/Makefile

Name        : Chase Cheng
Type        : Apps
Version     : 1.0.0, build 0140
Tag         : Ath-M-2008-02-26-0140
Description : 1.Reduce file size
Detail      : 1.Modify \apps\dhcpv6\
                                     client/Makefile
                                     common/Makefile
                                     dhcpctl/Makefile
                                     dst/Makefile
                                     minires/Makefile
                                     omapip/Makefile
                                     server/Makefile
              2.Modify \apps\dhcpv6\client\script\linux

Name        : Joe Lin
Type        : Apps
Version     : 1.0.0, build 0139
Tag         : Ath-M-2008-02-26-0139
Description : 1.check list add kernel build number and build date
Detail      : 1.\apps\httpd\core.c
              2.\apps\httpd\cmoapi.c

Name        : Nick Chou
Type        : Apps
Version     : 1.0.0, build 0138
Tag         : Ath-M-2008-02-25-0138
Description : 1.modify udhcpc param when using unicast
Detail      : 1.\apps\rc\wan.c

Name        : Albert Chen
Type        : Apps
Version     : 1.0.0, build 0137
Tag         : Ath-M-2008-02-25-0137
Description : 1.modify wantimer monitor time from 2 sec to 1 sec.
Detail      : 1.apps\rc\wantimer.c
	      2.apps\rc\qos.c
			  
Name        : Ken Chiang
Type        : Apps
Version     : 1.0.0, build 0136
Tag         : Ath-M-2008-02-22-0136
Description : 1.added checksum info in checklist file.
Detail      : 1.apps\httpd\httpd.c
			  2.apps\httpd\core.c
			  3.apps\sutil\sutil.c,sutil.h

Name        : Nick Chou
Type        : Apps
Version     : 1.0.0, build 0135
Tag         : Ath-M-2008-02-22-0135
Description : 1.modify busybox-1.01\defconfig-pb42 ( CUT )
              2.Merge DDNS function with Eagle
              
Detail      : 1. Modify \apps\busybox-1.01\defconfig-pb42
	          2. Modify \apps\rc\app.c
                        \apps\timer\timer.c

Name        : Albert
Type        : Apps
Version     : 1.0.0, build 0134
Tag         : Ath-M-2008-02-21-0134
Description : 1.fixed if non define dhcp netbios features will cause dhcp client daemon start fail
              2.Add static route xml for widget
              3.sometime fw query funtion will terminate by unknown process, add a signal for stop the terminate behavior.
              4.modify makefile call support minupunpd
              
Detail      : 1. Modify apps\rc\wan.c
	      2. Modify apps\httpd\widget.c
	      3. Modify apps\fwqd\main.c
	      4. Modify apps\Makefile
	      5. Modify apps\rc\app.c
	      

Name        : Nick Chou
Type        : Apps
Version     : 1.0.0, build 0133
Tag         : Ath-M-2008-02-21-0133
Description : fixed OWERA upgrade firmware error.
Detail      : 1. Modify apps\owera\src\app\src\client_loader.c

Name        : Chase Cheng
Type        : Apps
Version     : 1.0.0, build 0132
Tag         : Ath-M-2008-02-21-0132
Description : Make tunnel.o be generated while support CONFIG_IPV6_TUNNEL only.
Detail      : 1. Modify \apps\rc\Makefile

Name        : Nick Chou
Type        : Apps
Version     : 1.0.0, build 0131
Tag         : Ath-M-2008-02-20-0131
Description : 1. Add apps_version.c
Detail      : 2. Modify \apps\doc\apps_version.c

Name        : Nick Chou
Type        : Apps
Version     : 1.0.0, build 0130
Tag         : Ath-M-2008-02-20-0130
Description : 1. Merge AthSDK_4_16 (AP61-2008-02-18-0466) with Eagle apps (Ath-M-2008-02-19-0129)
              2. modify make menuconfig and default value
Detail      : 2. Modify \apps\config\Config

Name        : Chase Cheng
Type        : Apps
Version     : 1.0.0, build 0129
Tag         : Ath-M-2008-02-20-0129
Description : Use array to replace *ipv6_clone for avoiding memory issue.
	      Fix overflow issue in start_dhcpd6 function while long IPv6 address be assigned.
Detail      : 1. Modify apps/sutil/sutil.c
	      2. Modify apps/rc/app.c

Name        : Nick Chou
Type        : Apps
Version     : 1.0.0, build 0128
Tag         : Ath-M-2008-02-19-0128
Description : Merge AthSDK_4_16 (AP61-2008-02-18-0466) with Eagle apps (Ath-M-2008-02-19-0127)
Detail	    : 

Name        : Jackey Chen
Type        : Apps
Version     : 1.0.0, build 0127
Tag         : Ath-M-2008-02-19-0127
Description : RC support different wireless solution
Detail	    : 1.Modify apps/Makefile

Name        : Chase Cheng
Type        : Apps
Version     : 1.0.0, build 0126
Tag         : Ath-M-2008-02-18-0126
Description : 1.Fill stateless autoconfiguration mechanism while ipv6_wan_proto be set to linklocal
	      2.Fix client used both stateless and stateful auto configuration concurrently while set auto_configuration to stateful
Detail      : 1.Modify apps/rc/app.c

Name        : Chase Cheng
Type        : Apps
Version     : 1.0.0, build 0125
Tag         : Ath-M-2008-02-13-0125
Description : 1.Enhance get_ipv6_prefix usability
Detail      : 1.Modify apps/sutil/sutil.c

Name        : Chase Cheng
Type        : Apps
Version     : 1.0.0, build 0124
Tag         : Ath-M-2008-02-13-0124
Description : 1.Add IPv6_TEST flag for restore_default_ipv6_cgi
Detail      : 1.Modify apps/httpd/core.c

Name        : Jackey Chen
Type        : Apps
Version     : 1.0.0, build 0123
Tag         : Ath-M-2008-02-05-0123
Description : 1.Fixed the prefix for radvd when lan service change to stateful
Detail      : 1.Modify apps/rc/app.c

Name        : Rock Chen
Type        : Apps
Version     : 1.0.0, build 0122
Tag         : Ath-M-2008-02-04-0122
Description : Fixed the bug which can't show the hardware version on the UI page.
Detail      : 1.Modify apps/httpd/cmobasicaip.c
	      2.Modify apps/httpd/cmoapi.h

Name        : Jackey Chen
Type        : Apps
Version     : 1.0.0, build 0121
Tag         : Ath-M-2008-02-04-0121
Description : 1.Fixed 6in4 tunnel default gw to sit1
Detail      : 1.Modify apps/rc/tunnel.c

Name        : Jackey Chen
Type        : Apps
Version     : 1.0.0, build 0120
Tag         : Ath-M-2008-02-01-0120
Description : 1.Fixed the bug that radvd can not sent packets after br0 down then up.
	      2.Fixed radvd prefix that does not change when IPv6_proto change to dhcp.
	      3.Fixed tunnel can not be destoried when IPv6_proto change.  
Detail      : 1.Modify apps/rc/app.c
	      2.Modify apps/rc/tunnel.c
	      3.Modify apps/rc/lan.c
	      4.Modify apps/httpd/core.c

Name        : Chase Cheng
Type        : Apps
Version     : 1.0.0, build 0119
Tag         : Ath-M-2008-01-31-0119
Description : Add DNS support for dhcpc6 (Just append dns address(IPv4) in resolv.conf)
Detail      : 1.Add apps/rc/app.c

Name        : Chase Cheng
Type        : Apps
Version     : 1.0.0, build 0118
Tag         : Ath-M-2008-01-25-0118
Description : Add dhcpv6 daemon to CVS server
Detail      : 1.Add apps/dhcpv6/
	      2.Modify apps/Makefile

Name        : Chase Cheng
Type        : Apps
Version     : 1.0.0, build 0117
Tag         : Ath-M-2008-01-24-0117
Description : Add dhclient6 function
Detail      : 1.Modufy apps/rc/wan.c
              2.Modufy apps/sutil/shvar.h

Name        : Chase Cheng
Type        : Apps
Version     : 1.0.0, build 0116
Tag         : Ath-M-2008-01-24-0116
Description : Modify dhcpdv6 execute point (from start_lan to AppServices)
Detail      : 1.Modufy apps/rc/lan.c
	      2.Modufy apps/rc/app.c

Name        : Chase Cheng
Type        : Apps
Version     : 1.0.0, build 0115
Tag         : Ath-M-2008-01-23-0115
Description : Add DHCPv6 support for IPv6 (dhcpv6 daemon not ci to CVS server yet)
Detail      : 1.Modufy apps/rc/app.c
	      2.Modify apps/rc/rc.h
	      3.Modify apps/rc/lan.c
	      4.Modify apps/sutil/shvar.h
	      5.Modify apps/sutil/sutil.h
	      6.Modify apps/sutil/sutil.c
	      7.Modify apps/conf/Config
	      8.Modify apps/Makefile

Name        : Jackey Chen
Type        : Apps
Version     : 1.0.0, build 0114
Tag         : Ath-M-2008-01-23-0114
Description : Add DNS support for IPv6 (Just append dns address(IPv4) in resolv.conf)
Detail      : 1.Modufy apps/rc/app.c

Name        : Rock Chen
Type        : Apps
Version     : 1.0.0, build 0113
Tag         : Ath-M-2008-01-22-0113
Description : Modify the IPv6 page nvram value and add the ipv6_dhcpd_prefix value to nvram 
Detail      : 1.Modufy apps/httpd/cmobasicapi.c

Name        : Chun Lin
Type        : Apps
Version     : 1.0.0, build 0112
Tag         : Ath-M-2008-01-22-0112
Description : remove timer deamon
Detail      : Modify file:
				apps\rc\app.c
				apps\rc\wan.c
				apps\rc\rc.c
				apps\noip2\rc_noip.c
				apps\noip2\Makefile
				apps\ntpclient\rc_ntp.c
				apps\ntpclient\ntpclient.c
				apps\ntpclient\Makefile
				apps\sutil\shvar.h
				apps\Makefile
				
Name        : Jackey Chen
Type        : Apps
Version     : 1.0.0, build 0111
Tag         : Ath-M-2008-01-22-0111
Description : Move radvd setting from tunnel.c to app.c
Detail      : 1.Modify apps/rc/tunnel.c
              2.Modufy apps/rc/app.c

Name        : Jackey Chen
Type        : Apps
Version     : 1.0.0, build 0110
Tag         : Ath-M-2008-01-22-0110
Description : Move lan setting from tunnel.c to lan.c
Detail      : 1.Modify apps/Makefile
	      2.Modify apps/rc/tunnel.c
	      3.Modufy apps/rc/lan.c

Name        : Jackey Chen
Type        : Apps
Version     : 1.0.0, build 0109
Tag         : Ath-M-2008-01-22-0109
Description : Add static IPv6 function 
Detail      : 1.Modify apps/config/Config
	      2.Modify apps/Makefile
	      3.Modify apps/rc/tunnel.c
	      4.Modufy apps/rc/wan.c	

Name        : Chun Lin
Type        : Apps
Version     : 1.0.0, build 0108
Tag         : Ath-M-2008-01-21-0108
Description : add timer deamon
Detail      : Modify file:
				apps\rc\app.c
				apps\rc\wan.c
				apps\rc\rc.c
				apps\noip2\rc_noip.c
				apps\noip2\Makefile
				apps\ntpclient\rc_ntp.c
				apps\ntpclient\ntpclient.c
				apps\ntpclient\Makefile
				apps\sutil\shvar.h
				apps\Makefile
				
			  Add file:
				apps\timer\Makefile
				apps\timer\timer.c
				apps\tracegw\Makefile
				apps\tracegw\tracegw.c

	      
Name        : Jackey Chen
Type        : Apps
Version     : 1.0.0, build 0107
Tag         : Ath-M-2008-01-21-0107
Description : Seperate IPv6 test function for CHT using CFLAGS=-DIPv6_TEST
Detail      : 1.Modify apps/rc/rc.c
	      2.Modify apps/rc/app.c
	      3.Modify apps/httpd/core.c
	      4.Modify apps/config/Config
	      5.Modify apps/Makefile

Name        : Chase Cheng
Type        : Apps
Version     : 1.0.0, build 0106
Tag         : Ath-M-2008-01-18-0106
Description : 1. Fix bug in remove_6in4_tunnel function
              2. Modify nvram name (tunnel -> 6in4)
Detail      :   1. Modify \apps\rc\tunnel.c
                2. Modify \apps\http\cmobasic.c

Name        : Chun Lin
Type        : Apps
Version     : 1.0.0, build 0105
Tag         : Ath-M-2008-01-18-0105
Description : 1. Fix WCN-test-transfer-invalid
	      2. update wps
Detail      : 1.wpa\wsc\src\common\InbEap\InbEap.cpp
		wpa\wsc\src\common\inc\MasterControl.h
		wpa\wsc\src\common\inc\RegProtoTlv.h
		wpa\wsc\src\common\inc\StateMachineInfo.h
		wpa\wsc\src\common\inc\tutrace.h
		wpa\wsc\src\common\MasterControl\Info.cpp
		wpa\wsc\src\common\MasterControl\Info.h
		wpa\wsc\src\common\MasterControl\MasterControl.cpp
		wpa\wsc\src\common\RegProtocol\RegProtocol.cpp
		wpa\wsc\src\common\StateMachine\EnrolleeSM.cpp
		wpa\wsc\src\common\StateMachine\RegistrarSM.cpp
		wpa\wsc\src\common\StateMachine\StateMachine.cpp
		wpa\wsc\src\common\WscCmd\WscCmd.cpp

Name        : Chase Cheng
Type        : Apps
Version     : 1.0.0, build 0104
Tag         : Ath-M-2008-01-18-0104
Description : 1. Add get_ipv6_prefix function
              2. Add IPv6-in-IPv4 tunnel (Tunnel Broker)
Detail      :   1. Modify \apps\sutil\sutil.h \apps\sutil\sutil.c
                2. Modify \apps\config\Config \apps\Makefile \aps\rc\tunnel.c

Name        : Joe Lin
Type        : Apps
Version     : 1.0.0, build 0103
Tag         : Ath-M-2008-01-16-0103
Description : 1. fixed pure network too1 test routerlansetting case 26 & case 29
								 error dhcpd start ip & dhcpd end ip

Name        : Rock Chen
Type        : Apps
Version     : 1.0.0, build 0101
Tag         : Ath-M-2008-01-15-0101
Description : Modify the IPv6 page according to nvram value
              1.Modify apps/httpd/cmobasicapi.c

Name        : Jackey Chen
Type        : Apps
Version     : 1.0.0, build 0100
Tag         : Ath-M-2008-01-14-0100
Description : Add tunnel feature in Eagle
	      1.Add apps/rc/tunnel.c
	      2.Modify apps/config/Config
	      3.Modify apps/Makefile
	      4.Modify apps/rc/Makefile
	      5.Modify apps/rc/rc.c
	      6.Modify apps/rc/app.c
	      7.Modify apps/httpd/core.c

Name        : Rock Chen
Type        : Apps
Version     : 1.0.0, build 0099
Tag         : Ath-M-2008-01-14-0099
Description : Fixed the bug that router can't show count down page when user do apply cgi
              1.Modify apps/httpd/core.c

Name        : Jackey Chen
Type        : Apps
Version     : 1.0.0, build 0098
Tag         : Ath-M-2008-01-10-0098
Description : Fixed the bug for 6to4 tunnel function in rc
	      1.Modify apps/rc/app.c

Name        : Rock Chen
Type        : Apps
Version     : 1.0.0, build 0097
Tag         : Ath-M-2008-01-09-0097
Description : Modify the 6to4 functionality for IPv6 6to4 Page
              1.Modify apps/httpd/cmobasicapi.c

Name        : Jackey Chen
Type        : Apps
Version     : 1.0.0, build 0096
Tag         : Ath-M-2008-01-09-0096
Description : Add two cmogetstatus for 6to4 tunnel and add 6to4 tunnel function
              1.Modify apps/httpd/cmobasicapi.c
	      2.Modify apps/rc/app.c

Name        : Jackey Chen
Type        : Apps
Version     : 1.0.0, build 0095
Tag         : Ath-M-2008-01-09-0095
Description : Add two cmogetstatus for 6to4 tunnel and add 6to4 tunnel function
	      1.Modify apps/rc/app.c
	      2.Modify apps/httpd/cmobasicapi.c
	      3.Modify apps/httpd/cmoapi.h

Name        : Chun Lin
Type        : Apps
Version     : 1.0.0, build 0094
Tag         : Ath-M-2008-01-09-0094
Description : comment out wan_port_ping_response_start_ip and wan_port_ping_response_end_ip
	      1.modify apps\rc\firewall.c
	      
Name        : Chun Lin
Type        : Apps
Version     : 1.0.0, build 0093
Tag         : Ath-M-2008-01-08-0093
Description : modify vs_rule to set protocol as "TCP,UDP,Both,Any,6,17,256,257"
	      1.modify apps\rc\firewall.c
	      
Name        : Tina Tsao
Type        : Apps
Version     : 1.0.0, build 0092
Tag         : Ath-M-2008-01-07-0092
Description : Fixed: When SSID key :;?<test>test'~!@#$%^&*()_+-=[]\, SSID in Device info page displayed error.
	      1.modify apps\httpd\cmobasicapi.c


Name        : Chun Lin
Type        : Apps
Version     : 1.0.0, build 0091
Tag         : Ath-M-2007-01-03-0091
Description : Fix access_control doesn't log url message.
	      1.modify \apps\rc\firewall.c
	      
Name        : Rock Chen
Type        : Apps
Version     : 1.0.0, build 0090
Tag         : Ath-M-2007-12-28-0090
Description : add ipv6 args in combasicapi.c
	      1.modify apps/httpd/cmobasicapi.c
	     

Name        : Stella Huang
Type        : Apps
Version     : 1.0.0, build 0089
Tag         : Ath-M-2007-12-26-0089
Description : remove radvd config file

Name        : Chun Lin
Type        : Apps
Version     : 1.0.0, build 0088
Tag         : Ath-M-2007-12-21-0088
Description : 1. fix miniupnp crash when there is no WAN interface and GetToTalBytesSent() is performed.
				apps\miniupnpd-1.0-RC7\linux\getifstats.c

Name        : Chun Lin
Type        : Apps
Version     : 1.0.0, build 0087
Tag         : Ath-M-2007-12-18-0087
Description : 1. remove wps debug message
			  2. When it enters daylight saving time, router will add one hour automatically.
				 When it leaves daylight saving time, router will subtract one hour automatically.
			  1. apps\wpa\wsc\src\common\MasterControl\Info.cpp
				 apps\wpa\wsc\src\common\MasterControl\MasterControl.cpp
				 apps\wpa\wsc\src\common\RegProtocol\RegProtocol.cpp
				 apps\wpa\wsc\src\common\StateMachine\EnrolleeSM.cpp
				 apps\wpa\wsc\src\common\WscCmd\WscCmd.cpp
				 apps\wpa\wsc\lib\openssl-0.9.8a\crypto\rand\md_rand.c
			  2. apps\rc\app.c
				 apps\ntpclient\ntpclient.c
				 apps\ntpclient\rc_ntp.c
			    

Name        : Roy Tseng
Type        : Apps
Version     : 1.0.0, build 0086
Tag         : Ath-M-2007-12-17-0086
Description : Modify mrd for initial bug.

Name        : Stella Huang
Type        : Apps
Version     : 1.0.0, build 0085
Tag         : Ath-M-2007-12-17-0085
Description : Add radvd config file

Name        : Jackey Chen
Type        : Apps
Version     : 1.0.0, build 0084
Tag         : Ath-M-2007-12-14-0084
Description : Add MRD daemon

Name        : Chun Lin
Type        : Apps
Version     : 1.0.0, build 0083
Tag         : Ath-M-2007-12-13-0083
Description : Fix igmp member doesn't show in UI
			  apps\httpd\cmoapi.h
			  apps\httpd\cmobasicapi.c
			  apps\httpd\httpd_util.c
			  apps\httpd\httpd_util.h
			  apps\igmpproxy\defs.h
			  apps\igmpproxy\igmpproxy.c
			  apps\igmpproxy\rttable.c
			  apps\sutil\shvar.h
			 
Name        : Chun Lin
Type        : Apps
Version     : 1.0.0, build 0082
Tag         : Ath-M-2007-12-11-0081
Description : add #define QOS
			 1.apps\httpd\cmoapi.h
			 2.apps\httpd\cmobasicapi.c
			 3.apps\httpd\core.c
			 4.apps\httpd\httpd_util.c
			 5.apps\config\Config
			 6.apps\Makefile

Name        : Chun Lin
Type        : Apps
Version     : 1.0.0, build 0081
Tag         : Ath-M-2007-12-11-0081
Description : add checksum for configuration file
			 1.\apps\httpd\core.c
			 2.\apps\httpd\httpd_util.c

Name        : Stella Huang
Type        : Apps
Version     : 1.0.0, build 0080
Tag         : Ath-M-2007-12-10-0080
Description : Add ipv6 tag for CHT IOT phaseI pass

Name        : Chun Lin
Type        : Apps
Version     : 1.0.0, build 0079
Tag         : Ath-M-2007-12-07-0079
Description : fix virtual_server_rule with other protocol fail
			  \apps\rc\firewall.c
			  
Name        : Chun Lin
Type        : Apps
Version     : 1.0.0, build 0079
Tag         : Ath-M-2007-12-07-0079
Description : Fix internet session shows IP as "0.0.0.0"
			  \apps\httpd\httpd_util.c
			  
Name        : Chun Lin
Type        : Apps
Version     : 1.0.0, build 0078
Tag         : Ath-M-2007-12-06-0078
Description : 1. internet session shows all kinds of packets
			  apps\httpd\cmoapi.h
			  apps\httpd\cmobasicapi.c
			  apps\httpd\httpd_util.c
			  apps\httpd\httpd_util.h
	      	
Name        : Chun Lin
Type        : Apps
Version     : 1.0.0, build 0077
Tag         : Ath-M-2007-12-06-0077
Description : 1. After disable trigger port, the rule may still work for 65 seconds if it's in ASSURE state.
			  2. port trigger only DNAT for packets with dest_ip=WAN_IP and from wan interface.
	      	apps\rc\firewall.c
	      	
Name        : Chun Lin
Type        : Apps
Version     : 1.0.0, build 0076
Tag         : Ath-M-2007-12-03-0076
Description : Fix PPPoE dial on demand fail
	      	apps\rc\ppp.c
	      
Name        : Jackey Chen
Type        : Apps
Version     : 1.0.0, build 0075
Tag         : Ath-M-2007-11-26-0075
Description : RADVD support LAN only,WAN only and Both
	      1.Modify apps/sutil/sutil.c
	      2.Modify apps/httpd/cmobasicapi.c

Name        : Jackey Chen
Type        : Apps
Version     : 1.0.0, build 0074
Tag         : Ath-M-2007-11-22-0074
Description : Add ping6 elements(ping_size and ping_count)
	      1.Modify apps/httpd/httpd_util.c
	      2.Modify apps/httpd/httpd_util.h
	      3.Modify apps/httpd/cmoapi.h
	      4.Modify apps/httpd/core.c
	      5.Modify apps/httpd/cmobasicapi.c

Name        : Jackey Chen
Type        : Apps
Version     : 1.0.0, build 0073
Tag         : Ath-M-2007-11-22-0073
Description : Fixed the bugs of radvd and the CGI of test page
	      1.Modify apps/httpd/core.c
	      2.Modify apps/sutil/sutil.c
	      3.Modify apps/sutil/sutil.h
	      4.Modify apps/rc/app.c

Name        : Albert Chen
Type        : Apps
Version     : 1.0.0, build 0072
Tag         : Ath-M-2007-11-21-0072
Description : 1. fix access control other machine fail
				a) move firewall_rule() from NAT_PREROUTING to FILTER_FORWARD
				b) add fake log_only(), log is not implemented yet.
			  2. fix access control schedule fail
			  3. fix igmp list fail
			  	a) enlarge array size M_MAX_NAPT_SESSION_LIST from 256 to 600 (28*600=16800Byte)
			  	b) prevent httpd from getting session_list size > M_MAX_NAPT_SESSION_LIST
Detail      : apps\httpd\httpd_util.c
			  apps\httpd\httpd_util.h
			  apps\rc\firewall.c

Name        : Albert Chen
Type        : Apps
Version     : 1.0.0, build 0071
Tag         : Ath-M-2007-11-21-0071
Description : 1. fix pptp passthrough and l2tp passthrough can't work in wan type pptp and l2tp mode	
Detail      : 1. apps\rc\firewall.c
				 
Name        : Chun Lin
Type        : Apps
Version     : 1.0.0, build 0070
Tag         : Ath-M-2007-11-16-0070
Description : 1. fix build error for HTTP_DEBUG	
Detail      : 1. apps\httpd\makefile
				 apps\httpd\httpd.h
 				 
Name        : Chun Lin
Type        : Apps
Version     : 1.0.0, build 0069
Tag         : Ath-M-2007-11-16-0069
Description : 1. add measuring bandwidth function for UI	
              2. Fix reserve dhcp IP are still offered to other client		
Detail      : 1. apps\httpd\cmoapi.h
 				 apps\httpd\cmobasicapi.c
 				 apps\httpd\core.c
 				 apps\httpd\httpd_util.c
              2. apps\udhcp\serverpacket.c
              
              
Name        : Nick Chou
Type        : Apps
Version     : 1.0.0, build 0068
Tag         : Ath-M-2007-11-15-0068
Description : 1. Record PPP auth type in /var/etc/ppp_auth_type	
              2. disable  HTTP_DEBUG
Detail      : 1. apps\ppp\pppd\lcp.c
              2. apps\httpd\httpd.h

Name        : Chun Lin
Type        : Apps
Version     : 1.0.0, build 0067
Tag         : Ath-M-2007-11-08-0067
Description : fixed remote control user can login with default port 80
	      update wlan setting for LSDK 7.1.2.38
	      add define for dlink led define.
Detail      : \apps\rc\firewall.c
	      \apps\rc\rc.c
	      \apps\rc\wlan.c	

Name        : Chun Lin
Type        : Apps
Version     : 1.0.0, build 0066
Tag         : Ath-M-2007-11-08-0066
Description : fix build error
Detail      : \apps\rc\firewall.c

Name        : Nick Chou
Type        : Apps
Version     : 1.0.0, build 0065
Tag         : Ath-M-2007-11-08-0065
Description : PPPoE discovery => sending PADT before PADI
Detail      : \apps\rp-pppoe\discovery.c
              \apps\rp-pppoe\pppoe.c

Name        : Roy Tseng
Type        : Apps
Version     : 1.0.0, build 0064
Tag         : Ath-M-2007-11-05-0064
Description : Add the four hid folders of mireo 
Detail      : 1.Add apps/midero/compat/.deps, apps/midero/libteredo/.deps, apps/midero/libtun6/.deps, apps/midero/src/.deps,

Name        : Roy Tseng
Type        : Apps
Version     : 1.0.0, build 0063
Tag         : Ath-M-2007-11-05-0063
Description : Add miredo for Teredo
Detail      : 1.Import new folder "miredo"
              2.Modify apps/config/Config
              3.Modify apps/Makefile
              
Name        : Nick Chou
Type        : Apps
Version     : 1.0.0, build 0062
Tag         : Ath-M-2007-11-01-0062
Description : add nvram item for QoS
Detail      : 1.Modify apps/httpd/cmobasicapi.c
	      
Name        : Jackey Chen
Type        : Apps
Version     : 1.0.0, build 0061
Tag         : Ath-M-2007-11-01-0061
Description : Fixed ping6 CGI BUG
Detail      : 1.Modify apps/httpd/cmobasicapi.c
	      2.Modify apps/httpd/cmoapi.h

Name        : Jackey Chen
Type        : Apps
Version     : 1.0.0, build 0060
Tag         : Ath-M-2007-11-01-0060
Description : Add ping6 CGI
Detail      : 1.Modify apps/httpd/core.c
	      2.Modify apps/httpd/cmobasicapi.c
	      3.Modify apps/httpd/cmoapi.h
 	      4.Modify apps/httpd/httpd_util.c
	      5.Modify apps/busybox-1.01/networking/ping6.c

Name        : Jackey Chen
Type        : Apps
Version     : 1.0.0, build 0059
Tag         : Ath-M-2007-10-31-0059
Description : Add radvd conf
Detail      : 1.Modify apps/Makefile
	      2.Modify apps/rc/app.c
	      3.Modify apps/sutil/shvar.h

Name        : Nick Chou
Type        : Apps
Version     : 1.0.0, build 0058
Tag         : Ath-M-2007-10-29-0058
Description : modify nat type support for 2.6 kernel
Detail      : \apps\iptables_2_6\extensions\libipt_NATTYPE.c

Name        : Solo Wu
Type        : Apps
Version     : 1.0.0, build 0057
Tag         : Ath-M-2007-10-29-0057
Description : Add flex dep files
Detail      : flex/.dep/

Name        : Jackey Chen
Type        : Apps
Version     : 1.0.0, build 0056
Tag         : Ath-M-2007-10-29-0056
Description : Add flex library and radvd to support IPv6
Detail      : 1.Modify apps/config/Config
	      2.Modify apps/Makefile
	      3.Add the folder of flex
	      4.Add the folder of radvd

Name        : Chun Lin
Type        : Apps
Version     : 1.0.0, build 0055
Tag         : Ath-M-2007-10-25-0055
Description : Russia pppoe/pptp need to add second interface in firewall.c
Detail      : apps\rc\firewall.c

			  
Name        : Chun Lin
Type        : Apps
Version     : 1.0.0, build 0054
Tag         : Ath-M-2007-10-23-0054
Description : Fix build error
Detail      : apps\rc\firewall.c
			  apps\rc\wan.c  
                 
Name        : Chun Lin
Type        : Apps
Version     : 1.0.0, build 0053
Tag         : Ath-M-2007-10-22-0053
Description : 1. access control: other machine rule need to be placed in the last.
              2. UDHCPC_UNICAST define build error 
Detail      : 1. \apps\rc\firewall.c
                 \apps\sutil\sutil.h
              2. \apps\rc\app.c
              	 \apps\rc\wan.c  
                 \apps\udhcp\dhcpc.c 

                 
Name        : Nick Chou
Type        : Apps
Version     : 1.0.0, build 0052
Tag         : Ath-M-2007-10-22-0052
Description : 1. modify ip_conntrack_udp_timeout = 65 for XBOX Test
              2. fixed that PPTP/L2TP using specification DNS bugs
              3. syslog don'r rotate (message = > message.0)=> -b 0
              4. fixed that DHCPD Reserved IP Address bugs
              5. send log email when /var/log/message > SEND_LOG_THRESHOLD
              6. prvent "telnet 192.168.0.1 80" cause httpd "crash"
              7. modify httpd auth_check_time => timeout= 3 mins, every 5 secs to check 
Detail      : 1. \apps\rc\firewall.c
              2. \apps\rc\wan.c
              3. \apps\rc\rc.c
                 \apps\rc\app.c
              4. \apps\rc\app.c
              5. \apps\Mail-On-Schedule\main.c
              6. \apps\httpd\httpd.c
              7. \apps\httpd\httpd.c

Name        : Chun Lin
Type        : Apps
Version     : 1.0.0, build 0051
Tag         : Ath-M-2007-10-19-0051
Description : 1. Add SNAT for wan_phy_interface in Russia PPPOE 
Detail      : 1. \apps\rc\firewall.c

Name        : Nick Chou
Type        : Apps
Version     : 1.0.0, build 0050
Tag         : Ath-M-2007-10-18-0050
Description : 1. fixed that support Israel VPN cause PPPOE connecting Internet fail
Detail      : 1. \apps\rc\firewall.c

Name        : Chun Lin
Type        : Apps
Version     : 1.0.0, build 0049
Tag         : Ath-M-2007-10-17-0049
Description : 1. add symbolic link "wpa" to "wps_ath" if select CONFIG_WL_ATH
			  2. remove apps\.config( Now, we have to copy it from www/model_name)
			  3. remove apps\rp-l2tp\.depend (Avoid Eagle to use atheros_tool toolchain )
Detail      : 1. Modify \apps\Makefile
              2. Remove \apps\.config
              3. Remove apps\rp-l2tp\.depend
              
Name        : Nick Chou
Type        : Apps
Version     : 1.0.0, build 0048
Tag         : Ath-M-2007-10-17-0048
Description : support Israel VPN
                 => All VPN pass-throughput can over on all VPN clients (WAN Type)
                 => PPTP/L2TP/IPSEC client from PC side with VPN WAN
              2. fixed that STA can¡¦t connect with router which¡¦s security is PSK with 64bits and WPS function disabled
Detail      : 1. \apps\rc\firewall.c
              2. \apps\rc\wlan.c

Name        : Nick Chou
Type        : Apps
Version     : 1.0.0, build 0047
Tag         : Ath-M-2007-10-16-0047
Description : 1. modify "lcp-echo-failure 3\n"
                 Set number of consecutive echo failures to indicate link failure
Detail      : 1. \apps\rc\wan.c
                 \apps\sutil\sutil.c

Name        : Nick Chou
Type        : Apps
Version     : 1.0.0, build 0046
Tag         : Ath-M-2007-10-15-0046
Description : 1. fixed nvram_init() error, add /var/etc/nvram_count.txt   
              2. fixed port triger(udp), ip_conntrack_udp_timeout=1
              3. PPTP support MPPE (40 bit, 128 bit)   
              4. fixed stop_wan() bug
              5. fied return_internetonline_check() bug
Detail	    : 1. \apps\nvram\nvram.c
                 \apps\nvram\nvram.h
              2. \apps\rc\firewall.c
              3. \apps\ppp\pppd\ccp.c
                 \apps\rc\wan.c
                 \apps\httpd\cmobasicapi.c
                 \apps\sutil\sutil.c
              4. \apps\rc\wan.c
              5. \apps\httpd\cmobasicapi.c

Name        : Chun Lin
Type        : Apps
Version     : 1.0.0, build 0045
Tag         : Ath-M-2007-10-12-0045
Description : 1. initialize default_array[] to prevent from saving strange string
			  2. remove default_array[] as a global variable to prevent from referring to it when calculating nvram size 
Detail	    : \apps\nvram\nvram.c

Name        : Albert Chen
Type        : Apps
Version     : 1.0.0, build 0044
Tag         : Ath-M-2007-10-11-0044
Description : 1. Fixed wireless mode with auto channel setting could not work issue
Detail	    : 1. \apps\rc\wlan.c

Name        : Chun Lin
Type        : Apps
Version     : 1.0.0, build 0043
Tag         : Ath-M-2007-10-09-0043
Description : 1. reset send_signal_done flag=0 when signal has been sent.
			  2. fix busybox always pops out "make menuconfig"
			  3. fix busybox install path wrong.
Detail	    : 1. \apps\udhcp\dhcpc.c
				 \apps\ppp\pppd\ipcp.c
			  2. add \apps\busybox-1.01\.config
			  3. modify \apps\busybox-1.01\Makefile				 	

Name        : Nick Chou
Type        : Apps
Version     : 1.0.0, build 0042
Tag         : Ath-M-2007-10-08-0042
Description : 1. update return_online_firmware_check()
Detail	    : 1. \apps\httpd\cmobasicapi.c

Name        : Chun Lin
Type        : Apps
Version     : 1.0.0, build 0041
Tag         : Ath-M-2007-10-08-0041
Description : modify cd router tcp port scan only filter "syn" packet from wan 
Detail      : 1. apps\rc\firewall.c

Name        : Nick Chou
Type        : Apps
Version     : 1.0.0, build 0040
Tag         : Ath-M-2007-10-05-0040
Description : 1. modify firewall rule for VISTA NAT(IGD Data) test
                 udp_nat_type=1 => ENDPOINT_INDEPEND (Full Cone NAT) , Gaming Mode Enable
                 tcp_nat_type=0 => PORT_ADDRESS_RESTRICT(dependent), Gaming Mode Disable
Detail      : 1. apps\rc\firewall.c

Name        : Chun Lin
Type        : Apps
Version     : 1.0.0, build 0039
Tag         : Ath-M-2007-10-05-0039
Description : 1. Fix cd router test: router deny UDP port scan
			  2. fix cd router: DHCP client need to get WAN DNS info if DNS Relay is disabled
Detail      : 1. apps\rc\firewall.c
			  2. apps\rc\apps.c
 	      	  
Name        : Albert Chen
Type        : Apps
Version     : 1.0.0, build 0038
Tag         : Ath-M-2007-10-05-0038
Description : 1. Add log message when system sending mail 
              2. Change default country domain from DO to US.
Detail      : apps/busybox-1.01/sysklogd/klogd.c
 	      	  apps/httpd/core.c
	      	  apps/httpd/log.c 
              apps/mail_client/src/msmtp.c
              apps/mail_client/src/net.c 
              apps/mail_client/src/smtp.c
              apps/rc/wlan.c 
              doc/apps_version.c
              
Name        : Nick Chou
Type        : Apps
Version     : 1.0.0, build 0037
Tag         : Ath-M-2007-10-03-0037
1. Fix that if DHCP IP Address Range include LAN IP Address, 
                 the DHCP client will got the same as DUT LAN IP Address 
              2. add new firewall rule for VISTA NAT(IGD Data)test
              3. Fix that set Application Rule Trigger/Firewall port type to UDP
Detail	    : 1. apps\udhcp\dhcpd.c
                 apps\udhcp\serverpacket.c
              2. apps\rc\firewall.c
              3. apps\iptables_2_6\extensions\libipt_PORTTRIGGER.c
                 \apps\iptables\extensions\libipt_PORTTRIGGER.c

Name        : Chun Lin
Type        : Apps
Version     : 1.0.0, build 0036
Tag         : Ath-M-2007-10-03-0036
Description : 1. Fix cd router test:  firewall test 
				a) router must deny wan hosts port scan.
				b) router must deny wan host tp ping router's LAN IP
Detial      : 1.Modify apps\rc\firewall.c
	      	  	 
Name        : Nick Chou
Type        : Apps
Version     : 1.0.0, build 0035
Tag         : Ath-M-2007-10-02-0035
Description : 1.update miniupnpd-1.0-RC7 with AthSDK (build 0310) 
                for resolving cd-router test
Detial      : 1.Modify apps\miniupnpd-1.0-RC7\linux\iptcrdr.c
	      	  	 apps\miniupnpd-1.0-RC7\linux\iptcrdr.h
	      	  	 apps\miniupnpd-1.0-RC7\upnpredirect.c
	      	  	 apps\miniupnpd-1.0-RC7\upnpredirect.h
	      	  	 apps\miniupnpd-1.0-RC7\upnpsoap.c
	      	     apps\miniupnpd-1.0-RC7\minissdp.c

Name        : Nick Chou
Type        : Apps
Version     : 1.0.0, build 0034
Tag         : Ath-M-2007-10-01-0034
Description : 1.busybox-1.01 make error
              2.MPPPOE define
Detial      : 1.Modify apps\busybox-1.01\Makefile
              2.Modify apps\rc\wantimer.c

Name        : Nick Chou
Type        : Apps
Version     : 1.0.0, build 0033
Tag         : Ath-M-2007-10-01-0033
Description : 1.update firewall with AthSDK (build 0310)
Detial      : 1.Modify apps\rc\firewall.c

Name        : Nick Chou
Type        : Apps
Version     : 1.0.0, build 0032
Tag         : Ath-M-2007-09-28-0032
Description : 1.update rc with AthSDK (build 0310)
              2.update gpio with AthSDK (build 0310)
              3.update http with AthSDK (build 0310)
Detial      : 1.Modify apps\rc\rc.c
                       apps\rc\wlan_ath.c
                       apps\rc\wantimer.c
              2.Modify apps\gpio\gpio.c
              3.Modify apps\httpd\cmobasicapi.c
                       apps\httpd\httpd_util.c
                       apps\httpd\pure.c

Name        : Nick Chou
Type        : Apps
Version     : 1.0.0, build 0031
Tag         : Ath-M-2007-09-28-0031
Description : 1.fixed #ifdef UDHCPD_NETBIOS bug in DNS
Detial      : 1.Modify apps\dnsmasq\forward.c
                       apps\httpd\httpd_util.c
                       apps\rc\app.c
                       apps\rc\wan.c

Name        : Nick Chou
Type        : Apps
Version     : 1.0.0, build 0030
Tag         : Ath-M-2007-09-28-0030
Description : 1.fixed #ifdef UDHCPD_NETBIOS bug in rc
Detial      : 1.Modify apps\rc\app.c
                       apps\rc\wan.c

Name        : Nick Chou
Type        : Apps
Version     : 1.0.0, build 0029
Tag         : Ath-M-2007-09-28-0029
Description : 1. Add CONFIG_SMTP in menuconfig
              2. #define UPGRADE_COUNT_DOWN			core_itoa(CONFIG_UPGRADE_TIME)
Detial      : 1.Modify apps\config\Config
                       apps\Makefile
              2.Modify apps\sutil\shvar.h
                       apps\httpd\core.c

Name        : Chun Lin
Type        : Apps
Version     : 1.0.0, build 0027
Tag         : Ath-M-2007-09-27-0027
Description : Update with AthSDK_4_16
Detial      : 1.Modify apps\rc\firewall.c
		       
Name        : Jackey
Type        : Apps
Version     : 1.0.0, build 0026
Tag         : Ath-M-2007-09-27-0026
Description : Fix build error for miniupnpd-1.0-rc7
Detial      : 1.Modify apps/config/Config
		       apps/miniupnpd_1.0_RC7/Makefile

Name        : Chun Lin
Type        : Apps
Version     : 1.0.0, build 0025
Tag         : Ath-M-2007-09-27-0025
Description : Fix build error 
Detial      : 1.Modify apps\rc\wantimer.c

Name        : Jackey
Type        : Apps
Version     : 1.0.0, build 0024
Tag         : Ath-M-2007-09-27-0024
Description : Fix build error
Detial      : 1.Modify apps\httpd\httpd_util.c
		       apps\httpd\core.c

Name        : Chun Lin
Type        : Apps
Version     : 1.0.0, build 0023
Tag         : Ath-M-2007-09-27-0023
Description : Fix build error 
Detial      : 1.Modify apps\rc\firewall.c
                       apps\rc\ppp.c
                       apps\rc\rc.h
                       apps\rc\wan.c
                       apps\rc\wantimer.c
                       apps\sutil\sutil.c
                       apps\httpd\httpd_util.c
                       apps\httpd\httpd_util.h
                       apps\httpd\core.c
                       
Name        : Nick Chou
Type        : Apps
Version     : 1.0.0, build 0022
Tag         : Ath-M-2007-09-27-0022
Description : 1.dhcp don't use sutil
              2.CONFIG_PURE_NETWORK -> CONFIG_HTTPD_PURE
Detial      : 1.Modify apps\udhcp\Makefile
                       apps\udhcp\dhcpd.h
                       apps\udhcp\dhcpd.c
                       apps\udhcp\dhcpc.h
                       apps\udhcp\dhcpc.c
              2.apps\httpd\Makefile

Name        : Chun Lin
Type        : Apps
Version     : 1.0.0, build 0021
Tag         : Ath-M-2007-09-27-0021
Description : Fix build error 
Detial      : 1.Modify apps\rc\firewall.c
                       
Name        : Chun Lin
Type        : Apps
Version     : 1.0.0, build 0020
Tag         : Ath-M-2007-09-26-0020
Description : Add ifdef RPPPOE in russia pppoe codes.
Detial      : 1.Modify apps\udhcpd\dhcpc.c
                       apps\udhcpd\dhcpc.h
                       apps\rc\route.c
                       apps\rc\wan.c
                       apps\rc\ppp.c
                       
Name        : Nick Chou
Type        : Apps
Version     : 1.0.0, build 0019
Tag         : Ath-M-2007-09-26-0019
Description : display_lan_bytes, display_wan_bytes, display_wlan_bytes for MPPPOE or not
Detial      : 1.Modify apps\httpd\cmobasicapi.c
                       apps\sutil\sutil.h

Name        : Chun Lin
Type        : Apps
Version     : 1.0.0, build 0018
Tag         : Ath-M-2007-09-26-0018
Description : Menuconfig support russia_pppoe, spi, port_forward_both,access_control and inbound_filter.
Detial      : 1.Modify apps\Makefile
                       apps\config\Config
                       
Name        : Nick Chou
Type        : Apps
Version     : 1.0.0, build 0017
Tag         : Ath-M-2007-09-26-0017
Description : 1.update httpd with AthSDK (build 0301)
              2.update iptables with AthSDK (build 0301)
              3.update rc with AthSDK (build 0301)
              4.update sutil with AthSDK (build 0301)
Detial      : 1.Modify apps\httpd\log.c
                       apps\httpd\log.h
                       apps\httpd\pure_xml.c
                       apps\httpd\pure.c
                       apps\httpd\Makefile
                       apps\httpd\httpd_util.h
                       apps\httpd\httpd_util.c
                       apps\httpd\httpd.c
                       apps\httpd\core.c
                       apps\httpd\cmobasicapi.c
                       apps\httpd\cmoapi.h
              2.Modify apps\iptables\extensions\libipt_PORTTRIGGER.c
                       apps\iptables_2_6\extensions\libipt_PORTTRIGGER.c
              3.Modify apps\rc\firewall.c
                       apps\rc\lan.c
                       apps\rc\Makefile
                       apps\rc\psmon.c
                       apps\rc\wlan_ath.c
                       apps\rc\wan.c
                       apps\rc\rc.h
                       apps\rc\rc.c
                       apps\rc\route.c
                       apps\rc\ppp.c
                       apps\rc\platform.c
                       apps\rc\wantimer.c
                       apps\rc\app.c
              4.Modify apps\sutil\shvar.h
                       apps\sutil\sutil.h
                       \apps\sutil\sutil.c

Name        : Nick Chou
Type        : Apps
Version     : 1.0.0, build 0016
Tag         : Ath-M-2007-09-26-0016
Description : 1.modify noiop2
              2.update mail_client with AthSDK (build 0301)
              3.update Mail-On-Schedule with AthSDK (build 0301)
              4.update ppp with AthSDK (build 0301)
Detial      : 1.Modify apps\noip2\noip2.c
                       apps\noip2\rc_noip.c
              2.Modify apps\mail_client\src\net.c
                       apps\mail_client\src\msmtp.c
                       apps\mail_client\src\smtp.c
              3.Modify apps\Mail-On-Schedule\log.c
                       apps\Mail-On-Schedule\log.h
                       apps\Mail-On-Schedule\main.c
              4.Modify apps\ppp\pppd\ipcp.c

Name        : Nick Chou
Type        : Apps
Version     : 1.0.0, build 0015
Tag         : Ath-M-2007-09-26-0015
Description : 1.update busybox syslogd with AthSDK (build 0301)
              2.update tftpd with AthSDK (build 0301)
              3.update udhcp with AthSDK (build 0301)
              4.update ntpclient with AthSDK (build 0301)
Detial      : 1.Modify apps\busybox-1.00-pre10\sysklogd\syslogd.c
                       apps\apps\busybox-1.01\sysklogd\syslogd.c
              2.Modify apps\tftpd\tftp.c
              3.Modify apps\udhcp\dhcpc.c
                       apps\udhcp\dhcpd.c
                       apps\udhcp\files.c
                       apps\udhcp\leases.c
                       apps\udhcp\Makefile
                       apps\udhcp\packet.h
                       apps\udhcp\serverpacket.c
              4.Modify apps\ntpclient\ntpclient.c
                       apps\ntpclient\rc_ntp.c

Name        : Jackey Chen
Type        : Apps
Version     : 1.0.0, build 0014
Tag         : Ath-M-2007-09-21-0014
Description : Menuconfig support 802.11n for Athores chip.
Detial      : 1.Modify apps/config/Config
              2.Modify apps/Makefile

Name        : Jackey Chen
Type        : Apps
Version     : 1.0.0, build 0013
Tag         : Ath-M-2007-09-21-0013
Description : HTTPD support different wireless solution
Detial      : 1.Modify apps/Makefile

Name        : Jackey Chen
Type        : Apps
Version     : 1.0.0, build 0012
Tag         : Ath-M-2007-09-21-0012
Description : Modify LOG_FILE to LOG_FILE_HTTP in log.c
Detial      : 1.Modify apps/httpd/log.c
	      2.Modify apps/sutil/shvar.h
	      3.Modify apps/httpd/log.h

Name        : Jackey Chen
Type        : Apps
Version     : 1.0.0, build 0011
Tag         : Ath-M-2007-09-20-0011
Description : Remove special char for sutil
Detial      : 1.Modify apps/config/Config
	      2.Modify apps/Makefile
	      3.Modify apps/sutil/Makefile
	      4.Modify apps/sutil/sutil.c

Name        : Jackey Chen
Type        : Apps
Version     : 1.0.0, build 0010
Tag         : Ath-M-2007-09-20-0010
Description : 1.Menuconfig support time for reboot, restore default and so on.
  	      2.Merge sutil with AthSDK and Eagle
Detial      : 1.Modify apps/config/Config
              2.Modify apps/Makefile
              3.Modify apps/sutil/shvar.h

Name        : Jackey Chen
Type        : Apps
Version     : 1.0.0, build 0009
Tag         : Ath-M-2007-09-20-0009
Description : Modify ddns in rc/app.c
Detial      : 1.Modify apps/rc/app.c

Name        : Chun Lin
Type        : Apps
Version     : 1.0.0, build 0008
Tag         : Ath-M-2007-09-19-0008
Description : update noip with AthSDK (build 0301)
Detial      : 1.Modify apps/noip2/noip2.c
              2.Modify apps/noip2/rc_noip.c
	      
Name        : Jackey Chen
Type        : Apps
Version     : 1.0.0, build 0007
Tag         : Ath-M-2007-09-19-0007
Description : Menuconfig support reservating wireless domain.
Detial      : 1.Modify apps/config/Config
              2.Modify apps/Makefile
              3.Modify apps/nvram/nvram.c

Name        : Nick Chou
Type        : Apps
Version     : 1.0.0, build 0006
Tag         : Ath-M-2007-09-19-0006
Description : update nvram with AthSDK (build 0301)
Detial	    : 1.Modify apps/nvram/nvram.c
              2.Modify apps/nvram/nvram.h

Name        : Jackey Chen
Type        : Apps
Version     : 1.0.0, build 0005
Tag         : Ath-M-2007-09-14-0005
Description : Menuconfig support dynamic numbers for firewall rule,mac filter and so on.
Detial	    : 1.Modify apps/config/Config
              2.Modify apps/Makefile
              3.Modify apps/sutil/shvar.h

Name        : Ken Chiang
Type        : Apps
Version     : 1.0.0, build 0004
Tag         : Ath-M-2007-09-14-0004
Description : Add miniupnpd-1.0-RC7
              1.added apps/miniupnpd-1.0-RC7
	      
Name        : Jackey Chen
Type        : Apps
Version     : 1.0.0, build 0003
Tag         : Ath-M-2007-09-13-0003
Description : Menuconfig support dynamic nvram size
              1.Modify apps/config/Config
              2.Modify apps/Makefile
              3.Modify apps/nvram/nvram.c

Name        : Jackey Chen
Type        : Apps
Version     : 1.0.0, build 0002
Tag         : Ath-M-2007-09-13-0002
Description : 1.Modify Makefile to build different version of busybox by $(PLATFORM)
              2.Modify Makefile to build different version of miniupnpd
Detial      :
              1.Modify apps/config/Config
              2.Modify apps/Makefile

Name        : Jackey Chen
Type        : Apps
Version     : 1.0.0, build 0001
Tag         : Ath-M-2007-09-12-0001
Description : First release
*/
#endif
