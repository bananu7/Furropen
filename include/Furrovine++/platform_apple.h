#pragma once

#include <Furrovine++/Platform.OS.h>

#ifdef FURROVINEAPPLE
#include <dirent.h>
#endif // APPLE

namespace Furrovine {

#if FURROVINEAPPLE

	typedef void* WindowHandle;
	typedef void* MonitorHandle;

#endif // APPLE

}