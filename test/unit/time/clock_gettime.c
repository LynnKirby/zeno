#include "test.h"
#include <time.h>

/* Checks below assume clock will not overflow in the time it takes to run
 * this test executable. */

static void test(clockid_t clk)
{
    struct timespec ts;
    int r = clock_gettime(clk, &ts);
    assert(r == 0);
    assert(ts.tv_sec != 0 || ts.tv_nsec != 0);
}

int main(void)
{
    /* The default clocks work. */
    test(CLOCK_REALTIME);
    test(CLOCK_MONOTONIC);
    test(CLOCK_PROCESS_CPUTIME_ID);
    test(CLOCK_THREAD_CPUTIME_ID);

    return 0;
}
