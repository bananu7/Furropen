#pragma once

namespace Furrovine { namespace Graphics {

	enum class ShaderResourceViewDimension {
		Unknown,
		Buffer,
		Texture1D,
		Texture1DArray,
		Texture2D,
		Texture2DArray,
		Texture2DMultiSampled,
		Texture2DMultiSampledArray,
		Texture3D,
		TextureCube,
		TextureCubeArray,
		BufferExtended,
	};

}}
