#pragma once

#include <Furrovine++/Enums.h>

namespace Furrovine { namespace Graphics {

	enum class ShaderBufferFlags {
		None = 0x0,
		Userpacked = 0x1,
	};

	enumflagoperators( ShaderBufferFlags );

}}