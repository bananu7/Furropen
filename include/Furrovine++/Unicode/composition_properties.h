#pragma once

#include <initializer_list>
#include <Furrovine++/character_def.h>
#include <Furrovine++/Unicode/decomposition_type.h>

namespace Furrovine { namespace Unicode {

	struct composition_properties {
	public:
		std::initializer_list<const codepoint> decomposition_mapping;
		std::initializer_list<const codepoint> compatability_decomposition_mapping;
		decomposition_type decomposition;
		bool exclusion;
		bool composition_exclusion;
		bool full_composition_exclusion;

	};

}}