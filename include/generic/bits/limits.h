/*
 * SPDX-License-Identifier: CC0-1.0
 * bits/limits.h private header - private limits.h definitions
 */

#ifndef _BITS_LIMITS_H
#define _BITS_LIMITS_H

#define _LIBC_BOOL_WIDTH 8
#define _LIBC_CHAR_WIDTH 8
#define _LIBC_SHRT_WIDTH 16
#define _LIBC_INT_WIDTH  32

#ifdef __LONG_WIDTH__
#define _LIBC_LONG_WIDTH __LONG_WIDTH__
#elif __LONG_MAX__ == 0x7fffffff
#define _LIBC_LONG_WIDTH 32
#elif __LONG_MAX__ == 0x7fffffffffffffff
#define _LIBC_LONG_WIDTH 64
#else
#error "Could not determine LONG_WIDTH."
#endif

#define _LIBC_LLONG_WIDTH 64

#if '\0' - 1 > 0
#define _LIBC_CHAR_UNSIGNED 1
#else
#define _LIBC_CHAR_UNSIGNED 0
#endif

#endif
