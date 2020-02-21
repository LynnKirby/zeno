/* SPDX-License-Identifier: CC0-1.0 */

#include "basic/wasi/api.h"
#include "time/impl.h"
#include <errno.h>
#include <limits.h>
#include <time.h>

clock_t clock(void)
{
    __wasi_timestamp_t time;
    __wasi_errno_t err
        = __wasi_clock_time_get(__WASI_CLOCKID_PROCESS_CPUTIME_ID, 0, &time);
    if (err != 0) return -1;

    /* WASI has nanosecond resolution clocks. */
    __wasi_timestamp_t clocks = time / (NSEC_PER_SEC / CLOCKS_PER_SEC);
    if (clocks > LONG_MAX) return -1;
    return clocks;
}
