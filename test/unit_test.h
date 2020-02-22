/*
 * SPDX-License-Identifier: CC0-1.0
 * A unit test framework.
 */

#ifndef UNIT_TEST_H
#define UNIT_TEST_H

/*
 * Internal functions.
 */

typedef void (*LibcTestFn)(void);
int LibcTest_main(int argc, char **argv);
void LibcTest_register(const char *suite, const char *name, LibcTestFn fn);

/*
 * Define a unit test.
 */

#define TEST(suite, name)                                            \
    static void LibcTest_##suite##_##name(void);                     \
    static void LibcTest_register_##suite##_##name(void)             \
        __attribute__((constructor(__COUNTER__ + 1000)));            \
                                                                     \
    static void LibcTest_register_##suite##_##name(void)             \
    {                                                                \
        LibcTest_register(#suite, #name, LibcTest_##suite##_##name); \
    }                                                                \
                                                                     \
    static void LibcTest_##suite##_##name(void)

/*
 * Assertions.
 */

/* TODO: These assertions are only temporary until the existing tests are
 * moved to use proper assertions. */

_Bool LibcTest_expect_nonzero(
    _Bool expr, const char *expr_str, const char *file, int line);

#define EXPECT(cond) LibcTest_expect_nonzero(cond, #cond, __FILE__, __LINE__)
#define ASSERT(cond) if (!EXPECT(cond)) return

/*
 * main() definition.
 *
 * Some of the full test programs use this unit testing framework for assertions
 * but there isn't an easy way to determine which from CMake. Since we don't
 * know which need it, we always compile it into the test programs. This can
 * lead to link errors if the program has its own main() and we define a main()
 * in the test framework code. We get around that by putting main() in this
 * header, which is only included by programs that don't have their own.
 */

#ifdef LIBC_TEST_SHOW_MAIN
int main(int argc, char **argv, char **envp)
{
    (void)envp;
    return LibcTest_main(argc, argv);
}
#endif

#endif
