# Copyright (C) 2004-2012, 2014  Internet Systems Consortium, Inc. ("ISC")
# Copyright (C) 1998-2003  Internet Software Consortium.
#
# Permission to use, copy, modify, and/or distribute this software for any
# purpose with or without fee is hereby granted, provided that the above
# copyright notice and this permission notice appear in all copies.
#
# THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH
# REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
# AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,
# INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
# LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE
# OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
# PERFORMANCE OF THIS SOFTWARE.

# $Id: Makefile.in,v 1.145 2011/02/03 05:41:53 marka Exp $

srcdir =	.

top_srcdir =	../..

# Copyright (C) 2004, 2005, 2007, 2012  Internet Systems Consortium, Inc. ("ISC")
# Copyright (C) 1999-2001  Internet Software Consortium.
#
# Permission to use, copy, modify, and/or distribute this software for any
# purpose with or without fee is hereby granted, provided that the above
# copyright notice and this permission notice appear in all copies.
#
# THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH
# REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
# AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,
# INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
# LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE
# OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
# PERFORMANCE OF THIS SOFTWARE.

# $Id: includes.in,v 1.21 2007/06/19 23:47:24 tbox Exp $

# Search for machine-generated header files in the build tree,
# and for normal headers in the source tree (${top_srcdir}).
# We only need to look in OS-specific subdirectories for the
# latter case, because there are no machine-generated OS-specific
# headers.

ISC_INCLUDES = -I/Users/holzschu/src/Xcode_iPad/network_ios/originalSources/bind9-57.2/bind9/lib/isc/include \
	-I${top_srcdir}/lib/isc \
	-I${top_srcdir}/lib/isc/include \
	-I${top_srcdir}/lib/isc/unix/include \
	-I${top_srcdir}/lib/isc/pthreads/include \
	-I${top_srcdir}/lib/isc/noatomic/include

ISCCC_INCLUDES = -I/Users/holzschu/src/Xcode_iPad/network_ios/originalSources/bind9-57.2/bind9/lib/isccc/include \
       -I${top_srcdir}/lib/isccc/include

ISCCFG_INCLUDES = -I/Users/holzschu/src/Xcode_iPad/network_ios/originalSources/bind9-57.2/bind9/lib/isccfg/include \
       -I${top_srcdir}/lib/isccfg/include

DNS_INCLUDES = -I/Users/holzschu/src/Xcode_iPad/network_ios/originalSources/bind9-57.2/bind9/lib/dns/include \
	-I${top_srcdir}/lib/dns/include

LWRES_INCLUDES = -I/Users/holzschu/src/Xcode_iPad/network_ios/originalSources/bind9-57.2/bind9/lib/lwres/include \
	-I${top_srcdir}/lib/lwres/unix/include \
	-I${top_srcdir}/lib/lwres/include

BIND9_INCLUDES = -I/Users/holzschu/src/Xcode_iPad/network_ios/originalSources/bind9-57.2/bind9/lib/bind9/include \
	-I${top_srcdir}/lib/bind9/include

TEST_INCLUDES = \
	-I${top_srcdir}/lib/tests/include

CINCLUDES =	${DNS_INCLUDES} ${ISC_INCLUDES} ${ISCCFG_INCLUDES} \
		${LWRES_INCLUDES} ${OMAPI_INCLUDES}

CDEFINES =
CWARNINGS =
BACKTRACECFLAGS = 

DNSLIBS =	../../lib/dns/libdns.a 
ISCLIBS =	../../lib/isc/libisc.a 
ISCNOSYMLIBS =	../../lib/isc/libisc-nosymtbl.a 
ISCCFGLIBS = 	../../lib/isccfg/libisccfg.a
LWRESLIBS =	../../lib/lwres/liblwres.a

DNSDEPLIBS =	../../lib/dns/libdns.a
ISCDEPLIBS =	../../lib/isc/libisc.a
ISCDEPNOSYMLIBS = ../../lib/isc/libisc-nosymtbl.a
ISCCFGDEPLIBS = ../../lib/isccfg/libisccfg.a
LWRESDEPLIBS =	../../lib/lwres/liblwres.a

LIBS =		-ldl -lpthread 

SUBDIRS =	atomic db dst master mem hashes names net rbt resolver \
		sockaddr tasks timers system

# Test programs that are built by default:
# cfg_test is needed for regenerating doc/misc/options

# Alphabetically
TARGETS =	cfg_test

# All the other tests are optional and not built by default.

