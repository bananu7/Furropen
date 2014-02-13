#pragma once

#include <Furrovine++/std_defines.h>
#include <tuple>
#include <type_traits>
#include <utility>
#include <Furrovine++/indices_trick.h>
#include <Furrovine++/unqualified.h>

namespace Furrovine {

	template<unsigned I, typename T>
	struct unqualified_tuple_element {
		typedef typename std::tuple_element<I, typename unqualified<T>::type>::type type;
	};

	template<typename T, unsigned offset = 0>
	struct tuple_indices_for : make_indices<std::tuple_size<typename unqualified<T>::type>::value, offset> {
		typedef make_indices<std::tuple_size<typename unqualified<T>::type>::value, offset> type;
	};

	template <typename T>
	unqualified_tuple_element<0, T> head ( T&& t ){
		return std::get<0>( std::forward<T>( t ) );
	}

	template<typename T, unsigned... I>
	auto tail ( T&& t,  indices<I...> ) 
	-> decltype( std::forward_as_tuple( std::get<I>( std::forward<T>( t ) )... ) ){
		return std::forward_as_tuple( std::get<I>( std::forward<T>( t ) )... );
	}

}
 