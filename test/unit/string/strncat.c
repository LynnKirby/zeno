#include "unit_test.h"
#include <string.h>

TEST(strncat, given_exact_length_of_src)
{
    char dest[] = { 'f', 'o', 'o', '\0', 1, 2, 3, 4 };

    char *result = strncat(dest, "bar", 3);

    EXPECT(result == dest);
    EXPECT(dest[0] == 'f');
    EXPECT(dest[1] == 'o');
    EXPECT(dest[2] == 'o');
    EXPECT(dest[3] == 'b');
    EXPECT(dest[4] == 'a');
    EXPECT(dest[5] == 'r');
    EXPECT(dest[6] == '\0');
    EXPECT(dest[7] == 4);
}

TEST(strncat, given_length_less_than_src)
{
    char dest[] = { 'f', 'o', 'o', '\0', 1, 2, 3, 4 };

    char *result = strncat(dest, "bar", 2);

    EXPECT(result == dest);
    EXPECT(dest[0] == 'f');
    EXPECT(dest[1] == 'o');
    EXPECT(dest[2] == 'o');
    EXPECT(dest[3] == 'b');
    EXPECT(dest[4] == 'a');
    EXPECT(dest[5] == '\0');
    EXPECT(dest[6] == 3);
    EXPECT(dest[7] == 4);
}

TEST(strncat, given_length_greater_than_src)
{
    char dest[] = { 'f', 'o', 'o', '\0', 1, 2, 3, 4 };

    char *result = strncat(dest, "bar", 100);

    EXPECT(result == dest);
    EXPECT(dest[0] == 'f');
    EXPECT(dest[1] == 'o');
    EXPECT(dest[2] == 'o');
    EXPECT(dest[3] == 'b');
    EXPECT(dest[4] == 'a');
    EXPECT(dest[5] == 'r');
    EXPECT(dest[6] == '\0');
    EXPECT(dest[7] == 4);
}
