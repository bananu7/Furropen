#ifndef FURROVINECALLBACK1_H
#define FURROVINECALLBACK1_H

namespace Furrovine {
	
#ifdef FURROVINENOVARIADICS

	/////////////////
	/* 1 ARGUMENT  */
	/////////////////

	template<typename R, typename T0>
	class Callback<R (T0)> {
	public:
		typedef R (*TFunc)(void*, T0);
		typedef void* Callback::*SafeBoolType;

		static const std::size_t Arity = 1;

		Callback() : obj(0), func(0) {}
		Callback(void* o, TFunc f) : obj(o), func(f) {}

		R operator()(T0 t0) const {
			return (*func)(obj, t0);
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

		bool operator== ( const Callback<R (T0)>& right ) const {
			return obj == right.obj && func == right.func;
		}

		bool operator!= ( const Callback<R (T0)>& right ) const {
			return obj != right.obj || func != right.func;
		}

	private:
		void* obj;
		TFunc func;
	};

	namespace detail {
		template<typename R, class T, typename T0>
		struct DeduceConstMemCallback1 { 
			template<R(T::*Func)(T0) const> inline static Callback<R(T0)> Bind(T* o) {
				struct _ { static R wrapper(void* o, T0 t0) { return (static_cast<T*>(o)->*Func)(t0); } };
				return Callback<R(T0)>(o, (R(*)(void*, T0)) _::wrapper);
			}
		};
		template<typename R, class T, typename T0>
		struct DeduceMemCallback1 { 
			template<R(T::*Func)(T0)> inline static Callback<R(T0)> Bind(T* o) {
				struct _ { static R wrapper(void* o, T0 t0) { return (static_cast<T*>(o)->*Func)(t0); } };
				return Callback<R(T0)>(o, (R(*)(void*, T0)) _::wrapper);
			}
		};

		template<typename R, typename T0>
		struct DeduceStaticCallback1 { 
			template<R(*Func)(T0)> inline static Callback<R(T0)> Bind() { 
				struct _ { static R wrapper(void*, T0 t0) { return (*Func)(t0); } };
				return Callback<R(T0)>(0, (R(*)(void*, T0)) _::wrapper); 
			}
		};
	}

	template<typename R, class T, typename T0>
	detail::DeduceConstMemCallback1<R, T, T0> DeduceCallback1(R(T::*)(T0) const) {
		return detail::DeduceConstMemCallback1<R, T, T0>();
	}

	template<typename R, class T, typename T0>
	detail::DeduceMemCallback1<R, T, T0> DeduceCallback1(R(T::*)(T0)) {
		return detail::DeduceMemCallback1<R, T, T0>();
	}

	template<typename R, typename T0>
	detail::DeduceStaticCallback1<R, T0> DeduceCallback1(R(*)(T0)) {
		return detail::DeduceStaticCallback1<R, T0>();
	}

#endif
	
}

#endif // FURROVINECALLBACK1_H 