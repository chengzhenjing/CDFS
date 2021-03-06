/*
 * Copyright (C) 2000-2002 by CERN/IT/PDP/DM
 * All rights reserved
 */

#ifndef lint
static char sccsid[] = "@(#)nsmodifyclass.c,v 1.9 2002/08/21 09:58:21 CERN IT-PDP/DM Jean-Philippe Baud";
#endif /* not lint */

/*	nsmodifyclass - modify an existing file class */
#include <errno.h>
#include <grp.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include "Cgetopt.h"
#include "Cns_api.h"
#include "serrno.h"
int main(int argc, char **argv)
{
	int c;
	struct Cns_fileclass Cns_fileclass;
	int classid = 0;
	char *class_name = NULL;
	char *dp;
	int errflg = 0;
	struct group *gr;
	static struct Coptions longopts[] = {
		{"gid", REQUIRED_ARGUMENT, 0, OPT_CLASS_GID},
		{"group", REQUIRED_ARGUMENT, 0, OPT_CLASS_GROUP},
		{"id", REQUIRED_ARGUMENT, 0, OPT_CLASS_ID},
		{"name", REQUIRED_ARGUMENT, 0, OPT_CLASS_NAME},
		{"uid", REQUIRED_ARGUMENT, 0, OPT_CLASS_UID},
		{"user", REQUIRED_ARGUMENT, 0, OPT_CLASS_USER},
		{"flags", REQUIRED_ARGUMENT, 0, OPT_FLAGS},
		{"maxdrives", REQUIRED_ARGUMENT, 0, OPT_MAX_DRV},
		{"maxfilesize", REQUIRED_ARGUMENT, 0, OPT_MAX_FSZ},
		{"maxsegsize", REQUIRED_ARGUMENT, 0, OPT_MAX_SSZ},
		{"migr_interval", REQUIRED_ARGUMENT, 0, OPT_MIGR_INTV},
		{"minfilesize", REQUIRED_ARGUMENT, 0, OPT_MIN_FSZ},
		{"mintime", REQUIRED_ARGUMENT, 0, OPT_MIN_TIME},
		{"nbcopies", REQUIRED_ARGUMENT, 0, OPT_NBCOPIES},
		{"newname", REQUIRED_ARGUMENT, 0, OPT_NEW_C_NAME},
		{"retenp_on_disk", REQUIRED_ARGUMENT, 0, OPT_RETENP_DISK},
		{"tppools", REQUIRED_ARGUMENT, 0, OPT_TPPOOLS},
		{0, 0, 0, 0}
	};
	int nbtppools;
	char *p;
	struct passwd *pwd;
	char *q;
	char *server = NULL;

	memset (&Cns_fileclass, 0xFF, sizeof(struct Cns_fileclass));
	*(Cns_fileclass.name) = '\0';
	Copterr = 1;
	Coptind = 1;
	while ((c = Cgetopt_long (argc, argv, "h:", longopts, NULL)) != EOF) {
		switch (c) {
		case OPT_CLASS_GID:
			if ((Cns_fileclass.gid = strtol (Coptarg, &dp, 10)) < 0 ||
			    *dp != '\0') {
				fprintf (stderr,
				    "invalid class_gid %s\n", Coptarg);
				errflg++;
			}
			break;
		case OPT_CLASS_GROUP:
			if ((gr = getgrnam (Coptarg)) == NULL) {
				fprintf (stderr,
				    "invalid class_group: %s\n", Coptarg);
				errflg++;
			} else
				Cns_fileclass.gid = gr->gr_gid;
			break;
		case OPT_CLASS_ID:
			if ((classid = strtol (Coptarg, &dp, 10)) <= 0 ||
			    *dp != '\0') {
				fprintf (stderr,
				    "invalid classid %s\n", Coptarg);
				errflg++;
			} else
				Cns_fileclass.classid = classid;
			break;
		case OPT_CLASS_NAME:
			if (strlen (Coptarg) > CA_MAXCLASNAMELEN) {
				fprintf (stderr,
				    "class name too long: %s\n", Coptarg);
				errflg++;
			} else
				class_name = Coptarg;
			break;
		case OPT_CLASS_UID:
			if ((Cns_fileclass.uid = strtol (Coptarg, &dp, 10)) < 0 ||
			    *dp != '\0') {
				fprintf (stderr,
				    "invalid class_uid %s\n", Coptarg);
				errflg++;
			}
			break;
		case OPT_CLASS_USER:
			if ((pwd = getpwnam (Coptarg)) == NULL) {
				fprintf (stderr,
				    "invalid class_user: %s\n", Coptarg);
				errflg++;
			} else
				Cns_fileclass.uid = pwd->pw_uid;
			break;
		case OPT_FLAGS:
			if ((Cns_fileclass.flags = strtol (Coptarg, &dp, 10)) < 0 ||
			    *dp != '\0') {
				fprintf (stderr,
				    "invalid flags %s\n", Coptarg);
				errflg++;
			}
			break;
		case OPT_MAX_DRV:
			if ((Cns_fileclass.maxdrives = strtol (Coptarg, &dp, 10)) < 0 ||
			    *dp != '\0') {
				fprintf (stderr,
				    "invalid maxdrives %s\n", Coptarg);
				errflg++;
			}
			break;
		case OPT_MAX_FSZ:
			if ((Cns_fileclass.max_filesize = strtol (Coptarg, &dp, 10)) < 0 ||
			    *dp != '\0') {
				fprintf (stderr,
				    "invalid maxfilesize %s\n", Coptarg);
				errflg++;
			}
			break;
		case OPT_MAX_SSZ:
			if ((Cns_fileclass.max_segsize = strtol (Coptarg, &dp, 10)) < 0 ||
			    *dp != '\0') {
				fprintf (stderr,
				    "invalid maxsegsize %s\n", Coptarg);
				errflg++;
			}
			break;
		case OPT_MIGR_INTV:
			if ((Cns_fileclass.migr_time_interval = strtol (Coptarg, &dp, 10)) < 0 ||
			    *dp != '\0') {
				fprintf (stderr,
				    "invalid migr_interval %s\n", Coptarg);
				errflg++;
			}
			break;
		case OPT_MIN_FSZ:
			if ((Cns_fileclass.min_filesize = strtol (Coptarg, &dp, 10)) < 0 ||
			    *dp != '\0') {
				fprintf (stderr,
				    "invalid minfilesize %s\n", Coptarg);
				errflg++;
			}
			break;
		case OPT_MIN_TIME:
			if ((Cns_fileclass.mintime_beforemigr = strtol (Coptarg, &dp, 10)) < 0 ||
			    *dp != '\0') {
				fprintf (stderr,
				    "invalid mintime %s\n", Coptarg);
				errflg++;
			}
			break;
		case OPT_NBCOPIES:
			if ((Cns_fileclass.nbcopies = strtol (Coptarg, &dp, 10)) < 0 ||
			    *dp != '\0') {
				fprintf (stderr,
				    "invalid nbcopies %s\n", Coptarg);
				errflg++;
			}
			break;
		case OPT_NEW_C_NAME:
			if (strlen (Coptarg) > CA_MAXCLASNAMELEN) {
				fprintf (stderr,
				    "class name too long: %s\n", Coptarg);
				errflg++;
			} else
				strcpy (Cns_fileclass.name, Coptarg);
			break;
		case OPT_RETENP_DISK:
			if (strcmp (Coptarg, "AS_LONG_AS_POSSIBLE") == 0)
				Cns_fileclass.retenp_on_disk = AS_LONG_AS_POSSIBLE;
			else if (strcmp (Coptarg, "INFINITE_LIFETIME") == 0)
				Cns_fileclass.retenp_on_disk = INFINITE_LIFETIME;
			else if ((Cns_fileclass.retenp_on_disk =
			    strtol (Coptarg, &dp, 10)) < 0 || *dp != '\0') {
				fprintf (stderr,
				    "invalid retenp_on_disk %s\n", Coptarg);
				errflg++;
			}
			break;
		case OPT_TPPOOLS:
			nbtppools = 0;
			p = strtok (Coptarg, ":");
			if (p == NULL)
				nbtppools++;
			while (p) {
				if (strlen (p) > CA_MAXPOOLNAMELEN) {
					fprintf (stderr,
					    "invalid tppools %s\n", Coptarg);
					errflg++;
				} else
					nbtppools++;
				if (p = strtok (NULL, ":")) *(p - 1) = ':';
			}
			if (errflg) break;
			Cns_fileclass.nbtppools = nbtppools;
			if ((q = (char *)calloc (nbtppools, CA_MAXPOOLNAMELEN+1)) == NULL) {
				fprintf (stderr, "nsmodifyclass %s: %s\n",
				    Cns_fileclass.name, sstrerror(ENOMEM));
				errflg++;
				break;
			}
			Cns_fileclass.tppools = q;
			p = strtok (Coptarg, ":");
			while (p) {
				strcpy (q, p);
				q += (CA_MAXPOOLNAMELEN+1);
				p = strtok (NULL, ":");
			}
			break;
		case 'h':
			server = Coptarg;
			break;
		case '?':
			errflg++;
			break;
		default:
			break;
		}
	}
	if (Coptind < argc || (classid == 0 && class_name == NULL)) {
		errflg++;
	}
	if (errflg) {
		fprintf (stderr, "usage: %s %s %s %s %s %s", argv[0],
		    "--id classid --name class_name [--gid class_gid] [--group class_group]\n",
		    "[-h name_server] [--flags flags] [--maxdrives n] [--maxfilesize n]\n",
		    "[--maxsegsize n] [--migr_interval n] [--minfilesize n] [--mintime n]\n",
		    "[--nbcopies n] [--newname class_name] [--retenp_on_disk n]\n",
		    "[--tppools pool1:pool2...] [--uid class_uid] [--user class_user]\n");
		exit (USERR);
	}

	if (Cns_modifyclass (server, classid, class_name, &Cns_fileclass) < 0) {
		char buf[256];
		if (classid) sprintf (buf, "%d", classid);
		if (class_name) {
			if (classid) strcat (buf, ", ");
			else buf[0] = '\0';
			strcat (buf, class_name);
		}
		fprintf (stderr, "nsmodifyclass %s: %s\n", buf,
		    (serrno == ENOENT) ? "No such class" : sstrerror(serrno));
		exit (USERR);
	}
	exit (0);
}
