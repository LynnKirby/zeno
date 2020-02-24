#include "unit_test.h"
#include <string.h>

TEST(strncmp, works)
{
    EXPECT_INT(strncmp("foo", "foo", 10), ==, 0);
    EXPECT_INT(strncmp("abc", "xyzx", 10), <, 0);
    EXPECT_INT(strncmp("xyz", "abcx", 10), >, 0);
    EXPECT_INT(strncmp("aaa", "aabx", 2), ==, 0);
    EXPECT_INT(strncmp("baa", "aabx", 2), >, 0);
    EXPECT_INT(strncmp("aaa", "aabx", 3), <, 0);

    char abcde[]    = "abcde";
    char abcdx[]    = "abcdx";
    char cmpabcde[] = "abcde\0f";
    char cmpabcd_[] = "abcde\xfc";
    char empty[]    = "";
    char x[]        = "x";
    EXPECT_INT(strncmp(abcde, cmpabcde, 5), ==, 0);
    EXPECT_INT(strncmp(abcde, cmpabcde, 10), ==, 0);
    EXPECT_INT(strncmp(abcde, abcdx, 5), <, 0);
    EXPECT_INT(strncmp(abcdx, abcde, 5), >, 0);
    EXPECT_INT(strncmp(empty, abcde, 5), <, 0);
    EXPECT_INT(strncmp(abcde, empty, 5), >, 0);
    EXPECT_INT(strncmp(abcde, abcdx, 4), ==, 0);
    EXPECT_INT(strncmp(abcde, x, 0), ==, 0);
    EXPECT_INT(strncmp(abcde, x, 1), <, 0);
    EXPECT_INT(strncmp(abcde, cmpabcd_, 10), <, 0);
}
