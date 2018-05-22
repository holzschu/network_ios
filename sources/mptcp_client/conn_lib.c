/*
 * Copyright (c) 2012-2014 Apple Inc. All rights reserved.
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

//
//  Created by Anumita Biswas on 10/30/12.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <errno.h>


#include "conn_lib.h"

#define  SIOCGASSOCIDS  _IOWR('s', 150, struct so_aidreq) /* get associds */
#define  SIOCGCONNIDS  _IOWR('s', 151, struct so_cidreq) /* get connids */
#define  SIOCGCONNINFO  _IOWR('s', 152, struct so_cinforeq) /* get conninfo */

// https://opensource.apple.com/source/xnu/xnu-3247.1.106/bsd/sys/socket.h

/*
 * Structure for SIOCGASSOCIDS
 */
struct so_aidreq {
  __uint32_t  sar_cnt;  /* number of associations */
  sae_associd_t  *sar_aidp;  /* array of association IDs */
};

/*
 * Structure for SIOCGCONNIDS
 */
struct so_cidreq {
  sae_associd_t  scr_aid;  /* association ID */
  __uint32_t  scr_cnt;  /* number of connections */
  sae_connid_t  *scr_cidp;  /* array of connection IDs */
};

/*
*
* Structure for SIOCGCONNINFO
*/
struct so_cinforeq {
  sae_connid_t  scir_cid;    /* connection ID */
  __uint32_t  scir_flags;    /* see flags below */
  __uint32_t  scir_ifindex;    /* (last) outbound interface */
  __int32_t  scir_error;    /* most recent error */
  struct sockaddr  *scir_src;    /* source address */
  socklen_t  scir_src_len;    /* source address len */
  struct sockaddr *scir_dst;    /* destination address */
  socklen_t  scir_dst_len;    /* destination address len */
  __uint32_t  scir_aux_type;    /* aux data type (CIAUX) */
  void    *scir_aux_data;    /* aux data */
  __uint32_t  scir_aux_len;    /* aux data len */
};

int
ios_copyassocids(int s, sae_associd_t **aidpp, uint32_t *cnt)
{
	struct so_aidreq aidr;
	sae_associd_t *buf;
	int err;

	if (aidpp == NULL || cnt == NULL) {
		errno = EINVAL;
		return (-1);
	}
	*aidpp = NULL;
	*cnt = 0;

	bzero(&aidr, sizeof (aidr));

	err = ioctl(s, SIOCGASSOCIDS, &aidr);
	if (err != 0)
		return (-1);

	/* none, just return */
	if (aidr.sar_cnt == 0)
		return (0);

	buf = calloc(aidr.sar_cnt, sizeof (sae_associd_t));
	if (buf == NULL)
		return (-1);

	aidr.sar_aidp = buf;
	err = ioctl(s, SIOCGASSOCIDS, &aidr);
	if (err != 0) {
		free(buf);
		return (-1);
	}

	*aidpp = buf;
	*cnt = aidr.sar_cnt;

	return (0);
}

void
ios_freeassocids(sae_associd_t *aidp)
{
	free(aidp);
}

int
ios_copyconnids(int s, sae_associd_t aid, sae_connid_t **cidp, uint32_t *cnt)
{
	struct so_cidreq cidr;
	sae_connid_t *buf;
	int err;

	if (cidp == NULL || cnt == NULL) {
		errno = EINVAL;
		return (-1);
	}
	*cidp = NULL;
	*cnt = 0;

	bzero(&cidr, sizeof (cidr));

	cidr.scr_aid = aid;
	err = ioctl(s, SIOCGCONNIDS, &cidr);
	if (err != 0)
		return (-1);

	/* none, just return */
	if (cidr.scr_cnt == 0)
		return (0);

	buf = calloc(cidr.scr_cnt, sizeof (sae_connid_t));
	if (buf == NULL)
		return (-1);

	cidr.scr_cidp = buf;
	err = ioctl(s, SIOCGCONNIDS, &cidr);
	if (err != 0) {
		free(buf);
		return (-1);
	}

	*cidp = buf;
	*cnt = cidr.scr_cnt;

	return (0);
}

void
ios_freeconnids(sae_connid_t *cidp)
{
	free(cidp);
}

int
ios_copyconninfo(int s, sae_connid_t cid, conninfo_t **cfop)
{
	struct sockaddr *src = NULL, *dst = NULL, *aux = NULL;
	struct so_cinforeq scir;
	conninfo_t *buf = NULL;

	if (cfop == NULL) {
		errno = EINVAL;
		goto error;
	}
	*cfop = NULL;

	bzero(&scir, sizeof (scir));

	scir.scir_cid = cid;
	if (ioctl(s, SIOCGCONNINFO, &scir) != 0)
		goto error;

	if (scir.scir_src_len != 0) {
		src = calloc(1, scir.scir_src_len);
		if (src == NULL)
			goto error;
		scir.scir_src = src;
	}
	if (scir.scir_dst_len != 0) {
		dst = calloc(1, scir.scir_dst_len);
		if (dst == NULL)
			goto error;
		scir.scir_dst = dst;
	}
	if (scir.scir_aux_len != 0) {
		aux = calloc(1, scir.scir_aux_len);
		if (aux == NULL)
			goto error;
		scir.scir_aux_data = aux;
	}

	if (ioctl(s, SIOCGCONNINFO, &scir) != 0)
		goto error;

	buf = calloc(1, sizeof (*buf));
	if (buf == NULL)
		goto error;

	// When we query for the length using the first ioctl call above, the kernel
	// tells us the length of the aux structure so we know how much to allocate
	// memory. There may not be any aux data, which will be indicated by the aux
	// data length using the second ioctl call.
	if (scir.scir_aux_len == 0 && aux != NULL) {
		free(aux);
		aux = NULL;
		scir.scir_aux_data = NULL;
	}

	buf->ci_flags = scir.scir_flags;
	buf->ci_ifindex = scir.scir_ifindex;
	buf->ci_src = src;
	buf->ci_dst = dst;
	buf->ci_error = scir.scir_error;
	buf->ci_aux_type = scir.scir_aux_type;
	buf->ci_aux_data = aux;
	*cfop = (conninfo_t*)buf;

	return (0);

error:
	if (src != NULL)
		free(src);
	if (dst != NULL)
		free(dst);
	if (aux != NULL)
		free(aux);
	if (buf != NULL)
		free(buf);

	return (-1);
}

void
ios_freeconninfo(conninfo_t *cfo)
{
	if (cfo->ci_src != NULL)
		free(cfo->ci_src);

	if (cfo->ci_dst != NULL)
		free(cfo->ci_dst);

	if (cfo->ci_aux_data != NULL)
		free(cfo->ci_aux_data);

	free(cfo);
}
