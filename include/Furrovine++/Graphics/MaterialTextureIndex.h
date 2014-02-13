#pragma once

#include <Furrovine++/PrimitiveTypes.h>

namespace Furrovine { namespace Graphics {

	enum class MaterialTextureIndex {
		Diffuse,
		DiffuseFactor,
		Emissive,
		EmissiveFactor,
		Ambient,
		AmbientFactor,
		Specular,
		SpecularFactor,
		ShininessExponent,
		Shininess = ShininessExponent,
		NormalMap,
		Bump,
		Alpha,
		AlphaFactor,
		Reflection,
		ReflectionFactor,
		Displacement,
		VectorDisplacement,
		Decal = VectorDisplacement,
	};

	inline furrovineapi ulword ToIndex ( MaterialTextureIndex index ) {
		return (ulword)index;
	}

	inline furrovineapi MaterialTextureIndex ToMaterialTextureIndex ( ulword index ) {
		return (MaterialTextureIndex)index;
	}

	struct MaterialTextureIndices {

		furrovineapi static const ulword Count = 18;

	};

}}
