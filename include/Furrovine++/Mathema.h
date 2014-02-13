#pragma once

#include <Furrovine++/std_defines.h>
#include <limits>
#include <Furrovine++/inline.h>
#include <Furrovine++/null.h>
#include <Furrovine++/PrimitiveTypes.h>
#include <Furrovine++/Export.h>

namespace Furrovine {

	template < uint n > struct meta_factorial {
		static const uint64 value = n * meta_factorial<n-1>::value;
	};

	template<> struct meta_factorial<0> {
		static const uint64 value = 1;
	};

	template <typename T> 
	struct Mathema {
	public:
		typedef typename double TSigned;
		static const T BitMax[64];
		static const T BitIndexMax[64];
		static const T Pow10[10];
		static const T InversePow10[10];
		static const T Maximum;
		static const T Minimum;
		static const T Epsilon;
		static const T e;
		static const T Pi;
		static const T TwoPi;
		static const T InversePi;
		static const T InverseTwoPi;
		static const T ThreeTwoPi;
		static const T HalfPi;
		static const T QuarterPi;
		static const T RootE;
		static const T RootPi;
		static const T RootTwoPi;
		static const T RootHalfPi;
		static const T RootQuarterPi;

		static uint64 Factorial( uint n ) {
			switch ( n ) {
			case 20: return meta_factorial<20>::value;
			case 19: return meta_factorial<19>::value;
			case 18: return meta_factorial<18>::value;
			case 17: return meta_factorial<17>::value;
			case 16: return meta_factorial<16>::value;
			case 15: return meta_factorial<15>::value;
			case 14: return meta_factorial<14>::value;
			case 13: return meta_factorial<13>::value;
			case 12: return meta_factorial<12>::value;
			case 11: return meta_factorial<11>::value;
			case 10: return meta_factorial<10>::value;
			case 9: return meta_factorial<9>::value;
			case 8: return meta_factorial<8>::value;
			case 7: return meta_factorial<7>::value;
			case 6: return meta_factorial<6>::value;
			case 5: return meta_factorial<5>::value;
			case 4: return meta_factorial<4>::value;
			case 3: return meta_factorial<3>::value;
			case 2: return meta_factorial<2>::value;
			case 1: return meta_factorial<1>::value;
			case 0: return meta_factorial<0>::value;
			default: return 0;
			}
		}

		static T LastDigit ( T num ) {
			return num - 10 * (num / 10);
		}
		
		static T Power( T base, T exponent ) {
			return (T)pow(base, exponent);
		}

		inlinealways static T Abs (T value) {
			return (T)abs(value);
		}

		inlinealways static T Acos (T value) {
			return (T)acos(value);
		}

		inlinealways static T Asin (T value) {
			return (T)asin(value);
		}

		inlinealways static T Atan (T value) {
			return (T)atan(value);
		}

		inlinealways static T Cos (T value) {
			return (T)cos(value);
		}

		inlinealways static T Sin (T value) {
			return (T)sin(value);
		}

		inlinealways static T Tan (T value) {
			return (T)tan(value);
		}

		inlinealways static T Atan2 (T a, T b) {
			return (T)atan2(a, b);
		}

		inlinealways static T Sqrt (T value) {
			return (T)sqrt(value);
		}

		inlinealways static T Mod (T a, T b) {
			return (T)fmod(a, b);
		}

		inlinealways static T Min (T a, T b) {
			return (T)std::min(a, b);
		}

		inlinealways static T Max (T a, T b) {
			return (T)std::max(a, b);
		}

		inlinealways static T Ceiling (double value) {
			return (T)ceil(value);
		}

		inlinealways static T Floor (double value) {
			return (T)floor(value);
		}

		inlinealways static T MiniMax (T value, T min, T max) {
			return Min(Max(value, min), max);
		}

		inlinealways static T Round (T value) {
			return (T)floor( value + 0.5 );
		}

		inlinealways static T Sign (T value) {
			 return (T)(T(0) < value) - (value < T(0));
		}

		static T Inverse ( T value ) {
			return (T)( (T)1 / value );
		}

		static T Sincn ( T x ) {
			if (x == 0)
				return 1;
			T piex = Pi * x;
			return (T)( sin( piex ) / piex );
		}

		static T Sinc ( T x ) {
			if ( x == 0 )
				return 1;
			return (T)( sin(x) / x );
		}

		static T NormalizedGaussian2 (T radius, T stdev) {
			return NormalizedGaussian2(radius, radius, stdev);
		}

		static T NormalizedGaussian2 (T x, T y, T stdev) {
			T powdev = stdev * stdev;
			return (T)( pow( Mathema<T>::e, -( TSigned )( (x * x + y * y) / ( 2.0 * powdev ) ) / (TwoPi * powdev) ) );
		}

