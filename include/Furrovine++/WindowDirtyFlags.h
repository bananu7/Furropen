#pragma once

#include <Furrovine++/Enums.h>

namespace Furrovine {
	
	enum class WindowDirtyFlags {
		None = 0x00,
		Title = 0x01,
		Size = 0x02,
		Mode = 0x04,
		Position = 0x08,
		Style = 0x10,
		State = 0x20,
		Cursor = 0x40,
		All = Title | Size | Mode | Position | Style | State | Cursor,
	};

	enumflagoperators( WindowDirtyFlags );
	
}
