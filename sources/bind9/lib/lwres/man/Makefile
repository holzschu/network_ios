# Copyright (C) 2004, 2007, 2012  Internet Systems Consortium, Inc. ("ISC")
# Copyright (C) 2001  Internet Software Consortium.
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

# $Id: Makefile.in,v 1.9 2007/06/19 23:47:23 tbox Exp $

srcdir =	.

top_srcdir =	../../..

VERSION=9.9.7-P3

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


# Alphabetically
#MANPAGES =	lwres.3 lwres_addr_parse.3 lwres_buffer.3 \
#		lwres_buffer_add.3 lwres_buffer_back.3 lwres_buffer_clear.3 \
#		lwres_buffer_first.3 lwres_buffer_forward.3 \
#		lwres_buffer_getmem.3 lwres_buffer_getuint16.3 \
#		lwres_buffer_getuint32.3 lwres_buffer_getuint8.3 \
#		lwres_buffer_init.3 lwres_buffer_invalidate.3 \
#		lwres_buffer_putmem.3 lwres_buffer_putuint16.3 \
#		lwres_buffer_putuint32.3 lwres_buffer_putuint8.3 \
#		lwres_buffer_subtract.3 lwres_conf_clear.3 \
#		lwres_conf_get.3 lwres_conf_init.3 \
#		lwres_conf_parse.3 lwres_conf_print.3 \
#		lwres_config.3 lwres_context.3 \
#		lwres_context_allocmem.3 lwres_context_create.3 \
#		lwres_context_destroy.3 lwres_context_freemem.3 \
#		lwres_context_initserial.3 lwres_context_nextserial.3 \
#		lwres_context_sendrecv.3 lwres_endhostent.3 \
#		lwres_endhostent_r.3 lwres_freeaddrinfo.3 \
#		lwres_freehostent.3 lwres_gabn.3 \
#		lwres_gabnrequest_free.3 lwres_gabnrequest_parse.3 \
#		lwres_gabnrequest_render.3 lwres_gabnresponse_free.3 \
#		lwres_gabnresponse_parse.3 lwres_gabnresponse_render.3 \
#		lwres_gai_strerror.3 lwres_getaddrinfo.3 \
#		lwres_getaddrsbyname.3 lwres_gethostbyaddr.3 \
#		lwres_gethostbyaddr_r.3 lwres_gethostbyname.3 \
#		lwres_gethostbyname2.3 lwres_gethostbyname_r.3 \
#		lwres_gethostent.3 lwres_gethostent_r.3 \
#		lwres_getipnode.3 lwres_getipnodebyaddr.3 \
#		lwres_getipnodebyname.3 lwres_getnamebyaddr.3 \
#		lwres_getnameinfo.3 lwres_getrrsetbyname.3 \
#		lwres_gnba.3 lwres_gnbarequest_free.3 \
#		lwres_gnbarequest_parse.3 lwres_gnbarequest_render.3 \
#		lwres_gnbaresponse_free.3 lwres_gnbaresponse_parse.3 \
#		lwres_gnbaresponse_render.3 lwres_herror.3 \
#		lwres_hstrerror.3 lwres_inetntop.3 \
#		lwres_lwpacket_parseheader.3 lwres_lwpacket_renderheader.3 \
#		lwres_net_ntop.3 lwres_noop.3 \
#		lwres_nooprequest_free.3 lwres_nooprequest_parse.3 \
#		lwres_nooprequest_render.3 lwres_noopresponse_free.3 \
#		lwres_noopresponse_parse.3 lwres_noopresponse_render.3 \
#		lwres_packet.3 lwres_resutil.3 \
#		lwres_sethostent.3 lwres_sethostent_r.3 \
#		lwres_string_parse.3


MANPAGES = 	lwres.3 lwres_buffer.3 lwres_config.3 lwres_context.3	\
		lwres_gabn.3 lwres_gai_strerror.3 lwres_getaddrinfo.3			\
		lwres_gethostent.3 lwres_getipnode.3 lwres_getnameinfo.3		\
		lwres_getrrsetbyname.3 lwres_gnba.3 lwres_hstrerror.3 lwres_inetntop.3	\
		lwres_noop.3 lwres_packet.3 lwres_resutil.3

