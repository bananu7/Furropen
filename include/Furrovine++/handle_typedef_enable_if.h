#pragma once

namespace Furrovine {

	namespace detail {
		template <typename T>
		struct has_typedef_handle_type {
			typedef char yes[ 1 ];
			typedef char no[ 2 ];

			template <typename C>
			static yes& test( typename C::handle_type* );

			template <typename>
			static no& test( ... );

			static const bool value = sizeof( test<T>( 0 ) ) == sizeof( yes );
		};

		template <bool b, typename T, typename TFallback>
		struct handle_typedef_enable_if { };

		template <typename T, typename TFallback>
		struct handle_typedef_enable_if<false, T, TFallback> {
			typedef TFallback type;
		};

		template <typename T, typename TFallback>
		struct handle_typedef_enable_if<true, T, TFallback> {
			typedef typename T::handle_type type;
		};
	}

	template <typename T, typename TDx>
	struct get_handle_type {
		typedef typename detail::handle_typedef_enable_if<detail::has_typedef_handle_type<TDx>::value, TDx, T>::type type;
	};
}
