#include "unit_test.h"
#include "unit_test_main.c"
#include <stdio.h>

TEST(fwrite, returns_length_written)
{
    // CHECK: foo
    EXPECT_UINT(fwrite("foo", 3, 1, stdout), ==, 3);
}
