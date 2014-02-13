#ifndef FURROVINEMULTI_TAGGED_H
#define FURROVINEMULTI_TAGGED_H

namespace Furrovine {

	template <typename T, typename ...Tn>
	struct tagged_item {
		T element;
	};

	template <typename ...TTagn, typename T>
	tagged_item<T, TTagn...> tag ( T&& arg ) {
		tagged_item<T, TTagn...> result = { T( std::forward<T>( arg ) ) };
		return result;
	}

	template <typename T, typename ...TTagn, typename ...Tn>
	tagged_item<T, TTagn...> tag_from ( Tn&&... argn ) {
		tagged_item<T, TTagn...> result = { T( std::forward<Tn>( argn )... ) };
		return result;
	}

}

#endif // FURROVINEMULTI_TAGGED_H 