#pragma once

#include <Furrovine++/buffer_view.h>

namespace Furrovine { namespace Unicode {
	
	struct unihan_mapping_properties {
	public:
		buffer_view<const char> kXHC1983;
		buffer_view<const char> kBigFive;
		buffer_view<const char> kIBMJapan;
		buffer_view<const char> kJIS0213;
		buffer_view<const char> kJis0;
		buffer_view<const char> kJis1;
		buffer_view<const char> kKPS0;
		buffer_view<const char> kKPS1;
		buffer_view<const char> kKSC0;
		buffer_view<const char> kKSC1;
		buffer_view<const char> kPseudoGB1;
		buffer_view<const char> kMainlandTelegraph;
		buffer_view<const char> kTaiwanTelegraph;
		buffer_view<const char> kGB0;
		buffer_view<const char> kGB1;
		buffer_view<const char> kGB5;
		buffer_view<const char> kGB7;
		buffer_view<const char> kGB8;
		buffer_view<const char> kXerox;
		buffer_view<const char> kHKSCS;
	};

}}