#pragma once

#include <Furrovine++/std_defines.h>
#include <Furrovine++/handle.h>
#include <Furrovine++/nullgen_arg.h>
#include <Furrovine++/deleter_arg.h>
#include <type_traits>
#include <cstddef>

namespace Furrovine {

	template <typename T, typename... Tn>
	handle<T> make_handle( Tn&&... argn ) {
		return handle<T>( T( std::forward<Tn>( argn )... ) );
	}

	template <typename T, typename TDx, typename TDx0, typename... Tn>
	handle<T, TDx> make_handle( deleter_arg_t, TDx0&& dx, Tn&&... argn ) {
		return handle<T, TDx>( T( std::forward<Tn>( argn )... ), std::forward<TDx0>( dx ) );
	}

	template <typename T, typename TDx, typename TNull, typename TDx0, typename TNil, typename... Tn>
	handle<T, TDx, TNull> make_handle( deleter_arg_t, TDx0&& dx, nullgen_arg_t, TNil&& nil, Tn&&... argn ) {
		return handle<T, TDx, TNull>( T( std::forward<Tn>( argn )... ), std::forward<TDx0>( dx ), std::forward<TNil>( nil ) );
	}

	template <typename... THn, typename... Tn>
	void handle_reset( handle<THn...>& p, Tn&&... argn ) {
		p = make_handle<THn...>( std::forward<Tn>( argn )... );
	}

}
