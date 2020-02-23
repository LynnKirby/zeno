#include "unit_test.h"
#include <time.h>

/* Checks below assume clock will not overflow in the time it takes to run
 * the test executable. */

static void check(clockid_t clk)
{
    struct timespec ts;

    EXPECT(clock_gettime(clk, &ts) == 0);
    EXPECT(ts.tv_sec != 0 || ts.tv_nsec != 0);
}

TEST(clock_gettime, default_clocks_work)
{
    struct timespec ts;

    check(CLOCK_REALTIME);
    check(CLOCK_MONOTONIC);
    check(CLOCK_PROCESS_CPUTIME_ID);
    check(CLOCK_THREAD_CPUTIME_ID);
}
