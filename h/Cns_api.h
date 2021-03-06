/*
 * Cns_api.h,v 1.44 2004/03/03 08:50:30 bcouturi Exp
 */

/*
 * Copyright (C) 1999-2004 by CERN/IT/PDP/DM
 * All rights reserved
 */

/*
 * @(#)Cns_api.h,v 1.44 2004/03/03 08:50:30 CERN IT-PDP/DM Jean-Philippe Baud
 */

#ifndef _CNS_API_H
#define _CNS_API_H
#if defined(_WIN32)
#include <sys/utime.h>
#else
#include <utime.h>
#endif
#include "Cns_constants.h"
#include "osdep.h"

#include "XrdPosix/XrdPosixXrootd.hh"
#include "XrdOuc/XrdOucString.hh"
#include "XrdCl/XrdClFile.hh"

#include <json/json.h>
#include <string>
#include <vector>
using namespace std;

int *C__Cns_errno();
#define Cns_errno (*C__Cns_errno())

#define	CNS_LIST_BEGIN		0
#define	CNS_LIST_CONTINUE	1
#define	CNS_LIST_END		2

struct Cns_api_thread_info {
	u_signed64	cwd;		/* current HSM working directory */
	char *		errbufp;
	int		errbuflen;
	int		initialized;
	int		ns_errno;
	mode_t		mask;		/* current HSM umask */
	char		server[CA_MAXHOSTNAMELEN+1];	/* current HSM Name Server */
};

typedef struct {
	int		dd_fd;		/* socket for communication with server */
	u_signed64	fileid;
	int		bod;		/* beginning of directory */
	int		eod;		/* end of directory */
	int		dd_loc;		/* offset in buffer */
	int		dd_size;	/* amount of data in buffer */
	char		*dd_buf;	/* directory buffer */
} Cns_DIR;

struct Cns_direncomm {
	char		*comment;
	unsigned short	d_reclen;	/* length of this entry */
	char		d_name[1];
};

struct Cns_direnstat {
	u_signed64	fileid;
	mode_t		filemode;
	nlink_t		nlink;		/* number of files in a directory */
	uid_t		uid;
	gid_t		gid;
	size_t	        filesize;
	time_t		atime;		/* last access to file */
	time_t		mtime;		/* last file modification */
	time_t		ctime;		/* last metadata modification */
	short		fileclass;	/* 1 --> experiment, 2 --> user */
	char		status;		/* ' ' --> online, 'm' --> migrated */
	unsigned short	d_reclen;	/* length of this entry */
	char		d_name[1];
};

struct Cns_direnstatc {
	u_signed64	fileid;
	mode_t		filemode;
	int		nlink;		/* number of files in a directory */
	uid_t		uid;
	gid_t		gid;
	u_signed64	filesize;
	time_t		atime;		/* last access to file */
	time_t		mtime;		/* last file modification */
	time_t		ctime;		/* last metadata modification */
	short		fileclass;	/* 1 --> experiment, 2 --> user */
	char		status;		/* ' ' --> online, 'm' --> migrated */
	char		*comment;
	unsigned short	d_reclen;	/* length of this entry */
	char		d_name[1];
};

struct Cns_direntape {
	u_signed64	parent_fileid;
	u_signed64	fileid;
	int		copyno;
	int		fsec;		/* file section number */
	u_signed64	segsize;	/* file section size */
	int		compression;	/* compression factor */
	char		s_status;	/* 'd' --> deleted */
	char		vid[CA_MAXVIDLEN+1];
	char		checksum_name[CA_MAXCKSUMNAMELEN+1];
	unsigned long		checksum;
	int		side;
	int		fseq;		/* file sequence number */
	unsigned char	blockid[4];	/* for positionning with locate command */
	unsigned short	d_reclen;	/* length of this entry */
	char		d_name[1];
};

