#ifndef FURROVINECALLBACK3_H
#define FURROVINECALLBACK3_H

#include <Furrovine++/CallbackBase.h>

namespace Furrovine {

#ifdef FURROVINENOVARIADICS

	/////////////////
	/* 3 ARGUMENT  */
	/////////////////

	template<typename R, typename T0, typename T1, typename T2>
	class Callback<R (T0, T1, T2)> {
	public:
		typedef R (*TFunc)(void*, T0, T1, T2);
		typedef void* Callback::*SafeBoolType;

		static const std::size_t Arity = 2;

		Callback() : obj(0), func(0) {}
		Callback(void* o, TFunc f) : obj(o), func(f) {}

		R operator()(T0 t0, T1 t1, T2 t2) const {
			return (*func)(obj, t0, t1, t2);
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

		bool operator== ( const Callback<R (T0, T1, T2)>& right ) const {
			return obj == right.obj && func == right.func;
		}

		bool operator!= ( const Callback<R (T0, T1, T2)>& right ) const {
			return obj != right.obj || func != right.func;
		}

	private:
		void* obj;
		TFunc func;
	};

	namespace detail {
		template<typename R, class T, typename T0, typename T1, typename T2>
		struct DeduceConstMemCallback3 { 
			template<R(T::*Func)(T0, T1, T2) const> inline static Callback<R(T0, T1, T2)> Bind(T* o) {
				struct _ { static R wrapper(void* o, T0 t0, T1 t1, T2 t2) { return (static_cast<T*>(o)->*Func)(t0, t1, t2); } };
				return Callback<R(T0, T1, T2)>(o, (R(*)(void*, T0, T1, T2)) _::wrapper);
			}
		};

		template<typename R, class T, typename T0, typename T1, typename T2>
		struct DeduceMemCallback3 { 
			template<R(T::*Func)(T0, T1, T2)> inline static Callback<R(T0, T1, T2)> Bind(T* o) {
				struct _ { static R wrapper(void* o, T0 t0, T1 t1, T2 t2) { return (static_cast<T*>(o)->*Func)(t0, t1,  t2); } };
				return Callback<R(T0, T1, T2)>(o, (R(*)(void*, T0, T1, T2)) _::wrapper);
			}
		};

		template<typename R, typename T0, typename T1, typename T2>
		struct DeduceStaticCallback3 { 
			template<R(*Func)(T0, T1, T2)> inline static Callback<R(T0, T1, T2)> Bind() { 
				struct _ { static R wrapper(void*, T0 t0, T1 t1, T2 t2) { return (*Func)(t0, t1, t2); } };
				return Callback<R(T0, T1, T2)>(0, (R(*)(void*, T0, T1, T2)) _::wrapper); 
			}
		};
	}

	template<typename R, class T, typename T0, typename T1, typename T2>
	detail::DeduceConstMemCallback3<R, T, T0, T1, T2> DeduceCallback3(R(T::*)(T0, T1, T2) const) {
		return detail::DeduceConstMemCallback3<R, T, T0, T1, T2>();
	}

	template<typename R, class T, typename T0, typename T1, typename T2>
	detail::DeduceMemCallback3<R, T, T0, T1, T2> DeduceCallback3(R(T::*)(T0, T1, T2)) {
		return detail::DeduceMemCallback3<R, T, T0, T1, T2>();
	}

	template<typename R, typename T0, typename T1, typename T2>
	detail::DeduceStaticCallback3<R, T0, T1, T2> DeduceCallback3(R(*)(T0, T1, T2)) {
		return detail::DeduceStaticCallback3<R, T0, T1, T2>();
	}

#endif

}

#endif // FURROVINECALLBACK3_H 