# Alphabetically
XTARGETS =	adb_test \
		byaddr_test \
		backtrace_test \
		backtrace_test_nosymtbl \
		byname_test \
		compress_test \
		db_test \
		entropy_test \
		entropy2_test \
		gxba_test \
		gxbn_test \
		hash_test \
		fsaccess_test \
		inter_test \
		keyboard_test \
		lex_test \
		lfsr_test \
		log_test \
		lwres_test \
		lwresconf_test \
		master_test \
		mempool_test \
		name_test \
		nsecify \
		ratelimiter_test \
		rbt_test \
		rdata_test \
		rwlock_test \
		serial_test \
		shutdown_test \
		sig0_test \
		sock_test \
		sym_test \
		task_test \
		timer_test \
		wire_test \
		zone_test

# Alphabetically
SRCS =		cfg_test.c ${XSRCS}

XSRCS =		adb_test.c \
		byaddr_test.c \
		backtrace_test.c \
		byname_test.c \
		compress_test.c \
		db_test.c \
		entropy_test.c \
		entropy2_test.c \
		gxba_test.c \
		gxbn_test.c \
		hash_test.c \
		fsaccess_test.c \
		inter_test.c \
		keyboard_test.c \
		lex_test.c \
		lfsr_test.c \
		log_test.c \
		lwres_test.c \
		lwresconf_test.c \
		master_test.c \
		mempool_test.c \
		name_test.c \
		nsecify.c \
		printmsg.c \
		ratelimiter_test.c \
		rbt_test.c \
		rdata_test.c \
		rwlock_test.c \
		serial_test.c \
		shutdown_test.c \
		sig0_test.c \
		sock_test.c \
		sym_test.c \
		task_test.c \
		timer_test.c \
		wire_test.c \
		zone_test.c

# Copyright (C) 2004-2009, 2011, 2012, 2014  Internet Systems Consortium, Inc. ("ISC")
# Copyright (C) 1998-2003  Internet Software Consortium.
#
# Permission to use, copy, modify, and/or distribute this software for any
# purpose with or without fee is hereby granted, provided that the above
# copyright notice and this permission notice appear in all copies.
#
# THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH
# REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
# AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,
# INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
# LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE
# OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
# PERFORMANCE OF THIS SOFTWARE.

# $Id$

###
### Common Makefile rules for BIND 9.
###

###
### Paths
###
### Note: paths that vary by Makefile MUST NOT be listed
### here, or they won't get expanded correctly.

prefix =	/usr/local
exec_prefix =	${prefix}
bindir =	${exec_prefix}/bin
sbindir =	${exec_prefix}/sbin
includedir =	${prefix}/include
libdir =	${exec_prefix}/lib
sysconfdir =	/etc
localstatedir =	/var
mandir =	${datarootdir}/man
datarootdir =   ${prefix}/share
export_libdir =	${exec_prefix}/lib/bind9/
export_includedir = ${prefix}/include/bind9/

DESTDIR =



top_builddir =	/Users/holzschu/src/Xcode_iPad/network_ios/originalSources/bind9-57.2/bind9

###
### All
###
### Makefile may define:
###	TARGETS

all: subdirs ${TARGETS} testdirs

###
### Subdirectories
###
### Makefile may define:
###	SUBDIRS

ALL_SUBDIRS = ${SUBDIRS} nulldir
ALL_TESTDIRS = ${TESTDIRS} nulldir

#
# We use a single-colon rule so that additional dependencies of
# subdirectories can be specified after the inclusion of this file.
# The "depend" and "testdirs" targets are treated the same way.
#
subdirs:
	@for i in ${ALL_SUBDIRS}; do \
		if [ "$$i" != "nulldir" -a -d $$i ]; then \
			echo "making all in `pwd`/$$i"; \
			(cd $$i; ${MAKE} ${MAKEDEFS} DESTDIR="${DESTDIR}" all) || exit 1; \
		fi; \
	done

#
# Tests are built after the targets instead of before
#
testdirs:
	@for i in ${ALL_TESTDIRS}; do \
		if [ "$$i" != "nulldir" -a -d $$i ]; then \
			echo "making all in `pwd`/$$i"; \
			(cd $$i; ${MAKE} ${MAKEDEFS} DESTDIR="${DESTDIR}" all) || exit 1; \
		fi; \
	done

install:: all

install clean distclean maintainer-clean doc docclean man manclean::
	@for i in ${ALL_SUBDIRS} ${ALL_TESTDIRS}; do \
		if [ "$$i" != "nulldir" -a -d $$i ]; then \
			echo "making $@ in `pwd`/$$i"; \
			(cd $$i; ${MAKE} ${MAKEDEFS} DESTDIR="${DESTDIR}" $@) || exit 1; \
		fi; \
	done

