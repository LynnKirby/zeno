/*
 * SPDX-License-Identifier: CC0-1.0
 * bits/null.h private header - defining NULL
 */

#ifndef NULL

#if !defined(__cplusplus)
#define NULL ((void *)0)
#elif __cplusplus >= 201103L
#define NULL nullptr
#elif defined(__GNUG__)
#define NULL __null
#else
#define NULL 0L
#endif

#endif
