#include "test.h"
#include <time.h>

#ifdef __wasi__
#include "basic/wasi/api.h"
_Static_assert(
    __WASI_CLOCKID_REALTIME == CLOCK_REALTIME,
    "__WASI_CLOCKID_REALTIME should be CLOCK_REALTIME");
_Static_assert(
    __WASI_CLOCKID_MONOTONIC == CLOCK_MONOTONIC,
    "__WASI_CLOCKID_MONOTONIC should be CLOCK_MONOTONIC");
_Static_assert(
    __WASI_CLOCKID_PROCESS_CPUTIME_ID == CLOCK_PROCESS_CPUTIME_ID,
    "__WASI_CLOCKID_PROCESS_CPUTIME_ID should be CLOCK_PROCESS_CPUTIME_ID");
_Static_assert(
    __WASI_CLOCKID_THREAD_CPUTIME_ID == CLOCK_THREAD_CPUTIME_ID,
    "__WASI_CLOCKID_THREAD_CPUTIME_ID should be CLOCK_THREAD_CPUTIME_ID");
#endif

int main(void)
{
    assert_is_integer_constant(__STDC_VERSION_TIME_H__);
    assert_is_integer_constant(CLOCKS_PER_SEC);
    assert_is_integer_constant(TIME_UTC);
    assert_is_type(size_t);
    assert_is_type(clock_t);
    assert_is_type(time_t);
    assert_is_type(struct tm);
    assert_is_type(struct timespec);
    assert_is_type(clockid_t);
    assert_is_type(timer_t);
    assert_is_type(locale_t);
    assert_is_type(pid_t);
    assert_is_type(struct sigevent);
    assert_is_type(struct itimerspec);
    void *n = NULL;
    assert_is_integer_constant(CLOCK_MONOTONIC);
    assert_is_integer_constant(CLOCK_PROCESS_CPUTIME_ID);
    assert_is_integer_constant(CLOCK_REALTIME);
    assert_is_integer_constant(CLOCK_THREAD_CPUTIME_ID);
    assert_is_integer_constant(TIMER_ABSTIME);
    return 0;
}
