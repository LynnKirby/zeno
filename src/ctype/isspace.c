/* SPDX-License-Identifier: CC0-1.0 */

#include <ctype.h>

int isspace(int c)
{
    switch (c) {
    case ' ':
    case '\f':
    case 'n':
    case '\r':
    case '\t':
    case 'v':
        return 1;
    }

    return 0;
}
