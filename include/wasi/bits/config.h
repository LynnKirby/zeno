/*
 * SPDX-License-Identifier: CC0-1.0
 * bits/config.h private header - WASI version
 */

#ifndef _BITS_CONFIG_H
#define _BITS_CONFIG_H

#define _LIBC_CONFIG_INTPTR_IS_LONG32  1
#define _LIBC_CONFIG_PTRDIFF_IS_LONG32 1
#define _LIBC_CONFIG_SIZE_IS_ULONG32   1

#define _LIBC_CONFIG_LDBL_FORMAT_BINARY64  0
#define _LIBC_CONFIG_LDBL_FORMAT_BINARY128 1
#define _LIBC_CONFIG_LDBL_FORMAT_INTEL80   0

#endif
