#pragma once

#include <type_traits>
#include <Furrovine++/in_place.h>
#include <Furrovine++/tuple_tricks.h>
#include <Furrovine++/indices_trick.h>

namespace Furrovine {

	template<int i, typename... >
	struct tmp_integer : public std::integral_constant<int, i> {};

	template<bool b, typename... >
	struct tmp_boolean : public std::integral_constant<bool, b> {};

	template<bool b, typename... Tn>
	struct tmp_bool : public tmp_boolean<b, Tn...>::type {};

	template<typename If, typename Then, typename Else>
	struct tmp_conditional : public std::conditional<If::value, Then, Else>::type {};

	template<typename T>
	struct tmp_not : public tmp_bool<!T::value> {};

	template<typename... Tn>
	struct tmp_any : public tmp_bool<true> {};

	template<typename T, typename... Tn>
	struct tmp_any<T, Tn...> : public tmp_conditional<T, tmp_bool<true>, tmp_any<Tn...>>::type {};

	template<typename... Tn>
	struct tmp_all : tmp_bool<true> {};

	template<typename T, typename... Tn>
	struct tmp_all<T, Tn...> : public tmp_conditional<T, tmp_all<Tn...>, tmp_bool<false>>::type{};

}