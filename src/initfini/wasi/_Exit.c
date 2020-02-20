/* SPDX-License-Identifier: CC0-1.0 */

#include "basic/cdefs.h"
#include "basic/wasi/api.h"

_Noreturn void _Exit(int status)
{
    __wasi_proc_exit(status);
}

STRONG_ALIAS(_Exit, _exit);
