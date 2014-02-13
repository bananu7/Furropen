#pragma once

namespace Furrovine { namespace Graphics {
	
	enum class BlendFactor {
		Zero,
		One,
		SourceColor,
		InverseSourceColor,
		SourceAlpha,
		InverseSourceAlpha,
		DestinationAlpha,
		InverseDestinationAlpha,
		DestinationColor,
		InverseDestinationColor,
		SourceAlphaClamped,
		Manual,
		InverseManual,
		PixelShaderSourceColor,
		InversePixelShaderSourceColor,
		PixelShaderSourceAlpha,
		InversePixelShaderSourceAlpha
	};
	
}}
