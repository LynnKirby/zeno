#include "test.h"
#include <string.h>

int main(void)
{
    char str[] = "?a???b,,,#c";
    char *t;

    t = strtok(str, "?");
    assert(t == str + 1);
    assert(str[2] == '\0');

    t = strtok(NULL, ",");
    assert(t == str + 3);
    assert(str[6] == '\0');

    t = strtok(NULL, "#,");
    assert(t == str + 10);
    assert(str[11] == '\0');

    t = strtok(NULL, "?");
    assert(t == NULL);

    return 0;
}
