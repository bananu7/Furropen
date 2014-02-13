#pragma once

#include <Furrovine++/buffer_view.h>

namespace Furrovine { namespace Unicode {

	struct cjk_radical {
	public:
		buffer_view<const char> number;
		codepoint radical;
		codepoint ideograph;
	};

}}