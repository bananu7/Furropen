#pragma once

namespace Furrovine { namespace Graphics {

	enum class TextureFilter {
		Point,
		Linear,
		Anisotropic,
		MinPointMagLinearMipPoint,
		MinLinearMagPointMipLinear,
		MinMagPointMipLinear,
		MinMagLinearMipPoint,
		Default = Linear,
	};

}}
