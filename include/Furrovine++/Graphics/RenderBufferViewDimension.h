#pragma once

namespace Furrovine { namespace Graphics {

	enum class RenderBufferViewDimension {
		Unknown,
		Buffer,
		Texture1D,
		Texture1DArray,
		Texture2D,
		Texture2DArray,
		Texture2DMS,
		Texture2DMSArray,
		Texture3D,
	};

}}