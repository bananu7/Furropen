#pragma once

#include <Furrovine++/Enums.h>

namespace Furrovine { namespace Graphics {

	enum class GraphicsDeviceCreationFlags {
		None = 0,
		SingleThreaded = 0x01,
		Debug = 0x02,
		SwitchToReferenceDevice = 0x4,
		PreventThreadingOptimizations = 0x8,
		BlueGreenRedAlphaSupport = 0x20,
		Debuggable = 0x40,
		PreventRegistryDeviceAlterting = 0x80,
		NoTimeout = 0x100,
		VideoSupport = 0x800,
	};

	enumflagoperators( GraphicsDeviceCreationFlags );

}}
