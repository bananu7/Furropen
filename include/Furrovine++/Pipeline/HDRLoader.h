#pragma once

#include <Furrovine++/Graphics/Image2D.h>

namespace Furrovine { namespace Pipeline {

	struct HDRLoader {

		furrovineapi Graphics::Image2D operator() ( const String& path );
		furrovineapi Graphics::Image2D operator() ( IO::Stream& stream );

	};

}}