HTMLPAGES = 	lwres.html lwres_buffer.html lwres_config.html lwres_context.html	\
		lwres_gabn.html lwres_gai_strerror.html lwres_getaddrinfo.html			\
		lwres_gethostent.html lwres_getipnode.html lwres_getnameinfo.html		\
		lwres_getrrsetbyname.html lwres_gnba.html lwres_hstrerror.html lwres_inetntop.html	\
		lwres_noop.html lwres_packet.html lwres_resutil.html

MANOBJS =	${MANPAGES} ${HTMLPAGES}

doc man:: ${MANOBJS}

docclean manclean maintainer-clean::
	rm -f ${MANOBJS}

installdirs:
	$(SHELL) ${top_srcdir}/mkinstalldirs ${DESTDIR}${mandir}/man3

man3 = ${DESTDIR}${mandir}/man3

install:: installdirs
	for m in ${MANPAGES}; do ${INSTALL_DATA} ${srcdir}/$$m ${DESTDIR}${mandir}/man3; done
	rm -f ${man3}/lwres_addr_parse.3
	ln ${man3}/lwres_resutil.3 ${man3}/lwres_addr_parse.3
	rm -f ${man3}/lwres_buffer_add.3
	ln ${man3}/lwres_buffer.3 ${man3}/lwres_buffer_add.3
	rm -f ${man3}/lwres_buffer_back.3
	ln ${man3}/lwres_buffer.3 ${man3}/lwres_buffer_back.3
	rm -f ${man3}/lwres_buffer_clear.3
	ln ${man3}/lwres_buffer.3 ${man3}/lwres_buffer_clear.3
	rm -f ${man3}/lwres_buffer_first.3
	ln ${man3}/lwres_buffer.3 ${man3}/lwres_buffer_first.3
	rm -f ${man3}/lwres_buffer_forward.3
	ln ${man3}/lwres_buffer.3 ${man3}/lwres_buffer_forward.3
	rm -f ${man3}/lwres_buffer_getmem.3
	ln ${man3}/lwres_buffer.3 ${man3}/lwres_buffer_getmem.3
	rm -f ${man3}/lwres_buffer_getuint16.3
	ln ${man3}/lwres_buffer.3 ${man3}/lwres_buffer_getuint16.3
	rm -f ${man3}/lwres_buffer_getuint32.3
	ln ${man3}/lwres_buffer.3 ${man3}/lwres_buffer_getuint32.3
	rm -f ${man3}/lwres_buffer_getuint8.3
	ln ${man3}/lwres_buffer.3 ${man3}/lwres_buffer_getuint8.3
	rm -f ${man3}/lwres_buffer_init.3
	ln ${man3}/lwres_buffer.3 ${man3}/lwres_buffer_init.3
	rm -f ${man3}/lwres_buffer_invalidate.3
	ln ${man3}/lwres_buffer.3 ${man3}/lwres_buffer_invalidate.3
	rm -f ${man3}/lwres_buffer_putmem.3
	ln ${man3}/lwres_buffer.3 ${man3}/lwres_buffer_putmem.3
	rm -f ${man3}/lwres_buffer_putuint16.3
	ln ${man3}/lwres_buffer.3 ${man3}/lwres_buffer_putuint16.3
	rm -f ${man3}/lwres_buffer_putuint32.3
	ln ${man3}/lwres_buffer.3 ${man3}/lwres_buffer_putuint32.3
	rm -f ${man3}/lwres_buffer_putuint8.3
	ln ${man3}/lwres_buffer.3 ${man3}/lwres_buffer_putuint8.3
	rm -f ${man3}/lwres_buffer_subtract.3
	ln ${man3}/lwres_buffer.3 ${man3}/lwres_buffer_subtract.3
	rm -f ${man3}/lwres_conf_clear.3
	ln ${man3}/lwres_config.3 ${man3}/lwres_conf_clear.3
	rm -f ${man3}/lwres_conf_get.3
	ln ${man3}/lwres_config.3 ${man3}/lwres_conf_get.3
	rm -f ${man3}/lwres_conf_init.3
	ln ${man3}/lwres_config.3 ${man3}/lwres_conf_init.3
	rm -f ${man3}/lwres_conf_parse.3
	ln ${man3}/lwres_config.3 ${man3}/lwres_conf_parse.3
	rm -f ${man3}/lwres_conf_print.3
	ln ${man3}/lwres_config.3 ${man3}/lwres_conf_print.3
	rm -f ${man3}/lwres_context_allocmem.3
	ln ${man3}/lwres_context.3 ${man3}/lwres_context_allocmem.3
	rm -f ${man3}/lwres_context_create.3
	ln ${man3}/lwres_context.3 ${man3}/lwres_context_create.3
	rm -f ${man3}/lwres_context_destroy.3
	ln ${man3}/lwres_context.3 ${man3}/lwres_context_destroy.3
	rm -f ${man3}/lwres_context_freemem.3
	ln ${man3}/lwres_context.3 ${man3}/lwres_context_freemem.3
	rm -f ${man3}/lwres_context_initserial.3
	ln ${man3}/lwres_context.3 ${man3}/lwres_context_initserial.3
	rm -f ${man3}/lwres_context_nextserial.3
	ln ${man3}/lwres_context.3 ${man3}/lwres_context_nextserial.3
	rm -f ${man3}/lwres_context_sendrecv.3
	ln ${man3}/lwres_context.3 ${man3}/lwres_context_sendrecv.3
	rm -f ${man3}/lwres_endhostent.3
	ln ${man3}/lwres_gethostent.3 ${man3}/lwres_endhostent.3
	rm -f ${man3}/lwres_endhostent_r.3
	ln ${man3}/lwres_gethostent.3 ${man3}/lwres_endhostent_r.3
	rm -f ${man3}/lwres_freeaddrinfo.3
	ln ${man3}/lwres_getaddrinfo.3 ${man3}/lwres_freeaddrinfo.3
	rm -f ${man3}/lwres_freehostent.3
	ln ${man3}/lwres_getipnode.3 ${man3}/lwres_freehostent.3
	rm -f ${man3}/lwres_gabnrequest_free.3
	ln ${man3}/lwres_gabn.3 ${man3}/lwres_gabnrequest_free.3
	rm -f ${man3}/lwres_gabnrequest_parse.3
	ln ${man3}/lwres_gabn.3 ${man3}/lwres_gabnrequest_parse.3
	rm -f ${man3}/lwres_gabnrequest_render.3
	ln ${man3}/lwres_gabn.3 ${man3}/lwres_gabnrequest_render.3
	rm -f ${man3}/lwres_gabnresponse_free.3
	ln ${man3}/lwres_gabn.3 ${man3}/lwres_gabnresponse_free.3
	rm -f ${man3}/lwres_gabnresponse_parse.3
	ln ${man3}/lwres_gabn.3 ${man3}/lwres_gabnresponse_parse.3
	rm -f ${man3}/lwres_gabnresponse_render.3
	ln ${man3}/lwres_gabn.3 ${man3}/lwres_gabnresponse_render.3
	rm -f ${man3}/lwres_getaddrsbyname.3
	ln ${man3}/lwres_resutil.3 ${man3}/lwres_getaddrsbyname.3
	rm -f ${man3}/lwres_gethostbyaddr.3
	ln ${man3}/lwres_gethostent.3 ${man3}/lwres_gethostbyaddr.3
	rm -f ${man3}/lwres_gethostbyaddr_r.3
	ln ${man3}/lwres_gethostent.3 ${man3}/lwres_gethostbyaddr_r.3
	rm -f ${man3}/lwres_gethostbyname.3
	ln ${man3}/lwres_gethostent.3 ${man3}/lwres_gethostbyname.3
	rm -f ${man3}/lwres_gethostbyname2.3
	ln ${man3}/lwres_gethostent.3 ${man3}/lwres_gethostbyname2.3
	rm -f ${man3}/lwres_gethostbyname_r.3
	ln ${man3}/lwres_gethostent.3 ${man3}/lwres_gethostbyname_r.3
	rm -f ${man3}/lwres_gethostent_r.3
	ln ${man3}/lwres_gethostent.3 ${man3}/lwres_gethostent_r.3
	rm -f ${man3}/lwres_getipnodebyaddr.3
	ln ${man3}/lwres_getipnode.3 ${man3}/lwres_getipnodebyaddr.3
	rm -f ${man3}/lwres_getipnodebyname.3
	ln ${man3}/lwres_getipnode.3 ${man3}/lwres_getipnodebyname.3
	rm -f ${man3}/lwres_getnamebyaddr.3
	ln ${man3}/lwres_resutil.3 ${man3}/lwres_getnamebyaddr.3
	rm -f ${man3}/lwres_gnbarequest_free.3
	ln ${man3}/lwres_gnba.3 ${man3}/lwres_gnbarequest_free.3
	rm -f ${man3}/lwres_gnbarequest_parse.3
	ln ${man3}/lwres_gnba.3 ${man3}/lwres_gnbarequest_parse.3
	rm -f ${man3}/lwres_gnbarequest_render.3
	ln ${man3}/lwres_gnba.3 ${man3}/lwres_gnbarequest_render.3
	rm -f ${man3}/lwres_gnbaresponse_free.3
	ln ${man3}/lwres_gnba.3 ${man3}/lwres_gnbaresponse_free.3
	rm -f ${man3}/lwres_gnbaresponse_parse.3
	ln ${man3}/lwres_gnba.3 ${man3}/lwres_gnbaresponse_parse.3
	rm -f ${man3}/lwres_gnbaresponse_render.3
	ln ${man3}/lwres_gnba.3 ${man3}/lwres_gnbaresponse_render.3
	rm -f ${man3}/lwres_herror.3
	ln ${man3}/lwres_hstrerror.3 ${man3}/lwres_herror.3
	rm -f ${man3}/lwres_lwpacket_parseheader.3
	ln ${man3}/lwres_packet.3 ${man3}/lwres_lwpacket_parseheader.3
	rm -f ${man3}/lwres_lwpacket_renderheader.3
	ln ${man3}/lwres_packet.3 ${man3}/lwres_lwpacket_renderheader.3
	rm -f ${man3}/lwres_net_ntop.3
	ln ${man3}/lwres_inetntop.3 ${man3}/lwres_net_ntop.3
	rm -f ${man3}/lwres_nooprequest_free.3
	ln ${man3}/lwres_noop.3 ${man3}/lwres_nooprequest_free.3
	rm -f ${man3}/lwres_nooprequest_parse.3
	ln ${man3}/lwres_noop.3 ${man3}/lwres_nooprequest_parse.3
	rm -f ${man3}/lwres_nooprequest_render.3
	ln ${man3}/lwres_noop.3 ${man3}/lwres_nooprequest_render.3
	rm -f ${man3}/lwres_noopresponse_free.3
	ln ${man3}/lwres_noop.3 ${man3}/lwres_noopresponse_free.3
	rm -f ${man3}/lwres_noopresponse_parse.3
	ln ${man3}/lwres_noop.3 ${man3}/lwres_noopresponse_parse.3
	rm -f ${man3}/lwres_noopresponse_render.3
	ln ${man3}/lwres_noop.3 ${man3}/lwres_noopresponse_render.3
	rm -f ${man3}/lwres_sethostent.3
	ln ${man3}/lwres_gethostent.3 ${man3}/lwres_sethostent.3
	rm -f ${man3}/lwres_sethostent_r.3
	ln ${man3}/lwres_gethostent.3 ${man3}/lwres_sethostent_r.3
	rm -f ${man3}/lwres_string_parse.3
	ln ${man3}/lwres_resutil.3 ${man3}/lwres_string_parse.3
