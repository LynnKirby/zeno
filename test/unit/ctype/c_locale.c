#include "unit_test.h"
#include <ctype.h>

TEST(ctype, c_locale)
{
    EXPECT(isalnum('b'));
    EXPECT(!isalnum(' '));
    EXPECT(isalpha('a'));
    EXPECT(!isalpha('?'));
    EXPECT(isblank(' '));
    EXPECT(!isblank('\n'));
    EXPECT(iscntrl('\b'));
    EXPECT(!iscntrl('a'));
    EXPECT(isdigit('0'));
    EXPECT(!isdigit('-'));
    EXPECT(isgraph(':'));
    EXPECT(!isgraph('\t'));
    EXPECT(islower('m'));
    EXPECT(!islower('M'));
    EXPECT(isprint(' '));
    EXPECT(!isprint('\b'));
    EXPECT(ispunct(','));
    EXPECT(!ispunct(' '));
    EXPECT(isspace('\r'));
    EXPECT(!isspace('\0'));
    EXPECT(isupper('M'));
    EXPECT(!isupper('m'));
    EXPECT(isxdigit('F'));
    EXPECT(!isxdigit('x'));
    EXPECT(tolower('X') == 'x');
    EXPECT(tolower('+') == '+');
    EXPECT(toupper('x') == 'X');
    EXPECT(toupper('+') == '+');
}
