#pragma once

#include <Furrovine++/character_def.h>
#include <Furrovine++/Unicode/bidirectional_class_t.h>
#include <Furrovine++/Unicode/bidirectional_paired_bracket_type_t.h>

namespace Furrovine { namespace Unicode {

	struct bidirectional_properties {
	public:
		codepoint matching_bidirectional_paired_bracket;
		codepoint bidirectional_mirrored_glyph;
		bidirectional_class_t bidirectional_class;
		bidirectional_paired_bracket_type_t bidirectional_paired_bracket_type;
		bool bidirectional_control : 1;
		bool bidirectional_mirrored : 1;
	};

}}