#ifndef FURROVINEIS_INTEGER_EQUAL_H
#define FURROVINEIS_INTEGER_EQUAL_H

#include <type_traits>

namespace Furrovine {

	template <unsigned long long n, unsigned long long m>
	struct is_integer_equal : public std::integral_constant<bool, n == m> {

	};

}

#endif // FURROVINEIS_EQUAL_H 