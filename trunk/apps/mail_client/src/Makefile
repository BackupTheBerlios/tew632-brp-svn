# Makefile.in generated by automake 1.9.6 from Makefile.am.
# src/Makefile.  Generated from Makefile.in by configure.

# Copyright (C) 1994, 1995, 1996, 1997, 1998, 1999, 2000, 2001, 2002,
# 2003, 2004, 2005  Free Software Foundation, Inc.
# This Makefile.in is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY, to the extent permitted by law; without
# even the implied warranty of MERCHANTABILITY or FITNESS FOR A
# PARTICULAR PURPOSE.

include ../../../.config

export CROSS_COMPILE := $(APPS_CROSS)
export APPS_PATH := $(ENV_PATH)/apps
export FS_PATH := $(ENV_PATH)/rootfs/target
export TARGET := $(FS_PATH)
export CC := $(CROSS_COMPILE)gcc
export AS := $(CROSS_COMPILE)as
export AR := $(CROSS_COMPILE)ar
export LD := $(CROSS_COMPILE)ld
export CCPP := $(CROSS_COMPILE)g++
export COMPILER := $(CROSS_COMPILE)g++
export STRIP := $(CROSS_COMPILE)strip
export SIZE := $(CROSS_COMPILE)size
export RANLIB := $(CROSS_COMPILE)ranlib
export TOP := $(APPS_PATH)

ETCDIR = $(TARGET)/etc/

CFLAGS  += -I. -I$(TOP)/nvram -I$(TOP)/sutil
LDFLAGS	+= -L-I$(TOP)/nvram -lnvram -L$(TOP)/sutil -lsutil
LIBS += -L$(TOP)/nvram -lnvram -L$(TOP)/sutil -lsutil

srcdir = .
top_srcdir = ..

