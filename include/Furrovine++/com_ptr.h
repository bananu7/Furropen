#pragma once

#include <Furrovine++/ptr.h>
#include <Furrovine++/deleters.h>

namespace Furrovine {

	template <typename T>
	using com_ptr = ptr<T, release_deleter>;
	
}
