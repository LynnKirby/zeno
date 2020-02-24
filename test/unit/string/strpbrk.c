#include "unit_test.h"
#include <string.h>

TEST(strpbrk, found)
{
    const char *str = "abcd";
    char *result = strpbrk(str, "xybz");
    EXPECT_PTR(result, ==, str + 1);
}

TEST(strpbrk, not_found)
{
    char *result = strpbrk("abcd", "xyz");
    EXPECT_PTR(result, ==, NULL);
}
