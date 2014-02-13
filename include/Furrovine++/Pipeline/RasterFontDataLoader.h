#pragma once

#include <Furrovine++/Text/RasterFontDescription.h>
#include <Furrovine++/Text/RasterFontData.h>

namespace Furrovine { namespace Pipeline {

	struct RasterFontDataLoader {

		furrovineapi Text::RasterFontData operator ( ) ( const Text::RasterFontDescription& info ) const;

	};

}}