struct Cns_fileclass {
	int 	classid;
	char	name[CA_MAXCLASNAMELEN+1];
	uid_t	uid;
	gid_t	gid;
	int	min_filesize;	/* in Mbytes */
	int	max_filesize;	/* in Mbytes */
	int	flags;
	int	maxdrives;
	int	max_segsize;	/* in Mbytes */
	int	migr_time_interval;
	int	mintime_beforemigr;
	int	nbcopies;
	int	retenp_on_disk;
	int	nbtppools;
	char	*tppools;
};

struct Cns_fileid {
	char		server[CA_MAXHOSTNAMELEN+1];
	u_signed64	fileid;
};

struct Cns_filestat {
	u_signed64	fileid;
	mode_t		filemode;
	nlink_t		nlink;		/* number of files in a directory */
	uid_t		uid;
	gid_t		gid;
	size_t	        filesize;
	time_t		atime;		/* last access to file */
	time_t		mtime;		/* last file modification */
	time_t		ctime;		/* last metadata modification */
	short		fileclass;	/* 1 --> experiment, 2 --> user */
	char		status;		/* ' ' --> online, 'm' --> migrated */
	dev_t		dev;
	char		path[128];
	ino_t		ino;
	char		name[128];
//	char            bitmap[600];
};

typedef struct {
	int		fd;		/* socket for communication with server */
	int		eol;		/* end of list */
	int		offset;		/* offset in buffer */
	int		len;		/* amount of data in buffer */
	char		*buf;		/* cache buffer for list entries */
} Cns_list;

struct Cns_segattrs {
	int		copyno;
	int		fsec;		/* file section number */
	u_signed64	segsize;	/* file section size */
	int		compression;	/* compression factor */
	char		s_status;	/* 'd' --> deleted */
	char		vid[CA_MAXVIDLEN+1];
	int		side;
	int		fseq;		/* file sequence number */
	unsigned char	blockid[4];	/* for positionning with locate command */
	char		checksum_name[CA_MAXCKSUMNAMELEN+1];
	unsigned long		checksum;
};

struct Cns_file_transform_stat{
ino_t  ino;
time_t  mtime;
time_t  ctime;
time_t  atime;
nlink_t  nlink;
uid_t  uid;
dev_t  dev;
gid_t  gid;
char path[128];
off_t  size;
mode_t  mode;
char filena[128];
int           fileclass;      /* 1 --> experiment, 2 --> user */
char            status;         /* '-' --> online, 'm' --> migrated */
int fileid;
int parent_fileid;
//char bitmap[600];
};


			/* function prototypes */
EXTERN_C int Cns_unlink_t(const char *path, const char *name);
EXTERN_C int Cns_setmetadata(const char *filename, struct Cns_filestat fst);
EXTERN_C int Cns_getattr_id(int fileid, struct Cns_file_transform_stat *buf);
EXTERN_C int Cns_touch_t(const char *path, char *location);
EXTERN_C int Cns_access_t(const char *path,int mask);
EXTERN_C int Cns_open_t(const char *path, int flags);
EXTERN_C int Cns_read_t(const char *path, char * buf, size_t size, off_t offset, char *remote_path);
EXTERN_C int Cns_stat_t(const char *path, struct stat *buf);
EXTERN_C int Cns_opendir_t_xrd(const char *path, int * child_dirid);
EXTERN_C int Cns_rfsync(const char *to, const char *from);
EXTERN_C int Cns_refreshcache(char *cachefile, char *sourcefile, size_t filesize);
EXTERN_C int Cns_file_create(const char *path, char *actual_path, size_t filesize);
EXTERN_C int Cns_download_seg(const char *path, off_t offset, size_t size, char *location, size_t filesize, char *buff, char *host);
EXTERN_C int Cns_cat_segmetadata(const char *path,char * data_path,int *fd,size_t *filesize, int *mode);
EXTERN_C int Cns_set_segmetadata_by_fd(const char *path, int fd, size_t size, char *physic_path, int bitmap_num);
EXTERN_C int Cns_setfile_transform_metadata(const char *filename, struct Cns_filestat fst);
EXTERN_C int Cns_get_Data_daemon(const char *path, struct Cns_filestat *filentry);
EXTERN_C int Cns_setactualpath(const char *path, char *comment);
EXTERN_C int Cns_delactualpath(const char *path);
EXTERN_C int Cns_get_virpath(const char *actual_path, char *path);
EXTERN_C int Cns_loadmetadata(const char *host, const char *path, const int depth);

