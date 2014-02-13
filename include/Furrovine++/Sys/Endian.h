#pragma once

#include <Furrovine++/Sys/Endianess.h>
#include <Furrovine++/Sys/RegularByteOrder.h>
#include <Furrovine++/Sys/ReverseByteOrder.h>

namespace Furrovine { namespace Sys {
	
	class Endian {
	public:

		furrovineapi static ByteOrder System ();

		furrovineapi static ByteOrder Big ();

		furrovineapi static ByteOrder Little ();

		furrovineapi static ByteOrder Middle ( );

		furrovineapi static ByteOrder FromEndianness ( Endianness endianess );
	};

}}
