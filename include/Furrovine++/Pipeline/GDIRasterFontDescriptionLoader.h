#pragma once

#include <Furrovine++/Text/RasterFontDescription.h>
#include <Furrovine++/Text/RasterFontData.h>

namespace Furrovine { namespace Pipeline {

	struct GDIRasterFontDescriptionLoader {
	public:
		bool Kerning;
		
		furrovineapi GDIRasterFontDescriptionLoader( bool kerning = true );

		furrovineapi Text::RasterFontData operator ( ) ( const Text::RasterFontDescription& info ) const;
		furrovineapi Text::RasterFontData operator ( ) ( Text::RasterFontDescription&& info ) const;

	private:
		furrovineapi void Load( Text::RasterFontData& data ) const;
	};

}}
