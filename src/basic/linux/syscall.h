/*
 * SPDX-License-Identifier: CC0-1.0
 * Linux syscall functions.
 */

#ifndef BASIC_LINUX_SYSCALL_H
#define BASIC_LINUX_SYSCALL_H

#include <errno.h>

#if defined(__i386__)
#include "basic/linux/i386/syscall.h"
#elif defined(__x86_64__)
#include "basic/linux/x86_64/syscall.h"
#else
#error "Not implemented for this architecture."
#endif

static inline long __syscall_handle_errno(long r)
{
    if ((unsigned long)r > -4096UL) {
        errno = -r;
        return -1;
    }

    return r;
}

/* clang-format off */
/* Wrappers that cast arguments to long. */
#define __syscall1(n, a1) \
    __syscall1(n, (long)(a1))
#define __syscall2(n, a1, a2) \
    __syscall2(n, (long)(a1), (long)(a2))
#define __syscall3(n, a1, a2, a3) \
    __syscall3(n, (long)(a1), (long)(a2), (long)(a3))
#define __syscall4(n, a1, a2, a3, a4) \
    __syscall4(n, (long)(a1), (long)(a2), (long)(a3), (long)(a4))
#define __syscall5(n, a1, a2, a3, a4, a5) \
    __syscall5(n, (long)(a1), (long)(a2), (long)(a3), (long)(a4), (long)(a5))
#define __syscall6(n, a1, a2, a3, a4, a5, a6) \
    __syscall6(n, (long)(a1), (long)(a2), (long)(a3), (long)(a4), (long)(a5), (long)(a6))
/* clang-format on */

/* __syscall() macro that dispatches to target-specific __syscall#() */
#define __SYSCALL_LEN_X(_1, _2, _3, _4, _5, _6, _7, N, ...) N

#define __SYSCALL_LEN(...)    __SYSCALL_LEN_X(__VA_ARGS__, 6, 5, 4, 3, 2, 1, 0, )
#define __SYSCALL_CONCAT_X(n) __syscall##n
#define __SYSCALL_CONCAT(n)   __SYSCALL_CONCAT_X(n)
#define __syscall(...)        __SYSCALL_CONCAT(__SYSCALL_LEN(__VA_ARGS__))(__VA_ARGS__)

/* Like syscall(2) but not a variadic function. */
#define syscall(...) __syscall_handle_errno(__syscall(__VA_ARGS__))

#endif