pkgdatadir = $(datadir)/msmtp
pkglibdir = $(libdir)/msmtp
pkgincludedir = $(includedir)/msmtp
top_builddir = ..
am__cd = CDPATH="$${ZSH_VERSION+.}$(PATH_SEPARATOR)" && cd
INSTALL = /usr/bin/install -c
install_sh_DATA = $(install_sh) -c -m 644
install_sh_PROGRAM = $(install_sh) -c
install_sh_SCRIPT = $(install_sh) -c
INSTALL_HEADER = $(INSTALL_DATA)
transform = $(program_transform_name)
NORMAL_INSTALL = :
PRE_INSTALL = :
POST_INSTALL = :
NORMAL_UNINSTALL = :
PRE_UNINSTALL = :
POST_UNINSTALL = :
build_triplet = mips-linux-gnu
host_triplet = mips-linux-gnu
target_triplet = mips-linux-gnu
bin_PROGRAMS = msmtp$(EXEEXT)
subdir = src
DIST_COMMON = $(srcdir)/Makefile.am $(srcdir)/Makefile.in
ACLOCAL_M4 = $(top_srcdir)/aclocal.m4
am__aclocal_m4_deps = $(top_srcdir)/gnulib/m4/absolute-header.m4 \
	$(top_srcdir)/gnulib/m4/alloca.m4 \
	$(top_srcdir)/gnulib/m4/base64.m4 \
	$(top_srcdir)/gnulib/m4/eoverflow.m4 \
	$(top_srcdir)/gnulib/m4/extensions.m4 \
	$(top_srcdir)/gnulib/m4/getdelim.m4 \
	$(top_srcdir)/gnulib/m4/getline.m4 \
	$(top_srcdir)/gnulib/m4/getopt.m4 \
	$(top_srcdir)/gnulib/m4/getpass.m4 \
	$(top_srcdir)/gnulib/m4/gettext.m4 \
	$(top_srcdir)/gnulib/m4/gnulib-comp.m4 \
	$(top_srcdir)/gnulib/m4/hmac-md5.m4 \
	$(top_srcdir)/gnulib/m4/iconv.m4 \
	$(top_srcdir)/gnulib/m4/intmax_t.m4 \
	$(top_srcdir)/gnulib/m4/inttypes_h.m4 \
	$(top_srcdir)/gnulib/m4/lib-ld.m4 \
	$(top_srcdir)/gnulib/m4/lib-link.m4 \
	$(top_srcdir)/gnulib/m4/lib-prefix.m4 \
	$(top_srcdir)/gnulib/m4/lock.m4 \
	$(top_srcdir)/gnulib/m4/longdouble.m4 \
	$(top_srcdir)/gnulib/m4/longlong.m4 \
	$(top_srcdir)/gnulib/m4/md5.m4 \
	$(top_srcdir)/gnulib/m4/memxor.m4 \
	$(top_srcdir)/gnulib/m4/nls.m4 \
	$(top_srcdir)/gnulib/m4/onceonly_2_57.m4 \
	$(top_srcdir)/gnulib/m4/po.m4 \
	$(top_srcdir)/gnulib/m4/progtest.m4 \
	$(top_srcdir)/gnulib/m4/size_max.m4 \
	$(top_srcdir)/gnulib/m4/socklen.m4 \
	$(top_srcdir)/gnulib/m4/stdarg.m4 \
	$(top_srcdir)/gnulib/m4/stdbool.m4 \
	$(top_srcdir)/gnulib/m4/stdint.m4 \
	$(top_srcdir)/gnulib/m4/stdint_h.m4 \
	$(top_srcdir)/gnulib/m4/sys_socket_h.m4 \
	$(top_srcdir)/gnulib/m4/sysexits.m4 \
	$(top_srcdir)/gnulib/m4/ulonglong.m4 \
	$(top_srcdir)/gnulib/m4/unistd_h.m4 \
	$(top_srcdir)/gnulib/m4/vasnprintf.m4 \
	$(top_srcdir)/gnulib/m4/vasprintf.m4 \
	$(top_srcdir)/gnulib/m4/wchar_t.m4 \
	$(top_srcdir)/gnulib/m4/wint_t.m4 \
	$(top_srcdir)/gnulib/m4/xalloc.m4 \
	$(top_srcdir)/gnulib/m4/xsize.m4 \
	$(top_srcdir)/gnulib/m4/xvasprintf.m4 \
	$(top_srcdir)/configure.ac
am__configure_deps = $(am__aclocal_m4_deps) $(CONFIGURE_DEPENDENCIES) \
	$(ACLOCAL_M4)
mkinstalldirs = $(SHELL) $(top_srcdir)/mkinstalldirs
CONFIG_HEADER = $(top_builddir)/config.h
CONFIG_CLEAN_FILES =
am__installdirs = "$(DESTDIR)$(bindir)"
binPROGRAMS_INSTALL = $(INSTALL_PROGRAM)
PROGRAMS = $(bin_PROGRAMS)
am_msmtp_OBJECTS = conf.$(OBJEXT) list.$(OBJEXT) msmtp.$(OBJEXT) \
	net.$(OBJEXT) netrc.$(OBJEXT) smtp.$(OBJEXT) stream.$(OBJEXT) \
	tools.$(OBJEXT)
msmtp_OBJECTS = $(am_msmtp_OBJECTS)
DEFAULT_INCLUDES = -I. -I$(srcdir) -I$(top_builddir)
depcomp = $(SHELL) $(top_srcdir)/depcomp
am__depfiles_maybe = depfiles
COMPILE = $(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) \
	$(CPPFLAGS) $(AM_CFLAGS) $(CFLAGS)
