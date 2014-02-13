#pragma once

#include <Furrovine++/Enums.h>

namespace Furrovine { namespace Graphics {

	enum class SpriteEffects {
		None = 0x0,
		FlipHorizontally = 0x01,
		FlipVertically = 0x02,
	};

	enumflagoperators( SpriteEffects );

}}
