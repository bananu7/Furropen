#pragma once

#include <Furrovine++/Vector2.h>
#include <Furrovine++/Vector3.h>
#include <Furrovine++/Region.h>

namespace Furrovine { namespace Text {

	struct RasterGlyph {
		codepoint Character;
		Region Source;
		Region Cropping;
		Vector3 Kerning;
		Vector2 Size;

		furrovineapi float LeftBearing( ) const;

		furrovineapi float RightBearing( ) const;

		furrovineapi float Width( ) const;

		furrovineapi float GlyphWidth( ) const;
	};

}}
