#pragma once

#include <Furrovine++/buffer_view.h>
#include <Furrovine++/numeric_def.h>
#include <functional>

namespace Furrovine { namespace Graphics {

	template <typename T>
	struct mapped {
		buffer_view<void> elems;
		std::function<void( void*, ulword )> mapper;

		mapped( void* elemsdata, ulword bytecount, std::function<void(void*, ulword)> datamapper ) : elems( elemsdata, bytecount ), mapper( datamapper ) {

		}

		T& get ( ) {
			return *reinterpret_cast<T*>( elems.data( ) );
		}

		const T& get ( ) const {
			return *reinterpret_cast<const T*>( elems.data( ) );
		}

		operator T& ( ) {
			return get( );
		}

		operator const T& ( ) const {
			return get( );
		}

		void apply( ) {
			mapper( elems.data( ), elems.size( ) );
		}

		~mapped( ) {
			apply( );
		}

	};

}}
