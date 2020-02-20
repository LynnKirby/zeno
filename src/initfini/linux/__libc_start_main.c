/* SPDX-License-Identifier: CC0-1.0 */

#include "basic/cdefs.h"
#include "initfini.h"
#include <stdlib.h>

static void do_init(void (*rtld_fini)(void))
{
    if (rtld_fini) {
        atexit(rtld_fini);
    }

    /* Pre-init. */
    if (__preinit_array_start) {
        size_t count = __preinit_array_end - __preinit_array_start;

        for (size_t i = 0; i < count; ++i) {
            __preinit_array_start[i]();
        }
    }

    /* Application init. */
    if (_init) {
        _init();
    }

    if (__init_array_start) {
        size_t count = __init_array_end - __init_array_start;

        for (size_t i = 0; i < count; ++i) {
            __init_array_start[i]();
        }
    }
}

int __libc_start_main(
    int (*main)(int, char **, char **),
    int argc,
    char **ubp_av,
    void (*init)(void),
    void (*fini)(void),
    void (*rtld_fini)(void),
    void *stack_end)
{
    UNUSED_PARAM(init);
    UNUSED_PARAM(fini);
    UNUSED_PARAM(stack_end);

    do_init(rtld_fini);
    char **envp = ubp_av + argc + 1;
    exit(main(argc, ubp_av, envp));
}