###
### C Programs
###
### Makefile must define
###	CC
### Makefile may define
###	CFLAGS
###	LDFLAGS
###	CINCLUDES
###	CDEFINES
###	CWARNINGS
### User may define externally
###     EXT_CFLAGS

CC = 		clang
CFLAGS =	-isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/
LDFLAGS =	
STD_CINCLUDES =	
STD_CDEFINES =	 -D__APPLE_USE_RFC_3542
STD_CWARNINGS =	 -W -Wall -Wmissing-prototypes -Wcast-qual -Wwrite-strings -Wformat -Wpointer-arith -fno-strict-aliasing -fno-delete-null-pointer-checks

BUILD_CC = clang
BUILD_CFLAGS = -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/
BUILD_CPPFLAGS =  -D__APPLE_USE_RFC_3542 
BUILD_LDFLAGS = 
BUILD_LIBS = -ldl -lpthread 

.SUFFIXES:
.SUFFIXES: .c .o

ALWAYS_INCLUDES = -I${top_builddir}
ALWAYS_DEFINES = -D_REENTRANT
ALWAYS_WARNINGS =

ALL_CPPFLAGS = \
	${ALWAYS_INCLUDES} ${CINCLUDES} ${STD_CINCLUDES} \
	${ALWAYS_DEFINES} ${CDEFINES} ${STD_CDEFINES}

ALL_CFLAGS = ${EXT_CFLAGS} ${ALL_CPPFLAGS} ${CFLAGS} \
	${ALWAYS_WARNINGS} ${STD_CWARNINGS} ${CWARNINGS}

.c.o:
	${LIBTOOL_MODE_COMPILE} ${CC} ${ALL_CFLAGS} -c $<

SHELL = /bin/sh
LIBTOOL = 
LIBTOOL_MODE_COMPILE = ${LIBTOOL} 
LIBTOOL_MODE_INSTALL = ${LIBTOOL} 
LIBTOOL_MODE_LINK = ${LIBTOOL} 
PURIFY = 

MKDEP = ${SHELL} ${top_builddir}/make/mkdep

