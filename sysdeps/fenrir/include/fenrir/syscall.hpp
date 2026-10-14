#ifndef _MLIBC_SYSCALL_H
#define _MLIBC_SYSCALL_H

#include <stdint.h>

inline int64_t syscall(uint64_t syscall_id)
{
    register int64_t return_value asm("rax") = 0;
    register uint64_t _syscall_id asm("rax") = syscall_id;

    asm volatile("syscall" : "=r"(return_value) : "r"(_syscall_id) : "rcx", "r11", "memory");

    return return_value;
}

template <typename Arg0>
int64_t syscall(uint64_t syscall_id, Arg0 a0)
{
    register int64_t return_value asm("rax") = 0;
    register uint64_t _syscall_id asm("rax") = syscall_id;
    register uint64_t _argument_1 asm("rdi") = (uint64_t) a0;

    asm volatile("syscall" : "=r"(return_value) : "r"(_syscall_id), "r"(_argument_1) : "rcx", "r11", "memory");

    return return_value;
}

template <typename Arg0, typename Arg1>
int64_t syscall(uint64_t syscall_id, Arg0 a0, Arg1 a1)
{
    register int64_t return_value asm("rax") = 0;
    register uint64_t _syscall_id asm("rax") = syscall_id;
    register uint64_t _argument_1 asm("rdi") = (uint64_t) a0;
    register uint64_t _argument_2 asm("rsi") = (uint64_t) a1;

    asm volatile("syscall"
                 : "=r"(return_value)
                 : "r"(_syscall_id), "r"(_argument_1), "r"(_argument_2)
                 : "rcx", "r11", "memory");

    return return_value;
}

template <typename Arg0, typename Arg1, typename Arg2>
int64_t syscall(uint64_t syscall_id, Arg0 a0, Arg1 a1, Arg2 a2)
{
    register int64_t return_value asm("rax") = 0;
    register uint64_t _syscall_id asm("rax") = syscall_id;
    register uint64_t _argument_1 asm("rdi") = (uint64_t) a0;
    register uint64_t _argument_2 asm("rsi") = (uint64_t) a1;
    register uint64_t _argument_3 asm("rdx") = (uint64_t) a2;

    asm volatile("syscall"
                 : "=r"(return_value)
                 : "r"(_syscall_id), "r"(_argument_1), "r"(_argument_2), "r"(_argument_3)
                 : "rcx", "r11", "memory");

    return return_value;
}

template <typename Arg0, typename Arg1, typename Arg2, typename Arg3>
int64_t syscall(uint64_t syscall_id, Arg0 a0, Arg1 a1, Arg2 a2, Arg3 a3)
{
    register int64_t return_value asm("rax") = 0;
    register uint64_t _syscall_id asm("rax") = syscall_id;
    register uint64_t _argument_1 asm("rdi") = (uint64_t) a0;
    register uint64_t _argument_2 asm("rsi") = (uint64_t) a1;
    register uint64_t _argument_3 asm("rdx") = (uint64_t) a2;
    register uint64_t _argument_4 asm("r10") = (uint64_t) a3;

    asm volatile("syscall"
                 : "=r"(return_value)
                 : "r"(_syscall_id), "r"(_argument_1), "r"(_argument_2), "r"(_argument_3), "r"(_argument_4)
                 : "rcx", "r11", "memory");

    return return_value;
}

template <typename Arg0, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
int64_t syscall(uint64_t syscall_id, Arg0 a0, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4)
{
    register int64_t return_value asm("rax") = 0;
    register uint64_t _syscall_id asm("rax") = syscall_id;
    register uint64_t _argument_1 asm("rdi") = (uint64_t) a0;
    register uint64_t _argument_2 asm("rsi") = (uint64_t) a1;
    register uint64_t _argument_3 asm("rdx") = (uint64_t) a2;
    register uint64_t _argument_4 asm("r10") = (uint64_t) a3;
    register uint64_t _argument_5 asm("r8") = (uint64_t) a4;

    asm volatile(
        "syscall"
        : "=r"(return_value)
        : "r"(_syscall_id), "r"(_argument_1), "r"(_argument_2), "r"(_argument_3), "r"(_argument_4), "r"(_argument_5)
        : "rcx", "r11", "memory");

    return return_value;
}

template <typename Arg0, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
int64_t syscall(uint64_t syscall_id, Arg0 a0, Arg1 a1, Arg2 a2, Arg3 a3, Arg4 a4, Arg5 a5)
{
    register int64_t return_value asm("rax") = 0;
    register uint64_t _syscall_id asm("rax") = syscall_id;
    register uint64_t _argument_1 asm("rdi") = (uint64_t) a0;
    register uint64_t _argument_2 asm("rsi") = (uint64_t) a1;
    register uint64_t _argument_3 asm("rdx") = (uint64_t) a2;
    register uint64_t _argument_4 asm("r10") = (uint64_t) a3;
    register uint64_t _argument_5 asm("r8") = (uint64_t) a4;
    register uint64_t _argument_6 asm("r9") = (uint64_t) a5;

    asm volatile("syscall"
                 : "=r"(return_value)
                 : "r"(_syscall_id),
                   "r"(_argument_1),
                   "r"(_argument_2),
                   "r"(_argument_3),
                   "r"(_argument_4),
                   "r"(_argument_5),
                   "r"(_argument_6)
                 : "rcx", "r11", "memory");

    return return_value;
}

#endif /* _MLIBC_SYSCALL_H */
