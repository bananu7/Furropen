#pragma once

#include <Furrovine++/std_defines.h>
#include <cstdio>
#include <Furrovine++/Export.h>

namespace Furrovine { namespace IO {

	struct ReleaseFILE {
		furrovineapi void operator() ( FILE* ptr ) const;
	};

}}
