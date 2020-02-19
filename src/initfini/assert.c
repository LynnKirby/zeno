/* SPDX-License-Identifier: CC0-1.0 */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* 20 characters + null */
#define UTOA_BUF_SIZE 21

static char *utoa(unsigned value, char *buf)
{
    char *ptr = buf + UTOA_BUF_SIZE - 1;
    *ptr      = '\0';

    do {
        ptr -= 1;
        *ptr = '0' + (value % 10);
        value /= 10;
    } while (value != 0);

    return ptr;
}

_Noreturn void __assert_fail(
    const char *assertion, const char *file, int line, const char *func)
{
    char buf[UTOA_BUF_SIZE];

    /* Message similar to: "a.c:10: foobar: Assertion a == b failed."
     * TODO: replace with fprintf when implemented. */
    fputs(file, stderr);
    fputs(":", stderr);
    fputs(utoa((unsigned) line, buf), stderr);
    fputs(": ", stderr);
    fputs(func, stderr);
    fputs(": ", stderr);
    fputs("Assertion ", stderr);
    fputs(assertion, stderr);
    fputs(" failed.\n", stderr);

    /* TODO: Should flush streams and call abort() when implemented. */
    _Exit(127);
}
