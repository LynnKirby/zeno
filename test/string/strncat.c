#include "test.h"
#include <string.h>

int main(void)
{
    /* n == strlen(src) */
    {
        char dest[] = { 'f', 'o', 'o', '\0', 1, 2, 3, 4 };

        char *result = strncat(dest, "bar", 3);

        assert(result == dest);
        assert(dest[0] == 'f');
        assert(dest[1] == 'o');
        assert(dest[2] == 'o');
        assert(dest[3] == 'b');
        assert(dest[4] == 'a');
        assert(dest[5] == 'r');
        assert(dest[6] == '\0');
        assert(dest[7] == 4);
    }

    /* n > strlen(src) */
    {
        char dest[] = { 'f', 'o', 'o', '\0', 1, 2, 3, 4 };

        char *result = strncat(dest, "bar", 100);

        assert(result == dest);
        assert(dest[0] == 'f');
        assert(dest[1] == 'o');
        assert(dest[2] == 'o');
        assert(dest[3] == 'b');
        assert(dest[4] == 'a');
        assert(dest[5] == 'r');
        assert(dest[6] == '\0');
        assert(dest[7] == 4);
    }

    /* n < strlen(src) */
    {
        char dest[] = { 'f', 'o', 'o', '\0', 1, 2, 3, 4 };

        char *result = strncat(dest, "bar", 2);

        assert(result == dest);
        assert(dest[0] == 'f');
        assert(dest[1] == 'o');
        assert(dest[2] == 'o');
        assert(dest[3] == 'b');
        assert(dest[4] == 'a');
        assert(dest[5] == '\0');
        assert(dest[6] == 3);
        assert(dest[7] == 4);
    }

    return 0;
}
