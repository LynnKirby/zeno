/*
 * SPDX-License-Identifier: CC0-1.0
 * time.h standard C header
 */

#ifndef _TIME_H
#define _TIME_H

#include <bits/cdefs.h>
#include <bits/stdint.h>
#include <bits/types.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Macros and types.
 */

#define __STDC_VERSION_TIME_H__ 202001L

#define CLOCKS_PER_SEC 1000000L
#define TIME_UTC       1

typedef __libc_size_t size_t;
typedef __libc_uint64_t time_t;
typedef long clock_t;

struct timespec {
    time_t tv_sec;
    long tv_nsec;
};

struct tm {
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
    int tm_wday;
    int tm_yday;
    int tm_isdst;
};

/*
 * Time manipulation functions.
 */

clock_t clock(void);
double difftime(time_t, time_t);
time_t mktime(struct tm *);
time_t time(time_t *);
int timespec_get(struct timespec *, int);

/*
 * Time conversion functions.
 */

char *asctime(const struct tm *);
char *asctime_r(const struct tm *, char *);
char *ctime(const time_t *);
char *ctime_r(const time_t *, char *);
struct tm *gmtime(const time_t *);
struct tm *gmtime_r(const time_t *, struct tm *);
struct tm *localtime(const time_t *);
struct tm *localtime_r(const time_t *, struct tm *);
size_t strftime(
    char *__libc_restrict,
    size_t,
    const char *__libc_restrict,
    const struct tm *__libc_restrict);

#ifdef __cplusplus
}
#endif

#endif
