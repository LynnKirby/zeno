/* SPDX-License-Identifier: CC0-1.0 */

#include "test.h"
#include <string.h>

int main(void)
{
    unsigned char buffer[100];

    for (size_t i = 0; i < 100; i++) {
        buffer[i] = 0;
    }

    void *result = memset(buffer + 13, 127, 100 - 26);

    assert(result == buffer + 13);

    /* Must not modify data before. */
    for (size_t i = 0; i < 13; i++) {
        assert(buffer[i] == 0);
    }

    /* Must have filled ths specified buffer. */
    for (size_t i = 13; i < 100 - 13; i++) {
        assert(buffer[i] == 127);
    }

    /* Must not modify data after. */
    for (size_t i = 100 - 13; i < 100; i++) {
        assert(buffer[i] == 0);
    }

    return 0;
}
