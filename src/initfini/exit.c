/* SPDX-License-Identifier: CC0-1.0 */

#include "initfini.h"
#include <stdlib.h>

_Noreturn void exit(int status)
{
    __libc_run_atexit_handlers();
    _Exit(status);
}
