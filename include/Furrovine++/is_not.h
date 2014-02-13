#ifndef FURROVINEIS_NOT_H
#define FURROVINEIS_NOT_H

#include <type_traits>

namespace Furrovine {

	template <typename T>
	struct is_not : std::integral_constant<bool, !T::value> {
	
	};

	template <>
	struct is_not<std::true_type> : public std::false_type {
	
	};

	template <>
	struct is_not<std::false_type> : public std::true_type {
	
	};

}

#endif // FURROVINEIS_NOT_H