#pragma once

#include <Furrovine++/Enums.h>

namespace Furrovine { namespace IO {
	
	enum class StreamAccess {
		None = 0x00,
		Read = 0x01,
		Write = 0x02,
		Seek = 0x04,
		ReadWrite = Read | Write,
		ReadSeek = Read | Seek,
		ReadWriteSeek = Read | Write | Seek,
	};

	enumflagoperators( StreamAccess );
	
}}
