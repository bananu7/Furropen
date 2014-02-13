#pragma once

#include <Furrovine++/buffer_view.h>

namespace Furrovine { namespace Unicode {

	struct iso_properties {
	public:
		buffer_view<const char> iso_comment;
	};

}}