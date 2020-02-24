/* SPDX-License-Identifier: CC0-1.0 */

#include <time.h>

int timespec_get(struct timespec *ts, int base)
{
    /* We only support the one mandatory time base. */
    if (base != TIME_UTC) return 0;
    if (clock_gettime(CLOCK_REALTIME, ts) == 0) return base;
    return 0;
}
