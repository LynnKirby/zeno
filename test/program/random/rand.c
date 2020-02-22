#include "test.h"
#include <stdlib.h>

int main(void)
{
    /* Should act like its seeded with srand(1) at program start. */
    {
        int initial = rand();
        srand(1);
        assert(rand() == initial);
    }

    return 0;
}
