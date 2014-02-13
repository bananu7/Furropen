#pragma once

#include <Furrovine++/Rectangle.h>

namespace Furrovine { namespace Graphics {

	struct TextureLayerIndex {
		int32 TextureIndex;
		Rectangle Source;

		furrovineapi TextureLayerIndex (  );
	};

}}
