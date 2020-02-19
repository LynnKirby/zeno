#ifdef _MSC_VER
#define _LIBC_ALLOW_MSVC_NORETURN
#endif

#include <stdnoreturn.h>

#if defined(_MSC_VER) && defined(noreturn)
#error "noreturn was defined on MSVC"
#elif !defined(_MSC_VER) && !defined(noreturn)
#error "noreturn not defined"
#endif

int main(void)
{
    return 0;
}
