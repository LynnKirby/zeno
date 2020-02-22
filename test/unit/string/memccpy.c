#include "unit_test.h"
#include <string.h>

TEST(memccpy, found)
{
    unsigned char src[100] = { 0 };
    unsigned char dest[100];
    src[41]  = 127;
    src[42]  = 255;
    dest[41] = 1;
    dest[43] = 1;

    void *result = memccpy(dest, src, 127, 100);

    /* Result must be pointer after the found character in dest. */
    EXPECT(result == dest + 42);

    /* Must have copied up to the character. */
    for (size_t i = 0; i < 42; i++) {
        EXPECT(dest[i] == src[i]);
    }

    /* Must not have overwritten past the found character. */
    EXPECT(dest[43] == 1);
}

TEST(memccpy, not_found)
{
    unsigned char src[100] = { 0 };
    unsigned char dest[100];
    dest[42] = 42;

    void *result = memccpy(dest, src, 127, 100);

    /* Result must be NULL. */
    EXPECT(result == NULL);

    /* Must have copied the entire string. */
    for (size_t i = 0; i < 100; i++) {
        EXPECT(dest[i] == src[i]);
    }
}
