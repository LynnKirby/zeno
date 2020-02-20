/*
 * SPDX-License-Identifier: CC0-1.0
 * assert.h standard C header
 */

#ifndef _ASSERT_H
#define _ASSERT_H

#ifdef __cplusplus
extern "C" {
#endif

_Noreturn void __assert_fail(const char *, const char *, int, const char *);

#ifdef __cplusplus
}
#endif

#if __STDC_VERSION__ >= 201112L && !defined(__cplusplus)
#define static_assert _Static_assert
#endif

#endif /* !_ASSERT_H */

#undef assert

#ifdef NDEBUG
#define assert(x) ((void)0)
#else
#define assert(x) \
    ((void)((x) || (__assert_fail(#x, __FILE__, __LINE__, __func__), 0)))
#endif
