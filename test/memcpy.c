#include <string.h>
#include "test.h"

int main(void)
{
    char src[100];
    src[42] = 123;
    char dest[100];
    void *result = memcpy(dest, src, 100);
    assert(result == dest);

    for (size_t i = 0; i < 100; i++) {
        assert(dest[i] == src[i]);
    }
}
