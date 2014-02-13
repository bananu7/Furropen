#pragma once

#include <Furrovine++/Vector4.h>
#include <Furrovine++/Graphics/TextureFilter.h>
#include <Furrovine++/Graphics/TextureAddress.h>
#include <Furrovine++/Comparison.h>

namespace Furrovine { namespace Graphics {

	struct SamplerStateDescription {
		TextureFilter filter;
		TextureAddress u;
		TextureAddress v;
		TextureAddress w;
		float miplodbias;
		uint maxanisotropy;
		Comparison comparisonfunction;
		Vector4 bordercolor;
		float minlod;
		float maxlod;

		furrovineapi SamplerStateDescription ( TextureFilter texturefilter = TextureFilter::Default,
		TextureAddress addressu = TextureAddress::Clamp,
		TextureAddress addressv = TextureAddress::Clamp,
		TextureAddress addressw = TextureAddress::Clamp,
		float miplodbias = 0.0f,
		uint maxanisotropy = 16,
		Comparison comparisonfunction = Comparison::Never,
		Vector4 bordercolor = Vector4::Zero,
		float minlod = -FLT_MAX,
		float maxlod = FLT_MAX );

		furrovineapi SamplerStateDescription(
			TextureAddress auvw,
			TextureFilter afilter = TextureFilter::Default,
			float amiplodbias = 0.0f,
			uint amaxanisotropy = 16,
			Comparison acomparisonfunction = Comparison::Never,
			Vector4 abordercolor = Vector4::Zero,
			float aminlod = -FLT_MAX,
			float amaxlod = FLT_MAX );


	};

}}