CCLD = $(CC)
LINK = $(CCLD) $(AM_CFLAGS) $(CFLAGS) $(AM_LDFLAGS) $(LDFLAGS) -o $@
SOURCES = $(msmtp_SOURCES) $(EXTRA_msmtp_SOURCES)
DIST_SOURCES = $(msmtp_SOURCES) $(EXTRA_msmtp_SOURCES)
ETAGS = etags
CTAGS = ctags
DISTFILES = $(DIST_COMMON) $(DIST_SOURCES) $(TEXINFOS) $(EXTRA_DIST)
ABSOLUTE_STDINT_H = "///usr/include/stdint.h"
ACLOCAL = ${SHELL} $(ENV_PATH)/apps/mail_client/missing --run aclocal-1.9
ALLOCA = 
ALLOCA_H = alloca.h
AMDEP_FALSE = #
AMDEP_TRUE = 
AMTAR = ${SHELL} $(ENV_PATH)/apps/mail_client/missing --run tar
AUTOCONF = ${SHELL} $(ENV_PATH)/apps/mail_client/missing --run autoconf
AUTOHEADER = ${SHELL} $(ENV_PATH)/apps/mail_client/missing --run autoheader
AUTOMAKE = ${SHELL} $(ENV_PATH)/apps/mail_client/missing --run automake-1.9
AWK = gawk
BITSIZEOF_PTRDIFF_T = 32
BITSIZEOF_SIG_ATOMIC_T = 32
BITSIZEOF_SIZE_T = 32
BITSIZEOF_WCHAR_T = 32
BITSIZEOF_WINT_T = 32
CCDEPMODE = depmode=gcc3
CFLAGS += -g -O2
CPP = gcc -E
CPPFLAGS = 
CYGPATH_W = echo
DEFS = -DHAVE_CONFIG_H -DSYSCONFDIR=\"$(sysconfdir)\" \
	-DLOCALEDIR=\"$(localedir)\"
