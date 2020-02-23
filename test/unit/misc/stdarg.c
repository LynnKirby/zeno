#include "unit_test.h"
#include <stdarg.h>

/* Clang 9 has a bug related to vararg codegen that makes this test fail. */
/* TODO: We need a general purpose macro to test whether something really is
 * main-line Clang and not a related compiler, like XCode Clang or Intel. */
#if __clang_major__ == 9

TEST(stdarg, works)
{
    SKIP_TEST();
}

#else

struct s {
    unsigned char bigarray[256];
};

static void vafunc(int a0, ...)
{
    va_list ap[2];
    va_start(ap[0], a0);
    va_copy(ap[1], ap[0]);

    for (int i = 0; i < 2; i++) {
        int a1       = va_arg(ap[i], int);
        long a2      = va_arg(ap[i], long);
        double a3    = va_arg(ap[i], double);
        struct s a4  = va_arg(ap[i], struct s);
        struct s *a5 = va_arg(ap[i], struct s *);
        EXPECT(a1 == 1);
        EXPECT(a2 == 2L);
        EXPECT(a3 == 3.0);
        EXPECT(a4.bigarray[123] == 123);
        EXPECT(a5->bigarray[123] == 123);
        va_end(ap[i]);
    }
}

TEST(stdarg, works)
{
    struct s s;
    s.bigarray[123] = 123;
    vafunc(0, 1, 2L, 3.0, s, &s);
}

#endif
