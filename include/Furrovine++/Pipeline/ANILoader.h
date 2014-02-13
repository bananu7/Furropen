#pragma once

#include <Furrovine++/Pipeline/CurIcoLoader.h>
#include <Furrovine++/Pipeline/PNGLoader.h>

namespace Furrovine { namespace Pipeline {

	struct ANILoader {
		
		furrovineapi ANILoader ( );

		furrovineapi Graphics::Image Load ( IO::Stream& stream );
		furrovineapi Graphics::Image Load ( IO::ByteReader& reader );
		furrovineapi Graphics::Image operator() ( IO::Stream& stream );
		furrovineapi Graphics::Image operator() ( IO::ByteReader& reader );
	};

}}
