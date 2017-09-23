#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
AC_INIT(eca, 1.0.0, vitalie@ciubotaru.tokyo)
AC_CONFIG_SRCDIR([eca.c])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([libeca.pc])

# Checks for programs.
AC_PROG_CC
AC_PROG_LN_S
AC_PROG_MAKE_SET

PKG_PROG_PKG_CONFIG([0.25])

PKG_CHECK_MODULES(bitfield, libbitfield >= 1.0.0)

# Checks for header files.
AC_CHECK_HEADERS(limits.h stdlib.h string.h bitfield.h)

# Checks for library functions.
AC_FUNC_MALLOC

# AC_CONFIG_FILES(Makefile)
AC_OUTPUT([Makefile] [tests/Makefile] [examples/Makefile] [man/Makefile])
