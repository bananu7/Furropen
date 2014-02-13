#pragma once

const auto null = nullptr;

namespace Furrovine {

	template <typename T>
	struct null_of {
		static T* value;
	};

	template <typename T> 
	T* null_of<T>::value = static_cast<T*>( null );

	template <typename T>
	struct null_ref {
		static T& value;
	};

	template <typename T> 
	T& null_ref<T>::value = *static_cast<T*>(null);

}
