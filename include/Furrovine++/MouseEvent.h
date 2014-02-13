#pragma once

#include <Furrovine++/numeric_integer_def.h>
#include <Furrovine++/Vector2.h>
#include <Furrovine++/Input/MouseButtons.h>

namespace Furrovine {

	struct MouseEvent {
		Vector2i Absolute;
		Vector2i Relative;
		Vector2i Delta;
		Vector2i Wheel;
		Input::MouseButtons Buttons;
		bool Moved;
		bool InWindow;
	};

}