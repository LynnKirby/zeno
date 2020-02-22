#include "test.h"
#include <ctype.h>

int main(void)
{
    assert(isalnum('b'));
    assert(!isalnum(' '));
    assert(isalpha('a'));
    assert(!isalpha('?'));
    assert(isblank(' '));
    assert(!isblank('\n'));
    assert(iscntrl('\b'));
    assert(!iscntrl('a'));
    assert(isdigit('0'));
    assert(!isdigit('-'));
    assert(isgraph(':'));
    assert(!isgraph('\t'));
    assert(islower('m'));
    assert(!islower('M'));
    assert(isprint(' '));
    assert(!isprint('\b'));
    assert(ispunct(','));
    assert(!ispunct(' '));
    assert(isspace('\r'));
    assert(!isspace('\0'));
    assert(isupper('M'));
    assert(!isupper('m'));
    assert(isxdigit('F'));
    assert(!isxdigit('x'));
    assert(tolower('X') == 'x');
    assert(tolower('+') == '+');
    assert(toupper('x') == 'X');
    assert(toupper('+') == '+');
    return 0;
}
