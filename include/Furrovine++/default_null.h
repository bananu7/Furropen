#pragma once

#include <Furrovine++/null.h>

namespace Furrovine {

	template <typename T>
	struct default_null {
		static T value;
	};

	template <typename T>
	T default_null<T>::value = T{ };

}
