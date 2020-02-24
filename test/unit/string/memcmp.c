#include "unit_test.h"
#include <string.h>

TEST(memcmp, works)
{
    EXPECT_INT(memcmp("ffoo", "ffoo", 3), ==, 0);
    EXPECT_INT(memcmp("abc", "axyz", 3), <, 0);
    EXPECT_INT(memcmp("xyz", "xabc", 3), >, 0);
}
