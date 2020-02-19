#include "test.h"
#include <string.h>

int main(void)
{
    /* Found. */
    {
        const char *mem = "abc";
        void *result = memchr(mem, 'b', 3);
        assert(result == mem + 1);
    }

    /* Not found. */
    {
        const char *mem = "abc";
        void *result = memchr(mem, 'x', 3);
        assert(result == NULL);
    }

    return 0;
}
