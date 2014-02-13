#pragma once

#include <Furrovine++/Platform.Endian.h>
#include <Furrovine++/Platform.OS.h>
#include <Furrovine++/PrimitiveTypes.h>

namespace Furrovine {  namespace Sys {

	template <byte n20, byte n21, byte n40, byte n41, byte n42, byte n43, byte n80, byte n81, byte n82, byte n83, byte n84, byte n85, byte n86, byte n87 >
	struct ByteOrderUnit {
		static const byte b20 = n20;
		static const byte b21 = n21;
		static const byte b40 = n40;
		static const byte b41 = n41;
		static const byte b42 = n42;
		static const byte b43 = n43;
		static const byte b80 = n80;
		static const byte b81 = n81;
		static const byte b82 = n82;
		static const byte b83 = n83;
		static const byte b84 = n84;
		static const byte b85 = n85;
		static const byte b86 = n86;
		static const byte b87 = n87;
		static const byte Positions[14];
		
		static int8 Int8 ( int8 value ) {
			return Value( value );
		}

		static int16 Int16 ( int16 value ) {
			return Value( value );
		}

		static int32 Int32 ( int32 value ) {
			return Value( value );
		}

		static int64 Int64 ( int64 value ) {
			return Value( value );
		}

		static uint8 UInt8 ( uint8 value ) {
			return Value( value );
		}

		static uint16 UInt16 ( uint16 value ) {
			return Value( value );
		}

		static uint32 UInt32 ( uint32 value ) {
			return Value( value );
		}

		static uint64 UInt64 ( uint64 value ) {
			return Value( value );
		}

		static single Single ( single value ) {
			return Value( value );
		}

		static double Double ( double value ) {
			return Value( value );
		}

		template <typename T>
		static T Value ( T value ) {
			return Value<T>( reinterpret_cast<byte*>( &value ) );
		}

		template <typename T>
		static T Value ( byte* value ) {
			T out = 0;
			ulword p;
			byte* bout = (byte*)&out;
			const byte* pos = &Positions[ sizeof(T) > 2 ? sizeof(T) > 4 ? 6 : 2 : 0 ];
			for ( p = 0; p < sizeof( T ); ++p ) {
				bout[p] = value[ pos[p] ];
			}
			return out;
		}

		template <typename T>
		static T Value ( byte* value, ulword offset ) {
			return Value<T>( value + offset );
		}
	};

	template <byte n20, byte n21, byte n40, byte n41, byte n42, byte n43, byte n80, byte n81, byte n82, byte n83, byte n84, byte n85, byte n86, byte n87 >
	const byte ByteOrderUnit<n20, n21, n40, n41, n42, n43, n80, n81, n82, n83, n84, n85, n86, n87>::Positions[ 14 ] = {
		n20, n21, n40, n41, n42, n43, n80, n81, n82, n83, n84, n85, n86, n87 };

}}