EXTERN_C int xrd_read(const char *path, size_t size, off_t offset, char *buff, char *path_t, size_t filesize, char *host);
EXTERN_C int xrd_open(const char *path, int flags, mode_t mode, char * actual_path, size_t *filesize);
EXTERN_C int xrd_access(const char *path,int mask);
EXTERN_C int xrd_getattr(const char *path, struct stat *buf);
EXTERN_C int xrd_opendir(const char *path, int *child_dirid);
//EXTERN_C int xrd_readdir(const char *path, char **filename, struct stat *child_stat);
EXTERN_C int xrd_getattr_fid(int fileid, struct Cns_file_transform_stat * buf);
EXTERN_C int xrd_readdir(const char *path, vector <string> &filename, vector <struct stat> &child_stat);
EXTERN_C int xrd_rfsync(const char *from, const char *to);
EXTERN_C int xrd_refresh(char *cachefile ,char *sourcefile, size_t filesize);
EXTERN_C int xrd_unlink(char *path, char *name);
EXTERN_C int xrd_loadmetadata(char *path, int depth);

EXTERN_C int get_conf_value(char *file_path, char *key_name, char *value);
EXTERN_C int splitname(char *path, char *basename);
EXTERN_C void json_print_array(json_object *obj);
EXTERN_C void json_print_object(json_object *obj);
EXTERN_C void json_print_value(json_object *obj);
EXTERN_C int mkdirs(char *muldir, int mode);
EXTERN_C int pathsplit(char *path, char *mountpath);
EXTERN_C int SplitString(string s, vector <string>& v);
EXTERN_C int create_vpath(char *mdir, char *path, int mode);
EXTERN_C int get_metadatabyjson(char *cachefile, vector <string> &filename, vector <struct Cns_filestat> &st);
EXTERN_C void printf_cnsfilestat(int t, struct Cns_filestat st);
EXTERN_C int get_jsonbycurl(char *url_path, char *cachefile);
EXTERN_C unsigned int RSHash(char *str);

