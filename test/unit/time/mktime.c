#include "unit_test.h"
#include <errno.h>
#include <limits.h>
#include <time.h>

TEST(mktime, unix_zero)
{
    struct tm tm = {
        .tm_year  = 1970 - 1900,
        .tm_mon   = 0,
        .tm_mday  = 1,
        .tm_hour  = 0,
        .tm_min   = 0,
        .tm_sec   = 0,
        .tm_isdst = -1,
    };

    EXPECT_UINT(mktime(&tm), ==, 0);
    EXPECT_INT(tm.tm_wday, ==, 4);
    EXPECT_INT(tm.tm_year, ==, 1970 - 1900);
    EXPECT_INT(tm.tm_mon, ==, 0);
    EXPECT_INT(tm.tm_mday, ==, 1);
    EXPECT_INT(tm.tm_hour, ==, 0);
    EXPECT_INT(tm.tm_min, ==, 0);
    EXPECT_INT(tm.tm_sec, ==, 0);
    EXPECT_INT(tm.tm_yday, ==, 0);

    /* We don't have timezone support right now and UTC doesn't have DST. */
    EXPECT_INT(tm.tm_isdst, ==, 0);
}

TEST(mktime, wday_for_reasonable_values)
{
    struct tm tm = {
        .tm_year  = 2001 - 1900,
        .tm_mon   = 7 - 1,
        .tm_mday  = 4,
        .tm_hour  = 0,
        .tm_min   = 0,
        .tm_sec   = 1,
        .tm_isdst = -1,
    };

    EXPECT_UINT(mktime(&tm), !=, (time_t)-1);
    EXPECT_INT(tm.tm_wday, ==, 3);

    /* In range values should not change. */
    EXPECT_INT(tm.tm_year, ==, 2001 - 1900);
    EXPECT_INT(tm.tm_mon, ==, 7 - 1);
    EXPECT_INT(tm.tm_mday, ==, 4);
    EXPECT_INT(tm.tm_hour, ==, 0);
    EXPECT_INT(tm.tm_min, ==, 0);
    EXPECT_INT(tm.tm_sec, ==, 1);

    EXPECT_INT(tm.tm_isdst, ==, 0);
}

TEST(mktime, huge_value_overflows)
{
    /* The year member (int/int32_t) overflows. */
    struct tm huge = {
        .tm_year = INT_MAX,
        .tm_mon  = INT_MAX,
        .tm_mday = INT_MAX,
        .tm_hour = INT_MAX,
        .tm_min  = INT_MAX,
        .tm_sec  = INT_MAX,
    };

    EXPECT_UINT(mktime(&huge), ==, (time_t)-1);
    EXPECT_INT(errno, ==, EOVERFLOW);
}

TEST(mktime, lower_than_minimum_time_t_overflows)
{
    /* The date can't be represented as a time_t. */
    struct tm tm = {
        .tm_year  = 1969 - 1900,
        .tm_mon   = 0,
        .tm_mday  = 1,
        .tm_hour  = 0,
        .tm_min   = 0,
        .tm_sec   = 0,
        .tm_isdst = -1,
    };

    EXPECT_UINT(mktime(&tm), ==, (time_t)-1);
    EXPECT_INT(errno, ==, EOVERFLOW);
}

TEST(mktime, negative_values)
{
    struct tm tm = {
        .tm_year  = 3000 - 1900,
        .tm_mon   = 0 - 1,
        .tm_mday  = 1 - 1,
        .tm_hour  = 0 - 1,
        .tm_min   = 0 - 1,
        .tm_sec   = 0 - 1,
        .tm_isdst = -1,
    };

    EXPECT_UINT(mktime(&tm), !=, (time_t)-1);

    EXPECT_INT(tm.tm_year, ==, 2999 - 1900);
    EXPECT_INT(tm.tm_mon, ==, 10);
    EXPECT_INT(tm.tm_mday, ==, 29);
    EXPECT_INT(tm.tm_hour, ==, 22);
    EXPECT_INT(tm.tm_min, ==, 58);
    EXPECT_INT(tm.tm_sec, ==, 59);
    EXPECT_INT(tm.tm_yday, ==, 332);
    EXPECT_INT(tm.tm_wday, ==, 5);
    EXPECT_INT(tm.tm_isdst, ==, 0);
}

TEST(mktime, mixed_values)
{
    struct tm tm = {
        .tm_year  = 3000 - 1900,
        .tm_mon   = 0 - 1,
        .tm_mday  = 1 + 1,
        .tm_hour  = 0 - 1,
        .tm_min   = 0 - 1,
        .tm_sec   = 0 - 1,
        .tm_isdst = -1,
    };

    EXPECT_UINT(mktime(&tm), !=, (time_t)-1);

    EXPECT_INT(tm.tm_year, ==, 2999 - 1900);
    EXPECT_INT(tm.tm_mon, ==, 11);
    EXPECT_INT(tm.tm_mday, ==, 1);
    EXPECT_INT(tm.tm_hour, ==, 22);
    EXPECT_INT(tm.tm_min, ==, 58);
    EXPECT_INT(tm.tm_sec, ==, 59);
    EXPECT_INT(tm.tm_yday, ==, 334);
    EXPECT_INT(tm.tm_wday, ==, 0);
    EXPECT_INT(tm.tm_isdst, ==, 0);
}
