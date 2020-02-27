/* SPDX-License-Identifier: CC0-1.0 */

#include "fenv/x86/impl.h"
#include <bits/config.h>
#include <fenv.h>

int fesetenv(const fenv_t *envp)
{
    if (envp == FE_DFL_ENV) {
        /* Overwrite current environment with what we need for the default. */
        fenv_t env;
        fegetenv(&env);

        /* Clear status and control registeres except for the top bits of the
         * x87 status register which shouldn't be modified. */
        env.__status_word &= ~FE_ALL_EXCEPT;
        env.__mxcsr = 0;
        env.__control_word = 0;

        /* Mask all exceptions. */
        env.__control_word |= FE_ALL_EXCEPT;
        env.__mxcsr |= FE_ALL_EXCEPT << MXCSR_EXCEPT_MASK_SHIFT;

        /* Set precision. This is effectively the target-specific long double
         * format for x86. */
#if _LIBC_CONFIG_LDBL_FORMAT_INTEL80
        env.__control_word |= X87_EXTENDED_PRECISION;
#elif _LIBC_CONFIG_LDBL_FORMAT_BINARY64
        env.__control_word |= X87_DOUBLE_PRECISION;
#else
#error "Invalid long double format."
#endif

        __libc_fesetenv(&env);
    } else {
        __libc_fesetenv(envp);
    }

    return 0;
}
