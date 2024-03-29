#pragma once

#include <type_traits>
#include <Furrovine++/inline.h>

namespace Furrovine {

	template <typename TAs, typename T, std::size_t n>
	inlinealways typename std::conditional<std::is_const<T>::value, const TAs, TAs>::type ( &array_cast( T( &array )[ n ] ) )[ ( n * sizeof( T ) ) / sizeof( TAs ) ] {
		typedef typename std::conditional<std::is_const<T>::value, const TAs, TAs>::type cast[ ( n * sizeof( T ) ) / sizeof( TAs ) ];
		typedef typename std::conditional<std::is_const<T>::value, const void, void>::type pointer;
		return *static_cast<cast*>( static_cast<pointer*>( &array ) );
	}

}