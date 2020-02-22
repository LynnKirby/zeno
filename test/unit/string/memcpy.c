#include <string.h>
#include "unit_test.h"

TEST(memcpy, works)
{
    char src[100];
    src[42] = 123;
    char dest[100];
    void *result = memcpy(dest, src, 100);
    EXPECT(result == dest);

    for (size_t i = 0; i < 100; i++) {
        EXPECT(dest[i] == src[i]);
    }
}
