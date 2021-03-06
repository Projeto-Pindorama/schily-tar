/* @(#)dbgmalloc.h	1.11 19/04/03 Copyright 2009-2019 J. Schilling */
/*
 *	Definitions for libdmalloc
 *
 *	Copyright (c) 2009-2019 J. Schilling
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

#ifndef	_SCHILY_DBGMALLOC_H
#define	_SCHILY_DBGMALLOC_H

#ifndef _SCHILY_MCONFIG_H
#include <schily/mconfig.h>
#endif

#ifdef	DBG_MALLOC
#include <schily/types.h>
#include <schily/stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern	void	*dbg_malloc		__PR((size_t size, char *file,
							int line));
extern	void	*dbg_calloc		__PR((size_t nelem, size_t elsize,
							char *file, int line));
extern	void	*dbg_realloc		__PR((void *t, size_t size, char *file,
							int line));
extern	void	dbg_mark_alloc		__PR((void *t, char *file, int line));

#define	malloc(s)			dbg_malloc(s, __FILE__, __LINE__)
#define	calloc(n, s)			dbg_calloc(n, s, __FILE__, __LINE__)
#define	realloc(t, s)			dbg_realloc(t, s, __FILE__, __LINE__)

#define	DBG_MALLOC_MARK(a)		dbg_mark_alloc((a), __FILE__, __LINE__)

#ifdef __cplusplus
}
#endif

#else
#undef	DBG_MALLOC_MARK
#define	DBG_MALLOC_MARK(a)
#endif	/* DBG_MALLOC */

#ifdef	USE_JS_BOOL			/* #define USE_JS_BOOL if there is a */
#define	BOOL	JS_BOOL			/* different (incompatible) BOOL in  */
#endif					/* the using code		    */
#include <schily/standard.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef	FALSE
extern	int	acheckdamage		__PR((void));
extern	void	freechecking		__PR((int val));
extern	void	nomemraising		__PR((int val));
#else
extern	BOOL	acheckdamage		__PR((void));
extern	void	freechecking		__PR((BOOL val));
extern	void	nomemraising		__PR((BOOL val));
#endif

#if	defined(_SCHILY_STDIO_H) && defined(EOF)
extern	void	aprintfree		__PR((FILE *f));
extern	void	aprintlist		__PR((FILE *f, long l));
extern	void	aprintchunk		__PR((FILE *f, long l));
#else
extern	void	aprintfree		__PR((void *f));
extern	void	aprintlist		__PR((void *f, long l));
extern	void	aprintchunk		__PR((void *f, long l));
#endif

extern	size_t	apsize			__PR((char *t));
extern	void	*get_heapbeg		__PR((void));
extern	void	*get_heapend		__PR((void));

#ifdef	USE_JS_BOOL			/* If in workaround mode, */
#undef	BOOL				/* revert to default BOOL */
#endif

#ifdef __cplusplus
}
#endif

#endif	/* _SCHILY_DBGMALLOC_H */
