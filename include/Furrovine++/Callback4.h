#ifndef FURROVINECALLBACK4_H
#define FURROVINECALLBACK4_H

#include <Furrovine++/CallbackBase.h>

namespace Furrovine {
	
#ifdef FURROVINENOVARIADICS

	/////////////////
	/* 4 ARGUMENT  */
	/////////////////

	template<typename R, typename T0, typename T1, typename T2, typename T3>
	class Callback<R (T0, T1, T2, T3)> {
	public:
		typedef R (*TFunc)(void*, T0, T1, T2, T3);
		typedef void* Callback::*SafeBoolType;

		static const std::size_t Arity = 2;

		Callback() : obj(0), func(0) {}
		Callback(void* o, TFunc f) : obj(o), func(f) {}

		R operator()(T0 t0, T1 t1, T2 t2, T3 t3) const {
			return (*func)(obj, t0, t1, t2, t3);
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

		bool operator== ( const Callback<R (T0, T1, T2, T3)>& right ) const {
			return obj == right.obj && func == right.func;
		}

		bool operator!= ( const Callback<R (T0, T1, T2, T3)>& right ) const {
			return obj != right.obj || func != right.func;
		}

	private:
		void* obj;
		TFunc func;
	};

	namespace detail {
		template<typename R, class T, typename T0, typename T1, typename T2, typename T3>
		struct DeduceConstMemCallback4 { 
			template<R(T::*Func)(T0, T1, T2, T3) const> inline static Callback<R(T0, T1, T2, T3)> Bind(T* o) {
				struct _ { static R wrapper(void* o, T0 t0, T1 t1, T2 t2, T3 t3) { return (static_cast<T*>(o)->*Func)(t0, t1, t2, t3); } };
				return Callback<R(T0, T1, T2, T3)>(o, (R(*)(void*, T0, T1, T2, T3)) _::wrapper);
			}
		};
		template<typename R, class T, typename T0, typename T1, typename T2, typename T3>
		struct DeduceMemCallback4 { 
			template<R(T::*Func)(T0, T1, T2, T3)> inline static Callback<R(T0, T1, T2, T3)> Bind(T* o) {
				struct _ { static R wrapper(void* o, T0 t0, T1 t1, T2 t2, T3 t3) { return (static_cast<T*>(o)->*Func)(t0, t1, t2, t3); } };
				return Callback<R(T0, T1, T2, T3)>(o, (R(*)(void*, T0, T1, T2, T3)) _::wrapper);
			}
		};

		template<typename R, typename T0, typename T1, typename T2, typename T3>
		struct DeduceStaticCallback4 { 
			template<R(*Func)(T0, T1, T2, T3)> inline static Callback<R(T0, T1, T2, T3)> Bind() { 
				struct _ { static R wrapper(void*, T0 t0, T1 t1, T2 t2, T3 t3) { return (*Func)(t0, t1, t2, t3); } };
				return Callback<R(T0, T1, T2, T3)>(0, (R(*)(void*, T0, T1, T2, T3)) _::wrapper); 
			}
		};
	}

	template<typename R, class T, typename T0, typename T1, typename T2, typename T3>
	detail::DeduceConstMemCallback4<R, T, T0, T1, T2, T3> DeduceCallback4(R(T::*)(T0, T1, T2, T3) const) {
		return detail::DeduceConstMemCallback4<R, T, T0, T1, T2, T3>();
	}

	template<typename R, class T, typename T0, typename T1, typename T2, typename T3>
	detail::DeduceMemCallback4<R, T, T0, T1, T2, T3> DeduceCallback4(R(T::*)(T0, T1, T2, T3)) {
		return detail::DeduceMemCallback4<R, T, T0, T1, T2, T3>();
	}

	template<typename R, typename T0, typename T1, typename T2, typename T3>
	detail::DeduceStaticCallback4<R, T0, T1, T2, T3> DeduceCallback4(R(*)(T0, T1, T2, T3)) {
		return detail::DeduceStaticCallback4<R, T0, T1, T2, T3>();
	}

#endif
	
}

#endif // FURROVINECALLBACK4_H 