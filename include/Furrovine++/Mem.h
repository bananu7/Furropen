#pragma once

#include <cstring>
#include <Furrovine++/Export.h>
#include <Furrovine++/PrimitiveTypes.h>

namespace Furrovine {
	
	class Mem {
	public:
		template <typename T> 
		inlinealways static void Swap ( T& left, T& right) {
			std::swap( left, right );
		}

		template <typename T> 
		inlinealways static void Zero ( T& item ) {
			std::memset( &item, 0, sizeof( T ) );
		}

		template <typename T> 
		inlinealways static void Zero ( const T& item ) {
			std::memset( &item, 0, sizeof( T ) );
		}

		template <typename T> 
		inlinealways static void Zero ( const T* item ) {
			std::memset( item, 0, sizeof( T ) );
		}

		template <typename T> 
		inlinealways static void Zero ( T* item ) {
			std::memset( item, 0, sizeof( T ) );
		}

		template <typename T> 
		inlinealways static void Zero ( T* item, ulword sz ) {
			std::memset( item, 0, sz );
		}

		template <typename T> 
		inlinealways static void Zero ( const T* item, ulword sz ) {
			std::memset( item, 0, sz );
		}

	};
	
}
