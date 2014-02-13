#pragma once

#include <initializer_list>
#include <Furrovine++/buffer_view.h>
#include <Furrovine++/character_def.h>

namespace Furrovine { namespace Unicode {

	struct named_sequence {
	public:
		std::initializer_list<const codepoint> codepoints;
		buffer_view<const char> name;
	};

}}