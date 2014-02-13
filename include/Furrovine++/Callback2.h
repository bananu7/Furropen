#ifndef FURROVINECALLBACK2_H
#define FURROVINECALLBACK2_H

namespace Furrovine {
	
#ifdef FURROVINENOVARIADICS

	/////////////////
	/* 2 ARGUMENT  */
	/////////////////

	template<typename R, typename T0, typename T1>
	class Callback<R (T0, T1)> {
	public:
		typedef R (*TFunc)(void*, T0, T1);
		typedef void* Callback::*SafeBoolType;

		static const std::size_t Arity = 2;

		Callback() : obj(0), func(0) {}
		Callback(void* o, TFunc f) : obj(o), func(f) {}
		
		R operator()(T0 t0, T1 t1) const {
			return (*func)(obj, t0, t1);
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

		bool operator== ( const Callback<R (T0, T1)>& right ) const {
			return obj == right.obj && func == right.func;
		}

		bool operator!= ( const Callback<R (T0, T1)>& right ) const {
			return obj != right.obj || func != right.func;
		}

	private:
		void* obj;
		TFunc func;
	};

	namespace detail {
		template<typename R, class T, typename T0, typename T1>
		struct DeduceConstMemCallback2 { 
			template<R(T::*Func)(T0, T1) const> inline static Callback<R(T0, T1)> Bind(T* o) {
				struct _ { static R wrapper(void* o, T0 t0, T1 t1) { return (static_cast<T*>(o)->*Func)(t0, t1); } };
				return Callback<R(T0, T1)>(o, (R(*)(void*, T0, T1)) _::wrapper);
			}
		};

		template<typename R, class T, typename T0, typename T1>
		struct DeduceMemCallback2 { 
			template<R(T::*Func)(T0, T1)> inline static Callback<R(T0, T1)> Bind(T* o) {
				struct _ { static R wrapper(void* o, T0 t0, T1 t1) { return (static_cast<T*>(o)->*Func)(t0, t1); } };
				return Callback<R(T0, T1)>(o, (R(*)(void*, T0, T1)) _::wrapper);
			}
		};

		template<typename R, typename T0, typename T1>
		struct DeduceStaticCallback2 { 
			template<R(*Func)(T0, T1)> inline static Callback<R(T0, T1)> Bind() { 
				struct _ { static R wrapper(void*, T0 t0, T1 t1) { return (*Func)(t0, t1); } };
				return Callback<R(T0, T1)>(0, (R(*)(void*, T0, T1)) _::wrapper); 
			}
		};
	}

	template<typename R, class T, typename T0, typename T1>
	detail::DeduceConstMemCallback2<R, T, T0, T1> DeduceCallback2(R(T::*)(T0, T1) const) {
		return detail::DeduceConstMemCallback2<R, T, T0, T1>();
	}

	template<typename R, class T, typename T0, typename T1>
	detail::DeduceMemCallback2<R, T, T0, T1> DeduceCallback2(R(T::*)(T0, T1)) {
		return detail::DeduceMemCallback2<R, T, T0, T1>();
	}

	template<typename R, typename T0, typename T1>
	detail::DeduceStaticCallback2<R, T0, T1> DeduceCallback2(R(*)(T0, T1)) {
		return detail::DeduceStaticCallback2<R, T0, T1>();
	}

#endif
	
}

#endif // FURROVINECALLBACK2_H 