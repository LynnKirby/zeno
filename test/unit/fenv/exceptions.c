#include "unit_test.h"
#include <fenv.h>
#include <float.h>

/* FIXME: Get from math.h */
#define NAN      __builtin_nanf("")
#define INFINITY __builtin_inff()

#pragma STDC FENV_ACCESS ON

static volatile double zero     = 0;
static volatile double one      = 1;
static volatile double two      = 2;
static volatile double denormal = 4.94066e-324;

TEST(feclearexcept, is_cleared)
{
    EXPECT_INT(feclearexcept(FE_ALL_EXCEPT), ==, 0);
    EXPECT_INT(fetestexcept(FE_ALL_EXCEPT), ==, 0);
}

/* TODO: Should be replaced by parameterized test. */
#define MAKE_TESTS_FOR_EXCEPT(name, except, cause)                          \
    TEST(fetestexcept, name)                                                \
    {                                                                       \
        EXPECT_INT(feclearexcept(FE_ALL_EXCEPT), ==, 0);                    \
        volatile double x = cause;                                          \
        EXPECT_INT(fetestexcept(except), ==, except);                       \
    }                                                                       \
                                                                            \
    TEST(feraiseexcept, name)                                               \
    {                                                                       \
        EXPECT_INT(feclearexcept(FE_ALL_EXCEPT), ==, 0);                    \
        EXPECT_INT(feraiseexcept(except), ==, 0);                           \
        EXPECT_INT(fetestexcept(except), ==, except);                       \
    }                                                                       \
                                                                            \
    TEST(fesetexcept, name)                                                 \
    {                                                                       \
        EXPECT_INT(feclearexcept(FE_ALL_EXCEPT), ==, 0);                    \
        EXPECT_INT(fesetexcept(except), ==, 0);                             \
        EXPECT_INT(fetestexcept(except), ==, except);                       \
    }                                                                       \
                                                                            \
    TEST(fegetexceptflag, name)                                             \
    {                                                                       \
        fexcept_t original;                                                 \
        fexcept_t cleared;                                                  \
        EXPECT_INT(feclearexcept(FE_ALL_EXCEPT), ==, 0);                    \
                                                                            \
        EXPECT_INT(feraiseexcept(except), ==, 0);                           \
        EXPECT_INT(fegetexceptflag(&original, FE_ALL_EXCEPT), ==, 0);       \
        EXPECT_INT(fetestexceptflag(&original, except), ==, except);        \
                                                                            \
        EXPECT_INT(feclearexcept(FE_ALL_EXCEPT), ==, 0);                    \
        EXPECT_INT(fegetexceptflag(&cleared, FE_ALL_EXCEPT), ==, 0);        \
        EXPECT_INT(fetestexceptflag(&cleared, FE_ALL_EXCEPT), ==, 0);       \
                                                                            \
        EXPECT_INT(fesetexceptflag(&original, FE_ALL_EXCEPT), ==, 0);       \
        EXPECT_INT(fegetexceptflag(&original, FE_ALL_EXCEPT), ==, 0);       \
        EXPECT_INT(fetestexceptflag(&original, FE_ALL_EXCEPT), ==, except); \
    }

#ifdef FE_INVALID
MAKE_TESTS_FOR_EXCEPT(invalid, FE_INVALID, (int)(INFINITY + one))
#endif

#ifdef FE_DIVBYZERO
MAKE_TESTS_FOR_EXCEPT(divbyzero, FE_DIVBYZERO, 1.0 / zero)
#endif

#ifdef FE_OVERFLOW
MAKE_TESTS_FOR_EXCEPT(overflow, FE_OVERFLOW, DBL_MAX *two)
#endif

#ifdef FE_UNDERFLOW
MAKE_TESTS_FOR_EXCEPT(underflow, FE_UNDERFLOW, DBL_TRUE_MIN / two)
#endif

#ifdef FE_INEXACT
MAKE_TESTS_FOR_EXCEPT(inexact, FE_INEXACT, one / 10.0)
#endif

#ifdef FE_DENORMAL
MAKE_TESTS_FOR_EXCEPT(denormal, FE_DENORMAL, denormal + 1)
#endif
