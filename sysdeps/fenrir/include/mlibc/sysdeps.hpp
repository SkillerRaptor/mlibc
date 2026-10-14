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
    , Write { };

template <typename Tag>
using Sysdeps = SysdepOf<FenrirSysdepTags, Tag>;

struct SysdepTraits {
	static constexpr bool usesRtNetlink = false;
};

} // namespace mlibc
