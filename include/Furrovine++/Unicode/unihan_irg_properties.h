#pragma once

#include <Furrovine++/buffer_view.h>

namespace Furrovine { namespace Unicode {

	struct unihan_irg_properties {
	public:
		buffer_view<const char> kIICore;
		buffer_view<const char> kIRGDaeJaweon;
		buffer_view<const char> kIRGDaiKanwaZiten;
		buffer_view<const char> kIRGHanyuDaZidian;
		buffer_view<const char> kIRGKangXi;
		buffer_view<const char> kIRG_GSource;
		buffer_view<const char> kIRG_HSource;
		buffer_view<const char> kIRG_KPSource;
		buffer_view<const char> kIRG_KSource;
		buffer_view<const char> kIRG_MSource;
		buffer_view<const char> kIRG_TSource;
		buffer_view<const char> kIRG_USource;
		buffer_view<const char> kIRG_VSource;
	};

}}