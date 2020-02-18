/* SPDX-License-Identifier: CC0-1.0 */

#include <assert.h>

_Noreturn void __assert_fail(
    const char *expr, const char *file, int line, const char *func)
{
    /* FIXME: Fake assertion until IO is implemented. */
#ifdef _MSC_VER
    __debugbreak();
#else
    __builtin_trap();
#endif
}
