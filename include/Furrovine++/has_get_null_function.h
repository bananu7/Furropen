#pragma once

#include <type_traits>

namespace Furrovine {

	namespace detail {
		template<typename T>
		struct has_get_null_function {
			template<typename U, size_t( U::* )( ) const> struct SFINAE { };
			template<typename U> static char Test( SFINAE<U, &U::get_null>* );
			template<typename U> static int Test( ... );
			static const bool value = sizeof( Test<T>( 0 ) ) == sizeof( char );
		};
	}

	template <typename T>
	struct has_get_null_function : public std::integral_constant<bool, detail::has_get_null_function<T>::value > {

	};

}