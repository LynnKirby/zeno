/* SPDX-License-Identifier: CC0-1.0 */

#ifndef INITFINI_LINUX_INITFINI_H
#define INITFINI_LINUX_INITFINI_H

#include "basic/cdefs.h"
#include "initfini/impl.h"

/*
 * These function symbols are provided by the default linker script and point
 * to the correct sections.
 */

_LIBC_WEAK extern void _init(void);
_LIBC_WEAK extern void _fini(void);
_LIBC_WEAK _LIBC_HIDDEN extern StructorFn __preinit_array_start[];
_LIBC_WEAK _LIBC_HIDDEN extern StructorFn __preinit_array_end[];
_LIBC_WEAK _LIBC_HIDDEN extern StructorFn __init_array_start[];
_LIBC_WEAK _LIBC_HIDDEN extern StructorFn __init_array_end[];
_LIBC_WEAK _LIBC_HIDDEN extern StructorFn __fini_array_start[];
_LIBC_WEAK _LIBC_HIDDEN extern StructorFn __fini_array_end[];

#endif
