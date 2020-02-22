#include "unit_test.h"
#include <string.h>

TEST(strcmp, works)
{
    EXPECT(strcmp("foo", "foo") == 0);
    EXPECT(strcmp("abc", "xyz") < 0);
    EXPECT(strcmp("xyz", "abc") > 0);
}
