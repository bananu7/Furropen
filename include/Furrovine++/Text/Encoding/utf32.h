#ifndef FURROVINEUTF32_H
#define FURROVINEUTF32_H

#include <Furrovine++/Text/Encoding/tutf32.h>
#include <Furrovine++/Sys/ByteOrders.h>

namespace Furrovine { namespace Text { namespace Encoding {

	typedef tutf32<uint32, Sys::little> utf32le;
	typedef tutf32<uint32, Sys::big> utf32be;
	typedef tutf32<uint32, Sys::compilation_byte_order> utf32;

}}}

#endif // FURROVINEUTF32_H 