DEPDIR = .deps
ECHO_C = 
ECHO_N = -n
ECHO_T = 
EGREP = /bin/grep -E
EOVERFLOW = 
EXEEXT = 
GETOPT_H = 
GL_COND_LIBTOOL_FALSE = 
GL_COND_LIBTOOL_TRUE = #
GMSGFMT = :
GMSGFMT_015 = :
GREP = /bin/grep
HAVE_INTTYPES_H = 1
HAVE_LIBGNUTLS = no
HAVE_LIBGSASL = no
HAVE_LIBIDN = no
HAVE_LIBSSL = no
HAVE_LIBSSL32 = 
HAVE_LONG_LONG_INT = 1
HAVE_SIGNED_SIG_ATOMIC_T = 1
HAVE_SIGNED_WCHAR_T = 1
HAVE_SIGNED_WINT_T = 0
HAVE_STDINT_H = 1
HAVE_SYS_BITYPES_H = 1
HAVE_SYS_INTTYPES_H = 0
HAVE_SYS_TYPES_H = 1
HAVE_UNSIGNED_LONG_LONG_INT = 1
HAVE_WCHAR_H = 1
HAVE__BOOL = 1
INSTALL_DATA = ${INSTALL} -m 644
INSTALL_PROGRAM = ${INSTALL}
INSTALL_SCRIPT = ${INSTALL}
INSTALL_STRIP_PROGRAM = ${SHELL} $(install_sh) -c -s
INTLLIBS = 
INTL_MACOSX_LIBS = 
LIBGNUTLS = 
LIBGNU_LIBDEPS = 
LIBGNU_LTLIBDEPS = 
LIBGSASL = 
LIBICONV = -liconv
LIBIDN = 
LIBINTL = 
LIBOBJS = 
LIBSSL = 
LIBSSL32 = 
LTLIBGNUTLS = 
LTLIBGSASL = 
LTLIBICONV = -liconv
LTLIBIDN = 
LTLIBINTL = 
LTLIBOBJS = 
LTLIBSSL = 
LTLIBSSL32 = 
MAKEINFO = ${SHELL} $(ENV_PATH)/apps/mail_client/missing --run makeinfo
MSGFMT = :
MSGFMT_015 = :
MSGMERGE = :
OBJEXT = o
PACKAGE = msmtp
PACKAGE_BUGREPORT = marlam@marlam.de
PACKAGE_NAME = msmtp
PACKAGE_STRING = msmtp 1.4.9
PACKAGE_TARNAME = msmtp
PACKAGE_VERSION = 1.4.9
PATH_SEPARATOR = :
POSUB = po
PTRDIFF_T_SUFFIX = 
RANLIB = mips-linux-ranlib
SET_MAKE = 
SHELL = /bin/sh
SIG_ATOMIC_T_SUFFIX = 
SIZE_T_SUFFIX = u
STDBOOL_H = 
STDINT_H = stdint.h
STRIP = mips-linux-strip
SYSEXITS_H = 
SYS_SOCKET_H = 
UNISTD_H = 
USE_NLS = yes
VERSION = 1.4.9
WCHAR_T_SUFFIX = l
WINT_T_SUFFIX = u
XGETTEXT = :
XGETTEXT_015 = :
ac_ct_CC = gcc
am__fastdepCC_FALSE = #
am__fastdepCC_TRUE = 
am__include = include
am__leading_dot = .
am__quote = 
am__tar = ${AMTAR} chof - "$$tardir"
am__untar = ${AMTAR} xf -
bindir = ${exec_prefix}/sbin
build = i686-pc-linux-gnu
build_alias = 
build_cpu = i686
build_os = linux-gnu
build_vendor = pc
datadir = ${datarootdir}
datarootdir = ${prefix}/share
docdir = ${datarootdir}/doc/${PACKAGE_TARNAME}
dvidir = ${docdir}
exec_prefix = ${prefix}
gl_LIBOBJS =  asnprintf.o hmac-md5.o md5.o memxor.o printf-args.o printf-parse.o vasnprintf.o xmalloc.o
gl_LTLIBOBJS =  asnprintf.lo hmac-md5.lo md5.lo memxor.lo printf-args.lo printf-parse.lo vasnprintf.lo xmalloc.lo
host = mips-linux-gnu
host_alias = 
host_cpu = mips
host_os = linux-gnu
host_vendor = pc
htmldir = ${docdir}
includedir = ${prefix}/include
infodir = ${datarootdir}/info
install_sh = $(ENV_PATH)/apps/mail_client/install-sh
libdir = ${exec_prefix}/lib
libexecdir = ${exec_prefix}/libexec
localedir = $(datadir)/locale
localstatedir = ${prefix}/var
mandir = ${datarootdir}/man
mkdir_p = mkdir -p --
oldincludedir = /usr/include
pdfdir = ${docdir}
prefix = $(TARGET)
program_transform_name = s,x,x,
psdir = ${docdir}
sbindir = ${exec_prefix}/sbin
sharedstatedir = ${prefix}/com
sysconfdir = ${prefix}/etc
target = i686-pc-linux-gnu
target_alias = 
target_cpu = i686
target_os = linux-gnu
target_vendor = pc
tls_obj = 
msmtp_SOURCES = \
	conf.c conf.h \
	list.c list.h \
	msmtp.c \
	net.c net.h \
	netrc.c netrc.h \
	smtp.c smtp.h \
	stream.c stream.h \
	tools.c tools.h

msmtp_LDADD =  $(top_builddir)/gnulib/libgnu.a 
msmtp_DEPENDENCIES = 
EXTRA_msmtp_SOURCES = tls.c tls.h
AM_CPPFLAGS = -I$(top_srcdir)/gnulib
all: all-am

.SUFFIXES:
.SUFFIXES: .c .o .obj
$(srcdir)/Makefile.in:  $(srcdir)/Makefile.am  $(am__configure_deps)
	@for dep in $?; do \
	  case '$(am__configure_deps)' in \
	    *$$dep*) \
	      cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh \
		&& exit 0; \
	      exit 1;; \
	  esac; \
	done; \
	echo ' cd $(top_srcdir) && $(AUTOMAKE) --gnu  src/Makefile'; \
	cd $(top_srcdir) && \
	  $(AUTOMAKE) --gnu  src/Makefile
