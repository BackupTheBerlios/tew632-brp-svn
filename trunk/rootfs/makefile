
all: mkfs

mkfs:
	rm -rf target
	tar -jxf ../platform/AR9100/rootfs_ap81.tar.bz2

install:
	install -d $(IMG_PATH)

	rm -rf $(FS_PATH)/man/
	$(APPS_CROSS)strip $(FS_PATH)/bin/*
	$(APPS_CROSS)strip $(FS_PATH)/lib/*
	$(APPS_CROSS)strip $(FS_PATH)/sbin/*
	cp $(KERNEL_PATH)/arch/mips/boot/vmlinux.* /$(IMG_PATH)/
	sudo $(TOOL_PATH)/../tools/mkuImage.sh $(KERNEL_PATH) $(IMG_PATH)
	sudo $(TOOL_PATH)/../tools/release_rootfs.sh $(AP_TYPE)
	sudo $(TOOL_PATH)/../tools/release_image.sh $(CONFIG_MODEL_NAME)_$(AP_TYPE)_			

clean:
	rm -fr target 
	rm -fr tmp
	rm -fr $(IMG_PATH)
	
