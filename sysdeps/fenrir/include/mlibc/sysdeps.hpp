#pragma once

#include <mlibc/sysdep-signatures.hpp>

namespace mlibc {

struct FenrirSysdepTags
    : AnonAllocate
    , AnonFree
    , ClockGet
    , Close
    , Exit
    , FutexWait
    , FutexWake
    , Isatty
    , LibcLog
    , LibcPanic
    , Mkdir
    , Open
    , Read
    , Seek
    , TcbSet
    , VmMap
    , VmUnmap
    , Waitpid
    , Write { };

template <typename Tag>
using Sysdeps = SysdepOf<FenrirSysdepTags, Tag>;

} // namespace mlibc
