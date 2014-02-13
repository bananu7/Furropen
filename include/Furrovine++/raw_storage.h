#pragma once

#include <Furrovine++/numeric_integer_def.h>
#include <type_traits>

namespace Furrovine {

	template <ulword size, ulword align = sizeof( ulword )>
	struct raw_storage {
		typedef typename std::aligned_storage<size, align>::type buffer_t;
		const static ulword storage_size = sizeof( buffer_t );
		buffer_t buffer;

		template <typename T>
		T& get( ulword n ) {
			return *static_cast<T*>( static_cast<void*>( static_cast<byte*>( static_cast<void*>( std::addressof( buffer ) ) ) + n ) );
		}

		template <typename T>
		const T& get( ulword n ) const {
			return *static_cast<const T*>( static_cast<const void*>( static_cast<const byte*>( static_cast<const void*>( std::addressof( buffer ) ) ) + n ) );
		}

		template <typename T, ulword n = 0>
		T& get( ) {
			return *static_cast<T*>( static_cast<void*>( static_cast<byte*>( static_cast<void*>( std::addressof( buffer ) ) ) + n ) );
		}

		template <typename T, ulword n = 0>
		const T& get( ) const {
			return *static_cast<const T*>( static_cast<const void*>( static_cast<const byte*>( static_cast<const void*>( std::addressof( buffer ) ) ) + n ) );
		}
	};

}