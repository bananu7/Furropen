#pragma once

#include <Furrovine++/FurrovineApi.h>

namespace Furrovine { namespace Graphics {
	
	enum class FeatureLevel {
		LevelDx091,
		LevelDx092,
		LevelDx093,
		LevelDx100,
		LevelDx101,
		LevelDx110,
		LevelDx111,
		LevelGl011,
		LevelGl012,
		LevelGl013,
		LevelGl014,
		LevelGl015,
		LevelGl020,
		LevelGl021,
		LevelGl030,
		LevelGl031,
		LevelGl032,
		LevelGl033,
		LevelGl040,
		LevelGl041,
		LevelGl042,
		LevelGl043,
		LevelGl044,
		Default = LevelDx111
	};
	
	inline furrovineapi ulword ToIndex ( FeatureLevel level ) {
		return static_cast<ulword>( level );
	}

}}
