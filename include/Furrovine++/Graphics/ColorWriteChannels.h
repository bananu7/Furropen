#pragma once

#include <Furrovine++/Enums.h>

namespace Furrovine { namespace Graphics {
	
	enum class ColorWriteChannels : byte {
		None = 0x0,
		Red = 0x01,
		Green = 0x02,
		Blue = 0x04,
		Alpha = 0x08,
		All = Red | Green | Blue | Alpha,
	};

	enumflagoperators( ColorWriteChannels );

}}
