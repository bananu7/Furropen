#pragma once

#include <Furrovine++/buffer_view.h>

namespace Furrovine{ namespace Unicode {

	struct unihan_index_properties {
	public:
		buffer_view<const char> kGSR;
		buffer_view<const char> kFennIndex;
		buffer_view<const char> kCheungBauerIndex;
		buffer_view<const char> kCowles;
		buffer_view<const char> kNelson;
		buffer_view<const char> kSBGY;
		buffer_view<const char> kHanYu;
		buffer_view<const char> kCheungBauer;
		buffer_view<const char> kDaeJaweon;
		buffer_view<const char> kKangXi;
		buffer_view<const char> kAlternateKangXi;
		buffer_view<const char> kAlternateJEF;
		buffer_view<const char> kAlternateHanYu;
		buffer_view<const char> kMorohashi;
		buffer_view<const char> kAlternateMorohashi;
		buffer_view<const char> kMatthews;
		buffer_view<const char> kKarlgren;

	};

}}