#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
AC_INIT(bitfield-eca, 1.0.0, vitalie@ciubotaru.tokyo)
AC_CONFIG_SRCDIR([eca.c])
AC_CONFIG_HEADERS([config.h])

if test "x$prefix" = "xNONE" ; then
  prefix="/usr/local"
fi
if test "x$exec_prefix" = "xNONE" ; then
  exec_prefix=$prefix
fi
PREFIX=$prefix
AC_SUBST([PREFIX])
AC_SUBST([exec_prefix])

# Checks for programs.
AC_PROG_CC([gcc pcc icc])
AC_PROG_LN_S
AC_PROG_MAKE_SET

PKG_PROG_PKG_CONFIG([0.25])

PKG_CHECK_MODULES(libbitfield, libbitfield >= 1.0.0)

# Checks for header files.
AC_CHECK_HEADERS(limits.h stdlib.h string.h bitfield.h)

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T

# Checks for library functions.
AC_FUNC_MALLOC

# AC_CONFIG_FILES(Makefile)
AC_OUTPUT([Makefile] [tests/Makefile] [examples/Makefile] [man/Makefile])
