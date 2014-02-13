#pragma once

#include <Furrovine++/Graphics/Image.h>

namespace Furrovine { namespace Pipeline {

	class JPGLoader {
	public:
		
		furrovineapi Graphics::Image2D Load ( IO::Stream& reader );
		furrovineapi Graphics::Image2D Load ( IO::ByteReader& reader );
		furrovineapi Graphics::Image2D operator() ( IO::Stream& reader );
		furrovineapi Graphics::Image2D operator() ( IO::ByteReader& reader );

	};

}}