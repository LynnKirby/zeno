#include "unit_test.h"
#include <string.h>

TEST(strcmp, works)
{
    EXPECT_INT(strcmp("foo", "foo"), ==, 0);
    EXPECT_INT(strcmp("abc", "xyz"), <, 0);
    EXPECT_INT(strcmp("xyz", "abc"), >, 0);
}
