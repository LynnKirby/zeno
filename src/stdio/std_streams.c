/* SPDX-License-Identifier: CC0-1.0 */

#include <stdio.h>

#undef stdout
#undef stderr

FILE _stdout = { 1 };
FILE _stderr = { 2 };

FILE *const stdout = &_stdout;
FILE *const stderr = &_stderr;
