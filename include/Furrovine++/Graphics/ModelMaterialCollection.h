#pragma once

#include <Furrovine++/Graphics/Material.h>
#include <Furrovine++/Collections/IndexableDictionary.h>

namespace Furrovine { namespace Graphics {

	class ModelMaterialCollection : public Collections::IndexableDictionary<String, Material> {
	public:
		using IndexableDictionary::insert;

		furrovineapi ModelMaterialCollection ( );

		furrovineapi ModelMaterialCollection( const ModelMaterialCollection& copy );
		furrovineapi ModelMaterialCollection( ModelMaterialCollection&& mov );
		furrovineapi ModelMaterialCollection& operator=( const ModelMaterialCollection& copy );
		furrovineapi ModelMaterialCollection& operator=( ModelMaterialCollection&& mov );

		furrovineapi void insert ( const Material& material );

		furrovineapi void insert ( const ModelMaterialCollection& materialcollection );

	};

}}