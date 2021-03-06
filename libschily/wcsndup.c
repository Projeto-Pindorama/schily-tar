/* @(#)wcsndup.c	1.2 10/07/21 Copyright 2003-2010 J. Schilling */
#include <schily/mconfig.h>
#ifndef lint
static	UConst char sccsid[] =
	"@(#)wcsndup.c	1.2 10/07/21 Copyright 2003-2010 J. Schilling";
#endif
/*
 *	wcsndup() to be used if missing in libc
 *
 *	Copyright (c) 2003-2010 J. Schilling
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

#include <schily/standard.h>
#include <schily/stdlib.h>
#include <schily/string.h>
#include <schily/unistd.h>
#include <schily/wchar.h>
#include <schily/schily.h>
#include <schily/libport.h>

#ifndef	HAVE_WCSNDUP

EXPORT wchar_t *
wcsndup(s, len)
	const wchar_t	*s;
	size_t		len;
{
	size_t	i	= wcsnlen(s, len) + 1;
	wchar_t	 *res	= malloc(i);

	if (res == NULL)
		return (NULL);
	if (i > 16) {
		movebytes(s, res, --i);
		res[i] = '\0';
	} else {
		wchar_t	*s2 = res;

		while (--i > 0 && (*s2++ = *s++) != '\0')
			;
		if (i == 0)
			*s2 = '\0';
	}
	return (res);
}
#endif	/* HAVE_STRDUP */
