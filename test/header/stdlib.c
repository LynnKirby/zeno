#include "header_test.h"
#include <stdlib.h>

#ifndef MB_CUR_MAX
#error "MB_CUR_MAX not defined"
#endif

#ifndef NULL
#error "NULL not defined"
#endif

int main()
{
    void *n = NULL;

    type(size_t);
    type(wchar_t);
    type(div_t);
    type(ldiv_t);
    type(lldiv_t);

    integer_constant(__STDC_VERSION_STDLIB_H__);
    integer_constant(EXIT_FAILURE);
    integer_constant(EXIT_SUCCESS);
    integer_constant(RAND_MAX);

    return 0;
}
