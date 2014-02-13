#pragma once

#include <Furrovine++/buffer_view.h>

namespace Furrovine { namespace Unicode { 

	struct unihan_variant_properties {
	public:
		buffer_view<const char> kSemanticVariant;
		buffer_view<const char> kSimplifiedVariant;
		buffer_view<const char> kSpecializedSemanticVariant;
		buffer_view<const char> kTraditionalVariant;
		buffer_view<const char> kCompatabilityVariant;
		buffer_view<const char> kZVariant;
	};

}}