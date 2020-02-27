#include "unit_test.h"
#include <fenv.h>

#pragma STDC FENV_ACCESS ON

/* TODO: Replace these EXPECT() with EXPECT_FLOAT() when implemented. */

/* 0.1 can't be represented as a double so it'll be rounded to one of these  */
#define higher 0.1000000000000000055511151231257827021181583404541015625
#define lower 0.09999999999999999167332731531132594682276248931884765625

TEST(fesetround, fails_if_mode_does_not_exist)
{
    EXPECT_INT(fesetround(-123), !=, 0);
}

#define MAKE_TEST(name, mode, expected_pos, expected_neg) \
    TEST(fesetround, rounding_##name)                     \
    {                                                     \
        EXPECT_INT(fesetround(mode), ==, 0);              \
        EXPECT_INT(fegetround(), ==, mode);               \
                                                          \
        volatile double x = 1;                            \
                                                          \
        volatile double actual = x / 10;                  \
        EXPECT(actual == expected_pos);                   \
                                                          \
        actual = x / -10;                                 \
        EXPECT(actual == expected_neg);                   \
    }

MAKE_TEST(tonearest, FE_TONEAREST, higher, -higher)

#ifdef FE_UPWARD
MAKE_TEST(upward, FE_UPWARD, higher, -lower)
#endif

#ifdef FE_DOWNWARD
MAKE_TEST(downward, FE_DOWNWARD, lower, -higher)
#endif

#ifdef FE_TOWARDZERO
MAKE_TEST(towardzero, FE_TOWARDZERO, lower, -lower)
#endif
