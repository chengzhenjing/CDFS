/*
 * stage_messages.h,v 1.22 2003/05/13 09:34:32 jdurand Exp
 */

#ifndef __stage_messages_h
#define __stage_messages_h

#define STG00	"STG00 - stage daemon not available on %s (%s)\n"
#define STG01	"STG01 - no response from stage daemon\n"
#define STG02	"STG02 - %s : %s error : %s\n"
#define STG03   "STG03 - illegal function %d\n"
#define STG04   "STG04 - error reading request %s, read %d bytes but expected %d ones from %s (errno=%d [%s] - serrno=%d [%s])\n"
#define STG05	"STG05 - cannot get memory\n"
#define STG06	"STG06 - invalid value for option %s\n"
#define	STG07	"STG07 - pathname is mandatory\n"
#define STG08	"STG08 - incorrect pathname %s\n"
#define	STG09	"STG09 - fatal configuration error: %s %s\n"
#define	STG10	"STG10 - option G not allowed for user of group %s\n"
#define	STG11	"STG11 - invalid user: %s\n"
#define	STG12	"STG12 - vsn, vid or external_filename must be specified\n"
#define	STG13	"STG13 - duplicate option %s\n"
#define	STG14	"STG14 - too many vsns specified\n"
#define	STG15	"STG15 - parameter inconsistency with TMS: %s<->%s\n"
#define	STG16	"STG16 - extraneous parameter\n"
#define	STG17	"STG17 - option %s is invalid for %s\n"
#define	STG18	"STG18 - trailing dash in -q option is only valid for stagein\n"
#define	STG19	"STG19 - incorrect number of filenames specified\n"
#define	STG20	"STG20 - record length must be specified with recfm F\n"
#define	STG21	"STG21 - fseq string is too long\n"
#define	STG22	"STG22 - could not find corresponding stage request\n"
#define	STG23	"STG23 - %s is not accessible\n"
#define	STG24	"STG24 - pool %s is empty\n"
#define	STG25	"STG25 - %s name is missing\n"
#define	STG26	"STG26 - invalid description of %s %s\n"
#define	STG27	"STG27 - %s name %s is too long\n"
#define	STG28	"STG28 - missing or invalid value for DEFSIZE\n"
#define	STG29	"STG29 - no staging pool described\n"
#define	STG30	"STG30 - a default pool must be defined\n"
#define	STG31	"STG31 - staging host must be defined in configuration file\n"
#define	STG32	"STG32 - %s is not in the list of pools\n"
#define	STG33	"STG33 - %s : %s\n"
#define	STG34	"STG34 - program name must be stagein, stageout, stagewrt or stagecat\n"
#define	STG35	"STG35 - option(s) %s and %s are mutually exclusive\n"
#define	STG36	"STG36 - invalid group: %d\n"
#define	STG37	"STG37 - another request for same file is in progress\n"
#define	STG38	"STG38 - stage request too long\n"
#define	STG39	"STG39 - another stageinit is pending\n"
#define	STG40	"STG40 - another entry for same file exists already in catalog\n"
#define	STG41	"STG41 - %s %s for file %s on %s, return code %d\n\n"
#define	STG42	"STG42 - %s %s for file %s, return code %d\n\n"
#define	STG43	"STG43 - Retrying command, retry number %d\n\n"
#define	STG44	"STG44 - staging in afs directory is not supported\n"
#define	STG45	"STG45 - unable to allocate requested space (pool %s)\n"
#define	STG46	"STG46 - vid, linkname, internal or external filename must be specified\n"
#define	STG47	"STG47 - %s\n"
#define	STG48	"STG48 - the catalog %s seems to be corrupted\n"
#define	STG49	"STG49 - poolname mismatch: %s belongs to pool %s\n"
#define	STG50	"STG50 - poolname mismatch: %s does not belong to any pool\n"
#if defined(_WIN32)
#define	STG51	"STG51 - WSAStartup unsuccessful\n"
#define	STG52	"STG52 - you are not registered in the unix group/passwd mapping file\n"
#define	STG53	"STG53 - %s error %d\n"
#endif
#define	STG54	"STG54 - HSM hostname not specified\n"
#define	STG55	"STG55 - migrator name %s not defined\n"
#define	STG56	"STG56 - migration policy of migrator %s is not defined\n"
#define	STG57	"STG57 - Fileclass %s (classid %d) on name server %s (internal index %d) error : %s : %s\n"
#define	STG58	"STG58 - another stageshutdown is pending\n"
#define	STG59	"STG59 - Duplicate HSM file %s\n"
#define	STG60	"STG60 - Duplicated file sequence %s reduced by one\n"
/*
 * Old vms support was defining STG80 to STG83
 */
