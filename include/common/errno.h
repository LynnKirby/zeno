/*
 * SPDX-License-Identifier: CC0-1.0
 * errno.h standard C header
 */

#ifndef _ERRNO_H
#define _ERRNO_H

#ifdef __cplusplus
extern "C" {
#endif

int *__libc_errno(void);
#define errno (*__libc_errno())

/* FIXME: Dummy value */
#define EOVERFLOW 1

#ifdef __cplusplus
}
#endif

#endif
