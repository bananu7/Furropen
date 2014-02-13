#pragma once

#include <Furrovine++/raw_storage.h>

namespace Furrovine {

	template <typename T, ulword type_size = sizeof( T ), ulword type_align = std::alignment_of<T>::value>
	struct uninitialized {
		typedef raw_storage<type_size, type_align> storage_t;
		storage_t res;

		template <typename... Tn>
		void construct( Tn&&... argn ) {
			new ( std::addressof( get( ) ) )T( std::forward<Tn>( argn )... );
		}

		template <typename... Tn>
		void reconstruct( Tn&&... argn ) {
			destruct( );
			construct( std::forward<Tn>( argn )... );
		}

		T& get( ) {
			return res.get<T>( );
		}

		const T& get( ) const {
			return res.get<T>( );
		}

		T&& move( ) {
			return std::move( get( ) );
		}

		operator T && ( ) {
			return move( );
		}

		operator T& ( ) {
			return get( );
		}

		operator const T& ( ) const {
			return get( );
		}

		T* operator -> ( ) {
			return std::addressof( get( ) );
		}

		T const * operator -> ( ) const {
			return std::addressof( get( ) );
		}

		void destruct( ) {
			get( ).~T( );
		}
	};

}