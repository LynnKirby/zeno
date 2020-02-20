/*
 * SPDX-License-Identifier: CC0-1.0
 * Derived from wasi-libc.
 */

#include "basic/cdefs.h"
#include "basic/wasi/api.h"
#include <stdlib.h>
#include <sysexits.h>

/* TODO: Replace with the *real* empty __environ when its implemented. */
const char *empty_environ = NULL;

int main(int argc, char **argv, char **envp);

_LIBC_WEAK int __original_main(void)
{
    __wasi_errno_t err;

    /* Get the sizes of the arrays we'll have to create to copy in the args. */
    size_t argv_buf_size;
    size_t argc;
    err = __wasi_args_sizes_get(&argc, &argv_buf_size);

    if (err != __WASI_ERRNO_SUCCESS) {
        _Exit(EX_OSERR);
    }

    /* Add 1 for the NULL pointer to mark the end, and check for overflow. */
    size_t num_ptrs = argc + 1;
    if (num_ptrs == 0) {
        _Exit(EX_SOFTWARE);
    }

    /* Allocate memory for storing the argument chars. */
    char *argv_buf = malloc(argv_buf_size);
    if (argv_buf == NULL) {
        _Exit(EX_SOFTWARE);
    }

    /* Allocate memory for the array of pointers. */
    char **argv = calloc(num_ptrs, sizeof(char *));
    if (argv == NULL) {
        free(argv_buf);
        _Exit(EX_SOFTWARE);
    }

    /* Fill the argument chars, and the argv array. */
    err = __wasi_args_get((uint8_t **)argv, (uint8_t *)argv_buf);
    if (err != __WASI_ERRNO_SUCCESS) {
        free(argv_buf);
        free(argv);
        _Exit(EX_OSERR);
    }

    return main(argc, argv, (char **)&empty_environ);
}
