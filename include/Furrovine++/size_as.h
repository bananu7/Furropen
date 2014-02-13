#pragma once

#include <Furrovine++/PrimitiveTypes.h>
#include <Furrovine++/inline.h>

namespace Furrovine {

	namespace detail {
		template <typename T>
		struct sizer {
			ulword operator()( ) const {
				return sizeof( T );
			}
		};

		template <>
		struct sizer<void> {
			ulword operator()( ) const {
				return sizeof( char );
			}
		};
	}

	template <typename TAs, typename T = byte>
	inlinealways ulword size_as ( ulword size ) {
		return ( size * detail::sizer<T>( )( ) ) / detail::sizer<TAs>( )( );
	}

	template <typename T, ulword n>
	inlinealways ulword size_no_null( const T( &array )[ n ] ) {
		return n < 0 || array[ n - 1 ] == 0 ? n - 1 : n;
	}
}