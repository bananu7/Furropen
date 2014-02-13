#pragma once

#include <Furrovine++/Graphics/Bone.h>
#include <Furrovine++/Collections/IndexableDictionary.h>

namespace Furrovine { namespace Graphics {

	class ModelBoneCollection : public Collections::IndexableDictionary<String, Bone> {
	public:
		furrovineapi ModelBoneCollection ( );

		furrovineapi ModelBoneCollection ( const ModelBoneCollection& copy );

		furrovineapi ModelBoneCollection ( ModelBoneCollection&& mov );

		furrovineapi ModelBoneCollection& operator= ( const ModelBoneCollection& copy );

		furrovineapi ModelBoneCollection& operator= ( ModelBoneCollection&& mov );

	};

}}
