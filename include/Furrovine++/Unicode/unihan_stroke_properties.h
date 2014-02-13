#pragma once

#include <Furrovine++/buffer_view.h>

namespace Furrovine{ namespace Unicode {

	struct unihan_stroke_properties {
		buffer_view<const char> kRSAdobe_Japan1_6;
		buffer_view<const char> kRSUnicode;
		buffer_view<const char> kRSJapanese;
		buffer_view<const char> kRSKanWa;
		buffer_view<const char> kRSKangXi;
		buffer_view<const char> kRSKorean;
		buffer_view<const char> kRSMerged;
		
	};

}}