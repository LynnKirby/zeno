/* SPDX-License-Identifier: CC0-1.0 */

#include "initfini.h"
#include <stddef.h>

void __libc_csu_fini(void)
{
    if (__fini_array_start) {
        size_t count = __fini_array_end - __fini_array_start;

        for (size_t i = count; i > 0; --i) {
            __fini_array_start[i - 1]();
        }
    }

    if (_fini) {
        _fini();
    }
}
