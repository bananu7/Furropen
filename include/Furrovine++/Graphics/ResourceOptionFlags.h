#pragma once

#include <Furrovine++/Enums.h>

namespace Furrovine { namespace Graphics {

	enum class ResourceOptionFlags {
		None = 0,
		GenerateMips = 0x1L,
		Shared = 0x2L,
		TextureCube = 0x4L,
		DrawIndirectArgs = 0x10L,
		BufferAllowRawViews = 0x20L,
		BufferStructered = 0x40L,
		ResourceClamp = 0x80L,
		SharedKeyedMutex = 0x100L,
		GdiCompatible = 0x200L,
		SharedNTHandle = 0x800L,
		RestrictedContent = 0x1000L,
		RestrictSharedResource = 0x2000L,
		RestrictSharedResourceDriver = 0x4000L,
		Guarded = 0x8000L,
		TilePool = 0x20000L,
		Tiled = 0x40000L
	};

	enumflagoperators( ResourceOptionFlags );

}}
