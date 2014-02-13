#pragma once

#include <Furrovine++/Platform.Endian.h>
#include <Furrovine++/Platform.OS.h>
#include <Furrovine++/PrimitiveTypes.h>
#include <Furrovine++/FurrovineApi.h>
#include <Furrovine++/Sys/Endianess.h>
#include <Furrovine++/Sys/ByteOrderUnit.h>

namespace Furrovine { namespace Sys {

	class ByteOrder {
	public:

		furrovineapi static const Endianness SystemEndianess;
		furrovineapi static const Endianness CompiledEndianness;
		furrovineapi static const bool IsLittleEndian;
		furrovineapi static const bool IsBigEndian;

		furrovineapi static Endianness GetEndianess ();

		furrovineapi static Endianness GetReverse ();

		Endianness Endian;
		ulword b20, b21;
		ulword b40, b41, b42, b43;
		ulword b80, b81, b82, b83, b84, b85, b86, b87;

		furrovineapi ByteOrder ();

		furrovineapi ByteOrder( ulword n20, ulword n21, ulword n40, ulword n41, ulword n42, ulword n43, ulword n80, ulword n81, ulword n82, ulword n83, ulword n84, ulword n85, ulword n86, ulword n87 );
		furrovineapi ByteOrder( Endianness endianess, ulword n20, ulword n21, ulword n40, ulword n41, ulword n42, ulword n43, ulword n80, ulword n81, ulword n82, ulword n83, ulword n84, ulword n85, ulword n86, ulword n87 );
		template <byte n20, byte n21, byte n40, byte n41, byte n42, byte n43, byte n80, byte n81, byte n82, byte n83, byte n84, byte n85, byte n86, byte n87>
		ByteOrder ( ByteOrderUnit<n20, n21, n40, n41, n42, n43, n80, n81, n82, n83, n84, n85, n86, n87> order );

		furrovineapi int8 Int8 ( byte* bytes, ulword start ) const;

		furrovineapi uint8 UInt8 ( byte* bytes, ulword start ) const;

		furrovineapi int16 Int16 ( byte* bytes, ulword start ) const;

		furrovineapi uint16 UInt16 ( byte* bytes, ulword start ) const;

		furrovineapi int32 Int32 ( byte* bytes, ulword start ) const;

		furrovineapi uint32 UInt32 ( byte* bytes, ulword start ) const;

		furrovineapi int64 Int64 ( byte* bytes, ulword start ) const;

		furrovineapi uint64 UInt64 ( byte* bytes, ulword start ) const;

		furrovineapi single Single ( byte* bytes, ulword start ) const;

		furrovineapi double Double ( byte* bytes, ulword start ) const;

		furrovineapi virtual int8 Int8 ( byte* bytes ) const;

		furrovineapi virtual uint8 UInt8 ( byte* bytes ) const;

		furrovineapi virtual int16 Int16 ( byte* bytes ) const;

		furrovineapi virtual uint16 UInt16 ( byte* bytes ) const;

		furrovineapi virtual int32 Int24 ( byte* bytes ) const;

		furrovineapi virtual uint32 UInt24 ( byte* bytes ) const;

		furrovineapi virtual int32 Int32 ( byte* bytes ) const;

		furrovineapi virtual uint32 UInt32 ( byte* bytes ) const;

		furrovineapi virtual int64 Int64 ( byte* bytes ) const;

		furrovineapi virtual uint64 UInt64 ( byte* bytes ) const;

		furrovineapi virtual float Single ( byte* bytes ) const;

		furrovineapi virtual double Double ( byte* bytes ) const;

		furrovineapi virtual ~ByteOrder ( );
	};

}}
 