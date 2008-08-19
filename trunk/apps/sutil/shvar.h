/* For app.c */
#define DHCPD_CONF		"/var/etc/udhcpd.conf"
#define HTML_LEASES_FILE        "/var/misc/html.leases"
#define LEASES_FILE		"/var/misc/udhcpd.leases"
#define IGMPPROXY			"/var/etc/igmpproxy.conf"
#define SNMPV3_CONF_FILE	"/var/etc/snmpd.conf"
#define SNMPV3_AUTH_FILE	"/var/net-snmp/snmpd.conf"
#define UPNP_CONF_FILE		"/var/etc/miniupnpd.conf"
#define SMTP_CONF			"/var/etc/smtp.conf"
#define RC_FLAG_FILE		"/var/etc/rc_flag.conf"
#define IGMP_GROUP_FILE		"/var/tmp/igmp_group.conf"
#define DNS_QUERY_RESULT	"/var/tmp/dns_quesy_result"
#define INTERFACE_INFO		"/var/tmp/interface_info"
#define DOMAIN_INFO		"/var/tmp/domain_info"
#define DOMAIN_RECORDS		"/var/tmp/domain_records"
#define CLIENT_LIST_FILE        "/var/tmp/local_lan_ip"

#ifdef RADVD
#define RADVD_CONF_FILE		"/var/etc/radvd.conf"
#define LINK_LOCAL_INFO		"/var/etc/link_local_info"
#endif

#ifdef DHCPv6
#define DHCPD6_CONF_FILE        "/var/etc/dhcpd6.conf"
#define DHCPD6_LEASE_FILE       "/var/misc/dhcpd6.lease"
#define DHCPD6_PID_FILE         "/var/run/dhcpd6.pid"
#define DHCLIENT6_SCRIPT	"/etc/dhclient6.script"
#endif

#ifdef MRD_ENABLE
#define	MRD_CONF_FILE		"/var/etc/mrd.conf"
#endif

/* For gpio.c */
#define AP_RT_INFO		"/var/tmp/ap_rt_info"

/* For firewall.c */
#define FW_FILTER		"/var/tmp/fw_filter"
#define FW_NAT			"/var/tmp/fw_nat"
#define FW_MANGLE		"/var/tmp/fw_mangle"
#define HTTP_PORT		80	/* TCP */
#define L2TP_PORT		1701	/* UDP */
#define PPTP_PORT		1723	/* TCP */
#define ISAKMP_PORT	500		/* UDP */
#define IP_MULTICAST	"224.0.0.0/4"
#define IDENT_PORT               113      /* TCP */
#define IP_FORWARD	"/proc/sys/net/ipv4/ip_forward"
#define LAN_BRIDGE_INFO "/var/tmp/lanbrinfo"

#ifdef CONFIG_FIREWALL_NUMBER
#define MAX_FIREWALL_RULE_NUMBER		CONFIG_FIREWALL_NUMBER
#else
#define MAX_FIREWALL_RULE_NUMBER                20
#endif

#ifdef CONFIG_MAC_FILTER_NUMBER
#define MAX_MAC_FILTER_NUMBER			CONFIG_MAC_FILTER_NUMBER
#else
#define MAX_MAC_FILTER_NUMBER                   20
#endif

#ifdef CONFIG_APPLICATION_NUMBER
#define MAX_APPLICATION_RULE_NUMBER		CONFIG_APPLICATION_NUMBER
#else
#define MAX_APPLICATION_RULE_NUMBER             20
#endif

#ifdef CONFIG_PORT_FORWARD_NUMBER
#define MAX_PORT_FORWARDING_NUMBER		CONFIG_PORT_FORWARD_NUMBER
#else
#define MAX_PORT_FORWARDING_NUMBER              20
#endif

#ifdef CONFIG_VIRTUAL_SERVER_NUMBER
#define MAX_VIRTUAL_SERVER_NUMBER		CONFIG_VIRTUAL_SERVER_NUMBER
#else
#define MAX_VIRTUAL_SERVER_NUMBER               20
#endif

#ifdef CONFIG_URL_FILTER_NUMBER
#define MAX_URL_FILTER_NUMBER			CONFIG_URL_FILTER_NUMBER
#else
#define MAX_URL_FILTER_NUMBER                   20
#endif

#ifdef CONFIG_SCHEDULE_NUMBER
#define MAX_SCHEDULE_NUMBER			CONFIG_SCHEDULE_NUMBER
#else
#define MAX_SCHEDULE_NUMBER                     10
#endif

