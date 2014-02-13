#pragma once

#include <Furrovine++/Platform.OS.h>

#ifdef FURROVINEWIN

#ifdef FURROVINEUNICODECOMPILE

#ifdef FURROVINEDLL
#define furrovineunicodeexport __declspec( dllexport )
#else
#define furrovineunicodeexport 
#endif // FURROVINEDLL 

#else

#ifdef FURROVINEDLL
#define furrovineunicodeexport __declspec( dllimport )
#else
#define FURROVINEUNICODECOMPILE
#define furrovineunicodeexport 
#endif // FURROVINEDLL 

#endif // FURROVINEUNICODECOMPILE 

#elif FURROVINEAPPLE

#ifdef FURROVINEUNICODECOMPILE
#define furrovineunicodeexport 
#else
#define furrovineunicodeexport 
#endif // FURROVINEUNICODECOMPILE 

#else /* Linux? Or something else */

#ifdef FURROVINEUNICODECOMPILE
#define furrovineunicodeexport 
#else
#define furrovineunicodeexport 
#endif // FURROVINEUNICODECOMPILE 

#endif // WIN32 || APPLE || LINUX 

#define furrovineunicodeapi furrovineunicodeexport
