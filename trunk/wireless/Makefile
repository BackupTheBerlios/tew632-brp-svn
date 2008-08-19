all: hal_build madwifi_build madwifi_tools wireless_tools wifi_simple_config
ifeq ($(WL_PLATFORM), AP81)
	@echo =================== WL_PATH=$(WL_PATH) ===================
	cp $(WL_PATH)/art_ap81.ko $(FS_PATH)/lib/modules/art_ap.ko    
endif
ifeq ($(WL_PLATFORM), AP83)
	@echo =================== WL_PATH=$(WL_PATH) ===================
	cp $(WL_PATH)/art_ap83.ko $(FS_PATH)/lib/modules/art_ap.ko
endif
hal_build:
ifeq ($(WL_PLATFORM), ap61)
	(. $(PLATFORM_PATH)/configs/config.$(AP_TYPE); \
	cd $(HAL)/linux && make TARGET=mipsisa32-be-elf \
	&& make TARGET=mipsisa32-be-elf release)
else
ifeq ($(WL_PLATFORM), AP94)
	(. $(PLATFORM_PATH)/configs/config.$(AP_TYPE); \
	cd $(WL_PATH)/802_11/common/lmac/hal/linux && make TARGET=mipsisa32-be-elf clean\
	&& make TARGET=mipsisa32-be-elf && make TARGET=mipsisa32-be-elf release)
else	
	(. $(PLATFORM_PATH)/configs/config.$(AP_TYPE); \
	cd $(HAL)/common/hal/linux && make TARGET=mipsisa32-be-elf clean \
	&& make TARGET=mipsisa32-be-elf && make TARGET=mipsisa32-be-elf release)
endif
endif

madwifi_build:
ifeq ($(WL_PLATFORM), ap61)
	(. $(PLATFORM_PATH)/configs/config.$(AP_TYPE); \
	cd $(WL_PATH)/802_11/madwifi/madwifi && make \
	&& sudo make install) 
else
	. $(PLATFORM_PATH)/configs/config.$(AP_TYPE);  \
	cd $(WL_PATH)/802_11/linux && \
	ln -sf ./../common ./common && \
	$(MAKEARCH) TARGET=$(MADWIFITARGET) clean && \
	$(MAKEARCH) TARGET=$(MADWIFITARGET) && \
	$(MAKEARCH) TARGET=$(MADWIFITARGET) install
endif

madwifi_tools:
ifeq ($(WL_PLATFORM), ap61)
	cd $(WL_PATH)/802_11/madwifi/dfs && sudo make clean \
	&& make radartool && sudo make BINDIR=$(FS_PATH)/bin radartool-install
	cd $(WL_PATH)/802_11/madwifi/madwifi/tools && make \
	&&  sudo cp -f wlanconfig $(FS_PATH)/sbin;
else
	cd $(WL_PATH)/802_11/linux/tools && make ath_tools #BINDIR=$(FS_PATH)/sbin install 
endif

wireless_tools:
ifeq ($(WL_PLATFORM), ap61)
	cd $(WL_PATH)/wireless_tools.26; make; \
	sudo cp -f libiw.so.26 $(FS_PATH)/lib; \
	sudo cp -f iwpriv $(FS_PATH)/sbin; \
	sudo cp -f iwconfig $(FS_PATH)/sbin; 
	cd $(WL_PATH)/802_11/madwifi/madwifi/tools && make \
	&&  sudo cp -f wlanconfig $(FS_PATH)/sbin;
else
	cd $(WL_PATH)/wireless_tools.28; make PREFIX=$(FS_PATH) all && make PREFIX=$(FS_PATH) install; 
endif

openssl:
	cd ../apps/wpa/wsc/lib/openssl-0.9.8a; \
	make clean; sudo make; sudo cp -f libssl.a $(TOOLPATH)/lib;  \
	sudo cp -f libcrypto.a $(TOOLPATH)/lib;

wifi_simple_config: openssl
	cd ../apps/wpa/wsc/src/linux; make clean; make; \
	sudo make PREFIX=$(FS_PATH)/sbin CONFIG_PATH=$(FS_PATH)/etc/wlan DEFAULT_CFG=$(FS_PATH)/etc/wlan/default install;							

clean:
ifeq ($(WL_PLATFORM), ap61)
	cd $(WL_PATH)/802_11/madwifi/madwifi && make clean
else
ifeq ($(WL_PLATFORM), AP94)
	cd $(WL_PATH)/802_11/linux && make clean
	cd $(WL_PATH)/802_11/if_ath_net80211 && make clean	
	cd $(WL_PATH)/802_11/common/lmac/hal/linux && make TARGET=mipsisa32-be-elf clean
else
	cd $(HAL)/linux && make TARGET=mipsisa32-be-elf clean
endif
endif

ifeq ($(WL_PLATFORM), ap61)
	cd $(WL_PATH)/wireless_tools.26; make realclean
	cd $(WL_PATH)/802_11/madwifi/madwifi/tools && make clean
else
	cd $(WL_PATH)/wireless_tools.28; make realclean
endif
	cd ../apps/wpa/wsc/lib/openssl-0.9.8a; make clean;	
	cd ../apps/wpa/wsc/src/linux; make clean;	
install:	
	
	
