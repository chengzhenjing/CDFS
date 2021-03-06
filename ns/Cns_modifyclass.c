/*
 * Copyright (C) 2000 by CERN/IT/PDP/DM
 * All rights reserved
 */

#ifndef lint
static char sccsid[] = "@(#)Cns_modifyclass.c,v 1.2 2001/01/23 11:03:42 CERN IT-PDP/DM Jean-Philippe Baud";
#endif /* not lint */

/*	Cns_modifyclass - modify an existing fileclass definition */

#include <errno.h>
#include <string.h>
#include <sys/types.h>
#if defined(_WIN32)
#include <winsock2.h>
#else
#include <unistd.h>
#include <netinet/in.h>
#endif
#include "marshall.h"
#include "Cns_api.h"
#include "Cns.h"
#include "serrno.h"

int DLL_DECL
Cns_modifyclass(char *server, int classid, char *class_name, struct Cns_fileclass *Cns_fileclass)
{
	int c;
	char func[16];
	gid_t gid;
	int i;
	int msglen;
	char *p;
	char *q;
	char *sbp;
	char sendbuf[REQBUFSZ];
	struct Cns_api_thread_info *thip;
	uid_t uid;

	strcpy (func, "Cns_modifyclass");
	if (Cns_apiinit (&thip))
		return (-1);
	uid = geteuid();
	gid = getegid();
#if defined(_WIN32)
	if (uid < 0 || gid < 0) {
		Cns_errmsg (func, NS053);
		serrno = SENOMAPFND;
		return (-1);
	}
#endif

	if (! Cns_fileclass) {
		serrno = EFAULT;
		return (-1);
	}

	/* Build request header */

	sbp = sendbuf;
	marshall_LONG (sbp, CNS_MAGIC);
	marshall_LONG (sbp, CNS_MODCLASS);
	q = sbp;        /* save pointer. The next field will be updated */
	msglen = 3 * LONGSIZE;
	marshall_LONG (sbp, msglen);

	/* Build request body */

	marshall_LONG (sbp, uid);
	marshall_LONG (sbp, gid);
	marshall_LONG (sbp, classid);
	if (class_name) {
		marshall_STRING (sbp, class_name);
	} else {
		marshall_STRING (sbp, "");
	}
	marshall_STRING (sbp, Cns_fileclass->name);
	marshall_LONG (sbp, Cns_fileclass->uid);
	marshall_LONG (sbp, Cns_fileclass->gid);
	marshall_LONG (sbp, Cns_fileclass->min_filesize);
	marshall_LONG (sbp, Cns_fileclass->max_filesize);
	marshall_LONG (sbp, Cns_fileclass->flags);
	marshall_LONG (sbp, Cns_fileclass->maxdrives);
	marshall_LONG (sbp, Cns_fileclass->max_segsize);
	marshall_LONG (sbp, Cns_fileclass->migr_time_interval);
	marshall_LONG (sbp, Cns_fileclass->mintime_beforemigr);
	marshall_LONG (sbp, Cns_fileclass->nbcopies);
	marshall_LONG (sbp, Cns_fileclass->retenp_on_disk);
	marshall_LONG (sbp, Cns_fileclass->nbtppools);
	p = Cns_fileclass->tppools;
	for (i = 0; i < Cns_fileclass->nbtppools; i++) {
		marshall_STRING (sbp, p);
		p += (CA_MAXPOOLNAMELEN+1);
	}

	msglen = sbp - sendbuf;
	marshall_LONG (q, msglen);	/* update length field */

	while ((c = send2nsd (NULL, server, sendbuf, msglen, NULL, 0)) &&
	    serrno == ENSNACT)
		sleep (RETRYI);
	if (c && serrno == SENAMETOOLONG) serrno = ENAMETOOLONG;
	return (c);
}
