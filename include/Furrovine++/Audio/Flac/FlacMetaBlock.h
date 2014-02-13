#pragma once

#include <Furrovine++/Declarations.h>
#include <Furrovine++/Audio/Flac/FlacMetaId.h>

namespace Furrovine { namespace Audio { namespace Flac {

	struct FlacMetaBlock {
	public:
		ulword Data;

		furrovineapi bool Last( );

		furrovineapi FlacMetaId Meta( );

		furrovineapi lword Size( );

		furrovineapi void Read( IO::FlacReader& reader );
	};

}}}
