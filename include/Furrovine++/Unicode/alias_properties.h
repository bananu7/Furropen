#pragma once

#include <initializer_list>
#include <Furrovine++/Unicode/alias.h>

namespace Furrovine { namespace Unicode {

	struct alias_properties {
	public:
		std::initializer_list<const alias> aliases;
	};

}}