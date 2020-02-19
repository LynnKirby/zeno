/*
 * SPDX-License-Identifier: CC0-1.0
 * zeno/stdint.h private header - private stdint.h definitions
 */

#ifndef _ZENO_STDINT_H
#define _ZENO_STDINT_H

/*
 * Macros to access exact-width integer types by width.
 */

#define ___libc_int_t(n) __libc_int##n##_t
#define __libc_int_t(n)  ___libc_int_t(n)

#define ___libc_uint_t(n) __libc_uint##n##_t
#define __libc_uint_t(n)  ___libc_uint_t(n)

/*
 * Exact-width integer types.
 */

#ifdef __INT8_TYPE__
typedef __INT8_TYPE__ __libc_int8_t;
typedef __UINT8_TYPE__ __libc_uint8_t;
typedef __INT16_TYPE__ __libc_int16_t;
typedef __UINT16_TYPE__ __libc_uint16_t;
typedef __INT32_TYPE__ __libc_int32_t;
typedef __UINT32_TYPE__ __libc_uint32_t;
typedef __INT64_TYPE__ __libc_int64_t;
typedef __UINT64_TYPE__ __libc_uint64_t;
#else
#error "Could not determine exact-width integer types (int*_t)."
#endif

/*
 * Width of fastest minimum-width integer types.
 */

#ifdef __INT_FAST8_WIDTH__
#define _LIBC_INT_FAST8_WIDTH  __INT_FAST8_WIDTH__
#define _LIBC_INT_FAST16_WIDTH __INT_FAST16_WIDTH__
#define _LIBC_INT_FAST32_WIDTH __INT_FAST32_WIDTH__
#define _LIBC_INT_FAST64_WIDTH __INT_FAST64_WIDTH__
#else

/* clang-9 does not provide widths for fast types so we need to determine it
 * from the maximum. */

#if __INT_FAST8_MAX__ == 0x7f
#define _LIBC_INT_FAST8_WIDTH 8
#elif __INT_FAST8_MAX__ == 0x7fff
#define _LIBC_INT_FAST8_WIDTH 16
#elif __INT_FAST8_MAX__ == 0x7fffffff
#define _LIBC_INT_FAST8_WIDTH 32
#elif __INT_FAST8_MAX__ == 0x7fffffffffffffff
#define _LIBC_INT_FAST8_WIDTH 64
#else
#error "Could not determine INT_FAST8_WIDTH."
#endif

#if __INT_FAST16_MAX__ == 0x7fff
#define _LIBC_INT_FAST16_WIDTH 16
#elif __INT_FAST16_MAX__ == 0x7fffffff
#define _LIBC_INT_FAST16_WIDTH 32
#elif __INT_FAST16_MAX__ == 0x7fffffffffffffff
#define _LIBC_INT_FAST16_WIDTH 64
#else
#error "Could not determine INT_FAST16_WIDTH."
#endif

#if __INT_FAST32_MAX__ == 0x7fffffff
#define _LIBC_INT_FAST32_WIDTH 32
#elif __INT_FAST32_MAX__ == 0x7fffffffffffffff
#define _LIBC_INT_FAST32_WIDTH 64
#else
#error "Could not determine INT_FAST32_WIDTH."
#endif

#define _LIBC_INT_FAST64_WIDTH 64

#endif /* !__INT_FAST8_WIDTH__ */

/*
 * Width of integer types capable of holding object pointers.
 * Width of other integer types.
 */

#ifdef __INTPTR_WIDTH__
#define _LIBC_INTPTR_WIDTH     __INTPTR_WIDTH__
#define _LIBC_PTRDIFF_WIDTH    __PTRDIFF_WIDTH__
#define _LIBC_SIG_ATOMIC_WIDTH __SIG_ATOMIC_WIDTH__
#define _LIBC_SIZE_WIDTH       __SIZE_WIDTH__
#define _LIBC_WCHAR_WIDTH      __WCHAR_WIDTH__
#define _LIBC_WINT_WIDTH       __WINT_WIDTH__
#else
#error "Could not determine INTPTR_WIDTH."
#endif

/*
 * Signedness of other integer types.
 */

#if defined(__SIG_ATOMIC_MIN__)

#if __SIG_ATOMIC_MIN__ == 0
#define _LIBC_SIG_ATOMIC_UNSIGNED 1
#else
#define _LIBC_SIG_ATOMIC_UNSIGNED 0
#endif

#elif defined(__SIG_ATOMIC_MAX__)

#if (__SIG_ATOMIC_MAX__ == 0xff) || (__SIG_ATOMIC_MAX__ == 0xffff) \
    || (__SIG_ATOMIC_MAX__ == 0xffffffff)                          \
    || (__SIG_ATOMIC_MAX__ == 0xffffffffffffff)
#define _LIBC_SIG_ATOMIC_UNSIGNED 1
#else
#define _LIBC_SIG_ATOMIC_UNSIGNED 0
#endif

#else
#error "Could not determine signedness of sig_atomic_t."
#endif

#if L'\0' - 1 > 0
#define _LIBC_WCHAR_UNSIGNED 1
#else
#define _LIBC_WCHAR_UNSIGNED 0
#endif

#if __WINT_UNSIGNED__
#define _LIBC_WINT_UNSIGNED 1
#elif defined(__WINT_MIN__)
#if __WINT_MIN__ == 0
#define _LIBC_WINT_UNSIGNED 1
#else
#define _LIBC_WINT_UNSIGNED 0
#endif
#else
#error "Could not determine signedness of wint_t."
#endif

#endif
