/* @(#)procfs.h	1.1 09/08/07 Copyright 2009 J. Schilling */
/*
 *	Abstraction code for the process filesystem
 *
 *	Copyright (c) 2009 J. Schilling
 */
/*
 * The contents of this file are subject to the terms of the
 * Common Development and Distribution License, Version 1.0 only
 * (the "License").  You may not use this file except in compliance
 * with the License.
 *
 * See the file CDDL.Schily.txt in this distribution for details.
 * A copy of the CDDL is also available via the Internet at
 * http://www.opensource.org/licenses/cddl1.txt
 *
 * When distributing Covered Code, include this CDDL HEADER in each
 * file and include the License file CDDL.Schily.txt from this distribution.
 */

#ifndef	_SCHILY_PROCFS_H
#define	_SCHILY_PROCFS_H

#ifndef _SCHILY_MCONFIG_H
#include <schily/mconfig.h>
#endif

#ifdef	HAVE_PROCFS_H
#ifndef	_INCL_PROCFS_H
#define	_INCL_PROCFS_H
#include <procfs.h>
#endif
#else
#ifdef	HAVE_SYS_PROCFS_H
#ifndef	_INCL_SYS_PROCFS_H
#define	_INCL_SYS_PROCFS_H
#include <sys/procfs.h>
#endif
#endif
#endif

#endif	/* _SCHILY_PROCFS_H */
