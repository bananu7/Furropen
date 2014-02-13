#pragma once

#include <Furrovine++/default_null.h>
#include <type_traits>

namespace Furrovine {

	template <typename T>
	struct default_get_null {	
		static T get_null( ) {
			return default_null<T>::value;
		}
	};

}
