#include "unit_test.h"
#include <stdio.h>

TEST(fwrite, returns_length_written)
{
    // CHECK: foo
    EXPECT(fwrite("foo", 3, 1, stdout) == 3);
}
