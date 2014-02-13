#pragma once

#include <Furrovine++/Graphics/Image2D.h>

namespace Furrovine { namespace Pipeline {

	class PPMALoader {
	public:

		furrovineapi Graphics::Image2D Load (  IO::Stream& stream );
		furrovineapi Graphics::Image2D Load ( IO::TextReader& reader );
		furrovineapi Graphics::Image2D operator() (  IO::Stream& stream );
		furrovineapi Graphics::Image2D operator() ( IO::TextReader& reader );

	};

}}