.PRECIOUS: Makefile
Makefile: $(srcdir)/Makefile.in $(top_builddir)/config.status
	@case '$?' in \
	  *config.status*) \
	    cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh;; \
	  *) \
	    echo ' cd $(top_builddir) && $(SHELL) ./config.status $(subdir)/$@ $(am__depfiles_maybe)'; \
	    cd $(top_builddir) && $(SHELL) ./config.status $(subdir)/$@ $(am__depfiles_maybe);; \
	esac;

$(top_builddir)/config.status: $(top_srcdir)/configure $(CONFIG_STATUS_DEPENDENCIES)
	cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh

$(top_srcdir)/configure:  $(am__configure_deps)
	cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh
$(ACLOCAL_M4):  $(am__aclocal_m4_deps)
	cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh
install-binPROGRAMS: $(bin_PROGRAMS)
	@$(NORMAL_INSTALL)
	test -z "$(bindir)" || $(mkdir_p) "$(DESTDIR)$(bindir)"
	@list='$(bin_PROGRAMS)'; for p in $$list; do \
	  p1=`echo $$p|sed 's/$(EXEEXT)$$//'`; \
	  if test -f $$p \
	  ; then \
	    f=`echo "$$p1" | sed 's,^.*/,,;$(transform);s/$$/$(EXEEXT)/'`; \
	   echo " $(INSTALL_PROGRAM_ENV) $(binPROGRAMS_INSTALL) '$$p' '$(DESTDIR)$(bindir)/$$f'"; \
	   $(INSTALL_PROGRAM_ENV) $(binPROGRAMS_INSTALL) "$$p" "$(DESTDIR)$(bindir)/$$f" || exit 1; \
	  else :; fi; \
	done

uninstall-binPROGRAMS:
	@$(NORMAL_UNINSTALL)
	@list='$(bin_PROGRAMS)'; for p in $$list; do \
	  f=`echo "$$p" | sed 's,^.*/,,;s/$(EXEEXT)$$//;$(transform);s/$$/$(EXEEXT)/'`; \
	  echo " rm -f '$(DESTDIR)$(bindir)/$$f'"; \
	  rm -f "$(DESTDIR)$(bindir)/$$f"; \
	done

clean-binPROGRAMS:
	-test -z "$(bin_PROGRAMS)" || rm -f $(bin_PROGRAMS)
msmtp$(EXEEXT): $(msmtp_OBJECTS) $(msmtp_DEPENDENCIES) 
	@rm -f msmtp$(EXEEXT)
	$(LINK) $(msmtp_LDFLAGS) $(msmtp_OBJECTS) $(msmtp_LDADD) $(LIBS)

mostlyclean-compile:
	-rm -f *.$(OBJEXT)

distclean-compile:
	-rm -f *.tab.c

include ./$(DEPDIR)/conf.Po
include ./$(DEPDIR)/list.Po
include ./$(DEPDIR)/msmtp.Po
include ./$(DEPDIR)/net.Po
include ./$(DEPDIR)/netrc.Po
include ./$(DEPDIR)/smtp.Po
include ./$(DEPDIR)/stream.Po
include ./$(DEPDIR)/tls.Po
include ./$(DEPDIR)/tools.Po

.c.o:
	if $(COMPILE) -MT $@ -MD -MP -MF "$(DEPDIR)/$*.Tpo" -c -o $@ $<; \
	then mv -f "$(DEPDIR)/$*.Tpo" "$(DEPDIR)/$*.Po"; else rm -f "$(DEPDIR)/$*.Tpo"; exit 1; fi
#	source='$<' object='$@' libtool=no \
#	DEPDIR=$(DEPDIR) $(CCDEPMODE) $(depcomp) \
#	$(COMPILE) -c $<

