#include "test.h"
#include <string.h>

int main(void)
{
    assert(strncmp("foo", "foo", 10) == 0);
    assert(strncmp("abc", "xyzx", 10) < 0);
    assert(strncmp("xyz", "abcx", 10) > 0);
    assert(strncmp("aaa", "aabx", 2) == 0);
    assert(strncmp("baa", "aabx", 2) > 0);
    assert(strncmp("aaa", "aabx", 3) < 0);

    char abcde[]    = "abcde";
    char abcdx[]    = "abcdx";
    char cmpabcde[] = "abcde\0f";
    char cmpabcd_[] = "abcde\xfc";
    char empty[]    = "";
    char x[]        = "x";
    assert(strncmp(abcde, cmpabcde, 5) == 0);
    assert(strncmp(abcde, cmpabcde, 10) == 0);
    assert(strncmp(abcde, abcdx, 5) < 0);
    assert(strncmp(abcdx, abcde, 5) > 0);
    assert(strncmp(empty, abcde, 5) < 0);
    assert(strncmp(abcde, empty, 5) > 0);
    assert(strncmp(abcde, abcdx, 4) == 0);
    assert(strncmp(abcde, x, 0) == 0);
    assert(strncmp(abcde, x, 1) < 0);
    assert(strncmp(abcde, cmpabcd_, 10) < 0);

    return 0;
}
