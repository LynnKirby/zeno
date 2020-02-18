#include "test.h"

static int value = 0;

__attribute__((constructor)) static void ctor()
{
    assert(value == 0);
    value = 1;
}

int main()
{
    assert(value == 1);
    value = 2;
    return 0;
}

__attribute__((destructor)) static void dtor()
{
    assert(value == 2);
}
