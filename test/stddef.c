#include "test.h"
#include <stddef.h>

struct s {
    char f0;
    char f1;
};

int main(void)
{
    char *x = NULL;
    char start;
    char end;
    ptrdiff_t diff = &end - &start;

    size_t size = sizeof(x);

    assert_is_type(max_align_t);

    wchar_t wc = L'c';

    assert(offsetof(struct s, f0) == 0);
    assert(offsetof(struct s, f1) == 1);

    return 0;
}
