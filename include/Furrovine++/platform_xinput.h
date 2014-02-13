#pragma once

#include <Furrovine++/Platform.Conventions.h>

#ifdef FURROVINEWIN
#include <Furrovine++/platform_windows_def.h>
#endif // WIN
#ifdef FURROVINEXINPUT
#include <Xinput.h>
#endif // XINPUT
#ifdef FURROVINEWIN
#include <Furrovine++/platform_windows_undef.h>
#endif // WIN
