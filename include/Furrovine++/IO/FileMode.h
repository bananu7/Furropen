#pragma once

#include <Furrovine++/FurrovineApi.h>
#include <Furrovine++/std_defines.h>
#include <array>
#include <Furrovine++/Enums.h>
#include <Furrovine++/IO/FileAccess.h>

namespace Furrovine { namespace IO {
	
	enum class FileMode {
		None = 0x00,
		Open = 0x01,
		Create = 0x02,
		Truncate = 0x04,
		Append = 0x08,
		AtEnd = 0x10,
		OpenOrCreate = Open | Create,
	};
	
	enumflagoperators( FileMode );

}}
