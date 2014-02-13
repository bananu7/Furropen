#pragma once

#include <Furrovine++/FurrovineApi.h>
#include <Furrovine++/PrimitiveTypes.h>

namespace Furrovine {

	struct Bits {
	
		static int DeBruijn( ulword index ) {
			const static int debruijn[ 32 ] = {
				0, 1, 28, 2, 29, 14, 24, 3, 30, 22, 20, 15, 25, 17, 4, 8,
				31, 27, 13, 23, 21, 19, 16, 7, 26, 12, 18, 6, 11, 5, 10, 9
			};
			return debruijn[ index ];
		}

		static double InverseMax( ulword index ) {
			const static double inverses[ 32 ] = {
				0,
				1.0 / 0x1,
				1.0 / 0x3,
				1.0 / 0x7,
				1.0 / 0xF,
				1.0 / 0x1F,
				1.0 / 0x3F,
				1.0 / 0x7F,
				1.0 / 0xFF,
				1.0 / 0x1FF,
				1.0 / 0x3FF,
				1.0 / 0x7FF,
				1.0 / 0xFFF,
				1.0 / 0x1FFF,
				1.0 / 0x3FFF,
				1.0 / 0x7FFF,
				1.0 / 0xFFFF,
				1.0 / 0x1FFFF,
				1.0 / 0x3FFFF,
				1.0 / 0x7FFFF,
				1.0 / 0xFFFFF,
			};
			return inverses[ index ];
		}

		static uint32 NextPow2( uint32 value ) {
			uint32 pow2( 1 );
			while ( pow2 < value ) {
				pow2 <<= 1;
			}
			return pow2;
		}

		static uint64 NextPow2( uint64 value ) {
			uint64 pow2( 1 );
			while ( pow2 < value ) {
				pow2 <<= 1;
			}
			return pow2;
		}

		static int Count( uint32 i ) {
			i = i - ( ( i >> 1 ) & 0x55555555 );
			i = ( i & 0x33333333 ) + ( ( i >> 2 ) & 0x33333333 );
			return ( ( ( i + ( i >> 4 ) ) & 0x0F0F0F0F ) * 0x01010101 ) >> 24;
		}

		static int32 MostSignificantSet( uint32 k ) {
			union {
				unsigned asInt;
				float asFloat;
			};
			int n;

			k = k & ~( k >> 1 );           /* Fix problem with rounding. */
			asFloat = (float)k;
			n = 158 - ( asInt >> 23 );
			n = ( n & 31 ) + ( n >> 6 );     /* Fix problem with k = 0. */
			return n;
		}

		static int32 MostSignificantSet( uint64 k ) {
			int64 pos = 63;
			while ( ( k >> pos ) == 0 ) {
				--pos;
			}
			return (int32)pos;
		}

		static int32 LeastSignificantSet( int32 v ) {
			return DeBruijn( ( (uint)( ( v & -v ) * 0x077CB531U ) ) >> 27 );
		}

		static int32 LeastSignificantSet( int64 v ) {
			int32 pos = 0;
			while ( !( v & 1 ) ) {
				v >>= 1;
				++pos;
			}
			return pos;
		}

		static int LastSetBit( uint bit32 ) {
			return LastSetBitIndex( bit32 ) + 1;
		}

		static int LastSetBitIndex( uint bit32 ) {
			for ( int p = 31; p > -1; --p ) {
				if ( ( ( bit32 >> p ) & 0x1 ) == 1 )
					return p;
			}

			return 0;
		}

		static int FirstSetBit( uint bit32 ) {
			return FirstSetBitIndex( bit32 ) + 1;
		}

		static int FirstSetBitIndex( uint bit32 ) {
			return DeBruijn( ( (uint)( (int)bit32 & -(int)bit32 ) * 0x077CB531U ) >> 27 ) + 1;
		}

	};

}
 