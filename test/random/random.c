#include "test.h"
#include <stdlib.h>

int main(void)
{
    /* Should act like its seeded with srandom(1) at program start. */
    {
        int initial = random();
        srandom(1);
        assert(random() == initial);
    }

    /* Can switch states. */
    {
        char state0[8];
        char *result_state0 = initstate(123, state0, 8);
        long result_random0 = random();

        char state1[8];
        char *result_state1 = initstate(123, state1, 8);
        long result_random1 = random();

        assert(result_state0);
        assert(result_state1 == state0);
        assert(result_random0 == result_random1);
    }

    return 0;
}
