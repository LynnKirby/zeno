/* SPDX-License-Identifier: CC0-1.0 */

#include "unit_test.h"
#include <assert.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sysexits.h>

/*
 * Configuration.
 */

#ifndef __wasm__
#define EXIT_TEST_WITH_SETJMP 1
#include <setjmp.h>
#endif

/*
 * Types.
 */

typedef enum {
    STATUS_PASSED,
    STATUS_FAILURE,
    STATUS_SKIPPED,
} TestStatus;

#define TESTS_PER_NODE 64

typedef struct {
    LibcTestFn fn;
    const char *suite;
    const char *name;
    TestStatus status;
} Test;

typedef struct TestListNode {
    Test tests[TESTS_PER_NODE];
    struct TestListNode *next;
    size_t count;
} TestListNode;

/*
 * Forward declarations.
 */

_Noreturn static void run_test_loop(bool run_as_continuation);
static void run_current_test(bool run_as_continuation);
static void exit_current_test(void);

static void on_global_start(void);
static void on_global_end(void);
static void on_test_start(Test *test);
static void on_test_end(Test *test);

/*
 * Test runner state. Globals... for now.
 */

static TestListNode *tests_head;
static TestListNode *tests_tail;
static TestListNode *current_node;
static Test *current_test;
static size_t current_index;

static size_t test_count;
static size_t passed_count;
static size_t failed_count;
static size_t skipped_count;

static bool quiet;

#if EXIT_TEST_WITH_SETJMP
jmp_buf main_loop_jmp_buf;
#endif

/*
 * Utilities.
 */

static void outs(const char *s)
{
    fputs(s, stdout);
}

/* 20 characters + null */
#define UTOA_BUF_SIZE 21
static char utoa_buf[UTOA_BUF_SIZE];

static char *utoa(uintmax_t value)
{
    char *ptr = utoa_buf + UTOA_BUF_SIZE - 1;
    *ptr      = '\0';

    do {
        ptr -= 1;
        *ptr = '0' + (value % 10);
        value /= 10;
    } while (value != 0);

    return ptr;
}

static char *itoa(intmax_t value)
{
    if (value < 0) {
        char *ptr = utoa(-value);
        ptr--;
        ptr[0] = '-';
        return ptr;
    }

    return utoa(value);
}

static void puts_name(const Test *t)
{
    outs(t->suite);
    outs(".");
    puts(t->name);
}

static void outs_char(char c)
{
    char buf[2] = { 0 };

    if (isprint(c)) {
        buf[0] = c;
        outs("'");
        outs(buf);
        outs("'");
        return;
    }

    switch (c) {
    case '\0':
        outs("'\\0'");
        return;
    case '\a':
        outs("'\\a'");
        return;
    case '\b':
        outs("'\\b'");
        return;
    case '\f':
        outs("'\\f'");
        return;
    case '\n':
        outs("'\\n'");
        return;
    case '\r':
        outs("'\\r'");
        return;
    case '\t':
        outs("'\\t'");
        return;
    case '\v':
        outs("'\\v'");
        return;
    }

    /* TODO: Print hex escape. */
    outs(utoa((unsigned char)c));
}

static void outs_ptr(const void *p)
{
    if (!p) {
        outs("NULL");
    } else {
        /* TODO: Print hex escape. */
        outs(utoa((uintptr_t)p));
    }
}

#define RED    "\x1b[31m"
#define GRN    "\x1b[32m"
#define YELLOW "\x1b[33m"
#define RESET  "\x1b[0m"

static void *xcalloc(size_t n, size_t size)
{
    void *obj = calloc(n, size);
    if (!obj) {
        puts("error: could not allocate");
        _Exit(EX_SOFTWARE);
    }
    return obj;
}

/*
 * Main program loop.
 */

_Noreturn int LibcTest_main(int argc, char **argv)
{
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--quiet") == 0) {
            quiet = true;
        }
    }

    current_node  = tests_head;
    current_index = 0;
    on_global_start();
    run_test_loop(false);
}

