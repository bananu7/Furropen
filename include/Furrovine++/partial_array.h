#pragma once

#include <array>

namespace Furrovine {

	template <typename T, std::size_t n> 
	struct partial_array : public std::array<T, n> {
	public:
		typedef T value_type;
		typedef T& reference;
		typedef const T& const_reference;
		typedef T* pointer_type;
		typedef std::size_t size_type;
		typedef std::ptrdiff_t difference_type;
		typedef pointer_type iterator;
		typedef const pointer_type const_iterator;

		std::size_t len;

		std::size_t length () const {
			return len;
		}
	};

}
