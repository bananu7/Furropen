#pragma once

#include <Furrovine++/Enums.h>

namespace Furrovine { namespace Graphics {

	enum class IlluminationModel {
		Diffuse = 0x0001,
		Ambience = 0x0002,
		Specular = 0x0004,
		Emission = 0x0008,
		Transparency = 0x0010,
		Ray = 0x0020,
		Refraction = 0x0040,
		Glass = 0x0080,
		Reflection = 0x0100,
		Fresnel = 0x0200,
		Shadows = 0x1000,
		InvisibleShadows = 0x2000,

		Zero = Diffuse,
		One = Diffuse | Ambience,
		Two = Diffuse | Ambience | Specular | Emission,
		Three = Diffuse | Ambience | Specular | Emission | Reflection | Ray,
		Four = Diffuse | Ambience | Specular | Emission | Glass | Reflection | Ray,
		Five = Diffuse | Ambience | Specular | Emission | Fresnel | Ray | Reflection,
		Six = Diffuse | Ambience | Specular | Emission | Refraction | Reflection | Ray,
		Seven = Diffuse | Ambience | Specular | Emission | Refraction | Reflection | Fresnel | Ray,
		Eight = Diffuse | Ambience | Specular | Emission | Reflection,
		Nine = Diffuse | Ambience | Specular | Emission | Transparency | Glass | Reflection,
		Ten = Diffuse | Ambience | Specular | Emission | Shadows | InvisibleShadows,

		Lambertian = Diffuse | Ambience,
		Phong = Diffuse | Ambience | Specular | Emission,
	};

	enumflagoperators( IlluminationModel );

	inline furrovineapi IlluminationModel ToIlluminationModel ( ulword index ) {
		switch (index) {
		case 0:
			return IlluminationModel::Zero;
		case 1:
			return IlluminationModel::One;
		case 2:
			return IlluminationModel::Two;
		case 3:
			return IlluminationModel::Three;
		case 4:
			return IlluminationModel::Four;
		case 5:
			return IlluminationModel::Five;
		case 6:
			return IlluminationModel::Six;
		case 7:
			return IlluminationModel::Seven;
		case 8:
			return IlluminationModel::Eight;
		case 9:
			return IlluminationModel::Nine;
		case 10:
			return IlluminationModel::Ten;
		default:
			return IlluminationModel::Two;
		}
		return IlluminationModel::Two;
	}

}}
