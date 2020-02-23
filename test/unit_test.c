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

void LibcTest_skip_test(void)
{
    current_test->status = STATUS_SKIPPED;
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

int LibcTest_main(int argc, char **argv)
{
    bool quiet = false;

    /* Parse arguments. */
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--quiet") == 0) {
            quiet = true;
        }
    }

    /* Report startup information. */
    if (!quiet) {
        out(GRN "[==========] " RESET);
        out("Running ");
        out(utoa(test_count));
        if (test_count == 1) {
            puts(" test.");
        } else {
            puts(" tests.");
        }
    }

    /* Run tests. */
    size_t failed_count  = 0;
    size_t skipped_count = 0;

    for (TestListNode *node = tests_head; node; node = node->next) {
        for (size_t i = 0; i < node->count; i++) {
            current_test = &node->tests[i];

            if (!quiet) {
                out(GRN "[ RUN      ] " RESET);
                puts_name(current_test);
            }

            current_test->fn();

            switch (current_test->status) {
            case STATUS_FAILURE:
                failed_count++;
                if (!quiet) {
                    out(RED "[  FAILED  ] " RESET);
                }
                break;
            case STATUS_SKIPPED:
                skipped_count++;
                if (!quiet) {
                    out(YELLOW "[   SKIP   ] " RESET);
                }
                break;
            case STATUS_SUCCESS:
                if (!quiet) {
                    out(GRN "[       OK ] " RESET);
                }
                break;
            default:
                assert(0 && "unreachable");
            }

            puts_name(current_test);
        }
    }

    /* Report overall test results. */
    if (!quiet) {
        out(GRN "[==========] " RESET);
        out(utoa(test_count));
        if (test_count == 1) {
            out(" test ");
        } else {
            out(" tests ");
        }
        puts("ran.");

        size_t passed_count = test_count - failed_count - skipped_count;

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

    return failed_count == 0 ? 0 : 1;
}