###
### This is a template compound command to build an executable binary with
### an internal symbol table.
### This process is tricky.  We first link all objects including a tentative
### empty symbol table, then get a tentative list of symbols from the resulting
### binary ($@tmp0).  Next, we re-link all objects, but this time with the
### symbol table just created ($tmp@1).  The set of symbols should be the same,
### but the corresponding addresses would be changed due to the difference on
### the size of symbol tables.  So we create the symbol table and re-create the
### objects once again.  Finally, we check the symbol table embedded in the
### final binaryis consistent with the binary itself; otherwise the process is
### terminated.
###
### To minimize the overhead of creating symbol tables, the autoconf switch
### --enable-symtable takes an argument so that the symbol table can be created
### on a per application basis: unless the argument is set to "all", the symbol
### table is created only when a shell (environment) variable "MAKE_SYMTABLE" is
### set to a non-null value in the rule to build the executable binary.
###
### Each Makefile.in that uses this macro is expected to define "LIBS" and
### "NOSYMLIBS"; the former includes libisc with an empty symbol table, and
### the latter includes libisc without the definition of a symbol table.
### The rule to make the executable binary will look like this
### binary: ${OBJS}
###     #export MAKE_SYMTABLE="yes"; \  <- enable if symtable is always needed
###	export BASEOBJS="${OBJS}"; \
###	${FINALBUILDCMD}
###
### Normally, ${LIBS} includes all necessary libraries to build the binary;
### there are some exceptions however, where the rule lists some of the
### necessary libraries explicitly in addition to (or instead of) ${LIBS},
### like this:
### binary: ${OBJS}
###     cc -o $@ ${OBJS} ${OTHERLIB1} ${OTHERLIB2} ${lIBS}
### in order to modify such a rule to use this compound command, a separate
### variable "LIBS0" should be deinfed for the explicitly listed libraries,
### while making sure ${LIBS} still includes libisc.  So the above rule would
### be modified as follows:
### binary: ${OBJS}
###	export BASEOBJS="${OBJS}"; \
###	export LIBS0="${OTHERLIB1} ${OTHERLIB2}"; \
###     ${FINALBUILDCMD}
### See bin/check/Makefile.in for a complete example of the use of LIBS0.
###
FINALBUILDCMD = if [ X"${MKSYMTBL_PROGRAM}" = X -o X"$${MAKE_SYMTABLE:-${ALWAYS_MAKE_SYMTABLE}}" = X ] ; then \
		${LIBTOOL_MODE_LINK} ${PURIFY} ${CC} ${ALL_CFLAGS} ${LDFLAGS} \
		-o $@ $${BASEOBJS} $${LIBS0} ${LIBS}; \
	else \
		rm -f $@tmp0; \
		${LIBTOOL_MODE_LINK} ${PURIFY} ${CC} ${ALL_CFLAGS} ${LDFLAGS} \
		-o $@tmp0 $${BASEOBJS} $${LIBS0} ${LIBS} || exit 1; \
		rm -f $@-symtbl.c $@-symtbl.o; \
		${MKSYMTBL_PROGRAM} ${top_srcdir}/util/mksymtbl.pl \
		-o $@-symtbl.c $@tmp0 || exit 1; \
		$(MAKE) $@-symtbl.o || exit 1; \
		rm -f $@tmp1; \
		${LIBTOOL_MODE_LINK} ${PURIFY} ${CC} ${ALL_CFLAGS} ${LDFLAGS} \
		-o $@tmp1 $${BASEOBJS} $@-symtbl.o $${LIBS0} ${NOSYMLIBS} || exit 1; \
		rm -f $@-symtbl.c $@-symtbl.o; \
		${MKSYMTBL_PROGRAM} ${top_srcdir}/util/mksymtbl.pl \
		-o $@-symtbl.c $@tmp1 || exit 1; \
		$(MAKE) $@-symtbl.o || exit 1; \
		${LIBTOOL_MODE_LINK} ${PURIFY} ${CC} ${ALL_CFLAGS} ${LDFLAGS} \
		-o $@tmp2 $${BASEOBJS} $@-symtbl.o $${LIBS0} ${NOSYMLIBS}; \
		${MKSYMTBL_PROGRAM} ${top_srcdir}/util/mksymtbl.pl \
		-o $@-symtbl2.c $@tmp2; \
		count=0; \
		until diff $@-symtbl.c $@-symtbl2.c > /dev/null ; \
		do \
			count=`expr $$count + 1` ; \
			test $$count = 42 && exit 1 ; \
			rm -f $@-symtbl.c $@-symtbl.o; \
			${MKSYMTBL_PROGRAM} ${top_srcdir}/util/mksymtbl.pl \
			-o $@-symtbl.c $@tmp2 || exit 1; \
			$(MAKE) $@-symtbl.o || exit 1; \
			${LIBTOOL_MODE_LINK} ${PURIFY} ${CC} ${ALL_CFLAGS} \
			${LDFLAGS} -o $@tmp2 $${BASEOBJS} $@-symtbl.o \
			$${LIBS0} ${NOSYMLIBS}; \
			${MKSYMTBL_PROGRAM} ${top_srcdir}/util/mksymtbl.pl \
			-o $@-symtbl2.c $@tmp2; \
		done ; \
		mv $@tmp2 $@; \
		rm -f $@tmp0 $@tmp1 $@tmp2 $@-symtbl2.c; \
	fi

cleandir: distclean
superclean: maintainer-clean

clean distclean maintainer-clean::
	rm -f *.o *.o *.lo *.la core *.core *-symtbl.c *tmp0 *tmp1 *tmp2
	rm -rf .depend .libs

distclean maintainer-clean::
	rm -f Makefile

