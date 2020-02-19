/* SPDX-License-Identifier: CC0-1.0 */

#include "basic/linux/syscall.h"
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/syscall.h>

/* You can multiply any size_t value by this without it overflowing. */
#define MUL_NO_OVERFLOW (1UL << (sizeof(size_t) * 4))

size_t fwrite(
    const void *restrict ptr, size_t size, size_t nmemb, FILE *restrict stream)
{
    if (size == 0) return 0;
    if (nmemb == 0) return 0;

    /* Check `size * nmemb` overflow. */
    if ((size > MUL_NO_OVERFLOW || nmemb > MUL_NO_OVERFLOW)
        && (nmemb > SIZE_MAX / size)) {
        errno = EOVERFLOW;
        return 0;
    }

    const char *buf = ptr;
    const char *end = buf + (size * nmemb);

    /* Write until we are finished or get an error. */
    for (;;) {
        long ret = __syscall3(SYS_write, stream->__fd, (long)buf, end - buf);

        if (ret < 0) {
            errno = -ret;
            return end - buf;
        }

        buf += ret;

        if (buf >= end) {
            return end - buf;
        }
    }
}
