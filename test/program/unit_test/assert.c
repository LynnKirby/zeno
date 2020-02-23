#include "unit_test.h"
#include <stdio.h>

static void do_assert(void)
{
    ASSERT(0);
}

TEST(unit_test, assert_exits_test)
{
    // CHECK: before assert
    puts("before assert");
    do_assert();
}

TEST(unit_test, next_test_runs)
{
    // CHECK: next test
    puts("next test");
}
