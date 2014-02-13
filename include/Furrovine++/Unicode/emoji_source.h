#pragma once

#include <Furrovine++/character_def.h>
#include <Furrovine++/buffer_view.h>

namespace Furrovine { namespace Unicode {

	struct emoji_source {
	public:
		std::initializer_list<const codepoint> unicode;
		buffer_view<const char> docomo;
		buffer_view<const char> kddi;
		buffer_view<const char> softbank;
	};

}}