/*
 * SPDX-License-Identifier: CC0-1.0
 * i386-linux syscall functions.
 *
 * Calling convention:
 *
 *     EAX  return value / syscall number
 *     EBX  arg1
 *     ECX  arg2
 *     EDX  arg3
 *     ESI  arg4
 *     EDI  arg5
 *     EBP  arg6
 *
 * See also:
 * - syscall(2) - http://man7.org/linux/man-pages/man2/syscall.2.html
 */

/* TODO: Use VDSO instead of INT 80 */

#ifndef BASIC_LINUX_I386_SYSCALL_H
#define BASIC_LINUX_I386_SYSCALL_H

static inline long __syscall0(long n)
{
    unsigned long ret;
    __asm__ __volatile__("int $0x80" : "=a"(ret) : "a"(n) : "memory");
    return ret;
}

static inline long __syscall1(long n, long a1)
{
    unsigned long ret;
    __asm__ __volatile__("int $0x80" : "=a"(ret) : "a"(n), "b"(a1) : "memory");
    return ret;
}

static inline long __syscall2(long n, long a1, long a2)
{
    unsigned long ret;
    __asm__ __volatile__("int $0x80"
                         : "=a"(ret)
                         : "a"(n), "b"(a1), "c"(a2)
                         : "memory");
    return ret;
}

static inline long __syscall3(long n, long a1, long a2, long a3)
{
    unsigned long ret;
    __asm__ __volatile__("int $0x80"
                         : "=a"(ret)
                         : "a"(n), "b"(a1), "c"(a2), "d"(a3)
                         : "memory");
    return ret;
}

static inline long __syscall4(long n, long a1, long a2, long a3, long a4)
{
    unsigned long ret;
    __asm__ __volatile__("int $0x80"
                         : "=a"(ret)
                         : "a"(n), "b"(a1), "c"(a2), "d"(a3), "D"(a4)
                         : "memory");
    return ret;
}

static inline long __syscall5(
    long n, long a1, long a2, long a3, long a4, long a5)
{
    unsigned long ret;
    __asm__ __volatile__("int $0x80"
                         : "=a"(ret)
                         : "a"(n), "b"(a1), "c"(a2), "d"(a3), "S"(a4), "D"(a5)
                         : "memory");
    return ret;
}

static inline long __syscall6(
    long n, long a1, long a2, long a3, long a4, long a5, long a6)
{
    unsigned long ret;
    __asm__ __volatile__(
        /* This one is more involved because we need to save EBP. */
        "push %7;"             /* save a6 to stack */
        "push %%ebp;"          /* save EBP to stack */
        "mov 4(%%esp), %%ebp;" /* move saved a6 into syscall arg 6 */
        "int $0x80;"           /* do the syscall */
        "pop %%ebp;"           /* restore EBP from stack */
        "add $4, %%esp"        /* adjust ESP for the saved a6 on stack */
        : "=a"(ret)
        : "a"(n), "b"(a1), "c"(a2), "d"(a3), "S"(a4), "D"(a5), "g"(a6)
        : "memory");
    return ret;
}

#endif