depend:
	@for i in ${ALL_SUBDIRS}; do \
		if [ "$$i" != "nulldir" -a -d $$i ]; then \
			echo "making depend in `pwd`/$$i"; \
			(cd $$i; ${MAKE} ${MAKEDEFS} DESTDIR="${DESTDIR}" $@) || exit 1; \
		fi; \
	done
	@if [ X"${srcdir}" != X. ] ; then \
		if [ X"${SRCS}" != X -a X"${PSRCS}" != X ] ; then \
			echo ${MKDEP} -vpath ${srcdir} ${ALL_CPPFLAGS} ${ALL_CFLAGS} ${SRCS}; \
			${MKDEP} -vpath ${srcdir} ${ALL_CPPFLAGS} ${ALL_CFLAGS} ${SRCS}; \
			echo ${MKDEP} -vpath ${srcdir} -ap ${ALL_CPPFLAGS} ${ALL_CFLAGS} ${PSRCS}; \
			${MKDEP} -vpath ${srcdir} -ap ${ALL_CPPFLAGS} ${ALL_CFLAGS} ${PSRCS}; \
			${DEPENDEXTRA} \
		elif [ X"${SRCS}" != X ] ; then \
			echo ${MKDEP} -vpath ${srcdir} ${ALL_CPPFLAGS} ${ALL_CFLAGS} ${SRCS}; \
			${MKDEP} -vpath ${srcdir} ${ALL_CPPFLAGS} ${ALL_CFLAGS} ${SRCS}; \
			${DEPENDEXTRA} \
		elif [ X"${PSRCS}" != X ] ; then \
			echo ${MKDEP} -vpath ${srcdir} ${ALL_CPPFLAGS} ${ALL_CFLAGS} ${PSRCS}; \
			${MKDEP} -vpath ${srcdir} -p ${ALL_CPPFLAGS} ${ALL_CFLAGS} ${PSRCS}; \
			${DEPENDEXTRA} \
		fi \
	else \
		if [ X"${SRCS}" != X -a X"${PSRCS}" != X ] ; then \
			echo ${MKDEP} ${ALL_CPPFLAGS} ${ALL_CFLAGS} ${SRCS}; \
			${MKDEP} ${ALL_CPPFLAGS} ${ALL_CFLAGS} ${SRCS}; \
			echo ${MKDEP} -ap ${ALL_CPPFLAGS} ${ALL_CFLAGS} ${PSRCS}; \
			${MKDEP} -ap ${ALL_CPPFLAGS} ${ALL_CFLAGS} ${PSRCS}; \
			${DEPENDEXTRA} \
		elif [ X"${SRCS}" != X ] ; then \
			echo ${MKDEP} ${ALL_CPPFLAGS} ${ALL_CFLAGS} ${SRCS}; \
			${MKDEP} ${ALL_CPPFLAGS} ${ALL_CFLAGS} ${SRCS}; \
			${DEPENDEXTRA} \
		elif [ X"${PSRCS}" != X ] ; then \
			echo ${MKDEP} ${ALL_CPPFLAGS} ${ALL_CFLAGS} ${PSRCS}; \
			${MKDEP} -p ${ALL_CPPFLAGS} ${ALL_CFLAGS} ${PSRCS}; \
			${DEPENDEXTRA} \
		fi \
	fi

FORCE:

###
### Libraries
###

AR =		/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin//ar
ARFLAGS =	cruv
RANLIB =	ranlib

###
### Installation
###

INSTALL =		/usr/bin/install -c
INSTALL_PROGRAM =	${INSTALL}
LINK_PROGRAM =		ln -s
INSTALL_SCRIPT =	${INSTALL}
INSTALL_DATA =		${INSTALL} -m 644
INSTALL_LIBRARY =	${INSTALL_DATA}

###
### Programs used when generating documentation.  It's ok for these
### not to exist when not generating documentation.
###

XSLTPROC =		/usr/bin/xsltproc --novalid --xinclude --nonet
PERL =			/usr/bin/perl
LATEX =			/Library/TeX/texbin//latex
PDFLATEX =		/Library/TeX/texbin//pdflatex
W3M =			w3m

###
### Script language program used to create internal symbol tables
###
MKSYMTBL_PROGRAM =	/usr/bin/perl

###
### Switch to create internal symbol table selectively
###
ALWAYS_MAKE_SYMTABLE =	

###
### DocBook -> HTML
### DocBook -> man page
###

.SUFFIXES: .docbook .html .1 .2 .3 .4 .5 .6 .7 .8

.docbook.html:
	${XSLTPROC} -o $@ ${top_srcdir}/doc/xsl/isc-docbook-html.xsl $<

.docbook.1:
	${XSLTPROC} -o $@ ${top_srcdir}/doc/xsl/isc-manpage.xsl $<

.docbook.2:
	${XSLTPROC} -o $@ ${top_srcdir}/doc/xsl/isc-manpage.xsl $<

.docbook.3:
	${XSLTPROC} -o $@ ${top_srcdir}/doc/xsl/isc-manpage.xsl $<

.docbook.4:
	${XSLTPROC} -o $@ ${top_srcdir}/doc/xsl/isc-manpage.xsl $<

.docbook.5:
	${XSLTPROC} -o $@ ${top_srcdir}/doc/xsl/isc-manpage.xsl $<

.docbook.6:
	${XSLTPROC} -o $@ ${top_srcdir}/doc/xsl/isc-manpage.xsl $<

.docbook.7:
	${XSLTPROC} -o $@ ${top_srcdir}/doc/xsl/isc-manpage.xsl $<

