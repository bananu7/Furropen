#pragma once

#include <Furrovine++/Enums.h>

namespace Furrovine { namespace Graphics {
	
	enum class DisplayFilterFlags {
		Interlaced = 0x1,
		Scaling = 0x2,
		Stereo = 0x4,
		HiddenStereo = 0x8
	};

	enumflagoperators( DisplayFilterFlags );
	
}}
