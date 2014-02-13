#pragma once

#include <Furrovine++/Declarations.h>
#include <Furrovine++/Graphics/MaterialTextureIndex.h>
#include <Furrovine++/Graphics/ModelMaterialCollection.h>

namespace Furrovine { namespace Pipeline {

	class WavefrontMtlLoader {
	public:

		struct WavefrontMtlLoaderContext {
			Graphics::Material currentmaterial;
			bool commanded;
		};

		furrovineapi WavefrontMtlLoader ( );

		furrovineapi void Load ( IO::Stream& stream, Graphics::ModelMaterialCollection*& value );
		furrovineapi void Load ( IO::Stream& stream, ulword TextureLayerSkew, std::vector<String>& textures, Graphics::ModelMaterialCollection*& value );
		furrovineapi void Load ( IO::TextReader& stream, Graphics::ModelMaterialCollection*& value );
		furrovineapi void Load ( IO::TextReader& stream, ulword TextureLayerSkew, std::vector<String>& textures, Graphics::ModelMaterialCollection*& value );

		furrovineapi void Material ( WavefrontMtlLoaderContext& context, Graphics::ModelMaterialCollection*& value, bool lastpart = false );

	};

}}
