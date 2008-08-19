# www Makefile
#
# Copyright 2005, CAMEO Corporation 
# All Rights Reserved.

include $(APPS_PATH)/.config
INSTALLDIR = $(FS_PATH)

ifeq ($(CONFIG_TEST_PAGE),y)
	WWW_INSTALL += install-test-page
endif

ifeq ($(CONFIG_WWW),y)
	WWW_INSTALL += install-www
endif

all: 

clean:

install: $(WWW_INSTALL)

install-www: 
	mkdir -p $(INSTALLDIR)/www
	cp -R ./$(CONFIG_MODEL_NAME)/www/* $(INSTALLDIR)/www
ifeq ($(CONFIG_RUSSIA_WIZARD_PAGES),y)
	mv $(INSTALLDIR)/www/wizard3.russia.asp $(INSTALLDIR)/www/wizard3.asp
else
	rm -f $(INSTALLDIR)/www/wizard3.russia.asp
	rm -f $(INSTALLDIR)/www/wizard_russia1.asp
	rm -f $(INSTALLDIR)/www/wizard_russia2.asp
	rm -f $(INSTALLDIR)/www/wizard_russia3.asp
	rm -f $(INSTALLDIR)/www/wizard_russia4.asp
endif
	rm -fr $(INSTALLDIR)/www/CVS


install-test-page:
	mkdir -p $(INSTALLDIR)/www
	cp -R Test-Page/* $(INSTALLDIR)/www
	rm -fr $(INSTALLDIR)/www/CVS
