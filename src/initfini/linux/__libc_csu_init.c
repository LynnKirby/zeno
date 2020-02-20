/* SPDX-License-Identifier: CC0-1.0 */

#include "initfini.h"
#include <stddef.h>

void __libc_csu_init(void)
{
    if (__preinit_array_start) {
        size_t count = __preinit_array_end - __preinit_array_start;

        for (size_t i = 0; i < count; ++i) {
            __preinit_array_start[i]();
        }
    }

    if (_init) {
        _init();
    }

    if (__init_array_start) {
        size_t count = __init_array_end - __init_array_start;

        for (size_t i = 0; i < count; ++i) {
            __init_array_start[i]();
        }
    }

    /* Initialize libc subsystems. */
    __libc_init();
}
