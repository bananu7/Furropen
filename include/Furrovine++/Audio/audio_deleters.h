#pragma once

#include <Furrovine++/PrimitiveTypes.h>

namespace Furrovine { namespace Audio {

	struct audio_engine_deleter {
		furrovineapi void operator () ( void* p );
	};

	struct audio_voice_deleter {
		furrovineapi void operator () ( void* p );
	};

}}