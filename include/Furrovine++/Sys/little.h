#pragma once

#include <Furrovine++/Sys/ByteOrderUnit.h>

namespace Furrovine { namespace Sys {

	struct little : public ByteOrderUnit<0, 1, 0, 1, 2, 3, 0, 1, 2, 3, 4, 5, 6, 7>  {

	};

}}
