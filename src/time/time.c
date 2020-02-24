/* SPDX-License-Identifier: CC0-1.0 */

#include <time.h>

time_t time(time_t *tptr)
{
    time_t t;
    struct timespec ts;

    if (clock_gettime(CLOCK_REALTIME, &ts) == 0) {
        t = ts.tv_sec;
    } else {
        t = -1;
    }

    if (tptr) {
        *tptr = t;
    }

    return t;
}