.c.obj:
	if $(COMPILE) -MT $@ -MD -MP -MF "$(DEPDIR)/$*.Tpo" -c -o $@ `$(CYGPATH_W) '$<'`; \
	then mv -f "$(DEPDIR)/$*.Tpo" "$(DEPDIR)/$*.Po"; else rm -f "$(DEPDIR)/$*.Tpo"; exit 1; fi
#	source='$<' object='$@' libtool=no \
#	DEPDIR=$(DEPDIR) $(CCDEPMODE) $(depcomp) \
#	$(COMPILE) -c `$(CYGPATH_W) '$<'`
uninstall-info-am:

ID: $(HEADERS) $(SOURCES) $(LISP) $(TAGS_FILES)
	list='$(SOURCES) $(HEADERS) $(LISP) $(TAGS_FILES)'; \
	unique=`for i in $$list; do \
	    if test -f "$$i"; then echo $$i; else echo $(srcdir)/$$i; fi; \
	  done | \
	  $(AWK) '    { files[$$0] = 1; } \
	       END { for (i in files) print i; }'`; \
	mkid -fID $$unique
tags: TAGS

TAGS:  $(HEADERS) $(SOURCES)  $(TAGS_DEPENDENCIES) \
		$(TAGS_FILES) $(LISP)
	tags=; \
	here=`pwd`; \
	list='$(SOURCES) $(HEADERS)  $(LISP) $(TAGS_FILES)'; \
	unique=`for i in $$list; do \
	    if test -f "$$i"; then echo $$i; else echo $(srcdir)/$$i; fi; \
	  done | \
	  $(AWK) '    { files[$$0] = 1; } \
	       END { for (i in files) print i; }'`; \
	if test -z "$(ETAGS_ARGS)$$tags$$unique"; then :; else \
	  test -n "$$unique" || unique=$$empty_fix; \
	  $(ETAGS) $(ETAGSFLAGS) $(AM_ETAGSFLAGS) $(ETAGS_ARGS) \
	    $$tags $$unique; \
	fi
ctags: CTAGS
CTAGS:  $(HEADERS) $(SOURCES)  $(TAGS_DEPENDENCIES) \
		$(TAGS_FILES) $(LISP)
	tags=; \
	here=`pwd`; \
	list='$(SOURCES) $(HEADERS)  $(LISP) $(TAGS_FILES)'; \
	unique=`for i in $$list; do \
	    if test -f "$$i"; then echo $$i; else echo $(srcdir)/$$i; fi; \
	  done | \
	  $(AWK) '    { files[$$0] = 1; } \
	       END { for (i in files) print i; }'`; \
	test -z "$(CTAGS_ARGS)$$tags$$unique" \
	  || $(CTAGS) $(CTAGSFLAGS) $(AM_CTAGSFLAGS) $(CTAGS_ARGS) \
	     $$tags $$unique

GTAGS:
	here=`$(am__cd) $(top_builddir) && pwd` \
	  && cd $(top_srcdir) \
	  && gtags -i $(GTAGS_ARGS) $$here

distclean-tags:
	-rm -f TAGS ID GTAGS GRTAGS GSYMS GPATH tags

