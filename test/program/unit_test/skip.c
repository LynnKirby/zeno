#include "unit_test.h"
#include "unit_test_main.c"
#include <stdio.h>

static void do_skip(void)
{
    SKIP_TEST();
}

TEST(unit_test, skip_exits_test)
{
    // CHECK: before skip
    puts("before skip");
    do_skip();
}

TEST(unit_test, next_test_runs)
{
    // CHECK: next test
    puts("next test");
}
