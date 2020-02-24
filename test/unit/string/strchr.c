#include "unit_test.h"
#include <string.h>

TEST(strchr, found)
{
    const char *str = "abc";
    char *result    = strchr(str, 'b');
    EXPECT_PTR(result, ==, str + 1);
}

TEST(strchr, not_found)
{
    const char *str = "abc";
    char *result    = strchr(str, 'x');
    EXPECT_PTR(result, ==, NULL);
}

TEST(strchr, can_find_null)
{
    const char *str = "abc";
    char *result    = strchr(str, '\0');
    EXPECT_PTR(result, ==, str + 3);
}
