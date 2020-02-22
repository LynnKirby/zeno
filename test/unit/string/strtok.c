#include "unit_test.h"
#include <string.h>

TEST(strtok, works)
{
    char str[] = "?a???b,,,#c";
    char *t;

    t = strtok(str, "?");
    EXPECT(t == str + 1);
    EXPECT(str[2] == '\0');

    t = strtok(NULL, ",");
    EXPECT(t == str + 3);
    EXPECT(str[6] == '\0');

    t = strtok(NULL, "#,");
    EXPECT(t == str + 10);
    EXPECT(str[11] == '\0');

    t = strtok(NULL, "?");
    EXPECT(t == NULL);
}
