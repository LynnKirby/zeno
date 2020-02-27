#include "unit_test.h"
#include <fenv.h>

TEST(fegetenv, can_get)
{
    fenv_t env;
    ASSERT_INT(fegetenv(&env), ==, 0);
}

TEST(feholdexcept, clears_flags)
{
    fenv_t env;

    ASSERT_INT(feraiseexcept(FE_ALL_EXCEPT), ==, 0);
    ASSERT_INT(fetestexcept(FE_ALL_EXCEPT), ==, FE_ALL_EXCEPT);

    ASSERT_INT(feholdexcept(&env), ==, 0);
    ASSERT_INT(fetestexcept(FE_ALL_EXCEPT), ==, 0);
}

TEST(fesetenv, can_set_default)
{
    ASSERT_INT(fesetenv(FE_DFL_ENV), ==, 0);

    ASSERT_INT(fetestexcept(FE_ALL_EXCEPT), ==, 0);
    ASSERT_INT(fegetround(), ==, FE_TONEAREST);
}

TEST(fesetenv, can_set_previous)
{
    fenv_t env;

    ASSERT_INT(fesetexcept(FE_ALL_EXCEPT), ==, 0);
#ifdef FE_TOWARDZERO
    ASSERT_INT(fesetround(FE_TOWARDZERO), ==, 0);
#endif

    ASSERT_INT(fegetenv(&env), ==, 0);

    ASSERT_INT(fesetenv(FE_DFL_ENV), ==, 0);
    ASSERT_INT(fegetround(), ==, FE_TONEAREST);
    ASSERT_INT(fetestexcept(FE_ALL_EXCEPT), ==, 0);

    ASSERT_INT(fesetenv(&env), ==, 0);
    ASSERT_INT(fetestexcept(FE_ALL_EXCEPT), ==, FE_ALL_EXCEPT);
#ifdef FE_TOWARDZERO
    ASSERT_INT(fegetround(), ==, FE_TOWARDZERO);
#endif
}

TEST(feupdateenv, raises_existing_exceptions)
{
    fenv_t env;

    ASSERT_INT(fesetexcept(FE_ALL_EXCEPT), ==, 0);
#ifdef FE_TOWARDZERO
    ASSERT_INT(fesetround(FE_TOWARDZERO), ==, 0);
#endif
    ASSERT_INT(fegetenv(&env), ==, 0);

    ASSERT_INT(feclearexcept(FE_ALL_EXCEPT), ==, 0);

    ASSERT_INT(feupdateenv(&env), ==, 0);

    ASSERT_INT(fetestexcept(FE_ALL_EXCEPT), ==, 0);
#ifdef FE_TOWARDZERO
    ASSERT_INT(fesetround(FE_TOWARDZERO), ==, 0);
#endif
}