_Noreturn static void run_test_loop(bool run_as_continuation)
{
    for (; current_node; current_node = current_node->next) {
        for (; current_index < current_node->count; current_index++) {
            run_current_test(run_as_continuation);
            run_as_continuation = false;
        }
        current_index = 0;
    }

    on_global_end();
    exit(failed_count == 0 ? 0 : 1);
}

static void run_current_test(bool run_as_continuation)
{
#if EXIT_TEST_WITH_SETJMP
    (void)run_as_continuation;

    current_test = &current_node->tests[current_index];
    on_test_start(current_test);

    if (setjmp(main_loop_jmp_buf) == 0) {
        current_test->fn();
    }
#else
    if (!run_as_continuation) {
        current_test = &current_node->tests[current_index];
        on_test_start(current_test);
        current_test->fn();
    }
#endif

    switch (current_test->status) {
    case STATUS_PASSED:
        passed_count++;
        break;
    case STATUS_FAILURE:
        failed_count++;
        break;
    case STATUS_SKIPPED:
        skipped_count++;
        break;
    }

    on_test_end(current_test);
}

static void exit_current_test(void)
{
#if EXIT_TEST_WITH_SETJMP
    longjmp(main_loop_jmp_buf, 1);
#else
    run_test_loop(true);
#endif
}

/*
 * Test registration. Called from constructors.
 */

void LibcTest_register(const char *suite, const char *name, LibcTestFn fn)
{
    if (!tests_head) {
        tests_head = xcalloc(1, sizeof(TestListNode));
        tests_tail = tests_head;
    }

    if (tests_tail->count >= TESTS_PER_NODE) {
        TestListNode *new_tail = xcalloc(1, sizeof(TestListNode));
        tests_tail->next       = new_tail;
        tests_tail             = new_tail;
    }

    Test *test = &tests_tail->tests[tests_tail->count];

    test->fn    = fn;
    test->suite = suite;
    test->name  = name;

    tests_tail->count++;
    test_count++;
}

/*
 * Assertions implementations.
 */

void LibcTest_check_truthy(
    bool cond,
    const char *cond_str,
    const char *file,
    unsigned line,
    bool fatal)
{
    assert(cond_str);
    assert(file);

    if (cond) return;

    current_test->status = STATUS_FAILURE;

    outs(file);
    outs(":");
    outs(utoa(line));
    outs(": assertion failed: ");
    puts(cond_str);

    if (fatal) {
        exit_current_test();
    }

    return;
}

void LibcTest_check_char(
    bool cond,
    char lhs,
    char rhs,
    const char *lhs_str,
    const char *op_str,
    const char *rhs_str,
    const char *file,
    unsigned line,
    bool fatal)
{
    assert(lhs_str);
    assert(rhs_str);
    assert(file);

    if (cond) return;

    current_test->status = STATUS_FAILURE;

    outs(file);
    outs(":");
    outs(utoa(line));
    outs(": assertion failed: ");
    outs(lhs_str);
    outs(" ");
    outs(op_str);
    outs(" ");
    outs(rhs_str);
    outs(" (");
    outs_char(lhs);
    outs(" ");
    outs(op_str);
    outs(" ");
    outs_char(rhs);
    puts(")");

    if (fatal) {
        exit_current_test();
    }

    return;
}

void LibcTest_check_int(
    bool cond,
    intmax_t lhs,
    intmax_t rhs,
    const char *lhs_str,
    const char *op_str,
    const char *rhs_str,
    const char *file,
    unsigned line,
    bool fatal)
{
    assert(lhs_str);
    assert(rhs_str);
    assert(file);

    if (cond) return;

    current_test->status = STATUS_FAILURE;

    outs(file);
    outs(":");
    outs(utoa(line));
    outs(": assertion failed: ");
    outs(lhs_str);
    outs(" ");
    outs(op_str);
    outs(" ");
    outs(rhs_str);
    outs(" (");
    outs(itoa(lhs));
    outs(" ");
    outs(op_str);
    outs(" ");
    outs(itoa(rhs));
    puts(")");

    if (fatal) {
        exit_current_test();
    }

    return;
}

