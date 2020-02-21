/* TODO: Remove once feature tests are implemented. */
#define _LIBC_POSIX_VISIBLE 1

#include "test.h"
#include <stdlib.h>

int main(void)
{
    /* Is deterministic. */
    {
        unsigned state  = 123;
        long result0    = rand_r(&state);
        state           = 123;
        long result1    = rand_r(&state);
        unsigned state2 = 123;
        long result2    = rand_r(&state2);

        assert(result0 == result1);
        assert(result1 == result2);
    }

    return 0;
}
