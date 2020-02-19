#include "test.h"
#include <string.h>

int main(void)
{
    assert(strlen("") == 0);
    assert(strlen("foo") == 3);
    return 0;
}
