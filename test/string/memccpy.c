#include "test.h"
#include <string.h>

int main(void)
{
    /* Found */
    {
        unsigned char src[100] = { 0 };
        unsigned char dest[100];
        src[41]  = 127;
        src[42]  = 255;
        dest[41] = 1;
        dest[43] = 1;

        void *result = memccpy(dest, src, 127, 100);

        /* Result must be pointer after the found character in dest. */
        assert(result == dest + 42);

        /* Must have copied up to the character. */
        for (size_t i = 0; i < 42; i++) {
            assert(dest[i] == src[i]);
        }

        /* Must not have overwritten past the found character. */
        assert(dest[43] == 1);
    }

    /* Not found */
    {
        unsigned char src[100] = { 0 };
        unsigned char dest[100];
        dest[42] = 42;

        void *result = memccpy(dest, src, 127, 100);

        /* Result must be NULL. */
        assert(result == NULL);

        /* Must have copied the entire string. */
        for (size_t i = 0; i < 100; i++) {
            assert(dest[i] == src[i]);
        }
    }

    return 0;
}
