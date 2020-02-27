#include "header_test.h"
#include "fenv.h"

#ifndef FE_DFL_MODE
#error "FE_DFL_MODE not defined"
#endif

#ifndef FE_DFL_ENV
#error "FE_DFL_ENV not defined"
#endif

int main(void)
{
    integer_constant(__STDC_VERSION_FENV_H__);
    type(fenv_t);
    type(femode_t);
    type(fexcept_t);

#ifdef FE_DIVBYZERO
    integer_constant(FE_DIVBYZERO);
#endif
#ifdef FE_INEXACT
    integer_constant(FE_INEXACT);
#endif
#ifdef FE_INVALID
    integer_constant(FE_INVALID);
#endif
#ifdef FE_OVERFLOW
    integer_constant(FE_OVERFLOW);
#endif
#ifdef FE_UNDERFLOW
    integer_constant(FE_UNDERFLOW);
#endif
    integer_constant(FE_ALL_EXCEPT);

#ifdef FE_DOWNWARD
    integer_constant(FE_DOWNWARD);
#endif
#ifdef FE_TONEAREST
    integer_constant(FE_TONEAREST);
#endif
#ifdef FE_TONEARESTFROMZERO
    integer_constant(FE_TONEARESTFROMZERO);
#endif
#ifdef FE_TOWARDZERO
    integer_constant(FE_TOWARDZERO);
#endif
#ifdef FE_UPWARD
    integer_constant(FE_UPWARD);
#endif

    return 0;
}
