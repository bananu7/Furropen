#pragma once

#include <Furrovine++/buffer_view.h>

namespace Furrovine { namespace Unicode {

	struct block {
	public:
		buffer_view<const char> name;
		unsigned int first;
		unsigned int last;
	};

}}