#ifdef CONFIG_STATIC_ROUTE_NUMBER
#define MAX_STATIC_ROUTING_NUMBER		CONFIG_STATIC_ROUTE_NUMBER
#else
#define MAX_STATIC_ROUTING_NUMBER               20
#endif

#ifdef CONFIG_BLOCK_SERVICE_NUMBER
#define MAX_BLOCK_SERVICE_NUMBER		CONFIG_BLOCK_SERVICE_NUMBER
#else
#define MAX_BLOCK_SERVICE_NUMBER                10
#endif

#ifdef CONFIG_TRUST_IP_NUMBER
#define MAX_TRUST_IP_NUMBER			CONFIG_TRUST_IP_NUMBER
#else
#define MAX_TRUST_IP_NUMBER                     20
#endif

#ifdef CONFIG_DHCPD_RESERVATION_NUMBER
#define MAX_DHCPD_RESERVATION_NUMBER		CONFIG_DHCPD_RESERVATION_NUMBER
#else
#define MAX_DHCPD_RESERVATION_NUMBER            25
#endif

#ifdef CONFIG_MULTIPLE_ROUTING_NUMBER
#define MAX_MULTIPLE_ROUTING_NUMBER		CONFIG_MULTIPLE_ROUTING_NUMBER
#else
#define MAX_MULTIPLE_ROUTING_NUMBER		20
#endif

#ifdef CONFIG_QOS_NUMBER
#define MAX_QOS_NUMBER				CONFIG_QOS_NUMBER
#else
#define MAX_QOS_NUMBER				20
#endif

#define MAX_WISH_NUMBER			25

#ifdef CONFIG_INBOUND_FILTER_NUMBER
#define MAX_INBOUND_FILTER_NUMBER		CONFIG_INBOUND_FILTER_NUMBER
#else
#define MAX_INBOUND_FILTER_NUMBER		24
#endif

#ifdef CONFIG_ACCESS_CONTROL_NUMBER
#define MAX_ACCESS_CONTROL_NUMBER		CONFIG_ACCESS_CONTROL_NUMBER
#else
#define MAX_ACCESS_CONTROL_NUMBER		15
#endif

#ifdef CONFIG_SRC_MACHINE_NUMBER
#define MAX_SRC_MACHINE_NUMBER			CONFIG_SRC_MACHINE_NUMBER
#else
#define MAX_SRC_MACHINE_NUMBER			8
#endif

/* For wan.c */
#define RESOLVFILE				"/var/etc/resolv.conf"
#ifdef RPPPOE
#define RUSSIA_PHY_RESOLVFILE	"/var/tmp/russia_phy_dns.conf"
#endif
#define DHCPC_SCRIPT				"/usr/share/udhcpc/default.bound"
#define DHCPC_DNS_SCRIPT		"/usr/share/udhcpc/default.bound-dns"
#define DHCPC_NODNS_SCRIPT		"/usr/share/udhcpc/default.bound-nodns"
#define PPP_OPTIONS 				"/var/etc/options"
#define CHAP_SECRETS				"/var/etc/chap-secrets"
#define PAP_SECRETS				"/var/etc/pap-secrets"
#define CHAP_REMOTE_NAME        	"CAMEO"

#define AVERAGE_BYTES                   "/var/tmp/average_bytes"
#define LAN_TX_BYTES                    "/var/tmp/lan_tx_bytes"
#define LAN_RX_BYTES                    "/var/tmp/lan_rx_bytes"
#define WAN_TX_BYTES                    "/var/tmp/wan_tx_bytes"
#define WAN_RX_BYTES                    "/var/tmp/wan_rx_bytes"
#define WLAN_TX_BYTES                    "/var/tmp/wlan_tx_bytes"
#define WLAN_RX_BYTES                    "/var/tmp/wlan_rx_bytes"
#define TX_BYTES                        "/var/tmp/tx_bytes"
#define RX_BYTES                        "/var/tmp/rx_bytes"

