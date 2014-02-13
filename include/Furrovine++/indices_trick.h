#pragma once

#include <Furrovine++/numeric_integer_def.h>
#include <Furrovine++/unqualified.h>
#include <tuple>

namespace Furrovine {

	template <ulword... I> 
	struct indices { typedef indices type; };

	template <ulword N, ulword... I>
	struct make_indices : public make_indices<N - 1, N - 1, I...> { };

	template <ulword... I>
	struct make_indices<0, I...> : public indices<I...>{ };

	template <typename... Tn>
	struct types : make_indices<sizeof...( Tn )> { };

	template <typename T>
	struct tuple_indices : public make_indices<std::tuple_size<typename unqualified<T>::type>::value> { };

	template <typename... Tn>
	struct tuple_types : types<Tn...>, std::false_type { };

	template <typename... Tn>
	struct tuple_types<std::tuple<Tn...>> : types<Tn...>, std::true_type{ };


}
