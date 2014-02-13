#pragma once

#include <Furrovine++/buffer_view.h>

namespace Furrovine { namespace Unicode {

	struct unihan_numeric_properties {
	public:
		buffer_view<const char> kOtherNumeric;
		buffer_view<const char> kAccountingNumeric;
		buffer_view<const char> kPrimaryNumeric;
	};

}}