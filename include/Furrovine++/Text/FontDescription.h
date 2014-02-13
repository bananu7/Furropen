#pragma once

#include <Furrovine++/Strings.h>
#include <Furrovine++/Text/FontStyle.h>
#include <Furrovine++/Text/FontStretch.h>
#include <Furrovine++/Text/FontWeight.h>
#include <Furrovine++/Text/FontTraits.h>

namespace Furrovine { namespace Text {

	struct FontDescription {
	public:
		String Name;
		float Size;
		FontStyle Style;
		FontWeight Weight;
		FontStretch Stretch;

		furrovineapi FontDescription(
			String Name = "Arial", float Size = 14.0f,
			FontStyle Style = FontStyle::Regular, FontWeight Weight = FontWeight::Normal,
			FontStretch Stretch = FontStretch::Regular );

	};

}}