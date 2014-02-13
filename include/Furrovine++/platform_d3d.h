#pragma once

#include <Furrovine++/Platform.Conventions.h>
#include <Furrovine++/Platform.OS.h>

#ifdef FURROVINEDIRECTX
#ifdef FURROVINEWIN
#include <Furrovine++/platform_windows_def.h>
#endif // WIN

#include <initguid.h>
#include <d3d11.h>
#include <dxgi.h>
#include <dxgidebug.h>
#include <d3dtypes.h>
#include <d3dcommon.h>
#include <DirectXMath.h>
#include <DirectXPackedVector.h>
#include <d3dcompiler.h>
#include <d3d11shader.h>

#ifdef FURROVINEWIN
#include <Furrovine++/platform_windows_undef.h>
#endif // WIN

#endif // DIRECTX 


namespace Furrovine {

#ifdef FURROVINEDIRECTX

	typedef HRESULT dxresultcode;

#endif // DIRECTX

}
