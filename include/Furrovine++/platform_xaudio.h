#pragma once

#include <Furrovine++/Platform.Conventions.h>

#ifdef FURROVINEWIN
#include <Furrovine++/platform_windows_def.h>
#endif // WIN
#ifdef FURROVINEXAUDIO
#include <xaudio2.h>
#include <xaudio2fx.h>
#endif // XAUDIO
#ifdef FURROVINEWIN
#include <Furrovine++/platform_windows_undef.h>
#endif // WIN

namespace Furrovine {

#ifdef FURROVINEXAUDIO

	typedef HRESULT xaudioresultcode;

#endif // XAUDIO

}
