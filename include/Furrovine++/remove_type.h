#pragma once

namespace Furrovine {

	template <typename T>
	struct remove_type {
		typedef void type;
	};

	template <typename T>
	struct remove_type<T*> {
		typedef typename remove_type<T>::type* type;
	};

}
