#pragma once

#include <Furrovine++/Win32WindowDriver.h>

namespace Furrovine {

	typedef
#ifdef FURROVINEWIN
		Win32WindowDriver
#elif FURROVINEAPPLE

#elif FURROVINELINUX

#else
		EmptyWindowDriver
#endif // WIN || APPLE || LINUX
		WindowDriver;

}