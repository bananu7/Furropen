#pragma once

#include <Furrovine++/character_def.h>

namespace Furrovine { namespace Unicode {

	template <typename T>
	struct ucd_group {
		codepoint first;
		codepoint last;
		T properties;
	};

}}