#ifdef MPPPOE
#define MAX_PPPOE_CONNECTION	5
#define PPP_GATEWAY_IP                  "/var/tmp/mpppoe_gw_ip"
#define PPP_WAN_IP                      "/var/tmp/ppp_wan_ip"
#define MULTIPLE_ROUTING                "/var/tmp/multiple_routing"
#define DEL_MPPPOE_GW			"/var/tmp/del_mpppoe_gw"
#define DNS_FILE_00			"/var/etc/resolve_00"
#define DNS_FILE_01                     "/var/etc/resolve_01"
#define DNS_FILE_02                     "/var/etc/resolve_02"
#define DNS_FILE_03                     "/var/etc/resolve_03"
#define DNS_FILE_04                     "/var/etc/resolve_04"
#define DNS_FINAL_FILE			"/var/etc/dns_final"
#define DNS_MPPPOE			"/var/tmp/dns_mpppoe"
#define PPP_IDLE_00			"/var/tmp/ppp_idle_00"
#define PPP_IDLE_01                     "/var/tmp/ppp_idle_01"
#define PPP_IDLE_02                     "/var/tmp/ppp_idle_02"
#define PPP_IDLE_03                     "/var/tmp/ppp_idle_03"
#define PPP_IDLE_04                     "/var/tmp/ppp_idle_04"
#define PPP_START_IDLE_00		"/var/tmp/ppp_start_idle_00"
#define PPP_START_IDLE_01               "/var/tmp/ppp_start_idle_01"
#define PPP_START_IDLE_02               "/var/tmp/ppp_start_idle_02"
#define PPP_START_IDLE_03               "/var/tmp/ppp_start_idle_03"
#define PPP_START_IDLE_04               "/var/tmp/ppp_start_idle_04"
#define PPP_RESET_00			"/var/tmp/ppp_reset_00"
#define PPP_RESET_01                    "/var/tmp/ppp_reset_01"
#define PPP_RESET_02                    "/var/tmp/ppp_reset_02"
#define PPP_RESET_03                    "/var/tmp/ppp_reset_03"
#define PPP_RESET_04                    "/var/tmp/ppp_reset_04"
#else
#define MAX_PPPOE_CONNECTION	1
#endif


#define L2TP_CONF					"/var/etc/l2tp.conf"
#define RC_PID					"/var/run/rc.pid"
#define WCND_PID				"/var/run/wcnd.pid"
#define PPTP_PID				"/var/run/ppp-pptp.pid"
#define L2TP_PID				"/var/run/l2tp.pid"
#define UPNP_PID			"/var/run/upnpd.pid"
#define GPIO_PID			"/var/run/gpio.pid"
#define HTTPD_PID			"/var/run/httpd.pid"
#define NVRAM_UPGRADE_PID	"/var/run/nvram_upgrade.pid"
#define WANTIMER_PID		"/var/run/wan_timer.pid"
#define WAN_MONITOR_PID		"/var/run/monitor.pid"
#define UDHCPD_PID			"/var/run/udhcpd.pid"
#define IGMPPROXY_PID		"/var/run/igmpproxy.pid"
#define TIMER_PID			"/var/run/timer.pid"
#define TRACEGW_PID			"/var/run/tracegw.pid"


/* For route */
#define ZEBRA_CONF	"/var/etc/zebra.conf"
#define RIPD_CONF	"/var/etc/ripd.conf"

#ifdef MPPPOE
#define ROUTING_INFO	"/var/etc/routing_info"
#else
#define ROUTING_INFO	"/var/etc/routing.txt"
#endif

/* wpa supplicant */
#define WPASUP_CONFIG			"/var/etc/wpa.conf"
#define WPASUP_TLS_CONFIG		"/var/etc/tls.conf"
#define WPASUP_TTLS_CONFIG		"/var/etc/ttls.conf"
#define WPASUP_PEAP_CONFIG		"/var/etc/peap.conf"


/* firmware upgrade */
#define FW_UPGRADE_FILE			"/var/firm/image.bin"
#define HWID_LEN				24

