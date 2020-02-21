/*
 * SPDX-License-Identifier: CC0-1.0
 * stdlib.h standard C header
 */

#ifndef _STDLIB_H
#define _STDLIB_H

#include <bits/features.h>
#include <bits/integer_constants.h>
#include <bits/null.h>
#include <bits/types.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Types and macros.
 */

#define __STDC_VERSION_STDLIB_H__ 202001L

typedef __libc_size_t size_t;
typedef __libc_wchar_t wchar_t;

typedef struct {
    int quot;
    int rem;
} div_t;

typedef struct {
    long quot;
    long rem;
} ldiv_t;

typedef struct {
    long long quot;
    long long rem;
} lldiv_t;

#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

#define RAND_MAX _LIBC_INT32_MAX

/* TODO: Update when multibyte locales are supported. */
#define MB_CUR_MAX 1

/*
 * Numeric conversion functions.
 */

double atof(const char *);
int atoi(const char *);
long atol(const char *);
long long atoll(const char *);

int strfromd(
    char *__libc_restrict, size_t, const char *__libc_restrict, double);
int strfromf(char *__libc_restrict, size_t, const char *__libc_restrict, float);
int strfroml(
    char *__libc_restrict, size_t, const char *__libc_restrict, long double);

double strtod(const char *__libc_restrict, char **__libc_restrict);
float strtof(const char *__libc_restrict, char **__libc_restrict);
long double strtold(const char *__libc_restrict, char **__libc_restrict);

long strtol(const char *__libc_restrict, char **__libc_restrict, int);
long long strtoll(const char *__libc_restrict, char **__libc_restrict, int);
unsigned long strtoul(const char *__libc_restrict, char **__libc_restrict, int);
unsigned long long strtoull(
    const char *__libc_restrict, char **__libc_restrict, int);

/*
 * Pseudo-random sequence generation functions.
 */

int rand(void);
void srand(unsigned);

#if _LIBC_POSIX_VISIBLE
int rand_r(unsigned *);
long random(void);
void srandom(unsigned);
char *initstate(unsigned, char *, size_t);
char *setstate(char *);
#endif

/*
 * Memory management functions.
 */

void *aligned_alloc(size_t, size_t);
void *calloc(size_t, size_t);
void free(void *);
void *malloc(size_t);

/*
 * Communication with the environment.
 */

_Noreturn void abort(void);
int atexit(void (*)(void));
int at_quick_exit(void (*)(void));
_Noreturn void exit(int);
_Noreturn void _Exit(int);
char *getenv(const char *);
_Noreturn void quick_exit(int);
int system(const char *);

/*
 * Searching and sorting utilities.
 */

typedef int (*_LibcCompareFn)(const void *, const void *);

void *bsearch(const void *, const void *, size_t, size_t, _LibcCompareFn);
void qsort(void *, size_t, size_t, _LibcCompareFn);

/*
 * Integer arithmetic functions.
 */

int abs(int);
long labs(long);
long long llabs(long long);

div_t div(int, int);
ldiv_t ldiv(long, long);
lldiv_t lldiv(long long, long long);

/*
 * Multibyte/wide character conversion functions.
 */

int mblen(const char *, size_t);
int mbtowc(wchar_t *__libc_restrict, const char *__libc_restrict, size_t);
int wctomb(char *, wchar_t);

/*
 * Multibyte/wide string conversion functions.
 */

size_t mbstowcs(wchar_t *__libc_restrict, const char *__libc_restrict, size_t);
size_t wcstombs(char *__libc_restrict, const wchar_t *__libc_restrict, size_t);

#ifdef __cplusplus
}
#endif

#endif
