/*
 * SPDX-License-Identifier: CC0-1.0
 * unistd.h POSIX header
 */

#ifndef _UNISTD_H
#define _UNISTD_H

#include <bits/types.h>

typedef __libc_size_t size_t;
typedef __libc_ssize_t ssize_t;

ssize_t write(int, const void *, size_t);

#endif
