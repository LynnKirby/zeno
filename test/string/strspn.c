#include "test.h"
#include <string.h>

int main(void)
{
    assert(strspn("", "") == 0);
    assert(strspn("abc", "xyz") == 0);
    assert(strspn("validxx", "invalid") == 5);
    return 0;
}
