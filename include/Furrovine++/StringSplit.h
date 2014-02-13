#pragma once

#include <Furrovine++/Enums.h>

namespace Furrovine {

	enum class StringSplit {
		Remove = 0x0,
		PreserveEmpty = 0x01,
	};
	
	enumflagoperators( StringSplit );
}