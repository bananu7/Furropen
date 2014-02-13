#pragma once

#include <Furrovine++/Platform.h>

namespace Furrovine { namespace Native {

	struct Win32Message {
		IWindow& window;
		LRESULT result;
		HWND hwnd;
		UINT umsg;
		WPARAM wparam;
		LPARAM lparam;
	};

}}