#pragma once

#include <Furrovine++/Platform.h>

#ifdef FURROVINEWIN
#include <Furrovine++/Graphics/Windows/Platform.Windows.h>
#else
#error Implement for this platform
#endif