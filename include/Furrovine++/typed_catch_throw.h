#pragma once

namespace Furrovine {

	template <typename T>
	struct typed_throw {
		typedef void( *throw_t )( );

		static void check( ) {
			throw static_cast<T*>( nullptr );
		}
	};

	template <typename T>
	struct typed_catch {
		typedef typename typed_throw<T>::throw_t throw_t;
		typedef bool( *catch_t )( const throw_t& );

		static bool accept( const throw_t& check ) {
			try {
				check( );
			}
			catch ( T* ) {
				return true;
			}
			catch ( ... ) {
			}
			return false;
		}
	};

}