.docbook.8:
	${XSLTPROC} -o $@ ${top_srcdir}/doc/xsl/isc-manpage.xsl $<


# disable optimization for backtrace test to get the expected result	
BTTEST_CFLAGS =	${BACKTRACECFLAGS} ${EXT_CFLAGS} ${ALL_CPPFLAGS} -g \
		${ALWAYS_WARNINGS} ${STD_CWARNINGS} ${CWARNINGS}

all_tests: ${XTARGETS}

adb_test: adb_test.o ${ISCDEPLIBS} ${DNSDEPLIBS}
	${LIBTOOL_MODE_LINK} ${PURIFY} ${CC} ${CFLAGS} ${LDFLAGS} -o $@ adb_test.o \
		${DNSLIBS} ${ISCLIBS} ${LIBS}

backtrace_test_nosymtbl: backtrace_test.c ${ISCDEPLIBS}
	${LIBTOOL_MODE_LINK} ${PURIFY} ${CC} ${BTTEST_CFLAGS} ${LDFLAGS} -o $@ \
	backtrace_test.c ${ISCLIBS} ${LIBS}

backtrace_test: backtrace_test_nosymtbl
	#first step: create a first symbol table
	rm -f symtbl.c
	if test X${MKSYMTBL_PROGRAM} != X; then \
	${MKSYMTBL_PROGRAM} ${top_srcdir}/util/mksymtbl.pl \
	backtrace_test_nosymtbl; else \
	cp ${top_srcdir}/lib/isc/backtrace-emptytbl.c symtbl.c; fi
	#second step: build a binary with the first symbol table
	${LIBTOOL_MODE_LINK} ${PURIFY} ${CC} ${BTTEST_CFLAGS} ${LDFLAGS} \
	-o $@0 backtrace_test.c symtbl.c \
	${ISCNOSYMLIBS} ${LIBS}
	rm -f symtbl.c
	#third step: create a second symbol table
	if test X${MKSYMTBL_PROGRAM} != X; then \
	${MKSYMTBL_PROGRAM} ${top_srcdir}/util/mksymtbl.pl $@0; else \
	cp ${top_srcdir}/lib/isc/backtrace-emptytbl.c symtbl.c; fi
	#fourth step: build the final binary
	rm -f $@0
	${LIBTOOL_MODE_LINK} ${PURIFY} ${CC} ${BTTEST_CFLAGS} ${LDFLAGS} \
	-o $@ backtrace_test.c symtbl.c ${ISCNOSYMLIBS} ${LIBS}
	rm -f symtbl.c

nsecify: nsecify.o ${ISCDEPLIBS} ${DNSDEPLIBS}
	${LIBTOOL_MODE_LINK} ${PURIFY} ${CC} ${CFLAGS} ${LDFLAGS} -o $@ nsecify.o \
		${DNSLIBS} ${ISCLIBS} ${LIBS}

byaddr_test: byaddr_test.o ${ISCDEPLIBS} ${DNSDEPLIBS}
	${LIBTOOL_MODE_LINK} ${PURIFY} ${CC} ${CFLAGS} ${LDFLAGS} -o $@ byaddr_test.o \
		${DNSLIBS} ${ISCLIBS} ${LIBS}

byname_test: byname_test.o ${ISCDEPLIBS} ${DNSDEPLIBS}
	${LIBTOOL_MODE_LINK} ${PURIFY} ${CC} ${CFLAGS} ${LDFLAGS} -o $@ byname_test.o \
		${DNSLIBS} ${ISCLIBS} ${LIBS}

lex_test: lex_test.o ${ISCDEPLIBS}
	${LIBTOOL_MODE_LINK} ${PURIFY} ${CC} ${CFLAGS} ${LDFLAGS} -o $@ lex_test.o \
		${ISCLIBS} ${LIBS}

lfsr_test: lfsr_test.o ${ISCDEPLIBS}
	${LIBTOOL_MODE_LINK} ${PURIFY} ${CC} ${CFLAGS} ${LDFLAGS} -o $@ lfsr_test.o \
		${ISCLIBS} ${LIBS}

log_test: log_test.o ${ISCDEPLIBS} ${DNSDEPLIBS}
	${LIBTOOL_MODE_LINK} ${PURIFY} ${CC} ${CFLAGS} ${LDFLAGS} -o $@ log_test.o \
		${DNSLIBS} ${ISCLIBS} ${LIBS}

