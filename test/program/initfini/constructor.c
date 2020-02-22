#include <assert.h>
#include <stdio.h>

static int value = 0;

__attribute__((constructor)) static void ctor()
{
    // CHECK: ctor
    puts("ctor");
    assert(value == 0);
    value = 1;
}

int main()
{
    // CHECK: main
    puts("main");
    assert(value == 1);
    value = 2;
    return 0;
}

__attribute__((destructor)) static void dtor()
{
    // CHECK: dtor
    puts("dtor");
    assert(value == 2);
}
