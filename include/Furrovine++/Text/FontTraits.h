#pragma once

#include <Furrovine++/Enums.h>

namespace Furrovine { namespace Text {

	enum class FontTraits {
		None = 0x0,
		Strikethrough = 0x01,
		Underline = 0x02,
		SmallCaps = 0x04,
	};

	enumflagoperators( FontTraits );

}}