#pragma once

#include <Furrovine++/std_defines.h>
#include <unordered_map>
#include <Furrovine++/Strings.h>
#include <Furrovine++/optional.h>
#include <Furrovine++/Text/FontStyle.h>
#include <Furrovine++/Text/RasterGlyph.h>
#include <Furrovine++/Text/RasterFontDescription.h>
#include <Furrovine++/Graphics/Image2D.h>

namespace Furrovine { namespace Text {

	struct RasterFontData {
		RasterFontDescription Description;
		std::unordered_map<codepoint, RasterGlyph> Glyphs;
		Graphics::Image2D Raster;

		furrovineapi RasterFontData( const RasterFontDescription& desc );
		furrovineapi RasterFontData( RasterFontDescription&& desc );
		furrovineapi RasterFontData( const RasterFontData& copy ) = default;
		furrovineapi RasterFontData& operator=( const RasterFontData& copy ) = default;
		furrovineapi RasterFontData( RasterFontData && mov );
		furrovineapi RasterFontData& operator=( RasterFontData && mov );

	};

}}
