#pragma once

#include <initializer_list>
#include <Furrovine++/buffer_view.h>
#include <Furrovine++/character_def.h>

namespace Furrovine { namespace Unicode {

	struct standardized_variant {
	public:
		std::initializer_list<const codepoint> codepoints;
		buffer_view<const char> description;
		buffer_view<const char> when;

	};

}}