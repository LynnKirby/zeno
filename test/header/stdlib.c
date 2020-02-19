#include "test.h"
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

    assert_is_type(size_t);
    assert_is_type(wchar_t);
    assert_is_type(div_t);
    assert_is_type(ldiv_t);
    assert_is_type(lldiv_t);

    assert_is_integer_constant(__STDC_VERSION_STDLIB_H__);
    assert_is_integer_constant(EXIT_FAILURE);
    assert_is_integer_constant(EXIT_SUCCESS);
    assert_is_integer_constant(RAND_MAX);

    return 0;
}
