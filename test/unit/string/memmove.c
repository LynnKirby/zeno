#include "test.h"
#include <string.h>

int main(void)
{
    /* No overlap. src is before dest. */
    {
        char buffer[] = { 0, 1, 2, 3, 4, 5 };
        char *src     = buffer;
        char *dest    = buffer + 3;

        void *result = memmove(dest, src, 3);

        assert(result == dest);

        assert(buffer[0] == 0);
        assert(buffer[1] == 1);
        assert(buffer[2] == 2);
        assert(buffer[3] == 0);
        assert(buffer[4] == 1);
        assert(buffer[5] == 2);
    }

    /* No overlap. src is after dest. */
    {
        char buffer[] = { 0, 1, 2, 3, 4, 5 };
        char *src     = buffer + 3;
        char *dest    = buffer;

        void *result = memmove(dest, src, 3);

        assert(result == dest);

        assert(buffer[0] == 3);
        assert(buffer[1] == 4);
        assert(buffer[2] == 5);
        assert(buffer[3] == 3);
        assert(buffer[4] == 4);
        assert(buffer[5] == 5);
    }

    /* Overlap. src starts before dest. */
    {
        char buffer[] = { 0, 1, 2, 3, 4, 5 };
        char *src     = buffer;
        char *dest    = buffer + 2;

        void *result = memmove(dest, src, 4);

        assert(result == dest);

        assert(buffer[0] == 0);
        assert(buffer[1] == 1);
        assert(buffer[2] == 0);
        assert(buffer[3] == 1);
        assert(buffer[4] == 2);
        assert(buffer[5] == 3);
    }

    /* Overlap. src is after dest. */
    {
        char buffer[] = { 0, 1, 2, 3, 4, 5 };
        char *src     = buffer + 2;
        char *dest    = buffer;

        void *result = memmove(dest, src, 4);

        assert(result == dest);

        assert(buffer[0] == 2);
        assert(buffer[1] == 3);
        assert(buffer[2] == 4);
        assert(buffer[3] == 5);
        assert(buffer[4] == 4);
        assert(buffer[5] == 5);
    }

    /* src == dest. */
    {
        char buffer[] = { 0, 1, 2, 3, 4, 5 };

        void *result = memmove(buffer, buffer, 4);

        assert(result == buffer);

        assert(buffer[0] == 0);
        assert(buffer[1] == 1);
        assert(buffer[2] == 2);
        assert(buffer[3] == 3);
        assert(buffer[4] == 4);
        assert(buffer[5] == 5);
    }

    return 0;
}
