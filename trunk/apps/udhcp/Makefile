# udhcp makefile

DESTDIR     = $(TARGET)
prefix      = 
SBINDIR     = /sbin
USRSBINDIR  = $(DESTDIR)${prefix}/sbin
USRBINDIR   = $(DESTDIR)${prefix}/bin
USRSHAREDIR = $(DESTDIR)${prefix}/usr/share

# Uncomment this to get a shared binary. Call as udhcpd for the server,
# and udhcpc for the client
#COMBINED_BINARY=0

# Uncomment this for extra output and to compile with debugging symbols
#UDHCP_DEBUG=1

# Uncomment this to output messages to syslog, otherwise, messages go to stdout
CFLAGS += -DUDHCP_SYSLOG

#CROSS_COMPILE=arm-linux-gnu-
CC = $(CROSS_COMPILE)gcc
LD = $(CROSS_COMPILE)gcc
INSTALL = install

OBJS_SHARED = common.o options.o packet.o pidfile.o signalpipe.o socket.o
DHCPD_OBJS = dhcpd.o arpping.o files.o leases.o serverpacket.o static_leases.o 
DHCPC_OBJS = dhcpc.o clientpacket.o clientsocket.o script.o

ifdef COMBINED_BINARY
EXEC1 = udhcpd
OBJS1 = $(DHCPD_OBJS) $(DHCPC_OBJS) $(OBJS_SHARED) frontend.o
CFLAGS += -DCOMBINED_BINARY
else
EXEC1 = udhcpd
OBJS1 = $(DHCPD_OBJS) $(OBJS_SHARED)

EXEC2 = udhcpc
OBJS2 = $(DHCPC_OBJS) $(OBJS_SHARED)
endif

EXEC3 = dumpleases
OBJS3 = dumpleases.o

BOOT_PROGRAM = udhcpc
DAEMON = udhcpd
COMMAND = dumpleases

ifdef UDHCP_SYSLOG
CFLAGS += -DUDHCP_SYSLOG
endif

CFLAGS += -W -Wall -Wstrict-prototypes -D_GNU_SOURCE
## jimmy modified 20080428
#CFLAGS += -I./ -I$(TOP)/sutil/
CFLAGS += -I./ -I$(TOP)/sutil/ -I$(TOP)/nvram/
##----------------

ifeq ($(CONFIG_TC),y)
	CFLAGS +=-DCONFIG_TC
endif

LDFLAGS += -L$(TOP)/sutil -lsutil -L$(TOP)/nvram -lnvram

ifdef UDHCP_DEBUG
CFLAGS += -g -DUDHCP_DEBUG
STRIP=true
else
CFLAGS += -Os -fomit-frame-pointer
STRIP=$(CROSS_COMPILE)strip
endif

all: $(EXEC1) $(EXEC2) $(EXEC3)
	$(STRIP) --remove-section=.note --remove-section=.comment $(EXEC1) $(EXEC2) $(EXEC3)

$(OBJS1) $(OBJS2) $(OBJS3): *.h Makefile
$(EXEC1) $(EXEC2) $(EXEC3): Makefile

.c.o:
	$(CC) -c $(CFLAGS) $<
	
$(EXEC1): $(OBJS1)
	$(LD) $(LDFLAGS) $(OBJS1) -o $(EXEC1)

$(EXEC2): $(OBJS2)
	$(LD) $(LDFLAGS) $(OBJS2) -o $(EXEC2)

$(EXEC3): $(OBJS3)
	$(LD) $(LDFLAGS) $(OBJS3) -o $(EXEC3)


install: all
	mkdir -p $(USRSBINDIR) $(USRBINDIR) 
	$(INSTALL) -m 755 $(DAEMON) $(USRSBINDIR)
	$(STRIP)	$(USRSBINDIR)/$(DAEMON)
	$(INSTALL) -m 755 $(COMMAND) $(USRBINDIR)
	$(STRIP) $(USRBINDIR)/$(COMMAND)
ifdef COMBINED_BINARY
	ln -sf $(DAEMON) $(USRSBINDIR)/$(BOOT_PROGRAM)
else
	$(INSTALL) -m 755 $(BOOT_PROGRAM) $(USRBINDIR)
	$(STRIP) $(USRBINDIR)/$(BOOT_PROGRAM)
endif
	mkdir -p $(USRSHAREDIR)/udhcpc
	for name in russia-bound-nodns russia-bound-dns bound-dns bound-nodns deconfig nak renew script ; do \
		$(INSTALL) -m 755 samples/sample.$$name \
			$(USRSHAREDIR)/udhcpc/default.$$name ; \
	done
	cd $(FS_PATH)/etc ; ln -sf ../var/etc/resolv.conf resolv.conf
#	touch $(TARGET)/var/misc/udhcpd.leases
#	touch $(TARGET)/etc/udhcpd.conf
#	mkdir -p $(USRSHAREDIR)/man/man1
#	$(INSTALL) -m 644 dumpleases.1 $(USRSHAREDIR)/man/man1
#	mkdir -p $(USRSHAREDIR)/man/man5
#	$(INSTALL) -m 644 udhcpd.conf.5 $(USRSHAREDIR)/man/man5
#	mkdir -p $(USRSHAREDIR)/man/man8
#	$(INSTALL) -m 644 udhcpc.8 udhcpd.8 $(USRSHAREDIR)/man/man8

clean:
	-rm -f udhcpd udhcpc dumpleases *.o *~ core
