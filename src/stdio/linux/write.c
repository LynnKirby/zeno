/* SPDX-License-Identifier: CC0-1.0 */

#include "basic/linux/syscall.h"
#include <errno.h>
#include <sys/syscall.h>
#include <unistd.h>

ssize_t write(int fd, const void *buf, size_t count)
{
    return syscall(SYS_write, fd, (long)buf, count);
}
