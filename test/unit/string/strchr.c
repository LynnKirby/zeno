#include "test.h"
#include <string.h>

int main(void)
{
    /* Found. */
    {
        const char *str = "abc";
        char *result    = strchr(str, 'b');
        assert(result == str + 1);
    }

    /* Not found. */
    {
        const char *str = "abc";
        char *result    = strchr(str, 'x');
        assert(result == NULL);
    }

    /* Ending null is included in search. */
    {
        const char *str = "abc";
        char *result    = strchr(str, '\0');
        assert(result == str + 3);
    }

    return 0;
}
