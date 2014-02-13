#pragma once

#include <Furrovine++/Text/Encoding/utf16.h>
#include <Furrovine++/Text/Encoding/utf32.h>

namespace Furrovine { namespace Text { namespace Encoding {

#ifdef FURROVINEWIN
	typedef utf16 wide_encoding;
#else
	typedef utf32 wide_encoding;
#endif

}}}
 