#include "test.h"
#include <string.h>

int main(void)
{
    char dest[] = { 'f', 'o', 'o', '\0', 1, 2, 3 };

    char *result = strcat(dest, "bar");

    assert(result == dest);
    assert(dest[0] == 'f');
    assert(dest[1] == 'o');
    assert(dest[2] == 'o');
    assert(dest[3] == 'b');
    assert(dest[4] == 'a');
    assert(dest[5] == 'r');
    assert(dest[6] == '\0');

    return 0;
}
