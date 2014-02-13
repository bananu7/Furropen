#pragma once

#include <Furrovine++/PrimitiveTypes.h>

namespace Furrovine {

	union primitive_pointer_union {
		sbyte* sbytes;
		byte* bytes;
		short* shorts;
		ushort* ushorts;
		int* ints;
		uint* uints;
		long* longs;
		ulong* ulongs;
		llong* llongs;
		ullong* ullongs;

		int8* int8s;
		uint8* uint8s;
		int16* int16s;
		uint16* uint16s;
		int32* int32s;
		uint32* uint32s;
		int64* int64s;
		uint64* uint64s;
	};

}
