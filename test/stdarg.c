#include "test.h"
#include <stdarg.h>

/* FIXME: Temporary memcpy implementation to make this test work. */
void *memcpy(void *dest, const void *src, unsigned long len)
{
    char *d       = dest;
    const char *s = src;
    while (len--) {
        *d++ = *s++;
    }
    return dest;
}

#ifndef va_arg
#error "!defined(va_arg)"
#endif

#ifndef va_start
#error "!defined(va_start)"
#endif

#ifndef va_end
#error "!defined(va_end)"
#endif

#ifndef va_copy
#error "!defined(va_copy)"
#endif

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
        assert(a1 == 1);
        assert(a2 == 2L);
        assert(a3 == 3.0);
        assert(a4.bigarray[123] == 123);
        assert(a5->bigarray[123] == 123);
        va_end(ap[i]);
    }
}

int main(void)
{
    struct s s;
    s.bigarray[123] = 123;
    vafunc(0, 1, 2L, 3.0, s, &s);
    return 0;
}
