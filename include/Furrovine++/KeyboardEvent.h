#pragma once

#include <Furrovine++/numeric_integer_def.h>
#include <Furrovine++/Input/Key.h>
#include <Furrovine++/Export.h>
#include <Furrovine++/fixed_vector.h>

namespace Furrovine {

	struct KeyboardEvent {
		Input::Key Key;
		bool Down;
	};

}