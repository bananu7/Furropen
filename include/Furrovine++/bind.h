#include <Furrovine++/variadic_placeholders.h>
#include <Furrovine++/indices_trick.h>
#include <functional>

namespace Furrovine {

	namespace detail {
		template <ulword... idxs, class F, class... Tn>
		auto lazy_bind( indices<idxs...>, const F& f, Tn&&... argn )
			-> decltype( std::bind( f, std::forward<Tn>( argn )..., placeholder<idxs + 1>()... ) ) {
			return std::bind( f, std::forward<Tn>( argn )..., placeholder<idxs + 1>()... );
		}
	}

	template <typename R, typename... TFn, typename... Tn>
	auto lazy_bind( const std::function<R( TFn... )>& f, Tn&&... argn )
	-> decltype( detail::lazy_bind( make_indices<sizeof...(TFn)-sizeof...( Tn )>(), f, std::forward<Tn>( argn )... ) ) {
		return detail::lazy_bind( make_indices<sizeof...(TFn)-sizeof...( Tn )>(), f, std::forward<Tn>( argn )... );
	}

}