name_test: name_test.o ${ISCDEPLIBS} ${DNSDEPLIBS}
	${LIBTOOL_MODE_LINK} ${PURIFY} ${CC} ${CFLAGS} ${LDFLAGS} -o $@ name_test.o \
		${DNSLIBS} ${ISCLIBS} ${LIBS}

hash_test: hash_test.o ${ISCDEPLIBS}
	${LIBTOOL_MODE_LINK} ${PURIFY} ${CC} ${CFLAGS} ${LDFLAGS} -o $@ hash_test.o \
		${ISCLIBS} ${LIBS}

entropy_test: entropy_test.o ${ISCDEPLIBS}
	${LIBTOOL_MODE_LINK} ${PURIFY} ${CC} ${CFLAGS} ${LDFLAGS} -o $@ entropy_test.o \
		${ISCLIBS} ${LIBS}

entropy2_test: entropy2_test.o ${ISCDEPLIBS}
	${LIBTOOL_MODE_LINK} ${PURIFY} ${CC} ${CFLAGS} ${LDFLAGS} -o $@ entropy2_test.o \
		${ISCLIBS} ${LIBS}

sock_test: sock_test.o ${ISCDEPLIBS}
	${LIBTOOL_MODE_LINK} ${PURIFY} ${CC} ${CFLAGS} ${LDFLAGS} -o $@ sock_test.o \
		${ISCLIBS} ${LIBS}

sym_test: sym_test.o ${ISCDEPLIBS}
	${LIBTOOL_MODE_LINK} ${PURIFY} ${CC} ${CFLAGS} ${LDFLAGS} -o $@ sym_test.o \
		${ISCLIBS} ${LIBS}

task_test: task_test.o ${ISCDEPLIBS}
	${LIBTOOL_MODE_LINK} ${PURIFY} ${CC} ${CFLAGS} ${LDFLAGS} -o $@ task_test.o \
		${ISCLIBS} ${LIBS}

shutdown_test: shutdown_test.o ${ISCDEPLIBS}
	${LIBTOOL_MODE_LINK} ${PURIFY} ${CC} ${CFLAGS} ${LDFLAGS} -o $@ shutdown_test.o \
		${ISCLIBS} ${LIBS}

timer_test: timer_test.o ${ISCDEPLIBS}
	${LIBTOOL_MODE_LINK} ${PURIFY} ${CC} ${CFLAGS} ${LDFLAGS} -o $@ timer_test.o \
		${ISCLIBS} ${LIBS}

ratelimiter_test: ratelimiter_test.o ${ISCDEPLIBS} ${DNSDEPLIBS}
	${LIBTOOL_MODE_LINK} ${PURIFY} ${CC} ${CFLAGS} ${LDFLAGS} -o $@ ratelimiter_test.o \
		${DNSLIBS} ${ISCLIBS} ${LIBS}

rbt_test: rbt_test.o ${ISCDEPLIBS} ${DNSDEPLIBS}
	${LIBTOOL_MODE_LINK} ${PURIFY} ${CC} ${CFLAGS} ${LDFLAGS} -o $@ rbt_test.o \
		${DNSLIBS} ${ISCLIBS} ${LIBS}

rdata_test: rdata_test.o ${ISCDEPLIBS} ${DNSDEPLIBS}
	${LIBTOOL_MODE_LINK} ${PURIFY} ${CC} ${CFLAGS} ${LDFLAGS} -o $@ rdata_test.o \
		${DNSLIBS} ${ISCLIBS} ${LIBS}

rwlock_test: rwlock_test.o ${ISCDEPLIBS}
	${LIBTOOL_MODE_LINK} ${PURIFY} ${CC} ${CFLAGS} ${LDFLAGS} -o $@ rwlock_test.o \
		${ISCLIBS} ${LIBS}

wire_test: wire_test.o printmsg.o ${ISCDEPLIBS} ${DNSDEPLIBS}
	${LIBTOOL_MODE_LINK} ${PURIFY} ${CC} ${CFLAGS} ${LDFLAGS} -o $@ wire_test.o printmsg.o \
		${DNSLIBS} ${ISCLIBS} ${LIBS}

master_test: master_test.o ${ISCDEPLIBS} ${DNSDEPLIBS}
	${LIBTOOL_MODE_LINK} ${PURIFY} ${CC} ${CFLAGS} ${LDFLAGS} -o $@ master_test.o \
		${DNSLIBS} ${ISCLIBS} ${LIBS}

db_test: db_test.o ${ISCDEPLIBS} ${DNSDEPLIBS}
	${LIBTOOL_MODE_LINK} ${PURIFY} ${CC} ${CFLAGS} ${LDFLAGS} -o $@ db_test.o \
		${DNSLIBS} ${ISCLIBS} ${LIBS}

