/*
 * SPDX-License-Identifier: CC0-1.0
 * string.h standard C header
 */

#ifndef _STRING_H
#define _STRING_H

#include <zeno/cdefs.h>
#include <zeno/null.h>
#include <zeno/types.h>

typedef __libc_size_t size_t;

/*
 * Copying functions.
 */

void *memcpy(void *__libc_restrict, const void *__libc_restrict, size_t);
void *memccpy(void *__libc_restrict, const void *__libc_restrict, int, size_t);
void *memmove(void *, const void *, size_t);
char *strcpy(char *__libc_restrict, const char *__libc_restrict);
char *strncpy(char *__libc_restrict, const char *__libc_restrict, size_t);

/*
 * Concatenation functions.
 */

char *strcat(char *__libc_restrict, const char *__libc_restrict);
char *strncat(char *__libc_restrict, const char *__libc_restrict, size_t);

/*
 * Comparison functions.
 */

int memcmp(const void *, const void *, size_t);
int strcmp(const char *, const char *);
int strcoll(const char *, const char *);
int strncmp(const char *, const char *, size_t);
size_t strxfrm(char *__libc_restrict, const char *__libc_restrict, size_t);

/*
 * Search functions.
 */

void *memchr(const void *, int, size_t);
char *strchr(const char *, int);
size_t strcspn(const char *, const char *);
char *strpbrk(const char *, const char *);
char *strrchr(const char *, int);
size_t strspn(const char *, const char *);
char *strstr(const char *, const char *);
char *strtok(char *__libc_restrict, const char *__libc_restrict);

/*
 * Miscellaneous functions.
 */

void *memset(void *, int, size_t);
char *strerror(int);
size_t strlen(const char *);
char *strdup(const char *);
char *strndup(const char *, size_t);

#endif
