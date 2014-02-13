#pragma once

#include <Furrovine++/Enums.h>

namespace Furrovine { namespace Audio {

	enum class AudioBufferFlags {
		None = 0x00,
		StreamEnd = 0x01,
	};


	enumflagoperators( AudioBufferFlags );
}}