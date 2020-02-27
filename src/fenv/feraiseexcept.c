/* SPDX-License-Identifier: CC0-1.0 */

#include <fenv.h>

/*
 * This function is supposed to raise exceptions but the default environment has
 * all exceptions masked and we don't provide a way to change that, so we don't
 * need to raise anything specifically.
 */

int feraiseexcept(int excepts)
{
    return fesetexcept(excepts);
}
