#pragma once

#include <type_traits>

namespace Furrovine {

	template<typename T>
	struct unqualified {
		typedef typename std::remove_cv< typename std::remove_reference<T>::type>::type type;
	};

}
