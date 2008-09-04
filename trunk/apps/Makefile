include .config

export TARGET := $(FS_PATH)
export KERNEL_DIR := $(KERNEL_PATH)
export TOP := $(APPS_PATH)
export CFLAGS := $(APPS_CFLAG)

export CONFIG_MODEL_NAME := $(CONFIG_MODEL_NAME)
export CONFIG_HTTPD_PURE := $(CONFIG_HTTPD_PURE)
export CONFIG_XML_AGENT := $(CONFIG_XML_AGENT)
export CONFIG_AJAX := $(CONFIG_AJAX)
export IPROUTE2_IP := $(IPROUTE2_IP)
export CONFIG_TC := $(CONFIG_TC)
export CROSS_COMPILE = $(APPS_CROSS)
export CC := $(CROSS_COMPILE)gcc
export CXX := $(CROSS_COMPILE)g++
export AR := $(CROSS_COMPILE)ar
export AS := $(CROSS_COMPILE)as
export LD := $(CROSS_COMPILE)ld
export NM := $(CROSS_COMPILE)nm
export RANLIB := $(CROSS_COMPILE)ranlib
export STRIP := $(CROSS_COMPILE)strip
export SIZE := $(CROSS_COMPILE)size


#obj-y  += libplatform
obj-$(CONFIG_LIBVERSION) += libplatform

# BASE FEATURE
#obj-$(CONFIG_NVRAM) += nvram
#obj-$(CONFIG_SUTIL) += sutil
#obj-$(CONFIG_RC) += rc
#obj-$(CONFIG_TIMER) += timer
obj-$(CONFIG_BUSYBOX) += busybox-1.01

# Application
#obj-$(CONFIG_HTTPD) += httpd
obj-$(CONFIG_DNSMASQ) += dnsmasq-2.41
obj-$(CONFIG_DDNS) += noip2
obj-$(CONFIG_IPTABLES) += iptables_2_6

ifeq ($(CONFIG_UPNP),y)
obj-$(CONFIG_UPNP_ATH_MINIUPNPD_RC) += miniupnpd-1.0-RC7
endif

obj-$(CONFIG_UDHCP) += udhcp
obj-$(CONFIG_PPPD) += ppp
obj-$(CONFIG_RP_PPPoE) += rp-pppoe
obj-$(CONFIG_TFTPD) += tftpd
obj-$(CONFIG_NTP)   += ntpclient
#obj-$(CONFIG_GPIO)  += gpio
obj-$(CONFIG_MFORWARD)	+= igmpproxy
obj-$(CONFIG_BIGPOND) += bpalogin
#obj-$(CONFIG_PPTP_CLIENT) += accel-pptp-0.7.12
obj-$(CONFIG_L2TP_CLIENT) += rp-l2tp
obj-$(CONFIG_LLD2D) += lld2d
obj-$(CONFIG_ZEBRA) += zebra
obj-$(CONFIG_SMTP) += mail_client
obj-$(CONFIG_IP) += iproute2

#ifeq ($(CONFIG_WPS),y)
#obj-$(CONFIG_WL_ATH) += wps_ath
#endif

ifeq ($(CONFIG_SMTP),y)
#obj-$(CONFIG_MAILOS) += Mail-On-Schedule
endif

ifeq ($(CONFIG_IP_MATCH_3),y)
CFLAGS += -DIP_MATCH_3
endif

ifeq ($(CONFIG_IP_MATCH_4),y)
CFLAGS += -DIP_MATCH_4
endif


# Support Pure network or not
ifeq ($(CONFIG_HTTPD_PURE),y)
	CFLAGS +=-DPURE_NETWORK_ENABLE
endif

# Support OWERA or not
ifeq ($(CONFIG_OWERA),y)
	CFLAGS +=-DCONFIG_OWERA
endif

# Support Multiple PPPOE or not
ifeq ($(CONFIG_MULTIPLE_PPPoE),y)
	CFLAGS +=-DMPPPOE
endif

# Support Russia PPPOE or not
ifeq ($(CONFIG_RUSSIA_PPPoE),y)
	CFLAGS +=-DRPPPOE
endif

# Support NAT or not
ifeq ($(CONFIG_NAT_ENABLE),y)
	CFLAGS +=-DNAT_ENABLE
endif

# Support SPI or not
ifeq ($(CONFIG_SPI),y)
	CFLAGS +=-DSPI
