#include "unit_test.h"
#include <string.h>

TEST(strspn, works)
{
    EXPECT(strspn("", "") == 0);
    EXPECT(strspn("abc", "xyz") == 0);
    EXPECT(strspn("validxx", "invalid") == 5);
}
