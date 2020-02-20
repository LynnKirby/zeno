/* SPDX-License-Identifier: CC0-1.0 */

#include "basic/wasi/api.h"
#include <errno.h>
#include <unistd.h>

ssize_t write(int fd, const void *buf, size_t count)
{
    size_t written;
    __wasi_ciovec_t iovec = { .buf = (const uint8_t *)buf, .buf_len = count };
    __wasi_errno_t error  = __wasi_fd_write(fd, &iovec, 1, &written);

    if (error != 0) {
        errno = error;
        return -1;
    }

    return written;
}
