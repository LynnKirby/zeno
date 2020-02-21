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

/* __syscall() macro that dispatches to target-specific __syscall#() */
#define __SYSCALL_LEN_X(_1, _2, _3, _4, _5, _6, _7, N,...) N
#define __SYSCALL_LEN(...) __SYSCALL_LEN_X(__VA_ARGS__, 6, 5, 4, 3, 2, 1, 0,)
#define __SYSCALL_CONCAT_X(n) __syscall##n
#define __SYSCALL_CONCAT(n) __SYSCALL_CONCAT_X(n)
#define __syscall(...) __SYSCALL_CONCAT(__SYSCALL_LEN(__VA_ARGS__))(__VA_ARGS__)

/* Like syscall(2) but not a variadic function. */
#define syscall(...) __syscall_handle_errno(__syscall(__VA_ARGS__))

#endif
