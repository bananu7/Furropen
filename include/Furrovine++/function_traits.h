#pragma once

#include <tuple>
#include <Furrovine++/indices_trick.h>

namespace Furrovine {

	template<typename TFuncSignature>
	struct function_traits;

	template<typename T, typename R, typename... Tn>
	struct function_traits<R( T::* )( Tn... )> {
		static const std::size_t arity = sizeof...( Tn );
		static const bool is_member_function = true;
		typedef std::tuple<Tn...> arg_tuple_t;
		typedef types<Tn...> args_t;
		typedef R( T::* func_t )( Tn... );
		typedef R( T::* func_pointer_t )( Tn... );
		typedef R return_t;
		template <std::size_t i>
		using arg_n = std::tuple_element<i, arg_tuple_t>;
	};

	template<typename T, typename R, typename... Tn>
	struct function_traits<R( T::* )( Tn... ) const> {
		static const std::size_t arity = sizeof...( Tn );
		static const bool is_member_function = true;
		typedef std::tuple<Tn...> arg_tuple_t;
		typedef types<Tn...> args_t;
		typedef R( T::* func_t )( Tn... );
		typedef R( T::* func_pointer_t )( Tn... );
		typedef R return_t;
		template <std::size_t i>
		using arg_n = std::tuple_element<i, arg_tuple_t>;
	};

	template<typename R, typename... Tn>
	struct function_traits<R( Tn... )> {
		static const std::size_t arity = sizeof...( Tn );
		static const bool is_member_function = false;
		typedef std::tuple<Tn...> arg_tuple_t;
		typedef types<Tn...> args_t;
		typedef R( func_t )( Tn... );
		typedef R( *func_pointer_t )( Tn... );
		typedef R return_t;
		template <std::size_t i>
		using arg_n = std::tuple_element<i, arg_tuple_t>;
	};

	template<typename R, typename... Tn>
	struct function_traits<R( *)( Tn... )> {
		static const std::size_t arity = sizeof...( Tn );
		static const bool is_member_function = false;
		typedef std::tuple<Tn...> arg_tuple_t;
		typedef types<Tn...> args_t;
		typedef R( func_t )( Tn... );
		typedef R( *func_pointer_t )( Tn... );
		typedef R return_t;
		template <std::size_t i>
		using arg_n = std::tuple_element<i, arg_tuple_t>;
	};

	template<typename T, bool isclass = std::is_class<typename unqualified<T>::type>::value>
	struct is_callable_impl : std::is_function<T> { };

	template<typename T>
	struct is_callable_impl<T, true> {
		using yes = char;
		using no = struct { char s[ 2 ]; };

		struct F { void operator()( ); };
		struct Derived : T, F { };
		template<typename U, U> struct Check;

		template<typename V>
		static no test( Check<void ( F::* )( ), &V::operator()>* );

		template<typename>
		static yes test( ... );

		static const bool value = sizeof( test<Derived>( 0 ) ) == sizeof( yes );
	};

	template<typename T>
	struct is_callable : std::integral_constant<bool, is_callable_impl<T>::value> { };

}
