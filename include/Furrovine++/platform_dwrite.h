#pragma once

#include <Furrovine++/Platform.Conventions.h>

#ifdef FURROVINEDIRECTWRITE
#ifdef FURROVINEWIN
#include <Furrovine++/platform_windows_def.h>
#endif // WIN
#include <dwrite_1.h>
#ifdef FURROVINEWIN
#include <Furrovine++/platform_windows_undef.h>
#endif // WIN
#endif // DIRECTWRITE

namespace Furrovine {

#ifdef FURROVINEDIRECTWRITE
	typedef HRESULT dwresultcode;
#endif // FURROVINEDIRECTWRITE

}