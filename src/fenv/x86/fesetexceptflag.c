/* SPDX-License-Identifier: CC0-1.0 */

#include <fenv.h>
#include <stdint.h>

int fesetexceptflag(const fexcept_t *flagp, int excepts)
{
    fenv_t env;
    fegetenv(&env);
    excepts &= FE_ALL_EXCEPT;

    /* Unset exception status flags specified by excepts. */
    env.__mxcsr &= ~excepts;
    env.__status_word &= ~excepts;

    /* Set exception status flags from flagp that are specified by excepts.  */
    int set = *flagp & excepts & FE_ALL_EXCEPT;
    env.__mxcsr |= set;
    env.__status_word |= set;

    fesetenv(&env);
    return 0;
}
