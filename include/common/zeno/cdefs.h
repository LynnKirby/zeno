/*
 * SPDX-License-Identifier: CC0-1.0
 * zeno/cdefs.h private header - common definitions and macros
 */

#ifndef _ZENO_CDEFS_H
#define _ZENO_CDEFS_H

#define __LIBC_CONCAT3(a, b, c) a##b##c
#define _LIBC_CONCAT3(a, b, c)  __LIBC_CONCAT3(a, b, c)

#if __STDC_VERSION__ >= 199901L
#define __libc_restrict restrict
#elif defined(__GNUC__)
#define __libc_restrict __restrict
#else
#define __libc_restrict
#endif

#endif
