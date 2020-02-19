#include "test.h"
#include <string.h>

int main(void)
{
    assert(memcmp("ffoo", "ffoo", 3) == 0);
    assert(memcmp("abc", "axyz", 3) < 0);
    assert(memcmp("xyz", "xabc", 3) > 0);
    return 0;
}
