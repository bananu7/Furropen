#ifndef FURROVINECALLBACK0_H
#define FURROVINECALLBACK0_H

#include <Furrovine++/CallbackBase.h>

namespace Furrovine {
	
#ifdef FURROVINENOVARIADICS

	/////////////////
	/* 0 ARGUMENTS */
	/////////////////

	template<typename R>
	class Callback<R ()> {
	public:
		typedef R (*TFunc)(void*);
		typedef void* Callback::*SafeBoolType;

		static const std::size_t Arity = 0;

		Callback() : obj(0), func(0) {}
		Callback(void* o, TFunc f) : obj(o), func(f) {}

		R operator()( ) const {
			return (*func)(obj);
		}

		operator SafeBoolType () const {
			return func != 0? &Callback::obj : 0;
		}

		operator bool () const {
			return func != 0;
		}

		bool operator! () const {
			return func == 0;
		}

		bool operator== ( const Callback<R ()>& right ) const {
			return obj == right.obj && func == right.func;
		}

		bool operator!= ( const Callback<R ()>& right ) const {
			return obj != right.obj || func != right.func;
		}

	private:
		void* obj;
		TFunc func;
	};

	namespace detail {
		template<typename R, class T>
		struct DeduceConstMemCallback0 { 
			template<R(T::*Func)() const> inline static Callback<R()> Bind(T* o) {
				struct _ { static R wrapper(void* o) { return (static_cast<T*>(o)->*Func)(); } };
				return Callback<R()>(o, (R(*)(void*)) _::wrapper);
			}
		};

		template<typename R, class T>
		struct DeduceMemCallback0 { 
			template<R(T::*Func)()> inline static Callback<R()> Bind(T* o) {
				struct _ { static R wrapper(void* o) { return (static_cast<T*>(o)->*Func)(); } };
				return Callback<R()>(o, (R(*)(void*)) _::wrapper);
			}
		};

		template<typename R>
		struct DeduceStaticCallback0 { 
			template<R(*Func)()> inline static Callback<R()> Bind() { 
				struct _ { static R wrapper(void* ) { return (*Func)(); } };
				return Callback<R()>(0, (R(*)(void*)) _::wrapper); 
			}
		};
	}

	template<typename R, class T>
	detail::DeduceConstMemCallback0<R, T> DeduceCallback0( R(T::*)() const ) {
		return detail::DeduceConstMemCallback0<R, T>();
	}

	template<typename R, class T>
	detail::DeduceMemCallback0<R, T> DeduceCallback0(R(T::*)()) {
		return detail::DeduceMemCallback0<R, T>();
	}

	template<typename R>
	detail::DeduceStaticCallback0<R> DeduceCallback0(R(*)()) {
		return detail::DeduceStaticCallback0<R>();
	}
	
#endif

}

#endif // FURROVINECALLBACK0_H 