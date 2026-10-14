/*
 * Copyright (c) 2026-present, SkillerRaptor
 *
 * SPDX-License-Identifier: MIT
 */

#include <abi-bits/errno.h>
#include <bits/ensure.h>
#include <fenrir/syscall.hpp>
#include <mlibc/all-sysdeps.hpp>
#include <mlibc/debug.hpp>
#include <mlibc/tcb.hpp>
#include <stdio.h>
#include <string.h>

#define SYS_ANON_ALLOCATE 1
#define SYS_ANON_FREE 2
#define SYS_CLOSE 3
#define SYS_EXIT 4
#define SYS_ISATTY 5
#define SYS_MKDIR 6
#define SYS_OPEN 7
#define SYS_READ 8
#define SYS_SEEK 9
#define SYS_TCBSET 10
#define SYS_WRITE 11

#define STUB()                                 \
    ({                                         \
        __ensure(!"STUB function was called"); \
        __builtin_unreachable();               \
    })

namespace mlibc {

int Sysdeps<AnonAllocate>::operator()(size_t size, void **ptr)
{
    void *out = (void *) syscall(SYS_ANON_ALLOCATE, size);
    if (!out) {
        return ENOMEM;
    }

    *ptr = out;

    return 0;
}

int Sysdeps<AnonFree>::operator()(void *ptr, unsigned long size) { return syscall(SYS_ANON_FREE, ptr, size); }

int Sysdeps<ClockGet>::operator()(int, time_t *, long *) { STUB(); }

int Sysdeps<Close>::operator()(int fd) { return syscall(SYS_CLOSE, fd); }

void Sysdeps<Exit>::operator()(int status)
{
    syscall(SYS_EXIT, status);
    __builtin_unreachable();
}

int Sysdeps<FutexWait>::operator()(int *, int, const timespec *) { STUB(); }

int Sysdeps<FutexWake>::operator()(int *, bool) { STUB(); }

int Sysdeps<Isatty>::operator()(int fd) { return syscall(SYS_ISATTY, fd); }

void Sysdeps<LibcLog>::operator()(const char *message)
{
    syscall(SYS_WRITE, message, strlen(message));
    syscall(SYS_WRITE, "\n", 1);
}

void Sysdeps<LibcPanic>::operator()()
{
    sysdep<LibcLog>("!!! mlibc panic !!!");
    sysdep<Exit>(-1);
    __builtin_trap();
}

int Sysdeps<Mkdir>::operator()(const char *path, mode_t mode) { return syscall(SYS_MKDIR, path, mode); }

int Sysdeps<Open>::operator()(const char *pathname, int flags, mode_t mode, int *fd)
{
    int64_t file_descriptor = syscall(SYS_OPEN, pathname, flags, mode);
    if (file_descriptor < 0) {
        *fd = -1;
        return ENOENT;
    }

    *fd = file_descriptor;

    return 0;
}

int Sysdeps<Read>::operator()(int fd, void *buffer, size_t count, ssize_t *bytes_read)
{
    int64_t value = syscall(SYS_READ, fd, buffer, count);
    if (value < 0)
    {
        *bytes_read = -1;
        return EBADF;
    }

    *bytes_read = value;

    return 0;
}

int Sysdeps<Seek>::operator()(int fd, off_t offset, int whence, off_t *new_offset)
{
    if (fd == 0 || fd == 1 || fd == 2) {
        return ESPIPE;
    }

    int64_t value = syscall(SYS_SEEK, fd, offset, whence);
    if (value < 0) {
        // NOTE: This is not the correct error code
        *new_offset = -1;
        return EINVAL;
    }

    *new_offset = value;

    return 0;
}

int Sysdeps<TcbSet>::operator()(void *ptr) { return syscall(SYS_TCBSET, ptr); }

int Sysdeps<VmMap>::operator()(void *, size_t, int, int, int, off_t, void **) { STUB(); }

int Sysdeps<VmUnmap>::operator()(void *, size_t) { STUB(); }

int Sysdeps<Waitpid>::operator()(pid_t, int *, int, struct rusage *, pid_t *) { STUB(); }

int Sysdeps<Write>::operator()(int fd, const void *buffer, size_t count, ssize_t *bytes_written)
{
    if (fd == 1 || fd == 2) {
        const char *string_buffer = (const char *) buffer;

        char tmp[2];
        tmp[1] = '\0';
        for (size_t i = 0; i < count; ++i) {
            tmp[0] = string_buffer[i];
            syscall(SYS_WRITE, fd, tmp, strlen(tmp));
        }

        if (bytes_written) {
            *bytes_written = count;
        }

        return 0;
    }

    return EROFS;
}

} // namespace mlibc
