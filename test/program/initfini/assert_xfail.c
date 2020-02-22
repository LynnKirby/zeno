#include <assert.h>

int main(void)
{
    // RETURN: 127
    // ALLOW-STDERR: true
    assert(1 == 2);
    return 0;
}
