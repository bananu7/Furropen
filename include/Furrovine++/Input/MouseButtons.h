#pragma once

#include <Furrovine++/Enums.h>

namespace Furrovine { namespace Input {

	enum class MouseButtons {
		None = 0x0000,
		Left = 0x0001,
		Middle = 0x0002,
		Right = 0x0004,
		X1 = 0x0008,
		X2 = 0x0010,
		X3 = 0x0020,
		X4 = 0x0040,
		X5 = 0x0080,
		X6 = 0x0100,
		X7 = 0x0200,
		X8 = 0x0400,
		X9 = 0x0800,
		X10 = 0x1000,
		X11 = 0x2000,
		X12 = 0x4000,
	};

	enumflagoperators( MouseButtons );

}}
