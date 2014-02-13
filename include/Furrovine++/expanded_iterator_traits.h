#ifndef FURROVINEADVANCED_ITERATOR_TRAITS_H
#define FURROVINEADVANCED_ITERATOR_TRAITS_H
#pragma once

#include <type_traits>

namespace Furrovine {

	template<class It>
	struct is_special_iterator : public std::integral_constant<bool, std::is_void<typename std::iterator_traits<It>::value_type>::value> {
		
	};

	template<typename T, bool B>
	struct iterator_check {};

	template<typename T>
	struct iterator_check<T, true> { typedef typename T::container_type::value_type value_type; };

	template<typename T>
	struct iterator_check<T, false> { typedef typename std::iterator_traits<T>::value_type value_type; };

	template<typename T>
	struct expanded_iterator_traits : public iterator_check<T, is_special_iterator<T>::value> {};	

}

#endif // FURROVINEADVANCED_ITERATOR_TRAITS_H 