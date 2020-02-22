/*
 * SPDX-License-Identifier: CC0-1.0
 * Static assertions to verify header definitions.
 */

/* clang-format off */
/* clang-format doesn't like these single line macros. */

#ifndef HEADER_TEST_H
#define HEADER_TEST_H

#define STATIC_ASSERT(expr) _Static_assert(expr, #expr)
#define type(t)             ((void)(t*)0)
#define integer_constant(c) switch (c) { case c:; }
#define float_constant(f)   { long double x = f; }
#define string_constant(s)  { const char *x = s; }

#endif
