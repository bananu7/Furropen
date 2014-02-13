#include <Furrovine++/Platform.OS.h>
#include <Furrovine++/Platform.Conventions.h>

#ifdef FURROVINEXAUDIO
#include <Furrovine++/platform_xaudio.h>
#elif FURROVINEOPENAL
#include <Furrovine++/platform_openal.h>
#else
#error No Audio Library specified for this platform
#endif