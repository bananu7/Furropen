#pragma once

#include <array>
#include <Furrovine++/numeric_integer_def.h>

namespace Furrovine {

	template <ulword n>
	struct integral_type {
		typedef std::array < uint64, ( n / sizeof( uint64 ) ) + ( ( n % sizeof( uint64 ) ) > 0 ) > type;
	};

	template <>
	struct integral_type<0> {
		typedef byte type;
	};

	template <>
	struct integral_type<1> {
		typedef byte type;
	};

	template <>
	struct integral_type<2> {
		typedef uint16 type;
	};

	template <>
	struct integral_type<3> {
		typedef uint32 type;
	};

	template <>
	struct integral_type<4> {
		typedef uint32 type;
	};

	template <>
	struct integral_type<5> {
		typedef uint64 type;
	};

	template <>
	struct integral_type<6> {
		typedef uint64 type;
	};

	template <>
	struct integral_type<7> {
		typedef uint64 type;
	};

	template <>
	struct integral_type<8> {
		typedef uint64 type;
	};

	template <typename T>
	struct integral_type_of {
		typedef typename integral_type<sizeof( T )>::type type;
	};

}