#pragma once

#include <Furrovine++/Enums.h>

namespace Furrovine { namespace IO {

	enum class FileAccess {
		None = 0x00,
		Read = 0x01,
		Write = 0x02,
		ReadWrite = Read | Write,
		Seek = 0x04,
	};

	enumflagoperators( FileAccess );

}}