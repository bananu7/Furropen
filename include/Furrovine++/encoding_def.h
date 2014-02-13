#pragma once

#include <Furrovine++/fixed_vector.h>
#include <Furrovine++/character_def.h>

namespace Furrovine {

	typedef fixed_vector<byte, 8> codeunit_bytes;
	typedef fixed_vector<codepoint, 4> codepoint_casing;

}