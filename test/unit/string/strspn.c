#include "unit_test.h"
#include <string.h>

TEST(strspn, works)
{
    EXPECT_INT(strspn("", ""), ==, 0);
    EXPECT_INT(strspn("abc", "xyz"), ==, 0);
    EXPECT_INT(strspn("validxx", "invalid"), ==, 5);
}
