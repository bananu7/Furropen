#pragma once

namespace Furrovine {

#ifdef _MSC_VER
#define FURROVINE_VC
#elif __GNUC__
#define FURROVINE_GCC
#elif __clang__
#define FURROVINE_CLANG
#else
#error Unknown Compiler -- set unique define for this compiler
#endif // VC++ || GCC || Clang

}
