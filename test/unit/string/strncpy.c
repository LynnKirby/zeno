#include "test.h"
#include <string.h>

int main(void)
{
    /* n == strlen(src)+1 */
    {
        const char *src = "foo";
        char buffer[]   = { 1, 1, 1, 1, 1, 1 };
        char *dest      = buffer + 1;

        char *result = strncpy(dest, src, 4);

        assert(result == dest);

        assert(buffer[0] == 1);
        assert(buffer[1] == 'f');
        assert(buffer[2] == 'o');
        assert(buffer[3] == 'o');
        assert(buffer[4] == '\0');
        assert(buffer[5] == 1);
    }

    /* n < strlen(src)+1 */
    {
        const char *src = "foo";
        char buffer[]   = { 1, 1, 1, 1, 1, 1 };
        char *dest      = buffer + 1;

        char *result = strncpy(dest, src, 3);

        assert(result == dest);

        assert(buffer[0] == 1);
        assert(buffer[1] == 'f');
        assert(buffer[2] == 'o');
        assert(buffer[3] == 'o');
        assert(buffer[4] == 1);
        assert(buffer[5] == 1);
    }

    /* n > strlen(src)+1 */
    {
        const char *src = "foo";
        char buffer[]   = { 1, 1, 1, 1, 1, 1, 1, 1 };
        char *dest      = buffer + 1;

        char *result = strncpy(dest, src, 6);

        assert(result == dest);

        assert(buffer[0] == 1);
        assert(buffer[1] == 'f');
        assert(buffer[2] == 'o');
        assert(buffer[3] == 'o');
        assert(buffer[4] == '\0');
        assert(buffer[5] == '\0');
        assert(buffer[6] == '\0');
        assert(buffer[7] == 1);
    }

    return 0;
}