endif

# Support Access Control or not
ifeq ($(CONFIG_ACCESS_CONTROL),y)
	CFLAGS +=-DACCESS_CONTROL
endif

# Support Port Forward Both or not
ifeq ($(CONFIG_PORT_FORWARD_BOTH),y)
	CFLAGS +=-DPORT_FORWARD_BOTH
endif

# Support Inbound Filter or not
ifeq ($(CONFIG_INBOUND_FILTER),y)
	CFLAGS +=-DINBOUND_FILTER
endif

# Support netbios for udhcpd or not
ifeq ($(CONFIG_UDHCPD_NETBIOS),y)
        CFLAGS +=-DUDHCPD_NETBIOS
endif

# Support unicast for udhcpc or not
ifeq ($(CONFIG_UDHCPC_UNICAST),y)
        CFLAGS +=-DUDHCPC_UNICAST
endif

## jimmy added 20080428
# Support Static Route option (33) for udhcpc or not
ifeq ($(CONFIG_UDHCPC_STATIC_ROUTE),y)
	CFLAGS += -DUDHCPC_STATIC_ROUTE
endif
### Albert added 20080526
# Support ip look up in status page
ifeq ($(CONFIG_IP_LOOKUP),y)
	CFLAGS += -DCONFIG_IP_LOOKUP
endif

# Support classess static route for udhcpc or not
ifeq ($(CONFIG_UDHCPC_CLASSLESS_STATIC_ROUTE),y)
	ifeq ($(CONFIG_RFC_UDHCPC_CLASSLESS_STATIC_ROUTE),y)
		CFLAGS +=-DUDHCPC_RFC_CLASSLESS_STATIC_ROUTE
	else
		CFLAGS +=-DUDHCPC_MS_CLASSLESS_STATIC_ROUTE
	endif
endif
##---------------------

# Support revoke for udhcpd or not
ifeq ($(CONFIG_UDHCPD_REVOKE),y)
        CFLAGS +=-DUDHCPD_REVOKE
endif

# Support always broadcast for udhcpd or not
ifeq ($(CONFIG_UDHCPD_ALWAYS_BROADCAST),y)
        CFLAGS +=-DUDHCPD_ALWAYS_BROADCAST
endif

# Support timer interval for ddns or not
ifeq ($(CONFIG_DDNS_TIME_INTERVAL),y)
        CFLAGS +=-DDDNS_TIME_INTERVAL
endif

# Support reservate wireless domain or not
ifeq ($(CONFIG_RESERVATE_WIRELESS_DOMAIN),y)
        CFLAGS +=-DRESERVATE_WIRELESS_DOMAIN
endif

#Support SNMP or not
ifeq ($(CONFIG_SNMP),y)
	CFLAGS +=-DCONFIG_SNMP
endif

#Support ZEBRA or not
ifeq ($(CONFIG_ZEBRA),y)
	CFLAGS +=-DCONFIG_ZEBRA
endif


# Support QoS or not
ifeq ($(CONFIG_QOS),y)
	CFLAGS +=-DQOS
endif

#Support WISH or not
ifeq ($(CONFIG_WISH),y)
	CFLAGS +=-DCONFIG_WISH
endif

#Support CHECKSUM or not
ifeq ($(CONFIG_SHOW_CHECKSUM),y)
	CFLAGS +=-DCONFIG_SHOW_CHECKSUM
endif

# Support different wireless solution for HTTPD
ifeq ($(CONFIG_WL_ATH),y)
        CFLAGS +=-DCONFIG_WL_ATH
endif
ifeq ($(CONFIG_WL_BCM),y)
        CFLAGS +=-DCONFIG_WL_BCM
endif
ifeq ($(CONFIG_WL_MVL),y)
        CFLAGS +=-DCONFIG_WL_MVL
endif

# support 802.11n or not
ifeq ($(CONFIG_WL_ATH_WITH_N),y)
	CFLAGS +=-DAR9100
endif

# support miniupnpd or not
ifeq ($(CONFIG_UPNP_ATH_MINIUPNPD_RC),y)
	CFLAGS +=-DUPNP_ATH_MINIUPNPD_RC
endif

# support httpd time out to login page 
ifeq ($(CONFIG_HTTP_TIMEOUT),y)
	CFLAGS +=-DHTTP_TIMEOUT
endif

