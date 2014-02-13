#pragma once

#include <initializer_list>
#include <Furrovine++/Unicode/script_t.h>

namespace Furrovine { namespace Unicode {

	struct script_properties {
	public:
		std::initializer_list<script_t> script_extensions;
		script_t script;
	};

}}