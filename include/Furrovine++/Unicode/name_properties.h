#pragma once

#include <Furrovine++/buffer_view.h>

namespace Furrovine { namespace Unicode {

	struct name_properties {
	public:
		buffer_view<const char> name;
		buffer_view<const char> legacy_name;
		bool substitution : 1;
	};

}}