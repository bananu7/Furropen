#pragma once

#include <Furrovine++/Graphics/Image2D.h>

namespace Furrovine { namespace Pipeline {

	class PCXLoader {
	public:

		furrovineapi Graphics::Image2D Load( IO::Stream& stream );
		furrovineapi Graphics::Image2D Load( IO::ByteReader& reader );
		furrovineapi Graphics::Image2D operator()( IO::Stream& stream );
		furrovineapi Graphics::Image2D operator()( IO::ByteReader& reader );
	
	};

}}
