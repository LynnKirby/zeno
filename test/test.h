/* SPDX-License-Identifier: CC0-1.0 */

#ifndef TEST_H
#define TEST_H

/* clang-format off */
/* clang-format doesn't like some of these single-line macros. */

#undef NDEBUG
#include <assert.h>

#define assert_is_type(t)             ((void)(t*)0)
#define assert_is_integer_constant(c) switch (c) { case c:; }

#endif
