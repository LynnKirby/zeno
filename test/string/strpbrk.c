#include "test.h"
#include <string.h>

int main(void)
{
    /* Found. */
    {
        const char *str = "abcd";
        char *result = strpbrk(str, "xybz");
        assert(result == str + 1);
    }

    /* Not found. */
    {
        char *result = strpbrk("abcd", "xyz");
        assert(result == NULL);
    }

    return 0;
}
