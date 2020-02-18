/* SPDX-License-Identifier: CC0-1.0 */

#include "initfini.h"

/* TODO: Use size_t when available. */

void __libc_csu_init()
{
    if (__preinit_array_start) {
        unsigned long count = __preinit_array_end - __preinit_array_start;

        for (unsigned long i = 0; i < count; ++i) {
            __preinit_array_start[i]();
        }
    }

    if (_init) {
        _init();
    }

    if (__init_array_start) {
        unsigned long count = __init_array_end - __init_array_start;

        for (unsigned long i = 0; i < count; ++i) {
            __init_array_start[i]();
        }
    }
}
