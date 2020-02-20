/*
 * SPDX-License-Identifier: CC0-1.0
 * errno.h standard C header
 */

#ifndef _ERRNO_H
#define _ERRNO_H

#include <zeno/errno.h>

#ifdef __cplusplus
extern "C" {
#endif

int *__libc_errno(void);
#define errno (*__libc_errno())

#ifdef __cplusplus
}
#endif

#endif
