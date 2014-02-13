#pragma once

#include <Furrovine++/Platform.OS.h>

namespace Furrovine {

#ifdef FURROVINEWIN

#ifdef NOMINMAX
#undef NOMINMAX
#endif // NOMINMAX

#ifdef DBGHELP_TRANSLATE_TCHAR
#undef DBGHELP_TRANSLATE_TCHAR
#endif // DBGHELP_TRANSLATE_TCHAR

#ifdef WIN32_LEAN_AND_MEAN
#undef WIN32_LEAN_AND_MEAN
#endif // WIN32_LEAN_AND_MEAN

#endif

}