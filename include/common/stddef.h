/*
 * SPDX-License-Identifier: CC0-1.0
 * stddef.h standard C header
 */

#ifndef _STDDEF_H
#define _STDDEF_H

#include <zeno/null.h>
#include <zeno/types.h>

typedef __libc_ptrdiff_t ptrdiff_t;
typedef __libc_size_t size_t;
typedef __libc_wchar_t wchar_t;

#define offsetof(t, m) __builtin_offsetof(t, m)

typedef struct {
    long long __max_align_ll
        __attribute__((__aligned__(__alignof__(long long))));
    long double __max_align_ld
        __attribute__((__aligned__(__alignof__(long double))));
#if defined(__i386__)
    __float128 __max_align_f128
        __attribute__((__aligned__(__alignof(__float128))));
#endif
} max_align_t;

#endif
