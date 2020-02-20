/*
 * SPDX-License-Identifier: CC0-1.0
 * Compiler portability macros.
 */

#ifndef BASIC_CDEFS_H
#define BASIC_CDEFS_H

#define _LIBC_WEAK   __attribute__((__weak__))
#define _LIBC_HIDDEN __attribute__((__visibility__("hidden")))
#define _LIBC_USED   __attribute__((__used__))

#define UNUSED_PARAM(x) ((void)x);

#define STRONG_ALIAS(name, aliasname) \
    extern __typeof(name) aliasname __attribute__((alias(#name)))

#endif
