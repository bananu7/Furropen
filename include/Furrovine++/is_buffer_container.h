#pragma once

#include <type_traits>

namespace Furrovine {

	namespace detail {
		template<typename T>
		struct has_data_function {
			template<typename U, size_t( U::* )( ) const> struct SFINAE { };
			template<typename U> static char Test( SFINAE<U, &U::data>* );
			template<typename U> static int Test( ... );
			static const bool value = sizeof( Test<T>( 0 ) ) == sizeof( char );
		};

		template<typename T>
		struct has_size_function {
			template<typename U, size_t( U::* )( ) const> struct SFINAE { };
			template<typename U> static char Test( SFINAE<U, &U::size>* );
			template<typename U> static int Test( ... );
			static const bool value = sizeof( Test<T>( 0 ) ) == sizeof( char );
		};
	}

	template <typename T>
	struct is_buffer_container : public std::integral_constant<bool, detail::has_size_function<T>::value && detail::has_data_function<T>::value > {

	};

}