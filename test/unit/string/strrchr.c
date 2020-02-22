#include "unit_test.h"
#include <string.h>

TEST(strrchr, found)
{
    const char *str = "abc";
    char *result    = strrchr(str, '\0');
    EXPECT(result == str + 3);
}

TEST(strrchr, not_found)
{
    const char *str = "abc";
    char *result    = strrchr(str, 'x');
    EXPECT(result == NULL);
}

TEST(strrchr, find_end_null)
{
    const char *str = "abc";
    char *result    = strrchr(str, '\0');
    EXPECT(result == str + 3);
}