void LibcTest_check_uint(
    bool cond,
    uintmax_t lhs,
    uintmax_t rhs,
    const char *lhs_str,
    const char *op_str,
    const char *rhs_str,
    const char *file,
    unsigned line,
    bool fatal)
{
    assert(lhs_str);
    assert(rhs_str);
    assert(file);

    if (cond) return;

    current_test->status = STATUS_FAILURE;

    outs(file);
    outs(":");
    outs(utoa(line));
    outs(": assertion failed: ");
    outs(lhs_str);
    outs(" ");
    outs(op_str);
    outs(" ");
    outs(rhs_str);
    outs(" (");
    outs(utoa(lhs));
    outs(" ");
    outs(op_str);
    outs(" ");
    outs(utoa(rhs));
    puts(")");

    if (fatal) {
        exit_current_test();
    }

    return;
}

void LibcTest_check_ptr(
    bool cond,
    const void *lhs,
    const void *rhs,
    const char *lhs_str,
    const char *op_str,
    const char *rhs_str,
    const char *file,
    unsigned line,
    bool fatal)
{
    assert(lhs_str);
    assert(rhs_str);
    assert(file);

    if (cond) return;

    current_test->status = STATUS_FAILURE;

    outs(file);
    outs(":");
    outs(utoa(line));
    outs(": assertion failed: ");
    outs(lhs_str);
    outs(" ");
    outs(op_str);
    outs(" ");
    outs(rhs_str);
    outs(" (");
    outs_ptr(lhs);
    outs(" ");
    outs(op_str);
    outs(" ");
    outs_ptr(rhs);
    puts(")");

    if (fatal) {
        exit_current_test();
    }

    return;
}

/*
 * Status functions.
 */

void LibcTest_skip_test(void)
{
    current_test->status = STATUS_SKIPPED;
    exit_current_test();
}

/*
 * Test reporting.
 */

static void on_global_start(void)
{
    if (quiet) return;

    outs(GRN "[==========] " RESET);
    outs("Running ");
    outs(utoa(test_count));
    if (test_count == 1) {
        puts(" test.");
    } else {
        puts(" tests.");
    }
}

static void on_global_end(void)
{
    assert(passed_count + failed_count + skipped_count == test_count);

    if (quiet) return;

    outs(GRN "[==========] " RESET);
    outs(utoa(test_count));
    if (test_count == 1) {
        outs(" test ");
    } else {
        outs(" tests ");
    }
    puts("ran.");

    if (passed_count > 0) {
        outs(GRN "[  PASSED  ] " RESET);
        outs(utoa(passed_count));
        if (passed_count == 1) {
            puts(" test.");
        } else {
            puts(" tests.");
        }
    }

    if (skipped_count > 0) {
        outs(YELLOW "[ SKIPPED  ] " RESET);
        outs(utoa(skipped_count));
        if (skipped_count == 1) {
            puts(" test.");
        } else {
            puts(" tests.");
        }
    }

    if (failed_count > 0) {
        outs(RED "[  FAILED  ] " RESET);
        outs(utoa(failed_count));
        if (failed_count == 1) {
            puts(" test.");
        } else {
            puts(" tests.");
        }
    }
}

static void on_test_start(Test *test)
{
    if (quiet) return;
    outs(GRN "[ RUN      ] " RESET);
    puts_name(test);
}

static void on_test_end(Test *test)
{
    if (quiet) return;

    switch (test->status) {
    case STATUS_FAILURE:
        outs(RED "[  FAILED  ] " RESET);
        break;
    case STATUS_SKIPPED:
        outs(YELLOW "[   SKIP   ] " RESET);
        break;
    case STATUS_PASSED:
        outs(GRN "[       OK ] " RESET);
        break;
    default:
        assert(0 && "unreachable");
    }

    puts_name(test);
}
