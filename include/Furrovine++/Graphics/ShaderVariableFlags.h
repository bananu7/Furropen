#pragma once

#include <Furrovine++/Enums.h>

namespace Furrovine { namespace Graphics {

	enum class ShaderVariableFlags {
		None = 0,
		Userpacked = 0x01,
		Used = 0x02,
		InterfacePointer = 0x04,
		InterfaceParameter = 0x08,
	};

	enumflagoperators( ShaderVariableFlags );

}}
