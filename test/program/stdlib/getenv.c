// ENV: TEST_GETENV_VAR=123456

#include "unit_test.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

TEST(getenv, can_get_the_variable)
{
    char *value = getenv("TEST_GETENV_VAR");
    EXPECT(value);
    EXPECT(strcmp(value, "123456") == 0);
}
