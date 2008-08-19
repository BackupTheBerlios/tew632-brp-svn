const unsigned char __CAMEO_LINUX_VERSION__[] = "2.6.15-mips";
const unsigned char __CAMEO_LINUX_BUILD__[] = "0081";
const unsigned char __CAMEO_LINUX_BUILD_DATE__[] = "Wed, 06, Aug, 2008";

#if 0
/*
[Release Note]
Name        : Chase Cheng
Type        : Platform
Version     : 2.6.15-mips, build 0081
Tag         : AR7100_2008-08-06-0081
Description : 1.Make ipv6 router could accept ra.
Detail      : 1.Modify kernels/mips-linux-2.6.15/net/ipv6/ndisc.c

Name        : Ken Chinng
Type        : Platform
Version     : 2.6.15-mips, build 0080
Tag         : AR7100_2008-07-25-0080
Description : 1.setup LED gpio used bsp.h for different model.
Detail      : 1.added /kernels/mips-linux-2.6.15/init/bsp.h for main.c include the bsp.h
			  2.modify platform/AR9100/Makefile for copy bsp.h from $(WWW_PATH)
			  3.modify /kernels/mips-linux-2.6.15/init/main.c.
			  4.modify /kernels/mips-linux-2.6.15/arch/mips/ar7100/setup.c  
	
Name        : Albert Chen
Type        : Platform
Version     : 2.6.15-mips, build 0079
Tag         : AR7100_2008-07-02-0079
Description : 1. setup register for led switchable
Detail      : 1. kernels/mips-linux-2.6.15/arch/mips/ar7100/setup.c

	      
Name        : Albert Chen
Type        : Platform
Version     : 2.6.15-mips, build 0078
Tag         : AR7100_2008-06-23-0078
Description : 1. Add a function for AG switchable led 
Detail      : 1. kernels/mips-linux-2.6.15/arch/mips/ar7100/setup.c
	      2. kernels/mips-linux-2.6.15/include/asm-mips/mach-ar7100/ar7100.h

Name        : Jimmy Huang
Type        : Platform
Version     : 2.6.15-mips, build 0077
Tag         : AR7100_2008-06-16-0077
Description : 1. When block SynAck packet with invalid sequence, also, log to syslog
Detail      : 1. AR9100/kernels/mips-linux-2.6.15/net/ipv4/netfilter/ip_conntrack_proto_tcp.c

Name        : Jimmy Huang
Type        : Platform
Version     : 2.6.15-mips, build 0076
Tag         : AR7100_2008-06-16-0076
Description : 1. When SPI Enable, block SynAck packet with invalid sequence
Detail      : 1. AR9100/kernels/mips-linux-2.6.15/net/ipv4/netfilter/ip_conntrack_proto_tcp.c

Name        : Jimmy Huang
Type        : Platform
Version     : 2.6.15-mips, build 0075
Tag         : AR7100_2008-05-22-0075
Description : 1.Replace switch codes with older stable version
Detail      : 1./AR9100/drivers/net/ag7100/*

Name        : Albert Chen
Type        : Platform
Version     : 2.6.15-mips, build 0074
Tag         : AR7100_2008-05-14-0074
Description : 1.Modify the booup and backup mode LED behavoir 
Detail      : 
		1./u-boot/cpu/mips/start.S
		2./u-boot/httpd/httpd.c
		3./u-boot/lib_mips/board.c
			  
			  
Name        : Ken Chiang
Type        : Platform
Version     : 2.6.15-mips, build 0073
Tag         : AR7100_2008-05-14-0073
Description : 1.Modify for build AP83+rtl8366sr in u-boot and kernel.
Detail      : Build All:
			  1.Modify AthSDK/Makefile
			  2.Modify AthSDK/platform/AR9100/Makefile
			  3.Modify AthSDK/rootfs/Makefile
			  4.Added AthSDK/Makefile_ap83.inc
			  u-boot:
			  1.Modify ~/u-boot/config.mk	
			  2.Modify ~/u-boot/Makefile
			  3.Modify ~/u-boot/board/ar7100/ap83/Makefile
			  4.Modify ~/u-boot/board/ar7100/ap83/ap83.c
			  5.Modify ~/u-boot/board/ar7100/commom/phy.h,rtl8366sr_phy.h,rtl8366sr_phy.c
			  6.Modify ~/u-boot/cpu/mips/start.S
			  7.Modify ~/u-boot/mips/ar7100/meminit.c,ag7100.c,ag7100.h,ag7100_phy.h
			  8.Modify ~/u-boot/include/configs/ap83.h,ar7100.h
			  kernel:
			  1.Modify ~/drivers/net/ag7100/Makefile
			  2.Modify ~/drivers/net/ag7100/ag7100.c,ag7100_phy.h
			  3.Added ~/drivers/net/ag7100/rtl8366sr_phy.h,rtl8366sr_phy.c
			  4.Added ~/kernels/mips-linux-2.6.15/arch/mips/configs/ap83_defconfig_rtl8366sr,ap83_defconfig_aths26
			  5.Added ~/scripts/ap83/...
			  6.Added ~/wireless/AP83/...			   

Name        : Chun Lin
Type        : Platform
Version     : 2.6.15-mips, build 0072
Tag         : AR7100_2008-05-07-0072
Description : 1.When loading uboot, we also erase configuration sector.
Detail      : 1. AR9100\u-boot\httpd\cgi.c
		 
Name        : Jimmy
Type        : Platform
Version     : 2.6.15-mips, build 0071
Tag         : AR7100_2008-05-02-0071
Description : 1.add accel-pptp package to improve pptp performance
		also, disable IP_GRE
Detail      : 1. platform/AR9100/kernels/mips-linux-2.6.15/drivers/net/Kconfig
		 platform/AR9100/kernels/mips-linux-2.6.15/drivers/net/Makefile
		 platform/AR9100/kernels/mips-linux-2.6.15/drivers/net/pptp.c
		 platform/AR9100/kernels/mips-linux-2.6.15/include/linux/if_pppox.h
		 platform/AR9100/kernels/mips-linux-2.6.15/arch/mips/configs/ap81_defconfig

Name        : Chun Lin
Type        : Platform
Version     : 2.6.15-mips, build 0070
Tag         : AR7100_2008-04-28-0070
Description : 1.update ap81_defconfig for build process issue
Detail      : AR9100\kernels\mips-linux-2.6.15\arch\mips\configs\ap81_defconfig

Name        : Chun Lin
Type        : Platform
Version     : 2.6.15-mips, build 0069
Tag         : AR7100_2008-04-14-0069
Description : 1.Only log 2 attack message to avoid log full.
Detail      : AR9100\kernels\mips-linux-2.6.15\net\ipv4\netfilter\ipt_LOG.c
			  

Name        : Albert Chen
Type        : Platform
Version     : 2.6.15-mips, build 0068
Tag         : AR7100_2008-04-07-0068
Description : 1.Fixed i2eye from lan side call out to wan netmeeting
Detail      : AR9100/kernels/mips-linux-2.6.15/net/ipv4/netfilter/ip_conntrack_h323_h225.c

	      
Name        : Albert Chen
Type        : Platform
Version     : 2.6.15-mips, build 0067
Tag         : AR7100_2008-04-07-0067
Description : 1.Fixed i2eye from lan side call out to wan netmeeting
		2.update ethernet driver for when auto-nego with linking part with 10Mbps issue
Detail      : AR9100/kernels/mips-linux-2.6.15/net/ipv4/netfilter/ip_conntrack_h323_h225.c
	      AR9100/driver/net/ag7100/ag7100.c
	      AR9100/driver/net/ag7100/ag7100.h
		
Name        : Jimmy Huang
Type        : Platform
Version     : 2.6.15-mips, build 0066
Tag         : AR7100_2008-03-28-0066
Description : Fixed bug for cdrouter sip 73,45,100,101, and whole cdrouter sip-alg passed
Detail      : AR9100/kernels/mips-linux-2.6.15/net/ipv4/netfilter/ip_conntrack_sip.c
	      AR9100/kernels/mips-linux-2.6.15/net/ipv4/netfilter/ip_nat_sip.c
	      AR9100/kernels/mips-linux-2.6.15/net/ipv4/netfilter/ip_nat_standalone.c
	      1. For sip 45, 
		- when receiving "Register", verify sip src port is equal to the port 
		in Via header, then adjust it
		- Add one condition check in ip_nat_standalone.c, to avoid sip 100 failed
	      2. Remove the postion of destroy_sip_sibling_or_exp() to the place when 
		receiving replying 200 OK for BYE

Name        : Jimmy Huang
Type        : Platform
Version     : 2.6.15-mips, build 0065 
Tag         : AR7100_2008-03-24-0065
Description : Fixed bug for cdrouter sip 61,62,63,71,72
Detail      : AR9100/kernels/mips-linux-2.6.15/net/ipv4/netfilter/ip_conntrack_sip.c
	      AR9100/kernels/mips-linux-2.6.15/net/ipv4/netfilter/ip_nat_standalone.c
	      AR9100/kernels/mips-linux-2.6.15/include/linux/netfilter_ipv4/ip_conntrack_sip.h
	      1. When receiving "400 Bad Request", terminate rtp session 
	      2. When receiving "CANCEL",  terminate rtp session 
	      3. When receiving out coming rtp conntrack (UDP), before add it to conntrack hash
		 in POSTROUTINE, if that is our expected sip rtp, check if REPLY dst port 
		 need to change or not, if does, modify it.

Name        : Jimmy Huang
Type        : Platform
Version     : 2.6.15-mips, build 0064
Tag         : AR7100_2008-03-14-0064
Description : Remove unused ppp compress function
Detail      : AR9100/kernels/mips-linux-2.6.15/arch/mips/configs/ap81_defconfig
	      In kernel menuconfig
	      Device Drivers
		=> Network Device Support
	      1. unset CONFIG_PPP_MULTILINK
	      2. unset CONFIG_PPP_FILTER
	      3. unset CONFIG_PPP_DEFLATE
	      4. unset CONFIG_PPP_BSDCOMP
	      5. remove CONFIG_ZLIB_DEFLATE (related with CONFIG_PPP_DEFLATE)

Name	    : Albert Chen
Type	    : Platform
Version     : 2.6.15-mips, build 0063
Tag         : AR7100_2008-03-05-0063
Description : Add gpio pin define for DIR-605
Detail      : /AR9100/u-boot/board/ar7100/ap81/ap81.c

Name        : Jimmy Huang
Type        : Platform
Version     : 2.6.15-mips, build 0062
Tag         : AR7100_2008-03-05-0062
Description : 1. add new function to monitor SIP method "BYE" to stop rtp session
                ,works for cdrouter SIP test pattern 60 (61 still not workable)
Detail      : AR9100\kernel\mips-linux-2.6.15\net\ipv4\netfilter\ip_conntrack_sip.c

Name        : Albert Chen
Type        : Platform
Version     : 2.6.15-mips, build 0061
Tag         : AR7100_2008-03-05-0061
Description : 1. Take debug information in gpio and net driver
Detail      : drivers/gpio_led/gpio_mod.c
	      drivers/net/ag7100/ag7100.c
	      drivers/net/ag7100/athrs26_phy.c


Name        : Albert Chen
Type        : Platform
Version     : 2.6.15-mips, build 0060
Tag         : AR7100_2008-03-05-0060
Description : 1. fixed kernel panic issue  when find conntrack in nattype
Detail      : AR9100\kernel\mips-linux-2.6.15\net\ipv4\netfilter\ipt_NATTYPE.c

Name        : Chun Lin
Type        : Platform
Version     : 2.6.15-mips, build 0059
Tag         : AR7100_2008-02-25-0059
Description : 1. change KERNEL_HWID_LEN=24 to check HWID when loading normal image 
Detail      : AR9100\u-boot\httpd\cgi.c
	      
Name        : Albert Chen
Type        : Platform
Version     : 2.6.15-mips, build 0058
Tag         : AR7100_2008-02-15-0058
Description : 1. Fixed attack detect and spi enable kernel log could not display in log page 
Detail      : \AR9100\kernel\mips-linux-2.6.15\net\ipv4\ip_conntrack_proto_tcp.c
	      \AR9100\kernel\mips-linux-2.6.15\net\ipv4\netfilter\ipt_LOG.c

	      
Name        : Chun Lin
Type        : Platform
Version     : 2.6.15-mips, build 0057
Tag         : AR7100_2008-02-15-0057
Description : 1. Fix HWID=NULL in backup mode. 
				The following browser has been verified: 
				1)Linux OS
					a)Firefox 	/0.10.1 /2.0.0.12
				2. Windows
					a)Firefox 	/2.0.0.7 /2.0.0.12
					b)Opera		/9.23
					c)IE		/6.0.2900.2180	/7.0.5730.11
Detail      : AR9100\u-boot\httpd\cgi.c
	      
Name        : Albert Chen
Type        : Platform
Version     : 2.6.15-mips, build 0056
Tag         : AR7100_2008-02-15-0056
Description : 1. Add spi feature 
Detail      : \AR9100\kernel\mips-linux-2.6.15\net\ipv4\ip_conntrack_proto_tcp.c
	      \AR9100\kernel\mips-linux-2.6.15\net\ipv4\sysctl_net_ipv4.c
	      \AR9100\kernel\mips-linux-2.6.15\include\net\tcp.h
	      
Name        : Albert Chen
Type        : Platform
Version     : 2.6.15-mips, build 0055
Tag         : AR7100_2008-01-30-0055
Description : 1. Add attack log to log message
Detail      : \AR9100\kernel\mips-linux-2.6.15\net\ipv4\netfilter\ipt_LOG.c

	      
Name        : Albert Chen
Type        : Platform
Version     : 2.6.15-mips, build 0054
Tag         : AR7100_2008-01-30-0054
Description : 1. Modify wan speed 10M and 100M
Detail      : \AR9100\driver\net\ag7100\ag7100.c
	      \AR9100\driver\net\ag7100\ag7100.h
	      \AR9100\driver\net\ag7100\athrs26_phy.h
	      \AR9100\driver\net\ag7100\athrs26_phy.c
	      
Name        : Albert Chen
Type        : Platform
Version     : 2.6.15-mips, build 0053
Tag         : AR7100_2008-01-18-0053
Description : 1. Add config for disable DFS
Detail      : \AR9100\config\config.ap81
	
Name        : ken chaing
Type        : Platform
Version     : 2.6.15-mips, build 0052
Tag         : AR7100_2008-01-11-0052
Description : 1. fixed nat TYPE =1 or 2 cannot work bug
Detail      : \kernels\mips-linux-2.6.15\net\ipv4\netfilter\ipt_NATTYPE.c
	
Name        : jimmy huang
Type        : Platform
Version     : 2.6.15-mips, build 0051
Tag         : AR7100_2008-01-10-0051
Description : 1. For FTP ALW pass through, set CONFIG_IP_NF_FTP as moule
Detail      : \kernels\mips-linux-2.6.15\arch\mips\configs\ap81_defconfig

Name        : Jackey chen
Type        : Platform
Version     : 2.6.15-mips, build 0050
Tag         : AR7100_2008-01-09-0050
Description : 1. To avoid setting device tun6to4 fail
Detail      : kernels/mips-linux-2.6.15/net/ipv6/sit.c

Name        : Chun Lin
Type        : Platform
Version     : 2.6.15-mips, build 0049
Tag         : AR7100_2007-01-04-0049
Description : 1.Modify igmp from V3 to V2
	      2. Fixed wireless led could not blink issue
Detail      : kernels\mips-linux-2.6.15\net\ipv4\igmp.c
	      kernels\mips-linux-2.6.15\arch\mips\ar7100\setup.c

Name        : Chun Lin
Type        : Platform
Version     : 2.6.15-mips, build 0048
Tag         : AR7100_2007-01-03-0048
Description : 1.Fix access_control doesn't log url message
Detail      : kernels\mips-linux-2.6.15\net\ipv4\netfilter\ipt_urlfilter.c

Name        : Stella Huang
Type        : Platform
Version     : 2.6.15-mips, build 0047
Tag         : AR7100_2007-12-19-0047
Description : 1.filter CHT IOT test redundant redirect packet
Detail      : kernels/mips-linux-2.6.15/net/ipv6/ndisc.c


Name        : Albert Chen
Type        : Platform
Version     : 2.6.15-mips, build 0046
Tag         : AR7100_2007-12-12-0046
Description : 1.update code 
Detail      : kernels/mips-linux-2.6.15/include/asm-mips/mach-ar7100/ar7100.h
	      
Name        : Albert Chen
Type        : Platform
Version     : 2.6.15-mips, build 0045
Tag         : AR7100_2007-12-12-0045
Description : 1.add wireless led blinking feature with HW
Detail      : kernels/mips-linux-2.6.15/arch/mips/ar7100/gpio.c
	      kernels/mips-linux-2.6.15/arch/mips/ar7100/setup.c
	      kernels/mips-linux-2.6.15/include/asm-mips/mach-ar7100/ar7100.h
	      kernels/mips-linux-2.6.15/include/asm-mips/mach-ar7100/ar9100.h
		  
Name        : Stella Huang
Type        : Platform
Version     : 2.6.15-mips, build 0044
Tag         : AR7100_2007-12-03-0044
Description : 1.add config_ipv6 flag and set accept_ra=0, forwarding=1
Detail      : 1. \kernels\mips-linux-2.6.15\net\core\neighbour.c
			  2. \kernels\mips-linux-2.6.15\net\ipv6\addrconf.c
			  
Name        : Stella Huang
Type        : Platform
Version     : 2.6.15-mips, build 0043
Tag         : AR7100_2007-12-03-0043
Description : 1.reduce random fluctuation in ra reachable time 
Detail      : 1. \kernels\mips-linux-2.6.15\net\core\neighbour.c

Name        : Ken Chiang
Type        : Platform
Version     : 2.6.15-mips, build 0042
Tag         : AR7100_2007-11-30-0042
Description : 1.fixed sip null point bug 
Detail	    : 1. \kernels\mips-linux-2.6.15\net\ipv4\netfilter\ip_conntrack_sip.c
			2. \kernels\mips-linux-2.6.15\net\ipv4\netfilter\ip_conntrack_core.c
	      
Name        : Albert Chen
Type        : Platform
Version     : 2.6.15-mips, build 0041
Tag         : AR7100_2007-11-28-0041
Description : 1.add ioctl item for get ethernet stats 
Detail	    : 1. drivers\net\ag7100\ag7100.c
	      2. drivers\vct\vct.h

Name        : Albert Chen
Type        : Platform
Version     : 2.6.15-mips, build 0040
Tag         : AR7100_2007-11-23-0040
Description : 1.Take off NF_BRIDGE_FILTER target 
Detail	    : 1. \kernel\mips-linux-2.6.15\arch\mips\configs\ap81_defconfig

Name        : Albert Chen
Type        : Platform
Version     : 2.6.15-mips, build 0039
Tag         : AR7100_2007-11-22-0039
Description : 1. Change define DLINK_ROUTER_LED_DEFINE instead DLINK_SOLUTION
Detail	    : 1. \u-boot\ar7100\broad\ar7100\ap81\ap81.c

	      
Name        : Albert Chen
Type        : Platform
Version     : 2.6.15-mips, build 0038
Tag         : AR7100_2007-11-21-0038
Description : 1. Follow Dlink led spec modify
Detail	    : 1. \kernels\mips-linux-2.6.15\arch\init\main.c
	      2. \u-boot\httpd\httpd.c
	      3. \u-boot\ar7100\broad\ar7100\ap81\ap81.c

Name        : Chun Lin
Type        : Platform
Version     : 2.6.15-mips, build 0037
Tag         : AR7100_2007-11-20-0037
Description : 1. add QoS and mangle in kernel
Detail	    : 1. \kernels\mips-linux-2.6.15\arch\mips\configs\ap81_defconfig

Name        : Chun Lin
Type        : Platform
Version     : 2.6.15-mips, build 0036
Tag         : AR7100_2007-11-14-0036
Description : 1. add iptables "CONFIG_IP_NF_TARGET_REJECT=y" target
Detail	    : 1. \kernels\mips-linux-2.6.15\arch\mips\configs\ap81_defconfig

Name        : Nick Chou
Type        : Platform
Version     : 2.6.15-mips, build 0035
Tag         : AR7100_2007-11-08-0035
Description : 1. Fixed that PPPoE cause kernel panic in BT test
Detail	    : 1. \kernels\mips-linux-2.6.15\net\ipv4\netfilter\ipt_NATTYPE.c
	
Name        : Nick Chou
Type        : Platform
Version     : 2.6.15-mips, build 0034
Tag         : AR7100_2007-10-29-0034
Description : 1. Modify nat type struct from 2.4 to 2.6
Detail	    : 1. \kernels\mips-linux-2.6.15\net\ipv4\netfilter\ipt_NATTYPE.c

Name        : Albert Chen
Type        : Platform
Version     : 2.6.15-mips, build 0033
Tag         : AR7100_2007-10-26-0033
Description : 1. Take off debug message
Detail	    : 1. \AR9100\driver\net\ag7100.c


Name        : Chun Lin
Type        : Platform
Version     : 2.6.15-mips, build 0032
Tag         : AR7100_2007-10-17-0032
Description : 1. Only check image HWID length=22 in backup mode
Detail	    : 1. \u-boot\httpd\cgi.c

Name        : Chun Lin
Type        : Platform
Version     : 2.6.15-mips, build 0031
Tag         : AR7100_2007-10-16-0031
Description : 1. fix Firefox fail when len!=447
Detail	    : 1. \u-boot\httpd\cgi.c

Name        : Chun Lin
Type        : Platform
Version     : 2.6.15-mips, build 0030
Tag         : AR7100_2007-10-15-0030
Description : 1. for pass VISTA IGD data, but may cause kernel panic in BT test
Detail	    : 1. \kernels\mips-linux-2.6.15\net\ipv4\netfilter\ipt_NATTYPE.c
 
Name        : Chun Lin
Type        : Platform
Version     : 2.6.15-mips, build 0029
Tag         : AR7100_2007-10-12-0029
Description : 1. fix backup mac is different from nvram mac 
			  2. fix led is always on or off when correct image is upgraded
			  3. fix led doesn't blink every 3 seconds when wrong image is upgraded
			  4. fix led doesn't blink every 1 seconds when correct image is upgraded
Detail	    : u-boot\cpu\mips\ar7100\ag7100.c
			  u-boot\httpd\cgi.c
			  u-boot\httpd\httpd.c
			  u-boot\httpd\uip.h

Name        : Albert
Type        : Platform
Version     : 2.6.15-mips, build 0028
Tag         : AR7100_2007-10-08-0028
Description : Add backup mode support different browser.(firefox,opera,ie)
Detail	    : u-boot/httpd/cgi.c
	      
	     
Name        : Albert
Type        : Platform
Version     : 2.6.15-mips, build 0026
Tag         : AR7100_2007-09-27-0026
Description : Fixed wan port speed do not work when system bootup.
Detail	    :doc/linux_version.c
	     drivers/net/ag7100/ag7100.c
	     drivers/net/ag7100/athrs26_phy.c


Name        : Albert
Type        : Platform
Version     : 2.6.15-mips, build 0025
Tag         : AR7100_2007-09-26-0025
Description : Fixed wan port speed do not work issue. 
Detail	    :doc/linux_version.c
	     drivers/net/ag7100/ag7100.c

Name        : Albert
Type        : Platform
Version     : 2.6.15-mips, build 0024
Tag         : AR7100_2007-09-14-0024
Description : update LSDK 7.1.2.27 
Detail	    :doc/linux_version.c
	     drivers/net/ag7100/ag7100.c
	     drivers/net/ag7100/athrs26_phy.c
	     drivers/net/ag7100/athrs26_phy.h
	     kernels/mips-linux-2.6.15/ath_version.mk
	     kernels/mips-linux-2.6.15/arch/mips/ar7100/setup.c
	     kernels/mips-linux-2.6.15/include/asm-mips/mach-ar7100/ar7100.h
	     kernels/mips-linux-2.6.15/include/linux/version.h

Name        : Ken Chiang
Type        : Platform
Version     : 2.6.15-mips, build 0023
Tag         : AR7100_2007-09-07-0023
Description : modify for triger port==incomeing portcan't work
Detail		:\AR9100\kernels\mips-linux-2.6.15\net\ipv4\netfilter\ipt_PORTTRIGGER.c	

Name        : Albert Chen
Type        : Platform
Version     : 2.6.15-mips, build 0022
Tag         : AR7100_2007-09-07-0022
Description : modify kernel panic system will reboot
Detail		:\AR9100\kernels\mips-linux-2.6.15\arch\mips\ar7100\setup.c	


Name        : Ken Chiang
Type        : Platform
Version     : 2.6.15-mips, build 0021
Tag         : AR7100_2007-08-31-0021
Description : modify for protocol type==all(any) sometime can't work if timer=0
Detail		:\AR9100\kernels\mips-linux-2.6.15\net\ipv4\netfilter\ipt_PORTTRIGGER.c	

Name        : Albert Chen
Type        : Platform
Version     : 2.6.15-mips, build 0020
Tag         : AR7100_2007-08-30-0020
Description : Conflict in linux_version.c


Name        : Albert Chen
Type        : Platform
Version     : 2.6.15-mips, build 0019
Tag         : AR7100_2007-08-30-0019
Description : fixed ether net auto-negotiation issue
Detail      : /AR9100/driver/net/ag7100/ag7100.c
              /AR9100/driver/net/ag7100/athrs26_phy.c

Name        : Chun Lin
Type        : Platform
Version     : 2.6.15-mips, build 0018
Tag         : AR7100_2007-08-30-0018
Description : fix url filter can't deny keyword 
	      AR9100\kernels\mips-linux-2.6.15\net\ipv4\netfilter\ipt_urlfilter.c
				
Name        : Albert Chen
Type        : Platform
Version     : 2.6.15-mips, build 0017
Tag         : AR7100_2007-08-28-0017
Description : update kernel for Atheros release 7.1.2.19 

Name        : Albert Chen
Type        : Platform
Version     : 2.6.15-mips, build 0016
Tag         : AR7100_2007-08-22-0016
Description : update kernel for Atheros release 7.1.2.12 RC1

Name        : Ken Chiang
Type        : Platform
Version     : 2.6.15-mips, build 0015
Tag         : AR7100_2007-08-21-0015
Description : modify for protocol type==all(any) can't work

Name        : Albert Chen
Type        : Platform
Version     : 2.6.15-mips, build 0014
Tag         : AR7100_2007-08-09-0014
Description : modify if load wrong image in normal code, the device will jump to backup mode

Name        : Albert Chen
Type        : Platform
Version     : 2.6.15-mips, build 0013
Tag         : AR7100_2007-08-03-0013
Description : update LSDK 7.1.2.10
	      
	      
Name        : Albert Chen
Type        : Platform
Version     : 2.6.15-mips, build 0012
Tag         : AR7100_2007-07-31-0012
Description : update defconfig config
	      /kernel/mips-2.6.15/arch/mips/config/ap81_defconfig
	      
Name        : Albert Chen
Type        : Platform
Version     : 2.6.15-mips, build 0011
Tag         : AR7100_2007-07-30-0011
Description : 1.release Atheros 7.1.1.12 beta 3
	      	      
Name        : Albert Chen
Type        : Platform
Version     : 2.6.15-mips, build 0009
Tag         : AR7100_2007-07-18-0009
Description : 1.Add backup mode version
	      2.Support opera,firefox and ie browser.
	      /u-boot/httpd/fsdata.c
	      /u-boot/httpd/cgi.c
	      
Name        : Albert Chen
Type        : Platform
Version     : 2.6.15-mips, build 0008
Tag         : AR7100_2007-07-13-0008
Description : 1.Change wps led blink behavior
	      /kernel/mips-linux-2.6.15/arch/mips/ar7100/gpio.c

Name        : Albert Chen
Type        : Platform
Version     : 2.6.15-mips, build 0007
Tag         : AR7100_2007-07-10-0007
Description : 1.Update u-boot support upgrade boot
	      2.decrease count down time
	      /u-boot/httpd/fsdata.c
	      /u-boot/httpd/cgi.c 

Name        : Albert Chen
Type        : Platform
Version     : 2.6.15-mips, build 0006
Tag         : AR7100_2007-07-04-0006
Description : 1.Update u-boot support upgrade boot
	      2.Support ALG rtsp 

Detail      : drivers/net/ag7100/ag7100.c
	      kernels/mips-linux-2.6.15/include/linux/netfilter_ipv4/ip_conntrack_rtsp.h
	      kernels/mips-linux-2.6.15/net/ipv4/netfilter/ip_conntrack_rtsp.c
	      kernels/mips-linux-2.6.15/net/ipv4/netfilter/ip_nat_rtsp.c
	      u-boot/httpd/cgi.c

Name        : Albert Chen
Type        : Platform
Version     : 2.6.15-mips, build 0005
Tag         : AR7100_2007-05-03-0005
Description : 1.Update new LSDK pb42-6.1.1.42.
Detail      :

Name        : Albert Chen
Type        : Platform
Version     : 2.6.15-mips, build 0005
Tag         : AR7100_2007-05-03-0005
Description : 1.Update new LSDK pb42-6.1.1.42.
Detail	    :

Name        : Albert Chen
Type        : Platform
Version     : 2.6.15-mips, build 0004
Tag         : AR7100_2007-05-03-0004
Description : 1.Fixed urlfilter crash issue.
	      2.Change kernel config for fix pptp and pppoe not connect issue
Detail	    : /kernel/mips-linux-2.6.15/arch/mips/config/pb42_defconfig
	      /kernel/mips-linux-2.6.15/net/ipv4/netfilter/ipt_urlfilter.c

Name        : Albert Chen
Type        : Platform
Version     : 2.6.15-mips, build 0003
Tag         : AR7100_2007-04-19-0003
Description : 1.Update /dev/gpio_ioctl device instead of /dev/gpio
	      2.Remove kernel/.config
Detail	    : /rootfs/setup_rootdir_ap71

*
Name        : Albert Chen
Type        : Platform
Version     : 2.6.15-mips, build 0002
Tag         : AR7100_2007-04-17-0002
Description : Update /dev/gpio_ioctl device instead of /dev/gpio
Detail	    : /drivers/gpio_led

Name        : 
Type        : Platform
Version     : 2.6.25-mips, build 0001
Tag         :
Description : First Version
*/
#endif
