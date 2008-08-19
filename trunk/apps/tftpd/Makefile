# Router rc Makefile
#

CFLAGS += -I./ -I$(TOP)/sutil/ -I$(TOP)/nvram/ -I$(APPS_PATH)/libplatform -D$(PLATFORM)
LDFLAGS += -L$(TOP)/nvram -lnvram -L$(TOP)/sutil -lsutil -L$(APPS_PATH)/libplatform -lversion

OBJS :=  sserver.o tftp.o 

all: tftpd

.c.o:
	$(CC) $(CFLAGS) -c $<
		

clean:
	rm -f *.o *~ tftpd .*.depend
	rm -f $(WWW_PATH)/*.o


install: tftpd
	install -d $(TARGET)/sbin
	install tftpd $(TARGET)/sbin
	$(STRIP) $(TARGET)/sbin/tftpd

tftpd: $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)
#	$(CC) -o $@ $(OBJS) $(CFLAGS)
