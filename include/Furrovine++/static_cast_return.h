#pragma once

#include <type_traits>

namespace Furrovine {

	template <typename TTo, typename Tp>
	static TTo static_cast_return( std::true_type, Tp&& p ) {
		return p;
	}

	template <typename TTo, typename Tp>
	static TTo static_cast_return( std::false_type, Tp&& p ) {
		return static_cast<TTo>( p );
	}

	template <typename TTo, typename T, typename Tp>
	static TTo static_cast_return( Tp&& p ) {
		typedef typename std::is_same<TTo, T>::type is_same_t;
		return static_cast_return<TTo>( is_same_t( ), std::forward<T>( p ) );
	}

}