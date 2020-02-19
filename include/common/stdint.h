/*
 * SPDX-License-Identifier: CC0-1.0
 * stdint.h standard C header
 */

#ifndef _STDINT_H
#define _STDINT_H

#include <zeno/integer_constants.h>
#include <zeno/stdint.h>

#define __STDC_VERSION_STDINT_H__ 202001L

/*
 * Macros for integer constants.
 */

#define INT8_C(c)    _LIBC_INT8_C(c)
#define UINT8_C(c)   _LIBC_UINT8_C(c)
#define INT16_C(c)   _LIBC_INT16_C(c)
#define UINT16_C(c)  _LIBC_UINT16_C(c)
#define INT32_C(c)   _LIBC_INT32_C(c)
#define UINT32_C(c)  _LIBC_UINT32_C(c)
#define INT64_C(c)   _LIBC_INT64_C(c)
#define UINT64_C(c)  _LIBC_UINT64_C(c)
#define INTMAX_C(c)  INT64_C(c)
#define UINTMAX_C(c) UINT64_C(c)

/*
 * Exact-width integer types.
 */

#define INT8_WIDTH  8
#define INT16_WIDTH 16
#define INT32_WIDTH 32
#define INT64_WIDTH 64

#define UINT8_WIDTH  8
#define UINT16_WIDTH 16
#define UINT32_WIDTH 32
#define UINT64_WIDTH 64

typedef __libc_int8_t int8_t;
typedef __libc_uint8_t uint8_t;
typedef __libc_int16_t int16_t;
typedef __libc_uint16_t uint16_t;
typedef __libc_int32_t int32_t;
typedef __libc_uint32_t uint32_t;
typedef __libc_int64_t int64_t;
typedef __libc_uint64_t uint64_t;

#define INT8_MAX  _LIBC_INT8_MAX
#define INT16_MAX _LIBC_INT8_MAX
#define INT32_MAX _LIBC_INT8_MAX
#define INT64_MAX _LIBC_INT8_MAX

#define INT8_MIN  _LIBC_INT8_MIN
#define INT16_MIN _LIBC_INT16_MIN
#define INT32_MIN _LIBC_INT32_MIN
#define INT64_MIN _LIBC_INT64_MIN

#define UINT8_MAX  _LIBC_UINT8_MAX
#define UINT16_MAX _LIBC_UINT16_MAX
#define UINT32_MAX _LIBC_UINT32_MAX
#define UINT64_MAX _LIBC_UINT64_MAX

/*
 * Minimum-width integer types.
 */

#define INT_LEAST8_WIDTH  8
#define INT_LEAST16_WIDTH 16
#define INT_LEAST32_WIDTH 32
#define INT_LEAST64_WIDTH 64

#define UINT_LEAST8_WIDTH  8
#define UINT_LEAST16_WIDTH 16
#define UINT_LEAST32_WIDTH 32
#define UINT_LEAST64_WIDTH 64

typedef int8_t int_least8_t;
typedef uint8_t uint_least8_t;
typedef int16_t int_least16_t;
typedef uint16_t uint_least16_t;
typedef int32_t int_least32_t;
typedef uint32_t uint_least32_t;
typedef int64_t int_least64_t;
typedef uint64_t uint_least64_t;

#define INT_LEAST8_MAX  INT8_MAX
#define INT_LEAST16_MAX INT16_MAX
#define INT_LEAST32_MAX INT32_MAX
#define INT_LEAST64_MAX INT64_MAX

#define INT_LEAST8_MIN  INT8_MIN
#define INT_LEAST16_MIN INT16_MIN
#define INT_LEAST32_MIN INT32_MIN
#define INT_LEAST64_MIN INT64_MIN

#define UINT_LEAST8_MAX  UINT8_MAX
#define UINT_LEAST16_MAX UINT16_MAX
#define UINT_LEAST32_MAX UINT32_MAX
#define UINT_LEAST64_MAX UINT64_MAX

/*
 * Fastest minimum-width integer types.
 */

#define INT_FAST8_WIDTH  _LIBC_INT_FAST8_WIDTH
#define INT_FAST16_WIDTH _LIBC_INT_FAST16_WIDTH
#define INT_FAST32_WIDTH _LIBC_INT_FAST32_WIDTH
#define INT_FAST64_WIDTH _LIBC_INT_FAST64_WIDTH

#define UINT_FAST8_WIDTH  INT_FAST8_WIDTH
#define UINT_FAST16_WIDTH INT_FAST16_WIDTH
#define UINT_FAST32_WIDTH INT_FAST32_WIDTH
#define UINT_FAST64_WIDTH INT_FAST64_WIDTH

typedef __libc_int_t(INT_FAST8_WIDTH) int_fast8_t;
typedef __libc_uint_t(INT_FAST8_WIDTH) uint_fast8_t;
typedef __libc_int_t(INT_FAST16_WIDTH) int_fast16_t;
typedef __libc_uint_t(INT_FAST16_WIDTH) uint_fast16_t;
typedef __libc_int_t(INT_FAST32_WIDTH) int_fast32_t;
typedef __libc_uint_t(INT_FAST32_WIDTH) uint_fast32_t;
typedef __libc_int_t(INT_FAST64_WIDTH) int_fast64_t;
typedef __libc_uint_t(INT_FAST64_WIDTH) uint_fast64_t;

