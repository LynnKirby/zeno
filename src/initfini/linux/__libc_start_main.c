/* SPDX-License-Identifier: CC0-1.0 */

#include "initfini.h"
#include <stdlib.h>

int __libc_start_main(
    int (*main)(int, char **, char **),
    int argc,
    char **ubp_av,
    void (*init)(void),
    void (*fini)(void),
    void (*rtld_fini)(void),
    void *stack_end)
{
    if (init) {
        init();
    }

    if (rtld_fini) {
        atexit(rtld_fini);
    }

    if (fini) {
        atexit(fini);
    }

    char **envp = ubp_av + argc + 1;
    exit(main(argc, ubp_av, envp));
}
