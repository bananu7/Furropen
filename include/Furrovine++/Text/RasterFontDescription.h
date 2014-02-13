#pragma once

#include <Furrovine++/std_defines.h>
#include <unordered_map>
#include <vector>
#include <Furrovine++/optional.h>
#include <Furrovine++/Strings.h>
#include <Furrovine++/Text/CharacterRange.h>
#include <Furrovine++/Text/FontStyle.h>
#include <Furrovine++/Text/FontTraits.h>
#include <Furrovine++/Text/FontWeight.h>
#include <Furrovine++/make_vector.h>

namespace Furrovine { namespace Text {

	struct RasterFontDescription {
		String Name;
		float Size;
		FontStyle Style;
		FontTraits Traits;
		FontWeight Weight;
		std::vector<CharacterRange> CharacterRanges;
		optional<codepoint> DefaultCharacter;
		float CharacterSpacing;
		optional<float> LineSpacing;
		bool Kerning = false;

		furrovineapi RasterFontDescription( String fontname, float size,
			std::vector<CharacterRange> characters = make_vector( CharacterRange::Latin1 ),
			FontStyle style = FontStyle::Regular,
			FontWeight weight = FontWeight::Normal,
			FontTraits traits = FontTraits::None,
			optional<codepoint> defaultchar = nullopt, float characterspacing = 0.0f, optional<float> linespacing = nullopt );
	
		furrovineapi RasterFontDescription( String fontname, float size,
			FontStyle style,
			FontWeight weight,
			FontTraits traits,
			optional<codepoint> defaultchar = nullopt, float characterspacing = 0.0f, optional<float> linespacing = nullopt );
	};

}}
