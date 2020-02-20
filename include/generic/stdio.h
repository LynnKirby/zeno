/*
 * SPDX-License-Identifier: CC0-1.0
 * stdio.h standard C header
 */

#ifndef _STDIO_H
#define _STDIO_H

#include <bits/cdefs.h>
#include <bits/null.h>
#include <bits/types.h>

typedef __libc_size_t size_t;

typedef struct {
    int __fd;
} FILE;

#define EOF (-1)

extern FILE *const stderr;
extern FILE *const stdout;

#define stderr (stderr)
#define stdout (stdout)

/*
 * File access functions.
 */

int fflush(FILE *);

/*
 * Character input/output functions.
 */

int fputs(const char *__libc_restrict, FILE *__libc_restrict);
int puts(const char *);

/*
 * Direct input/output functions.
 */

size_t fwrite(
    const void *__libc_restrict, size_t, size_t, FILE *__libc_restrict);

#endif
