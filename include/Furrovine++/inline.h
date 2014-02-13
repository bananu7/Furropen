#pragma once

#include <Furrovine++/Platform.OS.h>

#if FURROVINEWIN

#define inlinealways __forceinline
#define inlinenever __declspec(noinline)

#elif FURROVINEAPPLE

#define inlinealways __attribute__((always_inline))
#define inlinenever __attribute__((noinline))

#elif FURROVINELINUX

#define inlinealways __attribute__((always_inline))
#define inlinenever __attribute__((noinline))

#else
#error Unknown OS / Platform to definining Inline
#endif
