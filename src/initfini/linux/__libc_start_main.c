/* SPDX-License-Identifier: CC0-1.0 */

#include "basic/cdefs.h"
#include "initfini/linux/impl.h"
#include "stdlib/impl.h"

static void do_init(char **envp, void (*rtld_fini)(void))
{
    environ = envp;

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

    char **envp = ubp_av + argc + 1;
    do_init(envp, rtld_fini);
    exit(main(argc, ubp_av, envp));
}
