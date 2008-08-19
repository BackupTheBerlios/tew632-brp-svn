include .config
include $(ENV_PATH)/platform/$(PLATFORM)/env.mk

export PLATFORM := $(PLATFORM)
export WL_PLATFORM := $(WL_PLATFORM)
export PRJ_PATH := $(ENV_PATH)
export FS_PATH := $(ENV_PATH)/rootfs/target

ifeq ($(WL_PLATFORM), AP81)	
include Makefile_ap81.inc
endif


export KERNEL_PATH := $(ENV_PATH)/platform/$(PLATFORM)/kernels/mips-linux-$(LSDK_KERNELVERSION)
export LOADER_PATH := $(ENV_PATH)/platform/$(PLATFORM)/redboot_cobra
export WL_PATH := $(ENV_PATH)/wireless/$(WL_PLATFORM)
export APPS_PATH := $(ENV_PATH)/apps
export IMG_PATH := $(ENV_PATH)/image
export TOOL_PATH := $(ENV_PATH)/tools
export WWW_PATH := $(ENV_PATH)/www/$(CONFIG_MODEL_NAME)
export PLATFORM_PATH := $(ENV_PATH)/platform/$(PLATFORM)
export PATH:=$(TOOL_PATH):${PATH}

export CONFIG_MODEL_NAME := $(CONFIG_MODEL_NAME)
export CONFIG_MODEL_NAME_NO_DASH := $(shell perl -w $(PRJ_PATH)/tools/split.pl $(CONFIG_MODEL_NAME))
export HARDWARE_ID := $(HARDWARE_ID)

export APPS_CROSS := $(APPS_CROSS)
export KRL_CROSS := $(KRL_CROSS)
export WL_CROSS := $(WL_CROSS)

export APPS_CFLAG := $(APPS_CFLAG)
export KRL_CFLAG := $(KRL_CFLAG)
export WL_CFLAG := $(WL_CFLAG)



all: build install

normal: normal_build install

normal_build:
#	$(MAKE) -C apps	clean;
	$(MAKE) -C apps;	

build:
	echo $(PATH)
	rm -fr $(IMG_PATH)
	mkdir -p $(IMG_PATH)
	$(MAKE) -C rootfs
	$(MAKE) -C platform 
	$(MAKE) -C apps	
	
install:
	$(MAKE) -C platform install
	$(MAKE) -C apps install
	$(MAKE) -C rootfs install
	@echo =================== Finish ===================

clean:
	$(MAKE) -C apps clean
	$(MAKE) -C platform clean
	$(MAKE) -C rootfs clean

conf mconf:
	$(MAKE) -C config
	@./config/$@ ./config/Config
	# kernel configure
	$(MAKE) apps$@

appsconf:
	$(MAKE) -C $(APPS_PATH) config

appsmconf:
	$(MAKE) -C $(APPS_PATH) menuconfig
		

menuconfig: mconf
# Default configurations
.config:
	cp config/defconfig $@
	$(MAKE) mconf
    
apps:
	$(MAKE) -C apps clean
	$(MAKE) -C apps 

#
### Generic rules
#
%: 
	[ ! -d $* ] || $(MAKE) -C $*

%-clean:
	[ ! -d $* ] || $(MAKE) -C $* clean

%-install:
	[ ! -d $* ] || $(MAKE) -C $* install
		
.PHONY: all clean install
.PHONY: apps 
.PHONY: dummy
