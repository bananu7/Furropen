#pragma once

#include <Furrovine++/Platform.OS.h>

#ifdef FURROVINEWIN

#ifdef FURROVINECOMPILE

#ifdef FURROVINEDLL
#define furrovineexport __declspec( dllexport )
#else
#define furrovineexport 
#endif // FURROVINEDLL 

#else

#ifdef FURROVINEDLL
#define furrovineexport __declspec( dllimport )
#else
#define FURROVINECOMPILE
#define furrovineexport 
#endif // FURROVINEDLL 

#endif // FURROVINECOMPILE 

#elif FURROVINEAPPLE

#ifdef FURROVINECOMPILE
#define furrovineexport 
#else
#define furrovineexport 
#endif // FURROVINECOMPILE 

#else /* Linux? Or something else */

#ifdef FURROVINECOMPILE
#define furrovineexport 
#else
#define furrovineexport 
#endif // FURROVINECOMPILE 

#endif // WIN32 || APPLE || LINUX 

#define furrovineapi furrovineexport
