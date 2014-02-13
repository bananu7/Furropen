#pragma once

#include <utility>
#include <type_traits>

namespace Furrovine {

	template<class L, class R>
	struct composed_t {
		L l; R r;

		template <typename CL, typename CR, typename TLR>
		struct composed_invoker {
			template<class... Ts>
			auto operator()( R& r, L& l, Ts&&... vs ) -> decltype( r( l( std::forward<Ts>( vs )... ) ) ) {
				return r( l( std::forward<Ts>( vs )... ) );
			}
		};

		template <typename CL, typename CR>
		struct composed_invoker<CL, CR, void> {
			template<class... Ts>
			auto operator()( R& r, L& l, Ts&&... vs ) -> decltype( r( ) ) {
				l( std::forward<Ts>( vs )... ); return r( );
			}
		};

		template<class... Ts>
		auto operator()( Ts&&... vs ) -> decltype( composed_invoker<L, R, decltype( l( std::forward<Ts>( vs )... ) )>( )( r, l, std::forward<Ts>( vs )... ) ) {
			composed_invoker<L, R, decltype( l( std::forward<Ts>( vs )... ) )> inv;
			return inv( r, l, std::forward<Ts>( vs )... );
		}

	};

	template<class L>
	struct composer {
		L l;

		template<class R>
		composer<composed_t<L, R>> then( R r ) const { return{ { l, r } }; }

		template<class... Ts>
		auto operator()( Ts&&... vs ) -> decltype( l( std::forward<Ts>( vs )... ) ) { 
			return l(std::forward<Ts>(vs)...); 
		}
	};

	template<class F>
	composer<F> lift(F f){ return {f}; }

	struct chainer {
		template<class F>
		composer<F> chain( F f ) { return{ f }; }

		template<class F, class... Fs>
		auto chain( F f, Fs... fs ) -> decltype( lift( f ).then( chain( fs... ) ) ) {
			return lift( f ).then( chain( fs... ) );
		}
	};

	template<class... Fs>
	auto chain(Fs... fs) -> decltype(chainer().chain(fs...))
	{ return chainer().chain(fs...); } 

}