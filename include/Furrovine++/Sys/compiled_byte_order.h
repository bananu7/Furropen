#pragma once

#include <Furrovine++/Sys/ByteOrderUnit.h>
#include <Furrovine++/Sys/little.h>
#include <Furrovine++/Sys/big.h>
#include <Furrovine++/Sys/pdp.h>

namespace Furrovine { namespace Sys {

#ifdef FURROVINELITTLEENDIAN
	typedef little compilation_byte_order;
#elif FURROVINEBIGENDIAN
	typedef big compilation_byte_order;
#elif FURROVINEPDPENDIAN
	typedef pdp compilation_byte_order;
#else
#error Unknown Endianness
#endif

}}
 