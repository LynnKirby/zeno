/*
 * SPDX-License-Identifier: CC0-1.0
 * time.h standard C header
 */

#ifndef _TIME_H
#define _TIME_H

#include <bits/cdefs.h>
#include <bits/features.h>
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
typedef __libc_int64_t time_t;
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

#if _LIBC_POSIX_VISIBLE
#include <bits/null.h>

typedef __libc_clockid_t clockid_t;
typedef __libc_timer_t timer_t;
typedef __libc_locale_t locale_t;
typedef __libc_pid_t pid_t;
struct sigevent;

struct itimerspec {
    struct timespec it_interval;
    struct timespec it_value;
};

#define CLOCK_REALTIME           0
#define CLOCK_MONOTONIC          1
#define CLOCK_PROCESS_CPUTIME_ID 2
#define CLOCK_THREAD_CPUTIME_ID  3

#define TIMER_ABSTIME 1

extern int getdate_err;
#endif

/*
 * Time manipulation functions.
 */

clock_t clock(void);
double difftime(time_t, time_t);
time_t mktime(struct tm *);
time_t time(time_t *);
int timespec_get(struct timespec *, int);

#if _LIBC_POSIX_VISIBLE
int clock_getcpuclockid(pid_t, clockid_t *);
int clock_getres(clockid_t, struct timespec *);
int clock_gettime(clockid_t, struct timespec *);
int clock_nanosleep(clockid_t, int, const struct timespec *, struct timespec *);
int clock_settime(clockid_t, const struct timespec *);
struct tm *getdate(const char *);
int nanosleep(const struct timespec *, struct timespec *);
int timer_create(
    clockid_t, struct sigevent *__libc_restrict, timer_t *__libc_restrict);
int timer_delete(timer_t);
int timer_getoverrun(timer_t);
int timer_gettime(timer_t, struct itimerspec *);
int timer_settime(
    timer_t,
    int,
    const struct itimerspec *__libc_restrict,
    struct itimerspec *__libc_restrict);
void tzset(void);
#endif

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

#if _LIBC_POSIX_VISIBLE
size_t strftime_l(
    char *__libc_restrict,
    size_t,
    const char *__libc_restrict,
    const struct tm *__libc_restrict,
    locale_t);
char *strptime(
    const char *__libc_restrict,
    const char *__libc_restrict,
    struct tm *__libc_restrict);
#endif

#ifdef __cplusplus
}
#endif

#endif
