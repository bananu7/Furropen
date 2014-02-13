#pragma once

#include <Furrovine++/Platform.Conventions.h>

#ifdef FURROVINEDIRECTX
#ifdef FURROVINEWIN
#include <Furrovine++/platform_windows_def.h>
#endif // WIN
#include <d2d1_1.h>
#ifdef FURROVINEWIN
#include <Furrovine++/platform_windows_undef.h>
#endif // WIN

#endif // DIRECTX