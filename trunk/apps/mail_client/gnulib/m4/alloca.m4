# alloca.m4 serial 6
dnl Copyright (C) 2002-2004, 2006 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

AC_DEFUN([gl_FUNC_ALLOCA],
[
  dnl Work around a bug of AC_EGREP_CPP in autoconf-2.57.
  AC_REQUIRE([AC_PROG_CPP])
  AC_REQUIRE([AC_PROG_EGREP])

  AC_REQUIRE([AC_FUNC_ALLOCA])
  if test $ac_cv_func_alloca_works = no; then
    gl_PREREQ_ALLOCA
  fi

  # Define an additional variable used in the Makefile substitution.
  if test $ac_cv_working_alloca_h = yes; then
    AC_CACHE_VAL([gl_cv_rpl_alloca], [
      AC_EGREP_CPP([Need own alloca], [
#if defined __GNUC__ || defined _AIX || defined _MSC_VER
          Need own alloca
#endif
        ], [gl_cv_rpl_alloca=yes], [gl_cv_rpl_alloca=no])
    ])
    if test $gl_cv_rpl_alloca = yes; then
      AC_DEFINE([HAVE_ALLOCA], 1,
        [Define to 1 if you have `alloca' after including <alloca.h>,
         a header that may be supplied by this distribution.])
      ALLOCA_H=alloca.h
    else
      ALLOCA_H=
    fi
  else
    ALLOCA_H=alloca.h
  fi
  AC_SUBST([ALLOCA_H])

  AC_DEFINE(HAVE_ALLOCA_H, 1,
    [Define HAVE_ALLOCA_H for backward compatibility with older code
     that includes <alloca.h> only if HAVE_ALLOCA_H is defined.])
])

# Prerequisites of lib/alloca.c.
# STACK_DIRECTION is already handled by AC_FUNC_ALLOCA.
AC_DEFUN([gl_PREREQ_ALLOCA], [:])
