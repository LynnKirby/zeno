#include "unit_test.h"
#include <time.h>

/* Checks below assume clock will not overflow in the time it takes to run
 * the test executable. */

TEST(clock_gettime, default_clocks_work)
{
    struct timespec ts;

    EXPECT(clock_gettime(CLOCK_REALTIME, &ts) == 0);
    EXPECT(ts.tv_sec != 0 || ts.tv_nsec != 0);

    EXPECT(clock_gettime(CLOCK_MONOTONIC, &ts) == 0);
    EXPECT(ts.tv_sec != 0 || ts.tv_nsec != 0);

    EXPECT(clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts) == 0);
    EXPECT(ts.tv_sec != 0 || ts.tv_nsec != 0);

    EXPECT(clock_gettime(CLOCK_THREAD_CPUTIME_ID, &ts) == 0);
    EXPECT(ts.tv_sec != 0 || ts.tv_nsec != 0);
}
