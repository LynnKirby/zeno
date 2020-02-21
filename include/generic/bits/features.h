/*
 * SPDX-License-Identifier: CC0-1.0
 * bits/features.h private header
 */

#ifndef _BITS_FEATURES_H
#define _BITS_FEATURES_H

/* Set to default if no feature test macros are defined. */
#if !defined(_POSIX_SOURCE) && !defined(_POSIX_C_SOURCE) \
    && !defined(_XOPEN_SOURCE) && !defined(__STRICT_ANSI__)
#define _XOPEN_SOURCE 700
#endif

/* Handle POSIX feature macros. Don't bother with the version, give it all. */
#if defined(_POSIX_SOURCE) || defined(_POSIX_C_SOURCE) || defined(_XOPEN_SOURCE)
#define _LIBC_POSIX_VISIBLE 1
#endif

#endif