EXTERN_C int DLL_DECL Cns_access _PROTO((const char *, int));
EXTERN_C int DLL_DECL Cns_apiinit _PROTO((struct Cns_api_thread_info **));
EXTERN_C int DLL_DECL Cns_chclass _PROTO((const char *, int, char *));
EXTERN_C int DLL_DECL Cns_chdir _PROTO((const char *));
EXTERN_C int DLL_DECL Cns_chmod _PROTO((const char *, mode_t));
EXTERN_C int DLL_DECL Cns_chown _PROTO((const char *, uid_t, gid_t));
EXTERN_C int DLL_DECL Cns_close _PROTO((int));
EXTERN_C int DLL_DECL Cns_closedir _PROTO((Cns_DIR *));
EXTERN_C int DLL_DECL Cns_creat _PROTO((const char *, mode_t));
EXTERN_C int DLL_DECL Cns_creatx _PROTO((const char *, mode_t, struct Cns_fileid *));
EXTERN_C int DLL_DECL Cns_delcomment _PROTO((const char *));
EXTERN_C int DLL_DECL Cns_deleteclass _PROTO((char *, int, char *));
EXTERN_C int DLL_DECL Cns_enterclass _PROTO((char *, struct Cns_fileclass *));
EXTERN_C int DLL_DECL Cns_errmsg _PROTO((char *, char *, ...));
EXTERN_C int DLL_DECL Cns_getcomment _PROTO((const char *, char *));
EXTERN_C char DLL_DECL *Cns_getcwd _PROTO((char *, int));
EXTERN_C int DLL_DECL Cns_getpath _PROTO((char *, u_signed64, char *));
EXTERN_C int DLL_DECL Cns_getsegattrs _PROTO((const char *, struct Cns_fileid *, int *, struct Cns_segattrs **));
EXTERN_C struct Cns_fileclass DLL_DECL *Cns_listclass _PROTO((char *, int, Cns_list *));
EXTERN_C struct Cns_direntape DLL_DECL *Cns_listtape _PROTO((char *, char *, int, Cns_list *));
EXTERN_C int DLL_DECL Cns_mkdir _PROTO((const char *, mode_t));
EXTERN_C int DLL_DECL Cns_modifyclass _PROTO((char *, int, char *, struct Cns_fileclass *));
EXTERN_C int DLL_DECL Cns_open _PROTO((const char *, int, mode_t));
EXTERN_C Cns_DIR DLL_DECL *Cns_opendir _PROTO((const char *));
EXTERN_C int DLL_DECL Cns_queryclass _PROTO((char *, int, char *, struct Cns_fileclass *));
EXTERN_C struct dirent DLL_DECL *Cns_readdir _PROTO((Cns_DIR *));
EXTERN_C struct Cns_direncomm DLL_DECL *Cns_readdirc _PROTO((Cns_DIR *));
EXTERN_C struct Cns_direnstat DLL_DECL *Cns_readdirx _PROTO((Cns_DIR *));
EXTERN_C struct Cns_direnstatc DLL_DECL *Cns_readdirxc _PROTO((Cns_DIR *));
EXTERN_C struct Cns_direntape DLL_DECL *Cns_readdirxt _PROTO((Cns_DIR *));
EXTERN_C int DLL_DECL Cns_rename _PROTO((const char *, const char *));
EXTERN_C int DLL_DECL Cns_replaceseg _PROTO((char *, u_signed64, struct Cns_segattrs *, struct Cns_segattrs *));
EXTERN_C int DLL_DECL Cns_updateseg_checksum _PROTO((char *, u_signed64, struct Cns_segattrs *, struct Cns_segattrs *));
EXTERN_C void DLL_DECL Cns_rewinddir _PROTO((Cns_DIR *));
EXTERN_C int DLL_DECL Cns_rmdir _PROTO((const char *));
EXTERN_C int DLL_DECL Cns_selectsrvr _PROTO((const char *, char *, char *, char **));
EXTERN_C int DLL_DECL Cns_setatime _PROTO((const char *, struct Cns_fileid *));
EXTERN_C int DLL_DECL Cns_setcomment _PROTO((const char *, char *));
EXTERN_C int DLL_DECL Cns_seterrbuf _PROTO((char *, int));
EXTERN_C int DLL_DECL Cns_setfsize _PROTO((const char *, struct Cns_fileid *, u_signed64));
EXTERN_C int DLL_DECL Cns_setsegattrs _PROTO((const char *, struct Cns_fileid *, int, struct Cns_segattrs *));
EXTERN_C int DLL_DECL Cns_stat _PROTO((const char *, struct Cns_filestat *));
EXTERN_C int DLL_DECL Cns_statx _PROTO((const char *, struct Cns_fileid *, struct Cns_filestat *));
EXTERN_C mode_t DLL_DECL Cns_umask _PROTO((mode_t));
EXTERN_C int DLL_DECL Cns_unlink _PROTO((const char *));
EXTERN_C int DLL_DECL Cns_utime _PROTO((const char *, struct utimbuf *));
EXTERN_C int DLL_DECL send2nsd _PROTO((int *, char *, char *, int, char *, int));
EXTERN_C Cns_DIR DLL_DECL *Cns_opendir_t _PROTO((const char *));
EXTERN_C int DLL_DECL Cns_closedir_t _PROTO((Cns_DIR *));
EXTERN_C struct dirent DLL_DECL *Cns_readdir_t _PROTO((Cns_DIR *));
EXTERN_C struct Cns_direncomm DLL_DECL *Cns_readdirc_t _PROTO((Cns_DIR *));
EXTERN_C struct Cns_direnstat DLL_DECL *Cns_readdirx_t _PROTO((Cns_DIR *));
EXTERN_C struct Cns_direnstatc DLL_DECL *Cns_readdirxc_t _PROTO((Cns_DIR *));
EXTERN_C struct Cns_direntape DLL_DECL *Cns_readdirxt_t _PROTO((Cns_DIR *));
#endif

