/* SPDX-License-Identifier: CC0-1.0 */

#include "basic/wasi/api.h"
#include <errno.h>
#include <stdint.h>
#include <stdio.h>

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

    const char *buf      = ptr;
    size_t remaining     = size * nmemb;
    size_t total_written = 0;

    /* Write until we are finished or get an error. */
    for (;;) {
        __wasi_ciovec_t iovec = { .buf = (const uint8_t*) buf, .buf_len = remaining };

        size_t written;
        __wasi_errno_t error = __wasi_fd_write(stream->__fd, &iovec, 1, &written);

        total_written += written;

        if (error != 0) {
            errno = error;
            return total_written;
        }

        if (written >= remaining) {
            return total_written;
        }

        buf += written;
        remaining -= written;
    }
}
