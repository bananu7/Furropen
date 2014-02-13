#ifndef FURROVINEPOINTER_TYPEDEF_ENABLE_IF_H
#define FURROVINEPOINTER_TYPEDEF_ENABLE_IF_H

namespace Furrovine {

	template <typename T>
	struct has_typedef_pointer {
		typedef char yes[1];
		typedef char no[2];

		template <typename C>
		static yes& test(typename C::pointer*);

		template <typename>
		static no& test(...);

		static const bool value = sizeof(test<T>(0)) == sizeof(yes);
	};

	template <bool b, typename T, typename TFallback>
	struct pointer_type_enable_if { };

	template <typename T, typename TFallback>
	struct pointer_type_enable_if<false, T, TFallback> {
		typedef TFallback type;
	};

	template <typename T, typename TFallback>
	struct pointer_type_enable_if<true, T, TFallback>{
		typedef typename T::pointer type;
	};

	template <typename T, typename TDx>
	struct get_pointer_type {
		typedef typename pointer_type_enable_if<has_typedef_pointer<TDx>::value, TDx, T>::type type;
	};

}

#endif // FURROVINEPOINTER_TYPEDEF_ENABLE_IF_H