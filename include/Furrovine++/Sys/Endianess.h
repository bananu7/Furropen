#pragma once

namespace Furrovine { namespace Sys {
	
	enum class Endianness {
		Regular = 0,
		Reverse = 1,
		Mixed = 2,
		Little = 0x1234,
		Big = 0x4321,
		Middle = 0x3412,
	};
	
}} 