#pragma once

#include <Furrovine++/default_handle_null.h>
#include <Furrovine++/has_get_null_function.h>

namespace Furrovine {

	namespace detail {
		template <typename T, typename TDx, bool b>
		struct handle_get_null_enable_if { };

		template <typename T, typename TDx>
		struct handle_get_null_enable_if<T, TDx, false> {
			typedef default_get_null<T> type;
		};

		template <typename T, typename TDx>
		struct handle_get_null_enable_if<T, TDx, true> {
			typedef TDx type;
		};
	}

	template <typename T, typename TDx>
	struct default_handle_get_null {
		typedef typename detail::handle_get_null_enable_if<T, TDx, detail::has_get_null_function<TDx>::value>::type type;
	};

}