#include "unit_test.h"
#include <time.h>

TEST(timespec_get, only_supports_TIME_UTC)
{
    int FAKE_TIME = 123;
    struct timespec ts;
    EXPECT_INT(timespec_get(&ts, FAKE_TIME), ==, 0);
}

TEST(timespec_get, can_get_TIME_UTC)
{
    struct timespec ts;
    EXPECT_INT(timespec_get(&ts, TIME_UTC), ==, TIME_UTC);
    EXPECT(ts.tv_sec != 0 || ts.tv_nsec != 0);
}
