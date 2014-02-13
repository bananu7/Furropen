#pragma once

#include <Furrovine++/buffer_view.h>

namespace Furrovine { namespace Unicode {
	
	struct unihan_dictionary_properties {
	public:
		buffer_view<const char> kPhonetic;
		buffer_view<const char> kCihaiT;
		buffer_view<const char> kFenn;
		buffer_view<const char> kFourCornerCode;
		buffer_view<const char> kTotalStrokes;
		buffer_view<const char> kHKGlyph;
		buffer_view<const char> kHDZRadBreak;
		buffer_view<const char> kGradeLevel;
		buffer_view<const char> kFrequency;
		buffer_view<const char> kCangjie;

	};


}}