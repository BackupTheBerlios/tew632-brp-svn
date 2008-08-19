export ENETDIR=$(KERNEL_PATH)/../../drivers/net/ag7100/
export GPIODIR=$(KERNEL_PATH)/../../drivers/gpio_led/
export MODULEPATH=$(FS_PATH)/lib/modules/2.6.15/net 

#
# This is the specific makefile for the pb42 board.  It has dependancies for both
# the "common" build and the "jffs2" build.  This is unique for each board type, and
# must be configured for each board.
#

#pb44_build: common_build madwifi_build $(BUILD_TYPE)_build

#common_build: check_tftp rootfs_prep toolchain_build kernel_build \
		kernel_info enet_build busybox_build hostapd wpa_supplicant sar

all: gpio_build
#all: enet_build 
#
# Unique rules for the ag7100 PHY with the ar7100 (Hydra)  board
#

gpio_build: 
	cd $(GPIODIR) 
	$(MAKE) -C $(KERNEL_PATH) SUBDIRS=$(GPIODIR) modules
	test -d $(MODULEPATH) || mkdir -p $(MODULEPATH)
	cp $(GPIODIR)/gpio_mod.ko $(MODULEPATH)

clean:
	cd $(GPIODIR) && rm -f *.o *.ko *.mod.*
