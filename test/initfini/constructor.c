#include "test.h"
#include <stdio.h>

static int value = 0;

__attribute__((constructor)) static void ctor()
{
    assert(value == 0);
    value = 1;
    puts("ctor\n");
}

int main()
{
    assert(value == 1);
    value = 2;
    puts("main\n");
    return 0;
}

__attribute__((destructor)) static void dtor()
{
    assert(value == 2);
    puts("dtor\n");
}
