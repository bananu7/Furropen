#pragma once

#include <Furrovine++/Graphics/ModelMaterialCollection.h>
#include <Furrovine++/Graphics/ModelBoneCollection.h>
#include <Furrovine++/Graphics/MeshDescription.Decl.h>
#include <Furrovine++/Graphics/NamedImage2D.h>

namespace Furrovine { namespace Graphics {

	struct ModelDescription {

		String Name;
		ModelMaterialCollection Materials;
		std::vector<NamedImage2D> Textures;
		BoundingBox Box;
		std::vector<MeshDescription> Meshes;

		furrovineapi ModelDescription ();

		furrovineapi ModelDescription ( ModelDescription&& mov );

	};

}}
