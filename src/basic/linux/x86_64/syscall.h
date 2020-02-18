/*
 * SPDX-License-Identifier: CC0-1.0
 * x86_64-linux syscall functions.
 *
 * Calling convention:
 *
 *     RAX  return value / syscall number
 *     RDI  arg1
 *     RSI  arg2
 *     RDX  arg3
 *     R10  arg4
 *     R8   arg5
 *     R9   arg6
 *
 * The SYSCALL instruction clobbers RCX and R11.
 *
 * See also:
 * - syscall(2) - http://man7.org/linux/man-pages/man2/syscall.2.html
 * - SYSCALL documentation - https://www.felixcloutier.com/x86/syscall
 */

#ifndef BASIC_LINUX_X86_64_SYSCALL_H
#define BASIC_LINUX_X86_64_SYSCALL_H

static inline long __syscall0(long n)
{
    unsigned long ret;
    __asm__ __volatile__("syscall"
                         : "=a"(ret)
                         : "a"(n)
                         : "rcx", "r11", "memory");
    return ret;
}

static inline long __syscall1(long n, long a1)
{
    unsigned long ret;
    __asm__ __volatile__("syscall"
                         : "=a"(ret)
                         : "a"(n), "D"(a1)
                         : "rcx", "r11", "memory");
    return ret;
}

static inline long __syscall2(long n, long a1, long a2)
{
    unsigned long ret;
    __asm__ __volatile__("syscall"
                         : "=a"(ret)
                         : "a"(n), "D"(a1), "S"(a2)
                         : "rcx", "r11", "memory");
    return ret;
}

static inline long __syscall3(long n, long a1, long a2, long a3)
{
    unsigned long ret;
    __asm__ __volatile__("syscall"
                         : "=a"(ret)
                         : "a"(n), "D"(a1), "S"(a2), "d"(a3)
                         : "rcx", "r11", "memory");
    return ret;
}

static inline long __syscall4(long n, long a1, long a2, long a3, long a4)
{
    unsigned long ret;
    register long r10 __asm__("r10") = a4;
    __asm__ __volatile__("syscall"
                         : "=a"(ret)
                         : "a"(n), "D"(a1), "S"(a2), "d"(a3), "r"(r10)
                         : "rcx", "r11", "memory");
    return ret;
}

static inline long __syscall5(
    long n, long a1, long a2, long a3, long a4, long a5)
{
    unsigned long ret;
    register long r10 __asm__("r10") = a4;
    register long r8 __asm__("r8") = a5;
    __asm__ __volatile__("syscall"
                         : "=a"(ret)
                         : "a"(n), "D"(a1), "S"(a2), "d"(a3), "r"(r10), "r"(r8)
                         : "rcx", "r11", "memory");
    return ret;
}

static inline long __syscall6(
    long n, long a1, long a2, long a3, long a4, long a5, long a6)
{
    unsigned long ret;
    register long r10 __asm__("r10") = a4;
    register long r8 __asm__("r8") = a5;
    register long r9 __asm__("r9") = a6;
    __asm__ __volatile__(
        "syscall"
        : "=a"(ret)
        : "a"(n), "D"(a1), "S"(a2), "d"(a3), "r"(r10), "r"(r8), "r"(r9)
        : "rcx", "r11", "memory");
    return ret;
}

#endif
