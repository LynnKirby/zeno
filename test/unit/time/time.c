#include "unit_test.h"
#include <time.h>

TEST(time, return_valid)
{
    time_t t = time(NULL);

    /* Should be greater than the time I wrote this test. */
    /* Sun Feb 23 17:06:28 2020 UTC */
    EXPECT_INT(t, >, 1582477588);
}

TEST(time, sets_pointer_argument)
{
    time_t out;
    time_t t = time(&out);
    EXPECT_INT(out, ==, t);
}
