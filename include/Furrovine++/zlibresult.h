#pragma once

#include <zlib.h>

namespace Furrovine {

	enum class zlibresult {
		OK           = 0,
		STREAM_END   = 1,
		NEED_DICT    = 2,
		ERRNO       = (-1),
		STREAM_ERROR = (-2),
		DATA_ERROR  = (-3),
		MEM_ERROR   = (-4),
		BUF_ERROR   = (-5),
		VERSION_ERROR = (-6),
	};

}
