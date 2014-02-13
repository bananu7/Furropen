#pragma once

#include <Furrovine++/Declarations.h>
#include <Furrovine++/Graphics/Declarations.Graphics.h>

namespace Furrovine { namespace Pipeline {

	struct JPGSaver {

		bool optimizehuffmantables = true;
		int qualityfactor = 100;
		int comps = 1;
		int subsampling = -1;

		furrovineapi void operator()( const Graphics::Image2D& data, const String& name );
		furrovineapi void operator()( const Graphics::Image2D& data, IO::Stream& stream );

	};

}}
