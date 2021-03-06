/*
 * SPDX-License-Identifier: CC0-1.0
 * A unit test framework.
 */

#ifndef UNIT_TEST_H
#define UNIT_TEST_H

#include <stdbool.h>
#include <stdint.h>

/*
 * Internal functions.
 */

typedef void (*LibcTestFn)(void);
int LibcTest_main(int argc, char **argv);
void LibcTest_register(const char *suite, const char *name, LibcTestFn fn);
void LibcTest_skip_test(void);

/*
 * Define a unit test.
 */

#define LIBC_TEST_FUNC_NAME_(suite, name) LibcTest_testfunc_##suite##_##name

#define TEST(suite, name)                                                    \
    static void LIBC_TEST_FUNC_NAME_(suite, name)(void);                     \
    static void LibcTest_register_##suite##_##name(void)                     \
        __attribute__((constructor(__COUNTER__ + 1000)));                    \
                                                                             \
    static void LibcTest_register_##suite##_##name(void)                     \
    {                                                                        \
        LibcTest_register(#suite, #name, LIBC_TEST_FUNC_NAME_(suite, name)); \
    }                                                                        \
                                                                             \
    static void LIBC_TEST_FUNC_NAME_(suite, name)(void)

/*
 * Assertions.
 */

#define LIBC_TEST_DECLARE_CHECK(name, type) \
    typedef type LibcTestCheck_##name;      \
    void LibcTest_check_##name(             \
        bool cond,                          \
        type lhs,                           \
        type rhs,                           \
        const char *lhs_str,                \
        const char *op_str,                 \
        const char *rhs_str,                \
        const char *file,                   \
        unsigned line,                      \
        bool fatal)

#define LIBC_TEST_CHECK(name, lhs, op, rhs, lhs_str, op_str, rhs_str, fatal) \
    do {                                                                     \
        LibcTestCheck_##name l_ = (lhs);                                     \
        LibcTestCheck_##name r_ = (rhs);                                     \
        LibcTest_check_##name(                                               \
            l_ op r_,                                                        \
            l_,                                                              \
            r_,                                                              \
            lhs_str,                                                         \
            op_str,                                                          \
            rhs_str,                                                         \
            __FILE__,                                                        \
            __LINE__,                                                        \
            fatal);                                                          \
    } while (0)

void LibcTest_check_truthy(
    bool cond,
    const char *cond_str,
    const char *file,
    unsigned line,
    bool fatal);

LIBC_TEST_DECLARE_CHECK(int, intmax_t);
LIBC_TEST_DECLARE_CHECK(uint, uintmax_t);
LIBC_TEST_DECLARE_CHECK(char, char);
LIBC_TEST_DECLARE_CHECK(ptr, const void *);

#define EXPECT(cond) \
    LibcTest_check_truthy(cond, #cond, __FILE__, __LINE__, /*fatal=*/false)

#define ASSERT(cond) \
    LibcTest_check_truthy(cond, #cond, __FILE__, __LINE__, /*fatal=*/true)

#define EXPECT_INT(lhs, op, rhs) \
    LIBC_TEST_CHECK(int, lhs, op, rhs, #lhs, #op, #rhs, /*fatal=*/false)

#define ASSERT_INT(lhs, op, rhs) \
    LIBC_TEST_CHECK(int, lhs, op, rhs, #lhs, #op, #rhs, /*fatal=*/true)

#define EXPECT_UINT(lhs, op, rhs) \
    LIBC_TEST_CHECK(uint, lhs, op, rhs, #lhs, #op, #rhs, /*fatal=*/false)

#define ASSERT_UINT(lhs, op, rhs) \
    LIBC_TEST_CHECK(uint, lhs, op, rhs, #lhs, #op, #rhs, /*fatal=*/true)

#define EXPECT_CHAR(lhs, op, rhs) \
    LIBC_TEST_CHECK(char, lhs, op, rhs, #lhs, #op, #rhs, /*fatal=*/false)

#define ASSERT_CHAR(lhs, op, rhs) \
    LIBC_TEST_CHECK(char, lhs, op, rhs, #lhs, #op, #rhs, /*fatal=*/true)

#define EXPECT_PTR(lhs, op, rhs) \
    LIBC_TEST_CHECK(ptr, lhs, op, rhs, #lhs, #op, #rhs, /*fatal=*/false)

#define ASSERT_PTR(lhs, op, rhs) \
    LIBC_TEST_CHECK(ptr, lhs, op, rhs, #lhs, #op, #rhs, /*fatal=*/true)

/*
 * Test control.
 */

#define SKIP_TEST() LibcTest_skip_test()

#endif
