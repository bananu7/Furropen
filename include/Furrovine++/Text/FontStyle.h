#pragma once

#include <Furrovine++/Enums.h>

namespace Furrovine { namespace Text {

	enum class FontStyle {
		Regular = 0x00,
		Oblique = 0x01,
		Italic = 0x02,
	};


	enumflagoperators( FontStyle );
}}
