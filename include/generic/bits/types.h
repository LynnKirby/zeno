/*
 * SPDX-License-Identifier: CC0-1.0
 * bits/types.h private header - private definitions of common types
 */

#ifndef _BITS_TYPES_H
#define _BITS_TYPES_H

#include <bits/config.h>
#include <bits/stdint.h>

#if _LIBC_CONFIG_PTRDIFF_IS_LONG32
typedef long __libc_ptrdiff_t;
#else
typedef __libc_int_t(_LIBC_PTRDIFF_WIDTH) __libc_ptrdiff_t;
#endif

#if _LIBC_CONFIG_SIZE_IS_ULONG32
typedef unsigned long __libc_size_t;
typedef long __libc_ssize_t;
#else
typedef __libc_uint_t(_LIBC_SIZE_WIDTH) __libc_size_t;
typedef __libc_int_t(_LIBC_SIZE_WIDTH) __libc_ssize_t;
#endif

#if _LIBC_WCHAR_UNSIGNED
typedef __libc_uint_t(_LIBC_WCHAR_WIDTH) __libc_wchar_t;
#else
typedef __libc_int_t(_LIBC_WCHAR_WIDTH) __libc_wchar_t;
#endif

#endif
