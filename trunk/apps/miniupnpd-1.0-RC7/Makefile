# $Id: Makefile,v 1.3 2007/10/02 06:49:17 NickChou Exp $
# http://miniupnp.free.fr/
# Author : Thomas Bernard
# for use with GNU Make
#include $(TOPDIR)/rules.mk
#CFLAGS = -Wall -O -D_GNU_SOURCE -g
#CFLAGS = -Wall -Os -D_GNU_SOURCE
#CC = mipsel-linux-gcc
#CC = /opt/ap71_tools/mips32k/bin/mips-linux-gcc
#CFLAGS = -Wall -O -D_GNU_SOURCE -g -DDEBUG
CFLAGS += -D_GNU_SOURCE
#LFLAGS += -L./../nvram -lnvram
RM = rm -f
INSTALL = install
#INCLUDE = ../nvram/
ifeq ($(PLATFORM),AthSDK_AP61) 
IPTABLESINC=../iptables/include
else
IPTABLESINC=../iptables_2_6/include
endif
BASEOBJS = miniupnpd.o upnphttp.o upnpdescgen.o upnpsoap.o \
           upnpreplyparse.o minixml.o \
		   upnpredirect.o getifaddr.o daemonize.o upnpglobalvars.o \
		   options.o upnppermissions.o minissdp.o

LNXOBJS = linux/getifstats.o linux/iptcrdr.o

ifeq ($(PLATFORM),AthSDK_AP61)
LIBS = ../iptables/libiptc/libiptc.a
else
LIBS = ../iptables_2_6/libiptc/libiptc.a
endif

TESTUPNPDESCGENOBJS = testupnpdescgen.o upnpdescgen.o

EXECUTABLES = miniupnpd testupnpdescgen

.PHONY:	all clean install depend

all:	$(EXECUTABLES)

clean:
	$(RM) $(BASEOBJS) $(LNXOBJS) $(EXECUTABLES) \
	testupnpdescgen.o
install:
	$(STRIP) ./miniupnpd
	cp ./miniupnpd  $(TARGET)/sbin
	@echo no install for now...

miniupnpd:	$(BASEOBJS) $(LNXOBJS) $(LIBS)
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

testupnpdescgen:	$(TESTUPNPDESCGENOBJS)

linux/iptcrdr.o: linux/iptcrdr.c
	$(CC) $(CFLAGS) -I$(IPTABLESINC) -c -o $@ $<

depend:	config.h
	makedepend -f$(MAKEFILE_LIST) -Y \
	$(BASEOBJS:.o=.c) $(LNXOBJS:.o=.c) $(TESTUPNPDESCGENOBJS:.o=.c) \
	2>/dev/null

config.h:	config.h.openwrt
	cp $< $@

# DO NOT DELETE

miniupnpd.o: config.h upnpglobalvars.h upnppermissions.h upnphttp.h
miniupnpd.o: upnpdescgen.h miniupnpdpath.h getifaddr.h daemonize.h upnpsoap.h
miniupnpd.o: options.h minissdp.h
upnphttp.o: upnphttp.h config.h upnpdescgen.h miniupnpdpath.h upnpsoap.h
upnpdescgen.o: upnpdescgen.h miniupnpdpath.h upnpglobalvars.h
upnpdescgen.o: upnppermissions.h config.h upnpdescstrings.h
upnpsoap.o: upnpglobalvars.h upnppermissions.h config.h upnphttp.h upnpsoap.h
upnpsoap.o: upnpreplyparse.h upnpredirect.h getifaddr.h getifstats.h
upnpreplyparse.o: upnpreplyparse.h minixml.h
minixml.o: minixml.h
upnpredirect.o: upnpredirect.h upnpglobalvars.h upnppermissions.h config.h
upnpredirect.o: openbsd/obsdrdr.h
getifaddr.o: getifaddr.h
daemonize.o: daemonize.h
upnpglobalvars.o: upnpglobalvars.h upnppermissions.h config.h
options.o: options.h upnppermissions.h config.h upnpglobalvars.h
upnppermissions.o: config.h upnppermissions.h
minissdp.o: config.h upnpdescstrings.h miniupnpdpath.h upnphttp.h
minissdp.o: upnpglobalvars.h upnppermissions.h minissdp.h
linux/getifstats.o: getifstats.h
linux/iptcrdr.o: linux/iptcrdr.h
testupnpdescgen.o: upnpdescgen.h
upnpdescgen.o: upnpdescgen.h miniupnpdpath.h upnpglobalvars.h
upnpdescgen.o: upnppermissions.h config.h upnpdescstrings.h
