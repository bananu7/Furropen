#pragma once

#include <Furrovine++/buffer_view.h>

namespace Furrovine { namespace Unicode {
	
	struct unihan_reading_properties {
	public:
		buffer_view<const char> kLau;
		buffer_view<const char> kMeyerWempe;
		buffer_view<const char> kCantonese;
		buffer_view<const char> kHanyuPinlu;
		buffer_view<const char> kHanyuPinyin;
		buffer_view<const char> kJapaneseKun;
		buffer_view<const char> kJapaneseOn;
		buffer_view<const char> kKorean;
		buffer_view<const char> kMandarin;
		buffer_view<const char> kTang;
		buffer_view<const char> kVietnamese;
		buffer_view<const char> kEACC;
		buffer_view<const char> kCCCII;
		buffer_view<const char> kCNS1986;
		buffer_view<const char> kCNS1992;
		buffer_view<const char> kDefinition;
		buffer_view<const char> kHangul;
		buffer_view<const char> kJHJ;
		buffer_view<const char> kWubi;

	};

}}