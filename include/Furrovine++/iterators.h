#pragma once

#include <iterator>

namespace Furrovine { namespace Unicode {

	template <typename T>
	std::reverse_iterator<T> make_reverse_iterator( T it ) {
		return std::reverse_iterator<T>( it );
	}

}}