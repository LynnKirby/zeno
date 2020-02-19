/* SPDX-License-Identifier: CC0-1.0 */

#include <errno.h>

/* TODO: Global until we get threads. */
static int global_errno;

int *__libc_errno(void)
{
    return &global_errno;
}
