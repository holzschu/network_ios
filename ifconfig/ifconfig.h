/*
 * Copyright (c) 2009-2021 Apple Inc. All rights reserved.
 *
 * @APPLE_OSREFERENCE_LICENSE_HEADER_START@
 *
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. The rights granted to you under the License
 * may not be used to create, or enable the creation or redistribution of,
 * unlawful or unlicensed copies of an Apple operating system, or to
 * circumvent, violate, or enable the circumvention or violation of, any
 * terms of an Apple operating system software license agreement.
 *
 * Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this file.
 *
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 *
 * @APPLE_OSREFERENCE_LICENSE_HEADER_END@
 */

/*
 * Copyright (c) 1997 Peter Wemm.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *      This product includes software developed for the FreeBSD Project
 *	by Peter Wemm.
 * 4. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * so there!
 *
 * $FreeBSD: src/sbin/ifconfig/ifconfig.h,v 1.21.2.1.2.1 2008/11/25 02:59:29 kensmith Exp $
 */

#define	__constructor	__attribute__((constructor))

struct afswtch;
struct cmd;

typedef	void c_func(const char *cmd, int arg, int s, const struct afswtch *afp);
typedef	void c_func2(const char *arg1, const char *arg2, int s, const struct afswtch *afp);
typedef	int c_funcv(int argc, char *const *argv, int s, const struct afswtch *afp);

struct cmd {
	const char *c_name;
	int	c_parameter;
#define	NEXTARG		0xffffff	/* has following arg */
#define	NEXTARG2	0xfffffe	/* has 2 following args */
#define	OPTARG		0xfffffd	/* has optional following arg */
#define	VAARGS		0xfffffc	/* has variable following args */
	union {
		c_func	*c_func;
		c_func2	*c_func2;
		c_funcv *c_funcv;
	} c_u;
	int	c_iscloneop;
	struct cmd *c_next;
};
void	cmd_register(struct cmd *);

typedef	void callback_func(int s, void *);
void	callback_register(callback_func *, void *);

/*
 * Macros for declaring command functions and initializing entries.
 */
#define	DECL_CMD_FUNC(name, cmd, arg) \
	void name(const char *cmd, int arg, int s, const struct afswtch *afp)
#define	DECL_CMD_FUNC2(name, arg1, arg2) \
	void name(const char *arg1, const char *arg2, int s, const struct afswtch *afp)

#define	DEF_CMD(name, param, func)	{ name, param, { .c_func = func } }
#define	DEF_CMD_ARG(name, func)		{ name, NEXTARG, { .c_func = func } }
#define	DEF_CMD_OPTARG(name, func)	{ name, OPTARG, { .c_func = func } }
#define	DEF_CMD_ARG2(name, func)	{ name, NEXTARG2, { .c_func2 = func } }
#define	DEF_CMD_VA(name, func)		{ name, VAARGS, { .c_funcv = func } }
#define	DEF_CLONE_CMD(name, param, func) { name, param, { .c_func = func }, 1 }
#define	DEF_CLONE_CMD_ARG(name, func)	{ name, NEXTARG, { .c_func = func }, 1 }

struct ifaddrs;
struct addrinfo;

enum {
	RIDADDR,
	ADDR,
	MASK,
	DSTADDR,
};

struct afswtch {
	const char	*af_name;	/* as given on cmd line, e.g. "inet" */
	const char	*af_clone_name; /* "bridge", "vlan", etc. */
	uint8_t		af_clone_name_length;
	short		af_af;		/* AF_* */
	/*
	 * Status is handled one of two ways; if there is an
	 * address associated with the interface then the
	 * associated address family af_status method is invoked
	 * with the appropriate addressin info.  Otherwise, if
	 * all possible info is to be displayed and af_other_status
	 * is defined then it is invoked after all address status
	 * is presented.
	 */
	void		(*af_status)(int, const struct ifaddrs *);
	void		(*af_other_status)(int);
					/* parse address method */
	void		(*af_getaddr)(const char *, int);
					/* parse prefix method (IPv6) */
	void		(*af_getprefix)(const char *, int);
	void		(*af_postproc)(int s, const struct afswtch *);
	u_long		af_difaddr;	/* set dst if address ioctl */
	u_long		af_aifaddr;	/* set if address ioctl */
	void		*af_ridreq;	/* */
	void		*af_addreq;	/* */
	struct afswtch	*af_next;

	/* XXX doesn't fit model */
	void		(*af_status_tunnel)(int);
	void		(*af_settunnel)(int s, struct addrinfo *srcres,
				struct addrinfo *dstres);

	void		(*af_setrouter)(int, int);
	int		(*af_routermode)(int, int, char *const *);
};
void	af_register(struct afswtch *);

struct ifconfig_option {
	const char *opt;
	const char *opt_usage;
	void	(*cb)(const char *arg);
	struct ifconfig_option *next;
};
void	opt_register(struct ifconfig_option *);

extern	struct ifreq ifr;
extern	char name[IFNAMSIZ];	/* name of interface */
extern	int allmedia;
extern	int supmedia;
extern	int printkeys;
extern	int newaddr;
extern	int verbose;
extern	int all;

void	setifcap(const char *, int value, int s, const struct afswtch *);

void	Perror(const char *cmd);
void	printb(const char *s, unsigned value, const char *bits);

void	ifmaybeload(const char *name);

typedef void clone_callback_func(int, struct ifreq *);
void	clone_setcallback(clone_callback_func *);

/*
 * XXX expose this so modules that neeed to know of any pending
 * operations on ifmedia can avoid cmd line ordering confusion.
 */
struct ifmediareq *ifmedia_getstate(int s);
