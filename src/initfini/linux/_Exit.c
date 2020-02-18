/* SPDX-License-Identifier: CC0-1.0 */

#include "basic/linux/syscall.h"
#include <sys/syscall.h>

_Noreturn void _Exit(int status)
{
    for (;;) {
        __syscall1(SYS_exit_group, status);
    }
}
