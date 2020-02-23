#include <assert.h>
#include <string.h>

#ifdef __wasi__
int main(int argc, char **argv)
#else
int main(int argc, char **argv, char **envp)
#endif
{
    assert(argc >= 1);
    assert(argv);
    assert(strstr(argv[0], "main_args"));
#ifndef __wasi__
    assert(envp);
#endif
    return 0;
}
