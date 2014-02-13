#pragma once

#include <Furrovine++/Collections/IndexableDictionary.h>
#include <Furrovine++/Graphics/TextureLayer.h>

namespace Furrovine { namespace Graphics {

	class ModelTextureCollection : public Collections::IndexableDictionary<String, Texture*> {
	public:

		furrovineapi ModelTextureCollection ( );

		furrovineapi ModelTextureCollection ( const ModelTextureCollection& copy );

		furrovineapi ModelTextureCollection ( ModelTextureCollection&& mov );

		furrovineapi ModelTextureCollection& operator= ( const ModelTextureCollection& copy );

		furrovineapi ModelTextureCollection& operator= ( ModelTextureCollection&& mov );
	};

}}