		static T NormalizedGaussian (T x, T stddev, T shift = 0) {
			if ( stddev == 0 )
				return 0;
			return Gaussian(x, (T)( 1 / (stddev * Mathema<double>::RootTwoPi)), shift, stddev );
		}

		static T Gaussian (T x, T a, T b, T c) {
			if ( c == 0 )
				return a;
			T skew = (x - b);
			skew *= skew;
			c *= c;
			c *= 2;
			return (T)( a * (pow(Mathema<double>::e, skew / c)) );
		}

		static T Lanczos2 (T x, T y, T alpha) {
			return Lanczos(x, alpha) * Lanczos(y, alpha);
		}

		static T Lanczos (T x, T alpha) {
			if (x > alpha || x < alpha)
				return 0;
			return Sincn(x) / Sincn(x / alpha);
		}
	};

#pragma warning(push)
#pragma warning(disable: 4309)

	template <typename T> const T Mathema<T>::Maximum = (T)std::numeric_limits<T>::max();
	template <typename T> const T Mathema<T>::Minimum = (T)std::numeric_limits<T>::lowest();
	template <typename T> const T Mathema<T>::Epsilon = (T)std::numeric_limits<T>::epsilon();
	template <typename T> const T Mathema<T>::e = (T)(2.7182818284);
	template <typename T> const T Mathema<T>::Pi = (T)(3.1415927);
	template <typename T> const T Mathema<T>::TwoPi = (T)(3.1415927 * 2.0);
	template <typename T> const T Mathema<T>::InversePi = (T)( 1 / 3.1415927);
	template <typename T> const T Mathema<T>::InverseTwoPi = (T)(1 / (3.1415927 * 2.0));
	template <typename T> const T Mathema<T>::ThreeTwoPi = (T)(3.1415927 * 1.5);
	template <typename T> const T Mathema<T>::HalfPi = (T)(3.1415927 * 0.5);
	template <typename T> const T Mathema<T>::QuarterPi = (T)(3.1415927 * 0.25);
	template <typename T> const T Mathema<T>::RootE = (T)(sqrt(2.7182818284));
	template <typename T> const T Mathema<T>::RootPi = (T)(sqrt(3.1415927));
	template <typename T> const T Mathema<T>::RootTwoPi = (T)(sqrt(3.1415927 * 2.0));
	template <typename T> const T Mathema<T>::RootHalfPi = (T)(sqrt(3.1415927 * 0.5));
	template <typename T> const T Mathema<T>::RootQuarterPi = (T)(sqrt(3.1415927 * 0.25));
	template <typename T> const T Mathema<T>::Pow10[10] = {
		(T)1.0, 
		(T)10.0, 
		(T)100.0, 
		(T)1000.0, 
		(T)10000.0, 
		(T)100000.0, 
		(T)1000000.0, 
		(T)10000000.0, 
		(T)100000000.0, 
		(T)1000000000.0 };
	template <typename T> const T Mathema<T>::InversePow10[10] = {
		(T)1.0, 
		(T)(1.0 / 10.0), 
		(T)(1.0 / 100.0), 
		(T)(1.0 / 1000.0), 
		(T)(1.0 / 10000.0), 
		(T)(1.0 / 100000.0), 
		(T)(1.0 / 1000000.0), 
		(T)(1.0 / 10000000.0), 
		(T)(1.0 / 100000000.0), 
		(T)(1.0 / 1000000000.0) };
	template <typename T> const T Mathema<T>::BitMax[64] = {
		(T)0x0000000000000001, 
		(T)0x0000000000000003, 
		(T)0x0000000000000007, 
		(T)0x000000000000000F,
		(T)0x000000000000001F, 
		(T)0x000000000000003F, 
		(T)0x000000000000007F, 
		(T)0x00000000000000FF,
		(T)0x00000000000001FF, 
		(T)0x00000000000003FF, 
		(T)0x00000000000007FF, 
		(T)0x0000000000000FFF,
		(T)0x0000000000001FFF, 
		(T)0x0000000000003FFF, 
		(T)0x0000000000007FFF, 
		(T)0x000000000000FFFF,
		(T)0x000000000001FFFF, 
		(T)0x000000000003FFFF, 
		(T)0x000000000007FFFF, 
		(T)0x00000000000FFFFF,
		(T)0x00000000001FFFFF, 
		(T)0x00000000003FFFFF, 
		(T)0x00000000007FFFFF, 
		(T)0x0000000000FFFFFF,
		(T)0x0000000001FFFFFF, 
		(T)0x0000000003FFFFFF, 
		(T)0x0000000007FFFFFF, 
		(T)0x000000000FFFFFFF,
		(T)0x000000001FFFFFFF, 
		(T)0x000000003FFFFFFF, 
		(T)0x000000007FFFFFFF, 
		(T)0x00000000FFFFFFFF,
		(T)0x00000001FFFFFFFF, 
		(T)0x00000003FFFFFFFF, 
		(T)0x00000007FFFFFFFF, 
		(T)0x0000000FFFFFFFFF,
		(T)0x0000001FFFFFFFFF, 
		(T)0x0000003FFFFFFFFF, 
		(T)0x0000007FFFFFFFFF, 
		(T)0x000000FFFFFFFFFF,
		(T)0x000001FFFFFFFFFF, 
		(T)0x000003FFFFFFFFFF, 
		(T)0x000007FFFFFFFFFF, 
		(T)0x00000FFFFFFFFFFF,
		(T)0x00001FFFFFFFFFFF, 
		(T)0x00003FFFFFFFFFFF, 
		(T)0x00007FFFFFFFFFFF, 
		(T)0x0000FFFFFFFFFFFF,
		(T)0x0001FFFFFFFFFFFF, 
		(T)0x0003FFFFFFFFFFFF, 
		(T)0x0007FFFFFFFFFFFF, 
		(T)0x000FFFFFFFFFFFFF,
		(T)0x001FFFFFFFFFFFFF, 
		(T)0x003FFFFFFFFFFFFF, 
		(T)0x007FFFFFFFFFFFFF, 
		(T)0x00FFFFFFFFFFFFFF,
		(T)0x01FFFFFFFFFFFFFF, 
		(T)0x03FFFFFFFFFFFFFF, 
		(T)0x07FFFFFFFFFFFFFF, 
		(T)0x0FFFFFFFFFFFFFFF,
		(T)0x1FFFFFFFFFFFFFFF, 
		(T)0x3FFFFFFFFFFFFFFF, 
		(T)0x7FFFFFFFFFFFFFFF, 
		(T)0xFFFFFFFFFFFFFFFF
	};

