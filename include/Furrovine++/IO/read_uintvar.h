#pragma once

#include <Furrovine++/IO/Stream.h>

namespace Furrovine { namespace IO {

	template <typename T = ulword>
	T read_uintvar( Stream& stream ) {
		T value = 0;
		byte read;
		do {
			read = stream.ReadByte( );
			value <<= 7;
			value |= ( read & 0x7F );
		} while ( ( read & 0x80 ) );
		return value;
	}

}}