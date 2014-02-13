#pragma once

#include <Furrovine++/uninitialized.h>

namespace Furrovine {

	template <typename T, ulword type_size = sizeof( T ), ulword type_align = std::alignment_of<T>::value>
	struct raw : public uninitialized<T, type_size, type_align> {
		typedef raw_storage<type_size, type_align> storage_t;
		storage_t res;

		template <typename ...Tn>
		raw ( Tn&&... argn ) {
			construct( std::forward<Tn>( argn )... );
		}

		operator T& ( ) {
			return get( );
		}

		operator const T& ( ) const {
			return get( );
		}

		~raw() {
			destruct( );
		}
	};

}
 