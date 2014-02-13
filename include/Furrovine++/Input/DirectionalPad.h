#pragma once

#include <Furrovine++/Enums.h>

namespace Furrovine { namespace Input {
	
	enum class DirectionalPad {
		Center = 0x0,
		Up = 0x01,
		Down = 0x02,
		Left = 0x04,
		Right = 0x08,
		UpLeft = Up | Left,
		UpRight = Up | Right,
		DownLeft = Down | Left,
		DownRight = Down | Right,
	};

	enumflagoperators( DirectionalPad );
	
}}
