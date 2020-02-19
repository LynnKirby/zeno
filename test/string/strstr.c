#include "test.h"
#include <string.h>

int main(void)
{
    /* Found in middle. */
    {
        const char *haystack = "foobar";
        const char *needle   = "oba";

        char *result = strstr(haystack, needle);

        assert(result == haystack + 2);
    }

    /* Found at end. */
    {
        const char *haystack = "foobar";
        const char *needle   = "bar";

        char *result = strstr(haystack, needle);

        assert(result == haystack + 3);
    }

    /* Not found. */
    {
        const char *haystack = "foobar";
        const char *needle   = "baz";

        char *result = strstr(haystack, needle);

        assert(result == NULL);
    }

    /* Empty needle. */
    {
        const char *haystack = "foobar";
        const char *needle   = "";

        char *result = strstr(haystack, needle);

        assert(result == haystack);
    }

    return 0;
}
