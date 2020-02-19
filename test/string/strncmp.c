#include "test.h"
#include <string.h>

int main(void)
{
    assert(strncmp("foo", "foo", 10) == 0);

    assert(strncmp("abc", "xyzx", 10) < 0);
    assert(strncmp("xyz", "abcx", 10) > 0);

    assert(strncmp("aaa", "aabx", 2) < 0);
    assert(strncmp("baa", "aabx", 2) > 0);

    return 0;
}
