#ifndef FURROVINEUTF16_H
#define FURROVINEUTF16_H

#include <Furrovine++/Text/Encoding/tutf16.h>
#include <Furrovine++/Sys/ByteOrders.h>

namespace Furrovine { namespace Text { namespace Encoding {
#ifdef FURROVINEWIN
	typedef tutf16<wchar_t, Sys::little> utf16le;
	typedef tutf16<wchar_t, Sys::big> utf16be;
	typedef tutf16<wchar_t, Sys::compilation_byte_order> utf16;
#else
	typedef tutf16<uint16, Sys::little> utf16le;
	typedef tutf16<uint16, Sys::big> utf16be;
	typedef tutf16<uint16, Sys::compilation_byte_order> utf16;
#endif

}}}

#endif // FURROVINEUTF16_H 