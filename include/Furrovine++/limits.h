#ifndef FURROVINEPRIMITIVETYPES_H
#define FURROVINEPRIMITIVETYPES_H

#include <Furrovine++/PrimitiveTypes.h>
#include <Furrovine++/Boolean.h>
#include <Furrovine++/Half.h>
#include <Furrovine++/Char.h>
#include <Furrovine++/Int8.h>
#include <Furrovine++/UInt8.h>
#include <Furrovine++/Int16.h>
#include <Furrovine++/UInt16.h>
#include <Furrovine++/Int24.h>
#include <Furrovine++/UInt24.h>
#include <Furrovine++/Int32.h>
#include <Furrovine++/UInt32.h>
#include <Furrovine++/Int64.h>
#include <Furrovine++/UInt64.h>
#include <Furrovine++/Single.h>
#include <Furrovine++/Double.h>

namespace Furrovine {

	typedef Single Float;
	typedef Int8 SByte;
	typedef UInt8 Byte;
	typedef Int16 Short;
	typedef UInt16 UShort;
	typedef Int32 Int;
	typedef UInt32 UInt;
	typedef Int32 Long;
	typedef UInt32 ULong;
	typedef Int64 LLong;
	typedef UInt64 ULLong;
	typedef Int64 LongLong;
	typedef UInt64 ULongLong;
	typedef Int64 LongLong;
	typedef UInt64 ULongLong;

	template <typename T> 
	struct limits;

	template <>
	struct limits<uint8> : public UInt8 {

	};

	template <>
	struct limits<int8> : public Int8 {

	};

	template <>
	struct limits<uint16> : public UInt16 {

	};

	template <>
	struct limits<int16> : public Int16 {

	};

	template <>
	struct limits<uint32> : public UInt32 {

	};

	template <>
	struct limits<int32> : public Int32 {

	};

	template <>
	struct limits<uint64> : public UInt64 {

	};

	template <>
	struct limits<int64> : public Int64 {

	};

	template <>
	struct limits<half> : public Half {

	};

	template <>
	struct limits<float> : public Single {

	};

	template <>
	struct limits<double> : public Double {

	};

}

#endif // FURROVINEPRIMITIVETYPES_H 