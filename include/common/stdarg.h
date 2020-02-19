/*
 * SPDX-License-Identifier: CC0-1.0
 * stdarg.h standard C header
 */

#ifndef _STDARG_H
#define _STDARG_H

#include <zeno/stdarg.h>

typedef __libc_va_list va_list;

#define va_arg(ap, t)      __builtin_va_arg(ap, t)
#define va_copy(dest, src) __builtin_va_copy(dest, src)
#define va_start(ap, p)    __builtin_va_start(ap, p)
#define va_end(ap)         __builtin_va_end(ap)

#endif
