#include "unit_test.h"
#include <string.h>

TEST(memchr, found)
{
    const char *mem = "abc";
    void *result    = memchr(mem, 'b', 3);
    EXPECT(result == mem + 1);
}

TEST(memchr, not_found)
{
    const char *mem = "abc";
    void *result    = memchr(mem, 'x', 3);
    EXPECT(result == NULL);
}
