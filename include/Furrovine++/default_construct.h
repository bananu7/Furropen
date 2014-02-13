#pragma once

#include <utility>

namespace Furrovine {
	
	template <typename T> 
	struct default_construct {
		template <typename... Args>
		void operator() ( T* item, Args... args ) const {
			new( item ) T( std::forward<Args>( args )... );
		}

		template <typename... Args>
		void operator() ( T& item, Args... args ) const {
			operator()( std::addressof( item ), std::forward<Args>( args )... );
		}
	};

	template <typename T, typename TAlloc>
	void cascading_construct( T* p, TAlloc&& alloc ) {

	}

	template <typename T, typename TAlloc, typename T0, typename... Tn>
	void cascading_construct( T* p, TAlloc&& alloc, T0&& arg0, Tn&&... argn ) {
		alloc.construct( p, std::forward<T0>( arg0 ) );
		cascading_construct( std::forward<TAlloc>( alloc ), ++p, std::forward<Tn>( argn )... );
	}

}
