#pragma once

#include <Furrovine++/Platform.OS.h>

namespace Furrovine {

#ifdef FURROVINEWIN

#ifndef NOMINMAX
#define NOMINMAX
#endif // NOMINMAX

#ifndef DBGHELP_TRANSLATE_TCHAR
#define DBGHELP_TRANSLATE_TCHAR
#endif // DBGHELP_TRANSLATE_TCHAR

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif // WIN32_LEAN_AND_MEAN

#endif

}