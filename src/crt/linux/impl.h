/* SPDX-License-Identifier: CC0-1.0 */

#ifndef CRT_LINUX_CRT_H
#define CRT_LINUX_CRT_H

typedef void (*StructorFn)(void);

#define SECTION(name) __attribute__((section(name), used))

#define ALIGNED_SECTION(name, type) \
    __attribute__((section(name), aligned(_Alignof(type)), used))

#endif
