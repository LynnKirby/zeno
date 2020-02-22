#include <stdio.h>
#include <stdlib.h>

#define make_dtor(n)   \
    void dtor##n(void) \
    {                  \
        puts(#n "-");  \
    }                  \
    extern char __var_to_allow_semicolon

/* At least 32 must be able to be registered and thats what we allow without
 * allocation. */
make_dtor(0);
make_dtor(1);
make_dtor(2);
make_dtor(3);
make_dtor(4);
make_dtor(5);
make_dtor(6);
make_dtor(7);
make_dtor(8);
make_dtor(9);
make_dtor(10);
make_dtor(11);
make_dtor(12);
make_dtor(13);
make_dtor(14);
make_dtor(15);
make_dtor(16);
make_dtor(17);
make_dtor(18);
make_dtor(19);
make_dtor(20);
make_dtor(21);
make_dtor(22);
make_dtor(23);
make_dtor(24);
make_dtor(25);
make_dtor(26);
make_dtor(27);
make_dtor(28);
make_dtor(29);
make_dtor(30);
make_dtor(31);

/* Next triggers allocation. */
make_dtor(32);

int main(void)
{
    atexit(dtor32);
    atexit(dtor31);
    atexit(dtor30);
    atexit(dtor29);
    atexit(dtor28);
    atexit(dtor27);
    atexit(dtor26);
    atexit(dtor25);
    atexit(dtor24);
    atexit(dtor23);
    atexit(dtor22);
    atexit(dtor21);
    atexit(dtor20);
    atexit(dtor19);
    atexit(dtor18);
    atexit(dtor17);
    atexit(dtor16);
    atexit(dtor15);
    atexit(dtor14);
    atexit(dtor13);
    atexit(dtor12);
    atexit(dtor11);
    atexit(dtor10);
    atexit(dtor9);
    atexit(dtor8);
    atexit(dtor7);
    atexit(dtor6);
    atexit(dtor5);
    atexit(dtor4);
    atexit(dtor3);
    atexit(dtor2);
    atexit(dtor1);
    atexit(dtor0);
    return 0;
}
