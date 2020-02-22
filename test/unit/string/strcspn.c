#include "test.h"
#include <string.h>

int main(void)
{
    assert(strcspn("", "") == 0);
    assert(strcspn("abc", "xyz") == 3);
    assert(strcspn("valid", "invalid") == 0);
    return 0;
}
