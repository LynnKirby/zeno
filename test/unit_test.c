/* SPDX-License-Identifier: CC0-1.0 */

#ifdef LIBC_TEST_COMPILING_UNIT_TEST
#define LIBC_TEST_SHOW_MAIN
#else
#undef LIBC_TEST_SHOW_MAIN
#endif

#include "unit_test.h"
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sysexits.h>

/*
 * Tests and result state.
 */

typedef enum { STATUS_SUCCESS, STATUS_FAILURE, STATUS_SKIPPED } TestStatus;

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

static TestListNode *tests_head;
static TestListNode *tests_tail;
static size_t test_count;
static Test *current_test;

/*
 * Utilities.
 */

static void out(const char *s)
{
    fputs(s, stdout);
}

/* 20 characters + null */
#define UTOA_BUF_SIZE 21
static char utoa_buf[UTOA_BUF_SIZE];

static char *utoa(unsigned value)
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

void puts_name(const Test *t)
{
    out(t->suite);
    out(".");
    puts(t->name);
}

#define RED    "\x1b[31m"
#define GRN    "\x1b[32m"
#define YELLOW "\x1b[33m"
#define RESET  "\x1b[0m"

void *xcalloc(size_t n, size_t size)
{
    void *obj = calloc(n, size);
    if (!obj) {
        puts("error: could not allocate");
        _Exit(EX_SOFTWARE);
    }
    return obj;
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

    if (tests_tail->count > TESTS_PER_NODE) {
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
 * Non-assertion status functions.
 */

_Noreturn static void run_test_loop(bool run_as_continuation);

void LibcTest_skip_test(void)
{
    current_test->status = STATUS_SKIPPED;
    run_test_loop(true);
}

void LibcTest_fatal_failure(void)
{
    assert(current_test->status == STATUS_FAILURE);
    run_test_loop(true);
}

/*
 * Assertion implementations.
 */

_Bool LibcTest_expect_nonzero(
    _Bool expr, const char *expr_str, const char *file, int line)
{
    if (expr) return true;

    current_test->status = STATUS_FAILURE;
    out(file);
    out(":");
    out(utoa(line));
    puts(": Failure");

    out("Expected: ");
    puts(expr_str);
    puts("Which is: zero");
    puts("   To be: nonzero");

    return false;
}

/*
 * Main test loop.
 */

size_t run_count;
size_t failed_count;
size_t skipped_count;
TestListNode *current_node;
size_t current_index;
bool quiet;

static void on_global_start(void)
{
    if (quiet) return;

    out(GRN "[==========] " RESET);
    out("Running ");
    out(utoa(test_count));
    if (test_count == 1) {
        puts(" test.");
    } else {
        puts(" tests.");
    }
}

static void on_test_start(Test *test)
{
    if (quiet) return;
    out(GRN "[ RUN      ] " RESET);
    puts_name(test);
}

static void on_global_end(void)
{
    assert(run_count + failed_count + skipped_count == test_count);

    if (quiet) return;

    out(GRN "[==========] " RESET);
    out(utoa(test_count));
    if (test_count == 1) {
        out(" test ");
    } else {
        out(" tests ");
    }
    puts("ran.");

    size_t passed_count = run_count - failed_count - skipped_count;

    if (passed_count > 0) {
        out(GRN "[  PASSED  ] " RESET);
        out(utoa(passed_count));
        if (passed_count == 1) {
            puts(" test.");
        } else {
            puts(" tests.");
        }
    }

    if (skipped_count > 0) {
        out(YELLOW "[ SKIPPED  ] " RESET);
        out(utoa(skipped_count));
        if (skipped_count == 1) {
            puts(" test.");
        } else {
            puts(" tests.");
        }
    }

    if (failed_count > 0) {
        out(RED "[  FAILED  ] " RESET);
        out(utoa(failed_count));
        if (failed_count == 1) {
            puts(" test.");
        } else {
            puts(" tests.");
        }
    }
}

static void on_test_end(Test *test)
{
    if (quiet) return;

    switch (test->status) {
    case STATUS_FAILURE:
        out(RED "[  FAILED  ] " RESET);
        break;
    case STATUS_SKIPPED:
        out(YELLOW "[   SKIP   ] " RESET);
        break;
    case STATUS_SUCCESS:
        out(GRN "[       OK ] " RESET);
        break;
    default:
        assert(0 && "unreachable");
    }

    puts_name(test);
}

_Noreturn static void run_test_loop(bool run_as_continuation)
{
    for (; current_node; current_node = current_node->next) {
        for (; current_index < current_node->count; current_index++) {
            if (!run_as_continuation) {
                current_test = &current_node->tests[current_index];
                on_test_start(current_test);
                current_test->fn();
            }

            run_as_continuation = false;
            on_test_end(current_test);
            run_count++;
        }
    }

    on_global_end();
    exit(failed_count == 0 ? 0 : 1);
}

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
