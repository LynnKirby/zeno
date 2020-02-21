/* SPDX-License-Identifier: CC0-1.0 */

#include "basic/cdefs.h"
#include "basic/linux/syscall.h"
#include <sys/syscall.h>

_Noreturn void _Exit(int status)
{
    for (;;) {
        __syscall(SYS_exit_group, status);
    }
}

STRONG_ALIAS(_Exit, _exit);
