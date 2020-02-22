#include "unit_test.h"
#include <string.h>

TEST(strcat, works)
{
    char dest[] = { 'f', 'o', 'o', '\0', 1, 2, 3 };

    char *result = strcat(dest, "bar");

    EXPECT(result == dest);
    EXPECT(dest[0] == 'f');
    EXPECT(dest[1] == 'o');
    EXPECT(dest[2] == 'o');
    EXPECT(dest[3] == 'b');
    EXPECT(dest[4] == 'a');
    EXPECT(dest[5] == 'r');
    EXPECT(dest[6] == '\0');
}
