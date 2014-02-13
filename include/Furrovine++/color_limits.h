#pragma once

#include <type_traits>
#include <limits>

namespace Furrovine {

	template <ulword n>
	struct packed_color_type {
		typedef std::array<byte, n> type;
	};

	template <>
	struct packed_color_type<0> {
		typedef byte type;
	};

	template <>
	struct packed_color_type<1> {
		typedef byte type;
	};

	template <>
	struct packed_color_type<2> {
		typedef uint16 type;
	};

	template <>
	struct packed_color_type<3> {
		typedef uint32 type;
	};

	template <>
	struct packed_color_type<4> {
		typedef uint32 type;
	};

	template <>
	struct packed_color_type<5> {
		typedef uint64 type;
	};

	template <>
	struct packed_color_type<6> {
		typedef uint64 type;
	};

	template <>
	struct packed_color_type<7> {
		typedef uint64 type;
	};

	template <>
	struct packed_color_type<8> {
		typedef uint64 type;
	};

	template <typename T>
	struct packed_color_type_of {
		typedef typename packed_color_type<sizeof( T )>::type type;
	};

	template <typename T>
	struct color_limits {
		const static T max( ) {
			return std::is_integral<T>::value ? static_cast<T>( 255 ) : static_cast<T>( 1 );
		}

		const static T min( ) {
			return std::is_integral<T>::value ? static_cast<T>( 0 ) : static_cast<T>( 0 );
		}
	};

	template <typename T, typename TValue, typename TIntermediate = double>
	T color_normalize( TValue value, TValue valuemax = color_limits<TValue>::max( ), TValue valuemin = color_limits<TValue>::min( ), T max = color_limits<T>::max( ), T min = color_limits<T>::min( ) ) {
		TIntermediate valuerange = valuemax - valuemin;
		TIntermediate percentage = static_cast<TIntermediate>( value ) / static_cast<TIntermediate>( valuerange );
		TIntermediate range = max - min;
		return static_cast<T>( percentage * ( range ) ) + min;
	}

	template <typename T>
	T color_normalize( T value, T valuemax = color_limits<T>::max( ), T valuemin = color_limits<T>::min( ), T max = color_limits<T>::max( ), T min = color_limits<T>::min( ) ) {
		return value;
	}

	template <typename T>
	T color_clamp( T value ) {
		const static auto ma = color_limits<T>::max( );
		const static auto mi = color_limits<T>::min( );
		return static_cast<T>( value > ma ? ma : value < mi ? mi : value );
	}

	namespace op {

		struct color_clamp {
			template <typename T>
			T operator()( T value ) {
				return ::Furrovine::color_clamp<T>( value );
			}
		};

	}

}