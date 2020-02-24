#include "unit_test.h"
#include <string.h>

TEST(strstr, found_in_middle)
{
    const char *haystack = "foobar";
    const char *needle   = "oba";

    char *result = strstr(haystack, needle);

    EXPECT_PTR(result, ==, haystack + 2);
}

TEST(strstr, found_at_end)
{
    const char *haystack = "foobar";
    const char *needle   = "bar";

    char *result = strstr(haystack, needle);

    EXPECT_PTR(result, ==, haystack + 3);
}

TEST(strstr, not_found)
{
    const char *haystack = "foobar";
    const char *needle   = "baz";

    char *result = strstr(haystack, needle);

    EXPECT_PTR(result, ==, NULL);
}

TEST(strstr, empty_needle)
{
    const char *haystack = "foobar";
    const char *needle   = "";

    char *result = strstr(haystack, needle);

    EXPECT_PTR(result, ==, haystack);
}
