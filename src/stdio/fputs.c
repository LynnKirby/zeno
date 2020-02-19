/* SPDX-License-Identifier: CC0-1.0 */

#include <stdio.h>
#include <string.h>

int fputs(const char *restrict s, FILE *restrict stream)
{
    size_t size = strlen(s);
    return fwrite(s, 1, size, stream) == size ? 1 : EOF;
}
