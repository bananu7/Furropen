#pragma once

#include <Furrovine++/ptr.h>
#include <Furrovine++/handle.h>

namespace Furrovine {

	template <typename T, typename TPtr>
	T* ptr_get( TPtr& p ) {
		return static_cast<T*>( p.get( ) );
	}

	template <typename T, typename TPtr>
	T& ref_get( TPtr& p ) {
		return *ptr_get<T, TPtr>( p );
	}

	template <typename T>
	T* ptr_get( void* p ) {
		return static_cast<T*>( p );
	}

	template <typename T>
	T& ref_get( void* p ) {
		return *ptr_get<T>( p );
	}

}