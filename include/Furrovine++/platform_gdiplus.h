#include <Furrovine++/Platform.OS.h>

#ifdef FURROVINEWIN

#include <Furrovine++/platform_windows_def.h>
#define min std::min
#define max std::max
#include <gdiplus.h>
#undef min
#undef max
#include <Furrovine++/platform_windows_undef.h>

#endif // WIN