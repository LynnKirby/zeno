/* SPDX-License-Identifier: CC0-1.0 */

#include "initfini/linux/impl.h"
#include <stdlib.h>

_Noreturn void exit(int status)
{
    __libc_run_atexit_handlers();

    if (__fini_array_start) {
        size_t count = __fini_array_end - __fini_array_start;

        for (size_t i = count; i > 0; --i) {
            __fini_array_start[i - 1]();
        }
    }

    if (_fini) {
        _fini();
    }

    _Exit(status);
}
