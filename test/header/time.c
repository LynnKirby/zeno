#include "test.h"
#include <time.h>

int main(void)
{
    assert_is_integer_constant(__STDC_VERSION_TIME_H__);
    assert_is_integer_constant(CLOCKS_PER_SEC);
    assert_is_integer_constant(TIME_UTC);
    assert_is_type(size_t);
    assert_is_type(clock_t);
    assert_is_type(time_t);
    assert_is_type(struct tm);
    assert_is_type(struct timespec);
    return 0;
}
