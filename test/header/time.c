#include "header_test.h"
#include <time.h>

#ifdef __wasi__
#include "basic/wasi/api.h"
STATIC_ASSERT(__WASI_CLOCKID_REALTIME == CLOCK_REALTIME);
STATIC_ASSERT(__WASI_CLOCKID_MONOTONIC == CLOCK_MONOTONIC);
STATIC_ASSERT(__WASI_CLOCKID_PROCESS_CPUTIME_ID == CLOCK_PROCESS_CPUTIME_ID);
STATIC_ASSERT(__WASI_CLOCKID_THREAD_CPUTIME_ID == CLOCK_THREAD_CPUTIME_ID);
#endif

#ifndef NULL
#error "NULL not defined"
#endif

int main(void)
{
    integer_constant(__STDC_VERSION_TIME_H__);
    integer_constant(CLOCKS_PER_SEC);
    integer_constant(TIME_UTC);
    type(size_t);
    type(clock_t);
    type(time_t);
    type(struct tm);
    type(struct timespec);
    type(clockid_t);
    type(timer_t);
    type(locale_t);
    type(pid_t);
    type(struct sigevent);
    type(struct itimerspec);
    void *n = NULL;
    integer_constant(CLOCK_MONOTONIC);
    integer_constant(CLOCK_PROCESS_CPUTIME_ID);
    integer_constant(CLOCK_REALTIME);
    integer_constant(CLOCK_THREAD_CPUTIME_ID);
    integer_constant(TIMER_ABSTIME);
    return 0;
}
