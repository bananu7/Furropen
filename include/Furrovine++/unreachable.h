#pragma once

#include <Furrovine++/Platform.Compiler.h>

namespace Furrovine {

#ifdef FURROVINE_VC
#define unreachable __assume( 0 )
#elif FURROVINE_GCC
#define unreachable __builtin_unreachable( )
#else
#error Define unreachable for this platform
#endif // VC++ || GCC

}