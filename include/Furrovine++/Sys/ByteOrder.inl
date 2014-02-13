#pragma once

#include <Furrovine++/Sys/ByteOrder.h>

namespace Furrovine { namespace Sys {

	template <byte n20, byte n21, byte n40, byte n41, byte n42, byte n43, byte n80, byte n81, byte n82, byte n83, byte n84, byte n85, byte n86, byte n87>
	ByteOrder::ByteOrder( ByteOrderUnit<n20, n21, n40, n41, n42, n43, n80, n81, n82, n83, n84, n85, n86, n87> order )
	: ByteOrder( Endianness::Mixed, n20, n21, n40, n41, n42, n43, n80, n81, n82, n83, n84, n85, n86, n87 ) {

	}

}}
