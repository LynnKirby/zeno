#include "test.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

extern char **environ;

int main(void)
{
    char *value = getenv("TEST_GETENV_VAR");
    assert(value);
    assert(strcmp(value, "123456") == 0);
    return 0;
}
