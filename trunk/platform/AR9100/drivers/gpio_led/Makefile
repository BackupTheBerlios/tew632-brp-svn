#
# Makefile for Atheros AR531X watchdog.
#
# Note! Dependencies are done automagically by 'make dep', which also
# removes any old dependencies. DON'T put your own dependencies here
# unless it's something special (ie not a .c file).
#
# Note 2! The CFLAGS definitions are now in the main makefile...

obj= .

obj-m			 += gpio_mod.o
ar531xgpio-objs		 := gpio.o
#export-objs		 := gpio.o
#list-multi		 := gpio.o

INCS += -I.

EXTRA_CFLAGS+=$(INCS) ${COPTS}

# release tag versioning
-include $(KERNELPATH)/ath_version.mk

-include $(TOPDIR)/Rules.make

STRIP=	${TOOLPREFIX}strip

ifndef MODPATH
MODPATH = ${KERNELPATH}/arch/mips/ar531x/RAMDISK/rootdir/lib/modules/${KERNELRELEASE}/
endif

all:
	$(MAKE)	-C ${KERNELPATH} SUBDIRS=$(shell pwd) modules

install: all
	$(STRIP) -S gpio.o
	cp gpio.o ${FS_PATH}/lib/modules/$(strip $(shell head -n 1 $(KERNELPATH)/Makefile | cut -f 2 -d'=')).$(strip $(shell head -n 2 $(KERNELPATH)/Makefile | tail -1 | cut -f 2 -d'=')).$(strip $(shell head -n 3 $(KERNELPATH)/Makefile | tail -1 | cut -f 2 -d'='))${EXTRAVERSION}/misc/.
clean:
	-rm -f *~ *.o *.ko *.mod.c
	-rm -f .version .*.o.flags .*.o.d .*.o.cmd .*.ko.cmd
