#pragma once

#include <Furrovine++/WindowDriver.h>
#include <Furrovine++/IWindowService.h>
#include <Furrovine++/IWindow.h>
#ifdef FURROVINEWIN
#include <Furrovine++/Graphics/Win32Window.h>
#elif FURROVINELINUX
#include <Furrovine++/Graphics/LinuxWindow.h>
#elif FURROVINEAPPLE
#include <Furrovine++/Graphics/AppleWindow.h>
#endif // FURROVINEWIN || FURROVINELINUX || FURROVINEAPPLE 

namespace Furrovine { namespace Graphics {

	typedef
#ifdef FURROVINEWIN
		Win32Window
#elif FURROVINELINUX
		LinuxWindow
#elif FURROVINEAPPLE
		AppleWindow
#else
		EmptyWindow
#endif // FURROVINEWIN || FURROVINELINUX || FURROVINEAPPLE 
        Window;

}}
