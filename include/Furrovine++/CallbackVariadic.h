#pragma once

#include <Furrovine++/CallbackBase.h>
#include <functional>
#include <Furrovine++/null.h>
#include <Furrovine++/inline.h>

namespace Furrovine {
	
	template <typename R, typename... Tn>
	class Callback<R(Tn...)> {
	public:
		static const std::size_t Arity = sizeof... ( Tn );
		typedef R( TFunc )( void*, Tn... );
		typedef R( *TFuncPtr )( void*, Tn... );

		Callback() : obj(null), func(null) {}
		Callback( TFuncPtr f ) : obj( null ), func( f ) {}
		Callback( void* o, TFuncPtr f ) : obj( o ), func( f ) {}
		
		R operator()(Tn... a) const {
			return (*func)(obj, a...);
		}

		explicit operator bool () const {
			return func ? true : false;
		}

		bool operator!() const {
			return func == 0;
		}
		bool operator== (const Callback<TFunc>& right) const {
			return obj == right.obj && func == right.func;
		}
		bool operator!= (const Callback<TFunc>& right) const {
			return obj != right.obj || func != right.func;
		}
	private:
		void* obj;
		TFuncPtr func;
	};

	namespace detail {
		template <typename R, typename T, typename... Tn>
		struct DeduceCallback { 
			template <R(T::*Func)( Tn... )> 
			inlinealways static Callback<R( Tn... )> Bind(T* o) {
				struct _ { static R wrapper(void* o, Tn... a) { return (static_cast<T*>(o)->*Func)(a...); } };
				return Callback<R( Tn... )>(o, (R(*)(void*, Tn...)) _::wrapper);
			}

			template <R( T::*Func )( Tn... ) const>
			inlinealways static Callback<R( Tn... )> Bind( T* o ) {
				struct _ { static R wrapper( void* o, Tn... a ) { return ( static_cast<T*>( o )->*Func )( a... ); } };
				return Callback<R( Tn... )>( o, ( R( *)( void*, Tn... ) ) _::wrapper );
			}
		};

		template<typename R, typename... Tn>
		struct DeduceStaticCallback { 
			template <R(*Func) (Tn... )> 
			inlinealways static Callback<R(Tn...)> Bind() { 
				struct _ { static R wrapper(void*, Tn... a) { return (*Func)(a...); } };
				return Callback<R(Tn...)>(0, (R(*)(void*, Tn...)) _::wrapper); 
			}
		};
	}

	template<typename R, class T, typename... Tn>
	detail::DeduceCallback<R, T, Tn...> DeduceCallback(R(T::*)(Tn...)) {
		return detail::DeduceCallback<R, T, Tn...>();
	}

	template<typename R, class T, typename... Tn>
	detail::DeduceCallback<R, T, Tn...> DeduceCallback(R(T::*)(Tn...) const) {
		return detail::DeduceCallback<R, T, Tn...>();
	}

	template<typename R, typename... Tn>
	detail::DeduceCallback<R, Tn...> DeduceCallback(R(*)(Tn...)) {
		return detail::DeduceStaticCallback<R, Tn...>();
	}

}
 