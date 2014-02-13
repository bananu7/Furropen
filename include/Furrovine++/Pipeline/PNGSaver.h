#pragma once

#include <Furrovine++/Graphics/Declarations.Graphics.h>
#include <Furrovine++/Declarations.h>

namespace Furrovine { namespace Pipeline {

	struct PNGSaver {

		furrovineapi void operator()( const Graphics::Image2D& data, const String& file );
		furrovineapi void operator()( const Graphics::Image2D& data, IO::Stream& stream );

	};

}}