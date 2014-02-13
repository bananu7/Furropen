#pragma once

#include <Furrovine++/Platform.OS.h>

#ifdef FURROVINEWIN

#include <Furrovine++/Platform.Conventions.h>

#include <Furrovine++/platform_windows_def.h>
#include <windows.h>
#include <windowsx.h>
#include <Dbghelp.h>
#include <Shlwapi.h>
#include <WinSock2.h>
#include <winioctl.h>
#include <mmsystem.h>
#include <dwmapi.h>
#include <Furrovine++/platform_windows_undef.h>

#endif // WIN

namespace Furrovine {

#ifdef FURROVINEWIN
	
	typedef HWND WindowHandle;
	typedef HMONITOR MonitorHandle;

	typedef HRESULT osresult;

#endif // WIN

}
