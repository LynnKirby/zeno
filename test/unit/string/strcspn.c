#include "unit_test.h"
#include <string.h>

TEST(strcspn, works)
{
    EXPECT_INT(strcspn("", ""), ==, 0);
    EXPECT_INT(strcspn("abc", "xyz"), ==, 3);
    EXPECT_INT(strcspn("valid", "invalid"), ==, 0);
}
