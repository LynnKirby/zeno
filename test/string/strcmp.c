#include "test.h"
#include <string.h>

int main(void)
{
    assert(strcmp("foo", "foo") == 0);
    assert(strcmp("abc", "xyz") < 0);
    assert(strcmp("xyz", "abc") > 0);
    return 0;
}
