#include "unit_test.h"
#include <string.h>

TEST(memcmp, works)
{
    EXPECT(memcmp("ffoo", "ffoo", 3) == 0);
    EXPECT(memcmp("abc", "axyz", 3) < 0);
    EXPECT(memcmp("xyz", "xabc", 3) > 0);
}
