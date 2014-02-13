#pragma once

#include <Furrovine++/numeric_integer_def.h>

namespace Furrovine {

	template <typename T, std::size_t n>
	std::size_t size_of( T( &array )[ n ] ) {
		return n;
	}

	template <typename T, std::size_t n>
	std::size_t byte_size_of( T( &array )[ n ] ) {
		return n * sizeof( T );
	}

	template <typename T, std::size_t n>
	std::ptrdiff_t ssize_of( T( &array )[ n ] ) {
		return n;
	}

	template <typename T, std::size_t n>
	std::ptrdiff_t byte_ssize_of( T( &array )[ n ] ) {
		return n * sizeof( T );
	}

}