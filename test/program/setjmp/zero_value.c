#include <assert.h>
#include <stdio.h>
#include <setjmp.h>

// CHECK: pre-setjmp
// CHECK: post-setjmp
// CHECK: pre-longjmp
// CHECK: post-setjmp
// CHECK: setjmp returned from longjmp

#ifndef SETJMP_VALUE
#define SETJMP_VALUE 0
#define EXPECTED_VALUE 1
#endif

int main(void)
{
    jmp_buf buf;

    puts("pre-setjmp");
    int value = setjmp(buf);
    puts("post-setjmp");

    if (value == 0) {
        puts("pre-longjmp");
        longjmp(buf, SETJMP_VALUE);
        puts("post-longjmp");
        assert(0 && "unreachable");
    } else {
        assert(value == EXPECTED_VALUE);
        puts("setjmp returned from longjmp");
    }

    return 0;
}
