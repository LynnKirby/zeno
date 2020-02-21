#include <time.h>
#include "test.h"

int main(void)
{
    /* Can get time. We assume clock will not overflow in the time it takes to
     * run this test executable. */
    assert(clock() != 0);
    assert(clock() != -1);
    assert(clock() > 0);
    return 0;
}
