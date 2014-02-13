#ifndef FURROVINELAMBDA_ENABLE_IF_H
#define FURROVINELAMBDA_ENABLE_IF_H

namespace Furrovine {

	template <typename T, typename TR, typename ... TArgs>
	struct has_lambda_operator {
		typedef char yes[1];
		typedef char no[2];
		
		template<typename C, TR (C::*)( TArgs... ) const> struct SFINAE {};

		template <typename C>
		static yes& test(SFINAE<C, &C::operator()>*);

		template <typename>
		static no& test(...);

		static const bool value = sizeof(test<T>(0)) == sizeof(yes);
	};

}

#endif // FURROVINELAMBDA_ENABLE_IF_H 