#define INT_FAST8_MAX  _LIBC_INT_MAX(INT_FAST8_WIDTH)
#define INT_FAST16_MAX _LIBC_INT_MAX(INT_FAST16_WIDTH)
#define INT_FAST32_MAX _LIBC_INT_MAX(INT_FAST32_WIDTH)
#define INT_FAST64_MAX _LIBC_INT_MAX(INT_FAST64_WIDTH)

#define INT_FAST8_MIN  _LIBC_INT_MIN(INT_FAST8_WIDTH)
#define INT_FAST16_MIN _LIBC_INT_MIN(INT_FAST16_WIDTH)
#define INT_FAST32_MIN _LIBC_INT_MIN(INT_FAST32_WIDTH)
#define INT_FAST64_MIN _LIBC_INT_MIN(INT_FAST64_WIDTH)

#define UINT_FAST8_MAX  _LIBC_UINT_MAX(INT_FAST8_WIDTH)
#define UINT_FAST16_MAX _LIBC_UINT_MAX(INT_FAST16_WIDTH)
#define UINT_FAST32_MAX _LIBC_UINT_MAX(INT_FAST32_WIDTH)
#define UINT_FAST64_MAX _LIBC_UINT_MAX(INT_FAST64_WIDTH)

/*
 * Integer types capable of holding object pointers.
 */

#define INTPTR_WIDTH  _LIBC_INTPTR_WIDTH
#define UINTPTR_WIDTH INTPTR_WIDTH

#ifdef _LIBC_INTPTR_IS_LONG32
typedef long intptr_t;
typedef unsigned long uintptr_t;
#define INTPTR_MAX  0x7fffffffL
#define UINTPTR_MAX 0xffffffffUL
#else
typedef __libc_int_t(INTPTR_WIDTH) intptr_t;
typedef __libc_uint_t(INTPTR_WIDTH) uintptr_t;
#define INTPTR_MAX  _LIBC_INT_MAX(INTPTR_WIDTH)
#define UINTPTR_MAX _LIBC_UINT_MAX(INTPTR_WIDTH)
#endif

#define INTPTR_MIN (-INTPTR_MAX - 1)

/*
 * Greatest-width integer types.
 */

#define INTMAX_WIDTH  64
#define UINTMAX_WIDTH 64

typedef int64_t intmax_t;
typedef uint64_t uintmax_t;

#define INTMAX_MIN  INT64_MIN
#define INTMAX_MAX  INT64_MAX
#define UINTMAX_MAX UINT64_MAX

/*
 * Other integer types.
 */

#define PTRDIFF_WIDTH    _LIBC_PTRDIFF_WIDTH
#define SIG_ATOMIC_WIDTH _LIBC_SIG_ATOMIC_WIDTH
#define SIZE_WIDTH       _LIBC_SIZE_WIDTH
#define WCHAR_WIDTH      _LIBC_WCHAR_WIDTH
#define WINT_WIDTH       _LIBC_WINT_WIDTH

#ifdef _LIBC_PTRDIFF_IS_LONG32
#define PTRDIFF_MAX 0x7fffffffL
#else
#define PTRDIFF_MAX _LIBC_INT_MAX(PTRDIFF_WIDTH)
#endif

#define PTRDIFF_MIN (-PTRDIFF_MAX - 1)

#if _LIBC_SIG_ATOMIC_UNSIGNED
#define SIG_ATOMIC_MIN _LIBC_INT_C(SIG_ATOMIC_WIDTH)(0)
#define SIG_ATOMIC_MAX _LIBC_UINT_MAX(SIG_ATOMIC_WIDTH)
#else
#define SIG_ATOMIC_MIN _LIBC_INT_MIN(SIG_ATOMIC_WIDTH)
#define SIG_ATOMIC_MAX _LIBC_INT_MAX(SIG_ATOMIC_WIDTH)
#endif

#ifdef _LIBC_SIZE_IS_ULONG32
#define SIZE_MAX 0xffffffffUL
#else
#define SIZE_MAX _LIBC_UINT_MAX(SIZE_WIDTH)
#endif

#if _LIBC_WCHAR_UNSIGNED
#define WCHAR_MIN _LIBC_INT_C(WCHAR_WIDTH)(0)
#define WCHAR_MAX _LIBC_UINT_MAX(WCHAR_WIDTH)
#else
#define WCHAR_MIN _LIBC_INT_MIN(WCHAR_WIDTH)
#define WCHAR_MAX _LIBC_INT_MIN(WCHAR_WIDTH)
#endif

#if _LIBC_WINT_UNSIGNED
#define WINT_MIN _LIBC_INT_C(WINT_WIDTH)(0)
#define WINT_MAX _LIBC_UINT_MAX(WINT_WIDTH)
#else
#define WINT_MIN _LIBC_INT_MIN(WINT_WIDTH)
#define WINT_MAX _LIBC_INT_MIN(WINT_WIDTH)
#endif

#endif
