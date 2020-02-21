/* SPDX-License-Identifier: CC0-1.0 */

#include "basic/linux/syscall.h"
#include <stdint.h>
#include <sys/syscall.h>
#include <time.h>

struct timespec32 {
    uint32_t tv_sec;
    long tv_nsec;
};

int clock_gettime(clockid_t clk, struct timespec *ts)
{
    long r;

#ifdef SYS_clock_gettime64
    /* Try to use 64-bit version if it's defined for this architecture. */
    r = __syscall(SYS_clock_gettime64, clk, (long)ts);

    /* clock_gettime64 is from Linux 5.1 (May 2019) so fall back to the 32-bit
     * version if we don't have it. */
    if (r == -ENOSYS) {
        struct timespec32 ts32;
        r = __syscall(SYS_clock_gettime, clk, (long)&ts32);
        if (r == 0) {
            ts->tv_sec  = ts32.tv_sec;
            ts->tv_nsec = ts32.tv_nsec;
        }
    }
#else
    r = __syscall(SYS_clock_gettime, clk, (long)ts);
#endif

    return __syscall_handle_errno(r);
}
