#pragma once

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(_WIN32_) || defined(__WIN32__)

#define FURROVINEWIN 1

#ifdef _WIN64
#define FURROVINEX64 1
#define FURROVINEWIN64 1
#else
#define FURROVINEX86 1
#define FURROVINEWIN32 1
#endif // WIN64 

#elif defined(__APPLE__) || defined(_APPLE) || defined(APPLE) || defined(MACOS) || defined(MACOSX) || defined(_MACOS_) || defined(_MACOSX_)

#define FURROVINEAPPLE 1

#define FURROVINEAPPLE32 1
#define FURROVINEX86 1

#elif defined(__LINUX__) || defined( _UNIX ) || defined( _POSIX )

#define FURROVINELINUX 1

#define FURROVINELINUX32 1
#define FURROVINEX86 1

#else /* Or something else */

#error Unknown Platform - please define the platform in PlatformOS.h

#endif // WIN32 || APPLE || LINUX 
