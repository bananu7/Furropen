#pragma once

#include <Furrovine++/Enums.h>

namespace Furrovine { namespace Graphics {
	
	enum class CpuAccessFlags {
		None = 0,
		Readable = 0x01,
		Writable = 0x02,
		ReadWritable = Readable | Writable,
		Default = None
	};

	enumflagoperators(CpuAccessFlags);

}}
 