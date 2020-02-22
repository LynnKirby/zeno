#include "test.h"
#include <string.h>

int main(void)
{
    /* Found. */
    {
        const char *str = "aab";
        char *result    = strrchr(str, 'a');
        assert(result == str + 1);
    }

    /* Not found. */
    {
        const char *str = "abc";
        char *result    = strrchr(str, 'x');
        assert(result == NULL);
    }

    /* Ending null is included in search. */
    {
        const char *str = "abc";
        char *result    = strrchr(str, '\0');
        assert(result == str + 3);
    }

    return 0;
}
