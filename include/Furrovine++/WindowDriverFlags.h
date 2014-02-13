#pragma once

#include <Furrovine++/Enums.h>

namespace Furrovine {

	enum class WindowDriverFlags {
		None = 0x00,
		AlwaysReceiveInput = 0x01,
		AllowLegacyInput = 0x02,
		OnlyLegacyInput = 0x04,
		CaptureMouse = 0x08,
		Default = AlwaysReceiveInput | AllowLegacyInput,
	};

	enumflagoperators( WindowDriverFlags );

}