#pragma once

#include <Furrovine++/Platform.Text.h>
#include <Furrovine++/Text/FontStyle.h>
#include <Furrovine++/Text/FontStretch.h>
#include <Furrovine++/Text/FontWeight.h>
#include <Furrovine++/Export.h>
#include <Furrovine++/make_array.h>

namespace Furrovine { namespace Text { namespace Dw {

	enum class FontStyle {
		None = DWRITE_FONT_STYLE_NORMAL,
		Oblique = DWRITE_FONT_STYLE_OBLIQUE,
		Italic = DWRITE_FONT_STYLE_ITALIC
	};

	enum class FontStretch {
		Any = DWRITE_FONT_STRETCH_UNDEFINED,
		UltraCondensed = DWRITE_FONT_STRETCH_ULTRA_CONDENSED,
		ExtraCondensed = DWRITE_FONT_STRETCH_EXTRA_CONDENSED,
		Condensed = DWRITE_FONT_STRETCH_CONDENSED,
		SemiCondensed = DWRITE_FONT_STRETCH_SEMI_CONDENSED,
		Normal = DWRITE_FONT_STRETCH_NORMAL,
		Medium = DWRITE_FONT_STRETCH_MEDIUM,
		SemiExpanded = DWRITE_FONT_STRETCH_SEMI_EXPANDED,
		Expanded = DWRITE_FONT_STRETCH_EXPANDED,
		ExtraExpanded = DWRITE_FONT_STRETCH_EXTRA_EXPANDED,
		UltraExpanded = DWRITE_FONT_STRETCH_ULTRA_EXPANDED
	};

	enum class FontWeight {
		Thin = DWRITE_FONT_WEIGHT_THIN,
		ExtraLight = DWRITE_FONT_WEIGHT_EXTRA_LIGHT,
		UltraLight = DWRITE_FONT_WEIGHT_ULTRA_LIGHT,
		Light = DWRITE_FONT_WEIGHT_LIGHT,
		SemiLight = DWRITE_FONT_WEIGHT_SEMI_LIGHT,
		Normal = DWRITE_FONT_WEIGHT_NORMAL,
		Regular = DWRITE_FONT_WEIGHT_REGULAR,
		Medium = DWRITE_FONT_WEIGHT_MEDIUM,
		DemiBold = DWRITE_FONT_WEIGHT_DEMI_BOLD,
		SemiBold = DWRITE_FONT_WEIGHT_SEMI_BOLD,
		Bold = DWRITE_FONT_WEIGHT_BOLD,
		ExtraBold = DWRITE_FONT_WEIGHT_EXTRA_BOLD,
		UltraBold = DWRITE_FONT_WEIGHT_ULTRA_BOLD,
		Black = DWRITE_FONT_WEIGHT_BLACK,
		Heavy = DWRITE_FONT_WEIGHT_HEAVY,
		ExtraBlack = DWRITE_FONT_WEIGHT_EXTRA_BLACK,
		UltraBlack = DWRITE_FONT_WEIGHT_ULTRA_BLACK
	};

	inline furrovineapi FontStretch ToPlatform( Text::FontStretch value ) {
		return enum_cast<FontStretch>( value );
	}

	inline furrovineapi FontStyle ToPlatform( Text::FontStyle value ) {
		const static auto platformlookup = make_array(
			FontStyle::None,
			FontStyle::Oblique,
			FontStyle::Italic
		);
		return accumulate_flags( value, platformlookup );
	}

	inline furrovineapi FontWeight ToPlatform( Text::FontWeight fontstretch ) {
		return enum_cast<FontWeight>( fontstretch );
	}

	template <typename T, typename TValue, typename... Tn>
	auto FromPlatform( TValue value, Tn&&... argn ) -> decltype( FromPlatform( static_cast<T>( value ), std::forward<Tn>( argn )... ) ) {
		return FromPlatform( static_cast<T>( value ), std::forward<Tn>( argn )... );
	}

	template <typename T, typename TValue, typename... Tn>
	auto ToPlatform( TValue value, Tn&&... argn ) -> decltype( static_cast<T>( ToPlatform( value, std::forward<Tn>( argn )... ) ) ) {
		return static_cast<T>( ToPlatform( value, std::forward<Tn>( argn )... ) );
	}

}}}