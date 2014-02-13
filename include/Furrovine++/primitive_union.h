#pragma once

#include <Furrovine++/PrimitiveTypes.h>

namespace Furrovine {
	
	union primitive_union {
		byte Byte;
		sbyte SByte;
		int Int;
		short Short;
		ushort UShort;
		uint UInt;
		long Long;
		ulong ULong;
		llong Llong;
		ullong ULlong;
		double Double;
		float Single;

		double double0;
		int64 int640;
		uint64 uint640;

		struct {
			int32 lowint32;
			int32 highint32;
		};

		struct {
			uint32 lowuint32;
			uint32 highuint32;
		};

		struct {
			single lowsingle;
			single highsingle;
		};

		int32 int32s[2];
		struct {
			int32 int320;
			int32 int321;
		};

		uint32 uint32s[2];
		struct {
			uint32 uint320;
			uint32 uint321;
		};

		single singles[2];
		struct {
			single single0;
			single single1;
		};

		uint16 uint16s[4];
		struct {
			uint16 uint160;
			uint16 uint161;
			uint16 uint162;
			uint16 uint163;
		};

		int16 int16s[4];
		struct {
			int16 int160;
			int16 int161;
			int16 int162;
			int16 int163;
		};

		byte bytes[8];
		struct {
			byte b0;
			byte b1;
			byte b2;
			byte b3;
			byte b4;
			byte b5;
			byte b6;
			byte b7;
		};
	};
}
