#pragma once

#include <Furrovine++/Text/RasterFont.h>
#include <Furrovine++/Text/RasterFontData.h>
#include <Furrovine++/Text/RasterFontDescription.h>

namespace Furrovine { namespace Pipeline {

	struct RasterFontLoader {

		Graphics::GraphicsDevice& graphicsdevice;

		furrovineapi RasterFontLoader( Graphics::GraphicsDevice& graphics );

		furrovineapi Text::RasterFont operator()( const Text::RasterFontDescription& desc ) const;
		furrovineapi Text::RasterFont operator()( const Text::RasterFontData& desc ) const;

	};

}}