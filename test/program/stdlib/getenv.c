// ENV: GETENV_VAR=123456

#include "unit_test.h"
#include "unit_test_main.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

TEST(getenv, can_get_the_variable)
{
    char *value = getenv("GETENV_VAR");
    EXPECT_PTR(value, !=, NULL);
    EXPECT_INT(strcmp(value, "123456"), ==, 0);
}
