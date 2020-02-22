#include <assert.h>
#include <string.h>

int main(int argc, char **argv, char **envp)
{
    assert(argc >= 1);
    assert(argv);
    assert(envp);
    assert(strstr(argv[0], "main_args"));
    return 0;
}
