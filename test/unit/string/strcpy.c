#include "test.h"
#include <string.h>

int main(void)
{
    const char *src = "foo";
    char buffer[]   = { 1, 1, 1, 1, 1, 1 };
    char *dest      = buffer + 1;

    char *result = strcpy(dest, src);

    assert(result == dest);

    assert(buffer[0] == 1);
    assert(buffer[1] == 'f');
    assert(buffer[2] == 'o');
    assert(buffer[3] == 'o');
    assert(buffer[4] == '\0');
    assert(buffer[5] == 1);

    return 0;
}
