/* SPDX-License-Identifier: CC0-1.0 */

#include "basic/linux/syscall.h"
#include <stdint.h>
#include <sys/syscall.h>
#include <time.h>

#ifdef SYS_clock_gettime64
struct timespec32 {
    int32_t tv_sec;
    int32_t tv_nsec;
};

struct timespec64 {
    int64_t tv_sec;
    int64_t tv_nsec;
};

int clock_gettime(clockid_t clk, struct timespec *ts)
{
    long r;
    struct timespec64 ts64;

    /* Try to use 64-bit version. */
    r = __syscall(SYS_clock_gettime64, clk, (long)&ts64);

    /* clock_gettime64 is from Linux 5.1 (May 2019) so fall back to the 32-bit
     * version if we don't have it. */
    if (r == -ENOSYS) {
        struct timespec32 ts32;
        r = __syscall(SYS_clock_gettime, clk, (long)&ts32);
        if (r == 0) {
            ts->tv_sec  = ts32.tv_sec;
            ts->tv_nsec = ts32.tv_nsec;
        }
    } else if (r == 0) {
        ts->tv_sec = ts64.tv_sec;
        /* It's a 64-bit value but the kernel always returns a normalized value
         * where tv_nsec is less than 1 second. */
        ts->tv_nsec = (int32_t)ts64.tv_nsec;
    }

    return __syscall_handle_errno(r);
}
#else
int clock_gettime(clockid_t clk, struct timespec *ts)
{
    __syscall_handle_errno(__syscall(SYS_clock_gettime, clk, (long)ts));
}
#endif
