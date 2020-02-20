/*
 * SPDX-License-Identifier: CC0-1.0
 * bits/integer_constants.h private header - constants for exact-width integers
 */

#ifndef _BITS_INTEGER_CONSTANTS_H
#define _BITS_INTEGER_CONSTANTS_H

#include <bits/cdefs.h>
#include <bits/limits.h>

/*
 * Macros to access the definitions below by width.
 */

#define _LIBC_INT_C(n)  _LIBC_CONCAT3(_LIBC_INT, n, _C)
#define _LIBC_UINT_C(n) _LIBC_CONCAT3(_LIBC_UINT, n, _C)

#define _LIBC_INT_MIN(n)  _LIBC_CONCAT3(_LIBC_INT, n, _MIN)
#define _LIBC_INT_MAX(n)  _LIBC_CONCAT3(_LIBC_INT, n, _MAX)
#define _LIBC_UINT_MAX(n) _LIBC_CONCAT3(_LIBC_UINT, n, _MAX)

/*
 * Macros for integer constants.
 */

#define _LIBC_INT8_C(c)   c
#define _LIBC_UINT8_C(c)  c
#define _LIBC_INT16_C(c)  c
#define _LIBC_UINT16_C(c) c
#define _LIBC_INT32_C(c)  c
#define _LIBC_UINT32_C(c) c##U

#if _LIBC_LONG_WIDTH == 64
#define _LIBC_INT64_C(c)  c##L
#define _LIBC_UINT64_C(c) c##UL
#else
#define _LIBC_INT64_C(c)  c##LL
#define _LIBC_UINT64_C(c) c##ULL
#endif

/*
 * Maximal and minimal values of exact-width integer types.
 */

#define _LIBC_INT8_MAX  _LIBC_INT8_C(0x7f)
#define _LIBC_INT16_MAX _LIBC_INT16_C(0x7fff)
#define _LIBC_INT32_MAX _LIBC_INT32_C(0x7fffffff)
#define _LIBC_INT64_MAX _LIBC_INT64_C(0x7fffffffffffffff)

#define _LIBC_INT8_MIN  (-_LIBC_INT8_MAX - 1)
#define _LIBC_INT16_MIN (-_LIBC_INT16_MAX - 1)
#define _LIBC_INT32_MIN (-_LIBC_INT32_MAX - 1)
#define _LIBC_INT64_MIN (-_LIBC_INT64_MAX - 1)

#define _LIBC_UINT8_MAX  _LIBC_UINT8_C(0xff)
#define _LIBC_UINT16_MAX _LIBC_UINT16_C(0xffff)
#define _LIBC_UINT32_MAX _LIBC_UINT32_C(0xffffffff)
#define _LIBC_UINT64_MAX _LIBC_UINT64_C(0xffffffffffffffff)

#endif
