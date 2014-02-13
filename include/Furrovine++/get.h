#pragma once

#include <Furrovine++/ptr.h>
#include <Furrovine++/handle.h>
#include <Furrovine++/optional.h>

namespace Furrovine {

	template <typename T>
	T* get ( T* ptr ) { return ptr; }

	template <typename T, typename TDx>
	T* get ( std::unique_ptr<T, TDx>& ptr ) { return ptr.get(); }

	template <typename T, typename TDx>
	T* get ( ptr<T, TDx>& ptr ) { return ptr.get(); }

	template <typename T, typename TDx, typename TNull>
	typename handle<T, TDx, TNull>::handle_type get ( handle<T, TDx, TNull>& ptr ) { return ptr.get(); }

	template <typename T>
	const T& get( const optional<T>& opt ) { return opt.value( ); }

	template <typename T>
	T& get( optional<T>& opt ) { return opt.value( ); }

}
