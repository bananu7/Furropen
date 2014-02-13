#pragma once

#include <Furrovine++/std_defines.h>
#include <vector>
#include <initializer_list>
#include <Furrovine++/buffer_view.h>

namespace Furrovine {

	template <typename T>
	std::vector<T> make_vector ( std::size_t n ) { 
		std::vector<T> x; x.reserve(n); return x; 
	}

	template <typename T>
	std::vector<T> make_vector( std::initializer_list<T> n ) {
		std::vector<T> x( n.begin( ), n.end( ) ); return x;
	}

	template <typename T, ulword n>
	std::vector<T> make_vector( const T (& arr)[n] ) {
		std::vector<T> x( arr, arr + n ); return x;
	}

	template <typename T>
	std::vector<T> make_vector( const buffer_view<T>& b ) {
		std::vector<T> x( b.begin( ), b.end( ) ); return x;
	}

}
