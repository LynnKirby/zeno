/* SPDX-License-Identifier: CC0-1.0 */

#include "initfini.h"

/* TODO: Use size_t when available. */

void __libc_csu_fini()
{
    if (__fini_array_start) {
        unsigned long count = __fini_array_end - __fini_array_start;

        for (unsigned long i = count; i > 0; --i) {
            __fini_array_start[i - 1]();
        }
    }

    if (_fini) {
        _fini();
    }
}
