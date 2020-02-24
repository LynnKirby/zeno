#include "unit_test.h"
#include <string.h>

TEST(strrchr, found)
{
    const char *str = "abc";
    char *result    = strrchr(str, '\0');
    EXPECT_PTR(result, ==, str + 3);
}

TEST(strrchr, not_found)
{
    const char *str = "abc";
    char *result    = strrchr(str, 'x');
    EXPECT_PTR(result, ==, NULL);
}

TEST(strrchr, find_end_null)
{
    const char *str = "abc";
    char *result    = strrchr(str, '\0');
    EXPECT_PTR(result, ==, str + 3);
}
