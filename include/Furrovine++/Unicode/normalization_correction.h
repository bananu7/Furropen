#pragma once

#include <Furrovine++/character_def.h>
#include <Furrovine++/Unicode/unicode_age.h>

namespace Furrovine { namespace Unicode {

	struct normalization_correction {
	public:
		codepoint targetcodepoint;
		codepoint oldcodepoint;
		codepoint newcodepoint;
		unicode_age when;
	};

}}