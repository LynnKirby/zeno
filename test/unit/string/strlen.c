#include "unit_test.h"
#include <string.h>

TEST(strlen, works)
{
    EXPECT_INT(strlen(""), ==, 0);
    EXPECT_INT(strlen("foo"), ==, 3);
}