distdir: $(DISTFILES)
	@srcdirstrip=`echo "$(srcdir)" | sed 's|.|.|g'`; \
	topsrcdirstrip=`echo "$(top_srcdir)" | sed 's|.|.|g'`; \
	list='$(DISTFILES)'; for file in $$list; do \
	  case $$file in \
	    $(srcdir)/*) file=`echo "$$file" | sed "s|^$$srcdirstrip/||"`;; \
	    $(top_srcdir)/*) file=`echo "$$file" | sed "s|^$$topsrcdirstrip/|$(top_builddir)/|"`;; \
	  esac; \
	  if test -f $$file || test -d $$file; then d=.; else d=$(srcdir); fi; \
	  dir=`echo "$$file" | sed -e 's,/[^/]*$$,,'`; \
	  if test "$$dir" != "$$file" && test "$$dir" != "."; then \
	    dir="/$$dir"; \
	    $(mkdir_p) "$(distdir)$$dir"; \
	  else \
	    dir=''; \
	  fi; \
	  if test -d $$d/$$file; then \
	    if test -d $(srcdir)/$$file && test $$d != $(srcdir); then \
	      cp -pR $(srcdir)/$$file $(distdir)$$dir || exit 1; \
	    fi; \
	    cp -pR $$d/$$file $(distdir)$$dir || exit 1; \
	  else \
	    test -f $(distdir)/$$file \
	    || cp -p $$d/$$file $(distdir)/$$file \
	    || exit 1; \
	  fi; \
	done
check-am: all-am
check: check-am
all-am: Makefile $(PROGRAMS)
	cp syslog.conf $(ETCDIR)
installdirs:
	for dir in "$(DESTDIR)$(bindir)"; do \
	  test -z "$$dir" || $(mkdir_p) "$$dir"; \
	done
install: install-am
install-exec: install-exec-am
install-data: install-data-am
uninstall: uninstall-am

install-am: all-am
	@$(MAKE) $(AM_MAKEFLAGS) install-exec-am install-data-am
	mips-linux-strip $(ENV_PATH)/rootfs/target/sbin/msmtp
installcheck: installcheck-am
install-strip:
	$(MAKE) $(AM_MAKEFLAGS) INSTALL_PROGRAM="$(INSTALL_STRIP_PROGRAM)" \
	  install_sh_PROGRAM="$(INSTALL_STRIP_PROGRAM)" INSTALL_STRIP_FLAG=-s \
	  `test -z '$(STRIP)' || \
	    echo "INSTALL_PROGRAM_ENV=STRIPPROG='$(STRIP)'"` install
mostlyclean-generic:

clean-generic:

distclean-generic:
	-test -z "$(CONFIG_CLEAN_FILES)" || rm -f $(CONFIG_CLEAN_FILES)

maintainer-clean-generic:
	@echo "This command is intended for maintainers to use"
	@echo "it deletes files that may require special tools to rebuild."
clean: clean-am

clean-am: clean-binPROGRAMS clean-generic mostlyclean-am

distclean: distclean-am
	-rm -rf ./$(DEPDIR)
	-rm -f Makefile
distclean-am: clean-am distclean-compile distclean-generic \
	distclean-tags

dvi: dvi-am

dvi-am:

html: html-am

info: info-am

info-am:

install-data-am:

install-exec-am: install-binPROGRAMS

install-info: install-info-am

install-man:

installcheck-am:

maintainer-clean: maintainer-clean-am
	-rm -rf ./$(DEPDIR)
	-rm -f Makefile
maintainer-clean-am: distclean-am maintainer-clean-generic

mostlyclean: mostlyclean-am

mostlyclean-am: mostlyclean-compile mostlyclean-generic

pdf: pdf-am

pdf-am:

ps: ps-am

ps-am:

uninstall-am: uninstall-binPROGRAMS uninstall-info-am

.PHONY: CTAGS GTAGS all all-am check check-am clean clean-binPROGRAMS \
	clean-generic ctags distclean distclean-compile \
	distclean-generic distclean-tags distdir dvi dvi-am html \
	html-am info info-am install install-am install-binPROGRAMS \
	install-data install-data-am install-exec install-exec-am \
	install-info install-info-am install-man install-strip \
	installcheck installcheck-am installdirs maintainer-clean \
	maintainer-clean-generic mostlyclean mostlyclean-compile \
	mostlyclean-generic pdf pdf-am ps ps-am tags uninstall \
	uninstall-am uninstall-binPROGRAMS uninstall-info-am

# Tell versions [3.59,3.63) of GNU make to not export all variables.
# Otherwise a system limit (for SysV at least) may be exceeded.
.NOEXPORT:
