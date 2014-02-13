#pragma once

namespace Furrovine { namespace Graphics {

	enum class UnorderedAccessViewDimension {
		Unknown,
		Buffer,
		Texture1D,
		Texture1DArray,
		Texture2D,
		Texture2DArray,
		Texture2DMS,
		Texture2DMSArray
	};

}}