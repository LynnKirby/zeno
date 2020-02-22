#include "unit_test.h"
#include <string.h>

TEST(strlen, works)
{
    EXPECT(strlen("") == 0);
    EXPECT(strlen("foo") == 3);
}
