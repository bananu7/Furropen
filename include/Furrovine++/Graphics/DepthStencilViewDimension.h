#pragma once

namespace Furrovine { namespace Graphics {

	enum class DepthStencilViewDimension {
		Unknown,
		Texture1D,
		Texture1DArray,
		Texture2D,
		Texture2DArray,
		Texture2DMS,
		Texture2DMSArray
	};

}}