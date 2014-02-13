#ifndef FURROVINEGRAPHICSDEVICEUSAGE_H
#define FURROVINEGRAPHICSDEVICEUSAGE_H

#include <Furrovine++/Graphics/GraphicsCore.h>

namespace Furrovine { namespace Graphics {
	
	enum GraphicsDeviceUsage {
		BackBuffer = DXGI_USAGE_BACK_BUFFER,
		ReadOnly = DXGI_USAGE_READ_ONLY,
		UnorderedAccess = DXGI_USAGE_UNORDERED_ACCESS,
		ShaperInput = DXGI_USAGE_SHADER_INPUT,
		RenderTargetOutput = DXGI_USAGE_RENDER_TARGET_OUTPUT,
		Shared = DXGI_USAGE_SHARED,
	};
	
}}

#endif // FURROVINEGRAPHICSDEVICEUSAGE_H 