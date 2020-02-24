#include "unit_test.h"
#include <string.h>

TEST(strtok, works)
{
    char str[] = "?a???b,,,#c";
    char *t;

    t = strtok(str, "?");
    EXPECT_PTR(t, ==, str + 1);
    EXPECT_CHAR(str[2], ==, '\0');

    t = strtok(NULL, ",");
    EXPECT_PTR(t, ==, str + 3);
    EXPECT_CHAR(str[6], ==, '\0');

    t = strtok(NULL, "#,");
    EXPECT_PTR(t, ==, str + 10);
    EXPECT_CHAR(str[11], ==, '\0');

    t = strtok(NULL, "?");
    EXPECT_PTR(t, ==, NULL);
}