compress_test: compress_test.o ${ISCDEPLIBS} ${DNSDEPLIBS}
	${LIBTOOL_MODE_LINK} ${PURIFY} ${CC} ${CFLAGS} ${LDFLAGS} -o $@ compress_test.o \
		${DNSLIBS} ${ISCLIBS} ${LIBS}

mempool_test: mempool_test.o ${ISCDEPLIBS}
	${LIBTOOL_MODE_LINK} ${PURIFY} ${CC} ${CFLAGS} ${LDFLAGS} -o $@ mempool_test.o \
		${ISCLIBS} ${LIBS}

serial_test: serial_test.o ${ISCDEPLIBS}
	${LIBTOOL_MODE_LINK} ${PURIFY} ${CC} ${CFLAGS} ${LDFLAGS} -o $@ serial_test.o \
		${ISCLIBS} ${LIBS}

zone_test: zone_test.o ${ISCDEPLIBS} ${DNSDEPLIBS}
	${LIBTOOL_MODE_LINK} ${PURIFY} ${CC} ${CFLAGS} ${LDFLAGS} -o $@ zone_test.o \
		${DNSLIBS} ${ISCLIBS} ${LIBS}

fsaccess_test: fsaccess_test.o ${ISCDEPLIBS}
	${LIBTOOL_MODE_LINK} ${PURIFY} ${CC} ${CFLAGS} ${LDFLAGS} -o $@ fsaccess_test.o \
		${ISCLIBS} ${LIBS}

inter_test: inter_test.o ${ISCDEPLIBS}
	${LIBTOOL_MODE_LINK} ${PURIFY} ${CC} ${CFLAGS} ${LDFLAGS} -o $@ inter_test.o \
		${ISCLIBS} ${LIBS}

keyboard_test: keyboard_test.o ${ISCDEPLIBS}
	${LIBTOOL_MODE_LINK} ${PURIFY} ${CC} ${CFLAGS} ${LDFLAGS} -o $@ keyboard_test.o \
		${ISCLIBS} ${LIBS}

lwresconf_test: lwresconf_test.o ${ISCDEPLIBS} ${LWRESDEPLIBS}
	${LIBTOOL_MODE_LINK} ${PURIFY} ${CC} ${CFLAGS} ${LDFLAGS} -o $@ lwresconf_test.o \
		${LWRESLIBS} ${ISCLIBS} ${LIBS}

lwres_test: lwres_test.o ${ISCDEPLIBS} ${LWRESDEPLIBS}
	${LIBTOOL_MODE_LINK} ${PURIFY} ${CC} ${CFLAGS} ${LDFLAGS} -o $@ lwres_test.o \
		${LWRESLIBS} ${ISCLIBS} ${LIBS}

gxbn_test: gxbn_test.o ${LWRESDEPLIBS}
	${LIBTOOL_MODE_LINK} ${PURIFY} ${CC} ${CFLAGS} ${LDFLAGS} -o $@ gxbn_test.o \
		${LWRESLIBS} ${ISCLIBS} ${LIBS}

gxba_test: gxba_test.o ${LWRESDEPLIBS}
	${LIBTOOL_MODE_LINK} ${PURIFY} ${CC} ${CFLAGS} ${LDFLAGS} -o $@ gxba_test.o \
		${LWRESLIBS} ${ISCLIBS} ${LIBS}

sig0_test: sig0_test.o ${ISCDEPLIBS} ${DNSDEPLIBS}
	${LIBTOOL_MODE_LINK} ${PURIFY} ${CC} ${CFLAGS} ${LDFLAGS} -o $@ sig0_test.o \
		${DNSLIBS} ${ISCLIBS} ${LIBS}

cfg_test: cfg_test.o ${ISCCFGDEPLIBS} ${ISCDEPLIBS}
	${LIBTOOL_MODE_LINK} ${CC} ${CFLAGS} ${LDFLAGS} -o $@ cfg_test.o \
		${ISCCFGLIBS} ${DNSLIBS} ${ISCLIBS} ${LIBS}

distclean::
	rm -f headerdep_test.sh

clean distclean::
	rm -f ${TARGETS} ${XTARGETS}
	rm -f t_journal
	rm -f backtrace_test_symtbl.c

check: test

test:
	@for dir in $(SUBDIRS) ;\
	do \
		( cd $$dir; $(MAKE) test ) ;\
	done
