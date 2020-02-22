#include "unit_test.h"
#include <string.h>

TEST(strncpy, given_exact_length_of_src)
{
    const char *src = "foo";
    char buffer[]   = { 1, 1, 1, 1, 1, 1 };
    char *dest      = buffer + 1;

    char *result = strncpy(dest, src, 4);

    EXPECT(result == dest);

    EXPECT(buffer[0] == 1);
    EXPECT(buffer[1] == 'f');
    EXPECT(buffer[2] == 'o');
    EXPECT(buffer[3] == 'o');
    EXPECT(buffer[4] == '\0');
    EXPECT(buffer[5] == 1);
}

TEST(strncpy, given_length_less_than_src)
{
    const char *src = "foo";
    char buffer[]   = { 1, 1, 1, 1, 1, 1 };
    char *dest      = buffer + 1;

    char *result = strncpy(dest, src, 3);

    EXPECT(result == dest);

    EXPECT(buffer[0] == 1);
    EXPECT(buffer[1] == 'f');
    EXPECT(buffer[2] == 'o');
    EXPECT(buffer[3] == 'o');
    EXPECT(buffer[4] == 1);
    EXPECT(buffer[5] == 1);
}

TEST(strncpy, given_length_greater_than_src)
{
    const char *src = "foo";
    char buffer[]   = { 1, 1, 1, 1, 1, 1, 1, 1 };
    char *dest      = buffer + 1;

    char *result = strncpy(dest, src, 6);

    EXPECT(result == dest);

    EXPECT(buffer[0] == 1);
    EXPECT(buffer[1] == 'f');
    EXPECT(buffer[2] == 'o');
    EXPECT(buffer[3] == 'o');
    EXPECT(buffer[4] == '\0');
    EXPECT(buffer[5] == '\0');
    EXPECT(buffer[6] == '\0');
    EXPECT(buffer[7] == 1);
}