	template <typename T> const T Mathema<T>::BitIndexMax[64] = {
		(T)0x0000000000000000, 
		(T)0x0000000000000001, 
		(T)0x0000000000000003, 
		(T)0x0000000000000007, 
		(T)0x000000000000000F,
		(T)0x000000000000001F, 
		(T)0x000000000000003F, 
		(T)0x000000000000007F, 
		(T)0x00000000000000FF,
		(T)0x00000000000001FF, 
		(T)0x00000000000003FF, 
		(T)0x00000000000007FF, 
		(T)0x0000000000000FFF,
		(T)0x0000000000001FFF, 
		(T)0x0000000000003FFF, 
		(T)0x0000000000007FFF, 
		(T)0x000000000000FFFF,
		(T)0x000000000001FFFF, 
		(T)0x000000000003FFFF, 
		(T)0x000000000007FFFF, 
		(T)0x00000000000FFFFF,
		(T)0x00000000001FFFFF, 
		(T)0x00000000003FFFFF, 
		(T)0x00000000007FFFFF, 
		(T)0x0000000000FFFFFF,
		(T)0x0000000001FFFFFF, 
		(T)0x0000000003FFFFFF, 
		(T)0x0000000007FFFFFF, 
		(T)0x000000000FFFFFFF,
		(T)0x000000001FFFFFFF, 
		(T)0x000000003FFFFFFF, 
		(T)0x000000007FFFFFFF, 
		(T)0x00000000FFFFFFFF,
		(T)0x00000001FFFFFFFF, 
		(T)0x00000003FFFFFFFF, 
		(T)0x00000007FFFFFFFF, 
		(T)0x0000000FFFFFFFFF,
		(T)0x0000001FFFFFFFFF, 
		(T)0x0000003FFFFFFFFF, 
		(T)0x0000007FFFFFFFFF, 
		(T)0x000000FFFFFFFFFF,
		(T)0x000001FFFFFFFFFF, 
		(T)0x000003FFFFFFFFFF, 
		(T)0x000007FFFFFFFFFF, 
		(T)0x00000FFFFFFFFFFF,
		(T)0x00001FFFFFFFFFFF, 
		(T)0x00003FFFFFFFFFFF, 
		(T)0x00007FFFFFFFFFFF, 
		(T)0x0000FFFFFFFFFFFF,
		(T)0x0001FFFFFFFFFFFF, 
		(T)0x0003FFFFFFFFFFFF, 
		(T)0x0007FFFFFFFFFFFF, 
		(T)0x000FFFFFFFFFFFFF,
		(T)0x001FFFFFFFFFFFFF, 
		(T)0x003FFFFFFFFFFFFF, 
		(T)0x007FFFFFFFFFFFFF, 
		(T)0x00FFFFFFFFFFFFFF,
		(T)0x01FFFFFFFFFFFFFF, 
		(T)0x03FFFFFFFFFFFFFF, 
		(T)0x07FFFFFFFFFFFFFF, 
		(T)0x0FFFFFFFFFFFFFFF,
		(T)0x1FFFFFFFFFFFFFFF, 
		(T)0x3FFFFFFFFFFFFFFF, 
		(T)0x7FFFFFFFFFFFFFFF
	};

#pragma warning(pop)

}

