/* SPDX-License-Identifier: CC0-1.0 */

#include "basic/wasi/api.h"
#include "time/impl.h"
#include <errno.h>
#include <stdint.h>
#include <time.h>

int clock_gettime(clockid_t clk, struct timespec *ts)
{
    __wasi_timestamp_t time;
    __wasi_errno_t err = __wasi_clock_time_get(clk, 1, &time);
    if (err != 0) {
        errno = err;
        return -1;
    }
    /* WASI has nanosecond resolution clocks. */
    ts->tv_sec  = time / NSEC_PER_SEC;
    ts->tv_nsec = time % NSEC_PER_SEC;
    return 0;
}
