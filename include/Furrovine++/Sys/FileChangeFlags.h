#pragma once

#include <Furrovine++/Enums.h>

namespace Furrovine { namespace Sys {
	
	enum class FileChangeFlags {
		None = 0x0,
		Created = 0x1,
		Modified = 0x2,
		Deleted = 0x4,
		Renamed = 0x8
	};
	
	enumflagoperators( FileChangeFlags );

}}
