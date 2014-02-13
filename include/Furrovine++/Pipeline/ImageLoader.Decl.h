#pragma once

#include <Furrovine++/Graphics/Image2D.h>
#include <Furrovine++/Strings.h>

namespace Furrovine { namespace Pipeline {

	struct ImageLoader {
		bool Decompress;

		furrovineapi ImageLoader ( bool decompress = false );

		furrovineapi std::vector<Graphics::Image2D> Load( const String& path );
		furrovineapi std::vector<Graphics::Image2D> operator () ( const String& path );

		furrovineapi std::vector<Graphics::Image2D> Load( IO::Stream& stream );
		furrovineapi std::vector<Graphics::Image2D> operator () ( IO::Stream& stream );

	};

}}