#define	STG92	"STG92 - %s request by %s (%d,%d) from %s\n"
#define	STG93	"STG93 - removing link %s\n"
#define	STG94	"STG94 - creating link %s\n"
#define	STG95	"STG95 - %s cleared by %s\n"
#define	STG96	"STG96 - %s already staged, size = %s (%.1f MB), nbaccess = %d\n"
#define	STG97	"STG97 - %s:%s staged by (%s,%s), server %s  unit %s  ifce %s  size %s  wtim %d  ttim %d rc %d\n"
#define	STG98	"STG98 - %s\n"
#define	STG99	"STG99 - stage returns %d\n"
#define STG100  "STG100 - Database %s error (%s) at %s:%d\n"
#define STG101  "STG101 - HSM File %s previously staged under name %s (fileid %s@%s), catalog updated\n"
#define STG102  "STG102 - Mixed %s HSM host with %s HSM filename: %s\n"
#define STG103  "STG103 - -F option is only for admin\n"
#define STG104  "STG104 - Internal error: status=0x%x but req not in waitq - Ask admin to try with -F option\n"
#define STG105  "STG105 - Internal error in %s : %s\n"
#define STG106  "STG106 - Internal error in %s for %s: %s\n"
#define	STG107	"STG107 - %s:%s segment %d staged by (%s,%s), server %s  unit %s  ifce %s  size %s  wtim %d  ttim %d rc %d\n"
#define	STG108	"STG108 - %s:%s staged in %d tries by (%s,%s), actual_size %s size %s rc %d\n"
#define	STG109	"STG109 - New fileclass %s@%s (classid %d), internal index %d\n"
#define STG110  "STG110 - Internal error in %s for pool %s, class %s@%s: %s\n"
#define STG111  "STG111 - Last used tape pool \"%s\" unknown to fileclass %s@%s (classid %d)\n"
#define STG112  "STG112 - %s already have %d copies (its current fileclass specifies %d cop%s), not migrated\n"
#define STG113  "STG113 - Cannot find next tape pool - use the first in the list\n"
#define STG114  "STG114 - Found more files to migrate (%d) that what is known in advance (%d)\n"
#define STG115  "STG115 - Reqid %d (%s) have no tape pool associated yet\n"
#define STG116  "STG116 - Not all input records have a tape pool\n"
#define STG117  "STG117 - Inputs No %d (%s) and %d (%s) differs vs. their tape pool (\"%s\" and \"%s\")\n"
#define STG118  "STG118 - Error: fileclass %s and another previous one share tape pool \"%s\" but have different %s values (%d and %d)\n"
#define STG119  "STG119 - Missing file path argument for HSM files %s\n"
#define STG120  "STG120 - %s already has a tppool assigned (\"%s\") - not expanded with respect to its class %s@%s (classid %d)\n"
#define STG121  "STG121 - No tape pool\n"
#define STG122  "STG122 - Bad tape pool \"%s\"\n"
#define STG123  "STG123 - (Warning) tape %s mounted but no segment writen at expected fseq %d, tape flagged %s\n"
#define STG124  "STG124 - Shutdown\n"
#define STG125  "STG125 - Your account \"%s\" (%s=%d) does not have the correct %s id (should be %d) to migrate %s\n"
#define STG126  "STG126 - Fileclass %s@%s (classid %d) have %d number of copies - Please contact your admin - rejected\n"
#define STG127  "STG127 - Fileclass %s@%s (classid %d) claims %d tape pools while we found %d of them - Please contact your admin - updated\n"
#define STG128  "STG128 - Fileclass %s@%s (classid %d) have duplicated tape pool %s - Please contact your admin  - duplicate removed\n"
#define STG129  "STG129 - Fileclass %s@%s (classid %d) have its number of tape pools finally reduced from %d to %d\n"
#define STG130  "STG130 - Fileclass %s@%s (classid %d) have %d number of copies v.s. %d tppools - copies possible reduced to %d\n"
#define STG131  "STG131 - %s not removed - Retention period %d > %d (now)\n"
#define STG132  "STG132 - %s fileclass : %s\n"
#define STG133  "STG133 - %s : Fileclass %s@%s (classid %d) specified retention period %d v.s. %d (now)\n"
#define STG134  "STG134 - Tape %s is not accessible (%s status)\n"
#define STG135  "STG135 - Stream No %d : %d HSM files - %s bytes - tape pool %s\n"
#define STG136  "STG136 - %s (copy number No %d) claims that start segment No %d is ok, while its segment No %d (same copy number) is NOT - Please contact your admin - copy number No %d declared non valid for recall\n"
#define STG137  "STG137 - %s (copy number No %d) : segment No %d not taken into account because of segment No %d - Please contact your admin\n"
#define STG138  "STG138 - Fileclass %s@%s (classid %d) : specifies %d nbcopies and %d nbtppools - only both zero or both non-zero is legal - invalid fileclass - Please contact your admin\n"
#define STG139  "STG139 - %s : fileclass %s@%s (classid %d) specifies %d nbcopies and %d nbtppools - this file will not be migrated\n"
#define	STG140	"STG140 - %s : could not find corresponding entry in catalog\n"
#define	STG141	"STG141 - Invalid magic number 0x%lx\n"
#define STG142  "STG142 - %s not removed - Retention period is %s\n"
#define STG143  "STG143 - %s : %s lifetime on disk exceeds %d day%s - %s\n"
/* NOT USED #define STG144  "STG144 - %s : retention period on disk is %d second%s (%s value)\n" */
/* NOT USED #define STG145  "STG145 - %s : retention period on disk changed from %d second%s (%s value) to %d second%s (%s value)\n" */
/* NOT USED #define STG146  "STG146 - %s : retention period on disk unchanged to %d second%s (%s value)\n" */
#define STG147  "STG147 - invalid value for option %s, maximum value is %s\n"
#define	STG148	"STG148 - Configuration warning: %s %s %d\n"
#define STG149  "STG149 - %s : will not be migrated until pool %s have an associated migrator\n"
#define STG150  "STG150 - %s : mintime_beforemigr unchanged to %d second%s (%s value)\n"
#define STG151  "STG151 - %s : mintime_beforemigr cannot be higher than %d second%s (%s value)\n"
#define STG152  "STG152 - %s : mintime_beforemigr changed from %d second%s (%s value) to %d second%s (%s value)\n"
#define STG153  "STG153 - %s : %s (pool %s)\n"
#define STG154  "STG154 - HSM File %s was renamed to %s (fileid %s@%s), catalog updated for reqid=%d\n"
#define STG155  "STG155 - HSM File %s, pool %s, fileid %s@%s moved from DELAY_MIGR to CAN_BE_MIGR\n"
#define STG156  "STG156 - Requests from (uid,gid) smaller than (%d,%d) are rejected\n"
#define STG157  "STG157 - HSM File %s was renamed to %s (fileid %s@%s), input updated\n"
#define STG158  "STG158 - %s : Fileclass %s@%s (classid %d) retention period %d is overwriten to %d\n"
#define STG159  "STG159 - %s : Tape pools differ : \"%s\" v.s. \"%s\" - Catalog updated\n"
#define STG160  "STG160 - Reaching system maximum number of file descriptors (%ld) - Please wait\n"
#define STG161  "STG161 - Stage not available or in pause mode - Please wait\n"
#define STG162  "STG162 - Stage will shutdown - Please retry later\n"
#define STG163  "STG163 - Pool %s have gc_start_thresh (%d) >= gc_stop_thread (%d)\n"
#define STG164  "STG164 - %s : wrong poolname \"%s\" - changed to \"%s\"\n"
#define STG165  "STG165 - %s : bad copy number %s (should be > 0)\n"
#define STG166  "STG166 - %s : not found within current pool definition\n"
#define STG167  "STG167 - %s : loop detected in filesystem selection\n"
#define STG168  "STG168 - %s : fileclass %s@%s (classid %d) specifies a %s filesize of %dM, yours is %s bytes (%s) - this file will not be migrated\n"
#define STG169  "STG169 - %s : refered by two physical files (%s and %s)\n"
#define STG170  "STG170 - %s : Ok for reqid=%d but reqid=%d should be in STAGEOUT|CAN_BE_MIGR|PUT_FAILED or STAGEOUT|PUT_FAILED status\n"
#define STG171  "STG171 - %s : size in name server (%s) != size on disk (%s)\n"
#define	STG172  "STG172 - Duplicate HSM file %s skipped because same invariants (fileid=%s@%s)\n"
#define STG173  "STG173 - %s : Fileclass changed from %d to %d (fileid %s@%s), catalog updated for reqid=%d\n"
#define	STG174  "STG174 - %s (fileid=%s@%s) %s : %s error : %s\n"
#define	STG175  "STG175 - %s (fileid=%s@%s) %s\n"
#define STG176  "STG176 - %s : fileclass %s@%s (classid %d) specifies a (uid=%ld,gid=%ld) filter and yours (%ld,%ld) do not match - this file will not be migrated\n"
#define STG177  "STG177 - %s : retention period of %s seconds expired\n"
#define STG178  "STG178 - Pool %s have metapool %s yet existing as a real pool name\n"
#define	STG179	"STG179 - Metapool %s can be used only for recall in explicit read-only mode\n"
#define	STG180	"STG180 - Metapool %s translated to pool %s\n"
#define	STG199	"STG199 - stage returns %d\n"

/* Special message - a mimic of STG02 only for use with TAPE error message, when side is > 0 */
#define STG202	"STG202 - %s/%d : %s error : %s\n"

#endif /* __stage_messages_h */
