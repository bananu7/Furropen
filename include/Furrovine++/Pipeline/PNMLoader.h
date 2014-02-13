#pragma once

#include <Furrovine++/Pipeline/PPMLoader.h>
#include <Furrovine++/Pipeline/PPMALoader.h>

namespace Furrovine { namespace Pipeline {
	
	class PNMLoader {
	public:
		
		furrovineapi Graphics::Image2D Load ( IO::Stream& stream );
		furrovineapi Graphics::Image2D Load ( IO::ByteReader& reader );
		furrovineapi Graphics::Image2D operator() ( IO::Stream& stream );
		furrovineapi Graphics::Image2D operator() ( IO::ByteReader& reader );

	};
	
}}
