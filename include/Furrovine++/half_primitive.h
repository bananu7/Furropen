#pragma once

#include <Furrovine++/Export.h>
#include <Furrovine++/numeric_integer_def.h>
#include <type_traits>

namespace Furrovine {

	//---------------------------------------------------------------------------
	//
	// Implementation --
	//
	// Representation of a float:
	//
	//	We assume that a float, f, is an IEEE 754 single-precision
	//	floating point number, whose bits are arranged as follows:
	//
	//	    31 (msb)
	//	    |
	//	    | 30     23
	//	    | |      |
	//	    | |      | 22                    0 (lsb)
	//	    | |      | |                     |
	//	    X XXXXXXXX XXXXXXXXXXXXXXXXXXXXXXX
	//
	//	    s e        m
	//
	//	S is the sign-bit, e is the exponent and m is the significand.
	//
	//	If e is between 1 and 254, f is a normalized number:
	//
	//	            s    e-127
	//	    f = (-1)  * 2      * 1.m
	//
	//	If e is 0, and m is not zero, f is a denormalized number:
	//
	//	            s    -126
	//	    f = (-1)  * 2      * 0.m
	//
	//	If e and m are both zero, f is zero:
	//
	//	    f = 0.0
	//
	//	If e is 255, f is an "infinity" or "not a number" (NAN),
	//	depending on whether m is zero or not.
	//
	//	Examples:
	//
	//	    0 00000000 00000000000000000000000 = 0.0
	//	    0 01111110 00000000000000000000000 = 0.5
	//	    0 01111111 00000000000000000000000 = 1.0
	//	    0 10000000 00000000000000000000000 = 2.0
	//	    0 10000000 10000000000000000000000 = 3.0
	//	    1 10000101 11110000010000000000000 = -124.0625
	//	    0 11111111 00000000000000000000000 = +infinity
	//	    1 11111111 00000000000000000000000 = -infinity
	//	    0 11111111 10000000000000000000000 = NAN
	//	    1 11111111 11111111111111111111111 = NAN
	//
	// Representation of a half:
	//
	//	Here is the bit-layout for a half number, h:
	//
	//	    15 (msb)
	//	    |
	//	    | 14  10
	//	    | |   |
	//	    | |   | 9        0 (lsb)
	//	    | |   | |        |
	//	    X XXXXX XXXXXXXXXX
	//
	//	    s e     m
	//
	//	S is the sign-bit, e is the exponent and m is the significand.
	//
	//	If e is between 1 and 30, h is a normalized number:
	//
	//	            s    e-15
	//	    h = (-1)  * 2     * 1.m
	//
	//	If e is 0, and m is not zero, h is a denormalized number:
	//
	//	            s    -14
	//	    h = (-1)  * 2     * 0.m
	//
	//	If e and m are both zero, h is zero:
	//
	//	    h = 0.0
	//
	//	If e is 31, h is an "infinity" or "not a number" (NAN),
	//	depending on whether m is zero or not.
	//
	//	Examples:
	//
	//	    0 00000 0000000000 = 0.0
	//	    0 01110 0000000000 = 0.5
	//	    0 01111 0000000000 = 1.0
	//	    0 10000 0000000000 = 2.0
	//	    0 10000 1000000000 = 3.0
	//	    1 10101 1111000001 = -124.0625
	//	    0 11111 0000000000 = +infinity
	//	    1 11111 0000000000 = -infinity
	//	    0 11111 1000000000 = NAN
	//	    1 11111 1111111111 = NAN
	//
	// Conversion:
	//
	//	Converting from a float to a half requires some non-trivial bit
	//	manipulations.  In some cases, this makes conversion relatively
	//	slow, but the most common case is accelerated via table lookups.
	//
	//	Converting back from a half to a float is easier because we don't
	//	have to do any rounding.  In addition, there are only 65536
	//	different half numbers; we can convert each of those numbers once
	//	and store the results in a table.  Later, all conversions can be
	//	done using only simple table lookups.
	//
	//---------------------------------------------------------------------------
	struct half {
		uint16 _res;

		
		furrovineapi half( ) = default;
		furrovineapi half( float f );
		furrovineapi half& operator = ( float f );

		//-----------------------------------------------
		// Overflow handler for float-to-half conversion;
		// generates a hardware floating-point Overflow,
		// which may be trapped by the operating system.
		//-----------------------------------------------
		furrovineapi float force_overflow( );

		//-----------------------------------------------------
		// Float-to-half conversion -- general case, including
		// zeroes, denormalized numbers and exponent overflows.
		//-----------------------------------------------------

		furrovineapi short convert( int i );

		furrovineapi float as_float( ) const;

		furrovineapi half round( uint n ) const;
		
		furrovineapi half operator - ( ) const;
		furrovineapi half operator + ( ) const;
		furrovineapi half& operator += ( half h );
		furrovineapi half& operator += ( float f );
		furrovineapi half& operator -= ( half h );
		furrovineapi half& operator -= ( float f );
		furrovineapi half& operator *= ( half h );
		furrovineapi half& operator *= ( float f );
		furrovineapi half& operator /= ( half h );
		furrovineapi half& operator /= ( float f );

		furrovineapi operator float( ) const;

		furrovineapi bool is_finite( ) const;
		furrovineapi bool is_normalized( ) const;
		furrovineapi bool is_denormalized( ) const;
		furrovineapi bool is_zero( ) const;
		furrovineapi bool is_nan( ) const;
		furrovineapi bool is_infinity( ) const;
		furrovineapi bool is_negative( ) const;

		furrovineapi half positive_infinity( );
		furrovineapi half negative_infinity( );
		
		furrovineapi half qNaN( );
		furrovineapi half sNaN( );

		furrovineapi uint16 bits( ) const;

	};

	furrovineapi half operator + ( half left, half right );
	furrovineapi half operator - ( half left, half right );
	furrovineapi half operator * ( half left, half right );
	furrovineapi half operator / ( half left, half right );
	furrovineapi float operator + ( float left, half right );
	furrovineapi float operator - ( float left, half right );
	furrovineapi float operator * ( float left, half right );
	furrovineapi float operator / ( float left, half right );
	furrovineapi float operator + ( half left, float right );
	furrovineapi float operator - ( half left, float right );
	furrovineapi float operator * ( half left, float right );
	furrovineapi float operator / ( half left, float right );

	namespace detail {
		furrovineapi double crunch_half( ushort _res );
	}

}

namespace std {
	
	template <>
	struct is_floating_point<Furrovine::half> : ::std::true_type {
		
	};

}