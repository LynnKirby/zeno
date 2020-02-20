/*
 * SPDX-License-Identifier: CC0-1.0
 * stdnoreturn.h standard C header
 */

#ifndef _STDNORETURN_H
#define _STDNORETURN_H

#ifndef __cplusplus

/* We can't define noreturn when it conflicts with __declspec(noreturn). */
#ifdef _MSC_VER

#ifdef _LIBC_ALLOW_MSVC_NORETURN
/* Do nothing, the developer asked for it. */
#else
#error Your compiler does not support <stdnoreturn.h>. Use _Noreturn directly. \
       You can suppress this message by defining _LIBC_ALLOW_MSVC_NORETURN.
#endif

#else
#define noreturn _Noreturn
#endif

#endif /* !__cplusplus */

#endif