CFLAGS +=-DCONFIG_NVRAM_SIZE=$(CONFIG_NVRAM_SIZE) -DCONFIG_FIREWALL_NUMBER=$(CONFIG_FIREWALL_NUMBER) -DCONFIG_MAC_FILTER_NUMBER=$(CONFIG_MAC_FILTER_NUMBER) -DCONFIG_APPLICATION_NUMBER=$(CONFIG_APPLICATION_NUMBER) -DCONFIG_PORT_FORWARD_NUMBER=$(CONFIG_PORT_FORWARD_NUMBER) -DCONFIG_VIRTUAL_SERVER_NUMBER=$(CONFIG_VIRTUAL_SERVER_NUMBER) -DCONFIG_URL_FILTER_NUMBER=$(CONFIG_URL_FILTER_NUMBER) -DCONFIG_SCHEDULE_NUMBER=$(CONFIG_SCHEDULE_NUMBER) -DCONFIG_STATIC_ROUTE_NUMBER=$(CONFIG_STATIC_ROUTE_NUMBER) -DCONFIG_BLOCK_SERVICE_NUMBER=$(CONFIG_BLOCK_SERVICE_NUMBER) -DCONFIG_TRUST_IP_NUMBER=$(CONFIG_TRUST_IP_NUMBER) -DCONFIG_DHCPD_RESERVATION_NUMBER=$(CONFIG_DHCPD_RESERVATION_NUMBER) -DCONFIG_MULTIPLE_ROUTING_NUMBER=$(CONFIG_MULTIPLE_ROUTING_NUMBER) -DCONFIG_QOS_NUMBER=$(CONFIG_QOS_NUMBER) -DCONFIG_INBOUND_FILTER_NUMBER=$(CONFIG_INBOUND_FILTER_NUMBER) -DCONFIG_ACCESS_CONTROL_NUMBER=$(CONFIG_ACCESS_CONTROL_NUMBER) -DCONFIG_SRC_MACHINE_NUMBER=$(CONFIG_SRC_MACHINE_NUMBER) -DCONFIG_UPLOAD_TIME=$(CONFIG_UPLOAD_TIME) -DCONFIG_REBOOT_TIME=$(CONFIG_REBOOT_TIME) -DCONFIG_RESTORE_TIME=$(CONFIG_RESTORE_TIME) -DCONFIG_RESTORE_WIRELESS_TIME=$(CONFIG_RESTORE_WIRELESS_TIME) -DCONFIG_RESET_TIME=$(CONFIG_RESET_TIME) -DCONFIG_UPLOAD_CERTIFICATION_TIME=$(CONFIG_UPLOAD_CERTIFICATION_TIME) -DCONFIG_LAN_IP_CHANGE_REBOOT_TIME=$(CONFIG_LAN_IP_CHANGE_REBOOT_TIME) -DCONFIG_SUPER_G_REBOOT_TIME=$(CONFIG_SUPER_G_REBOOT_TIME) -DCONFIG_UPGRADE_TIME=$(CONFIG_UPGRADE_TIME)


obj-clean := $(foreach obj,$(obj-y) $(obj-n),$(obj)-clean)
obj-install := $(foreach obj,$(obj-y),$(obj)-install)

all:

#ifeq ($(CONFIG_WL_ATH), y)
#	ln -sf wps_ath wpa
#	cp -f $(WWW_PATH)/bsp.h	./gpio/
#	cp -f $(WWW_PATH)/bsp.h	./rc/
#	cp -f ./rc/wlan_ath.c ./rc/wlan.c
#endif

	for i in $(obj-y); do \
		(cd $$i; make) || exit 1; \
	done

clean: $(obj-clean);
	$(MAKE) -C config clean	

install: $(obj-install)
	$(MAKE) -C $(APPS_PATH)/../www install

conf mconf:
	$(MAKE) -C config
	@./config/$@ ./config/Config

menuconfig: mconf


# Default configurations
.config:
	cp config/defconfig $@
	$(MAKE) mconf


#
## Generic rules
#

%:
	[ ! -d $* ] || $(MAKE) -C $*

%-clean:
	[ ! -d $* ] || $(MAKE) -C $* clean

%-install:
	[ ! -d $* ] || $(MAKE) -C $* install

$(obj-y) $(obj-n) $(obj-clean) $(obj-install): dummy

.PHONY: all clean install
.PHONY: conf mconf menuconfig
.PHONY: dummy
