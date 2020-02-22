#include "unit_test.h"
#include <string.h>

TEST(strcpy, works)
{
    const char *src = "foo";
    char buffer[]   = { 1, 1, 1, 1, 1, 1 };
    char *dest      = buffer + 1;

    char *result = strcpy(dest, src);

    EXPECT(result == dest);

    EXPECT(buffer[0] == 1);
    EXPECT(buffer[1] == 'f');
    EXPECT(buffer[2] == 'o');
    EXPECT(buffer[3] == 'o');
    EXPECT(buffer[4] == '\0');
    EXPECT(buffer[5] == 1);
}
