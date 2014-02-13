#pragma once

#include <Furrovine++/Colors.h>
#include <Furrovine++/Strings.h>
#include <Furrovine++/Graphics/IlluminationModel.h>
#include <Furrovine++/Graphics/MaterialTextureIndex.h>
#include <Furrovine++/Graphics/TextureLayerIndex.h>

namespace Furrovine { namespace Graphics {

	class Material {
	protected:
		String materialname;

	public:
		furrovineapi static const Material Default;
		furrovineapi static const String DefaultMaterialName;

		std::array<TextureLayerIndex, 18> Layers;
		Color Ambience, Diffuse, Emissive, Specular;
		Vector4 Transmission;
		float Shininess, Alpha, Reflectivity;
		IlluminationModel Illumination;

		furrovineapi Material::Material ( const String& name = DefaultMaterialName, 
			Color ambience = Colors::NearBlack, Color diffuse = Colors::DarkBlue,
			Color specular = Colors::White, Color emission = Colors::Transparent, 
			float shininess = 10.0f, 
			float alpha = 1.0f, float refraction = 1.0f, 
			IlluminationModel illimunation = IlluminationModel::Two );

		furrovineapi const String& MaterialName () const;

		furrovineapi void Material::SetMaterialName ( const String& name );

		furrovineapi TextureLayerIndex& LayerAt ( MaterialTextureIndex Layer );

		furrovineapi const TextureLayerIndex& LayerAt ( MaterialTextureIndex Layer ) const;

		furrovineapi TextureLayerIndex& LayerAt ( ulword Layer );

		furrovineapi const TextureLayerIndex& LayerAt ( ulword Layer ) const;

		furrovineapi TextureLayerIndex& operator[ ] ( MaterialTextureIndex Layer );

		furrovineapi const TextureLayerIndex& operator[ ] ( MaterialTextureIndex Layer ) const;

		furrovineapi TextureLayerIndex& operator[ ] ( ulword Layer );

		furrovineapi const TextureLayerIndex& operator[ ] ( ulword Layer ) const;

	};	

}}