#ifdef ATHEROS_11N_DRIVER
#ifdef AR9100
#define SYS_KERNEL_START_ADDR		0xBF030000
#define SYS_KERNEL_MTDBLK               "/dev/mtdblock2"
#define SYS_KERNEL_MTD 			"/dev/mtd2"
#define IMG_LOWER_BOUND			3 * 1024 * 1024
#define IMG_UPPER_BOUND			4 * 1024 * 1024
#define FW_KERNEL_BUF_SIZE		0x100000 
#define SYS_ROOTFS_MTDBLK               "/dev/mtdblock3"
#define SYS_ROOTFS_MTD                  "/dev/mtd3"
#define FW_ROOTFS_BUF_SIZE		0x2B0000 
#define FW_BUF_SIZE			FW_KERNEL_BUF_SIZE + FW_ROOTFS_BUF_SIZE
#define SYS_CAL_MTDBLK               	"/dev/mtdblock4"
#define SYS_CAL_MTD 			"/dev/mtd4"
#define FW_CAL_BUF_SIZE			0x20000 
#define CAL_UPGRADE_ADDR		0xbf3e0000
#define ATH_MAC_OFFSET  		0x1120c 
#define SYS_BOOT_MTDBLK			"/dev/mtdblock0"
#define SYS_BOOT_MTD 			"/dev/mtd0"
#define BOOT_BUF_SIZE			0x20000 
#define SYS_BOOT_START_ADDR		0xBF000000
#else //AR9100
#define SYS_KERNEL_START_ADDR		0xBF050000
#define SYS_KERNEL_MTDBLK               "/dev/mtdblock2"
#define SYS_KERNEL_MTD 			"/dev/mtd2"
#define IMG_LOWER_BOUND			5 * 512 * 1024
#define IMG_UPPER_BOUND			4 * 1024 * 1024
#define FW_KERNEL_BUF_SIZE		0x100000 
#define SYS_ROOTFS_MTDBLK               "/dev/mtdblock3"
#define SYS_ROOTFS_MTD                  "/dev/mtd3"
#define FW_ROOTFS_BUF_SIZE		0x200000 
#define FW_BUF_SIZE			FW_KERNEL_BUF_SIZE + FW_ROOTFS_BUF_SIZE
#define SYS_CAL_MTDBLK               "/dev/mtdblock6"
#define SYS_CAL_MTD 			"/dev/mtd/6"
#define FW_CAL_BUF_SIZE			0x10000 
#define CAL_UPGRADE_ADDR		0xBF4f0000
#endif //AR9100

#else //#ifdef ATHEROS_11N_DRIVER

#define SYS_KERNEL_START_ADDR		0xbfc40000
#define SYS_KERNEL_MTDBLK               "/dev/mtdblock/2"
#define SYS_KERNEL_MTD                  "/dev/mtd/2"
#define IMG_LOWER_BOUND                 2 * 1024 * 1024

#ifndef MPPPOE
#define IMG_UPPER_BOUND			4 * 1024 * 1024
#else //#ifndef MPPPOE
#define IMG_UPPER_BOUND                 3 * 1024 * 1024			
#endif //#ifndef MPPPOE

#define FW_KERNEL_BUF_SIZE		0x90000 
#define SYS_ROOTFS_MTDBLK               "/dev/mtdblock/3"
#define SYS_ROOTFS_MTD                  "/dev/mtd/3"
#define FW_ROOTFS_BUF_SIZE              0x280000
#define FW_BUF_SIZE			FW_KERNEL_BUF_SIZE + FW_ROOTFS_BUF_SIZE
#define SYS_CAL_MTDBLK               	"/dev/mtdblock/5"
#define SYS_CAL_MTD 			"/dev/mtd/5"
#define FW_CAL_BUF_SIZE			0x10000 
#define CAL_UPGRADE_ADDR		0xbfff0000
#define ATH_MAC_OFFSET  		0x132 
#define SYS_BOOT_MTDBLK			"/dev/mtdblock/0"
#define SYS_BOOT_MTD 			"/dev/mtd/0"
#define BOOT_BUF_SIZE			0x30000 
#define SYS_BOOT_START_ADDR		0xbfc00000

#endif //#ifdef ATHEROS_11N_DRIVER

/* nvram tmp */
#define NVRAM_UPGRADE_TMP	"/var/tmp/nvram.tmp"
#define NVRAM_CONFIG_TMP		"/var/tmp/nvram.bin"

/* SSL Cer */
#define CA_CERTIFICATION		"/var/tmp/ca.cer"
#define CLIENT_CERTIFICATION	"/var/tmp/client.cer"
#define PRIVATE_KEY				"/var/tmp/pkey.pfx"
#define CA_NVRAM_TAG			"ca"
#define CLIENT_NVRAM_TAG		"cl"
#define PRIVATE_TAG         		"pk"

/* Wlan.c */
#ifdef MVL8361
#define WLAN_DRIVER_FILE	"ap8x.o"
#elif defined BCM5352
#define WLAN_DRIVER_FILE	"wl.o"
#endif

#ifdef KERNEL_2_6_15
#define GPIO_DRIVER_PATH	"/lib/modules/2.6.15/net/gpio_mod.ko"
#define WPS_LED_GPIO_DRIVER_PATH "/lib/modules/2.6.15/net/ar531xgpio.o"	
#else
#define GPIO_DRIVER_PATH	"/lib/modules/2.4.25-LSDK-5.2.0.47/misc/ar531x-gpio.o"
#define WPS_LED_GPIO_DRIVER_PATH "/lib/modules/2.4.25-LSDK-5.2.0.47/misc/ar531xgpio.o"	
#endif

