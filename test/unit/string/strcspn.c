#include "unit_test.h"
#include <string.h>

TEST(strcspn, works)
{
    EXPECT(strcspn("", "") == 0);
    EXPECT(strcspn("abc", "xyz") == 3);
    EXPECT(strcspn("valid", "invalid") == 0);
}
