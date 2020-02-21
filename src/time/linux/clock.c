/* SPDX-License-Identifier: CC0-1.0 */

#include "time/impl.h"
#include <limits.h>
#include <time.h>

clock_t clock(void)
{
    struct timespec ts;

    if (clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts) != 0) {
        return -1;
    }

    if (ts.tv_sec > LONG_MAX / CLOCKS_PER_SEC) return -1;
    long converted_sec = ts.tv_sec * CLOCKS_PER_SEC;
    if (ts.tv_nsec / 1000 > LONG_MAX - converted_sec) return -1;
    return converted_sec + (ts.tv_nsec / (NSEC_PER_SEC / CLOCKS_PER_SEC));
}