#define WLAN_EAP_CONFIG_FILE    "/etc/hostapd.conf"


/* Httpd server page Count Down Value */
#ifdef CONFIG_UPLOAD_TIME
#define UPLOAD_COUNT_DOWN			core_itoa(CONFIG_UPLOAD_TIME)
#else
#define UPLOAD_COUNT_DOWN			"120"
#endif

#ifdef CONFIG_REBOOT_TIME
#define REBOOT_COUNT_DOWN			core_itoa(CONFIG_REBOOT_TIME)
#else
#define REBOOT_COUNT_DOWN			"60"
#endif

#ifdef CONFIG_RESTORE_TIME
#define RESTORE_COUNT_DOWN			core_itoa(CONFIG_RESTORE_TIME)
#else
#define RESTORE_COUNT_DOWN			"70"
#endif

#ifdef CONFIG_RESTORE_WIRELESS_TIME
#define RESTORE_WIRELESS_COUNT_DOWN		core_itoa(CONFIG_RESTORE_WIRELESS_TIME)
#else
#define RESTORE_WIRELESS_COUNT_DOWN		"30"
#endif

#ifdef CONFIG_RESET_TIME
#define RESET_COUNT_DOWN			core_itoa(CONFIG_RESET_TIME)
#else
#define RESET_COUNT_DOWN			"3"
#endif

#ifdef CONFIG_UPLOAD_CERTIFICATION_TIME
#define UPLOAD_CERTIFICATION_COUNT_DOWN		core_itoa(CONFIG_UPLOAD_CERTIFICATION_TIME)
#else
#define UPLOAD_CERTIFICATION_COUNT_DOWN		"3"
#endif

#ifdef CONFIG_LAN_IP_CHANGE_REBOOT_TIME
#define LANIP_CHANGED_REBOOT_COUNT_DOWN		core_itoa(CONFIG_LAN_IP_CHANGE_REBOOT_TIME)
#else
#define LANIP_CHANGED_REBOOT_COUNT_DOWN		"60"
#endif

#ifdef CONFIG_SUPER_G_REBOOT_TIME
#define SUPERG_DOMAIN_CHANGED_REBOOT_COUNT_DOWN	core_itoa(CONFIG_SUPER_G_REBOOT_TIME)
#else
#define SUPERG_DOMAIN_CHANGED_REBOOT_COUNT_DOWN "70"
#endif

#ifdef CONFIG_UPGRADE_TIME
#define UPGRADE_COUNT_DOWN			core_itoa(CONFIG_UPGRADE_TIME)
#else
#define UPGRADE_COUNT_DOWN			"140"
#endif

/*for smtp.c*/
#define LOG_FILE     "/var/log/FW_log"
#define LOG_FILE_HTTP "/var/log/messages"
#define LOG_FILE_FULL	"/var/log/messages_full"
#define LOG_FILE_BAK "/var/log/messages_bak"
/* ken modify to fixed log full SIZE IS OVER UI log page*/
#define LOG_MAX_SIZE	20 /*KB*/

/* Wlan.c */
#define WLAN_DRIVER_PATH    "/lib/modules/2.4.25-LSDK-5.2.0.47/net/wlan.o"
#define HOSTAPD_DUMP_FILE_0   "/tmp/hostapd.dump.0.0"
#define HOSTAPD_DUMP_FILE_1   "/tmp/hostapd.dump.0.1"
#define HOSTAPD_DUMP_FILE_2   "/tmp/hostapd.dump.0.2"
#define HOSTAPD_DUMP_FILE_3   "/tmp/hostapd.dump.0.3"
#define HOSTAPD_TMP_CONFIG_0  "/tmp/hostapd.conf.0.0"
#define HOSTAPD_TMP_CONFIG_1  "/tmp/hostapd.conf.0.1"
#define HOSTAPD_TMP_CONFIG_2  "/tmp/hostapd.conf.0.2"
#define HOSTAPD_TMP_CONFIG_3  "/tmp/hostapd.conf.0.3"
#define DHCPD_REVOKE_FILE     "/var/tmp/dhcp_revoke"

#ifdef CONFIG_WL_ATH
#define AP_SCAN_LIST	      "/var/tmp/ap_scan_list"
#endif

