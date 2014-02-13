#pragma once

#include <Furrovine++/Graphics/SubMeshDescription.Decl.h>
#include <Furrovine++/Graphics/IndexBufferData.h>
#include <Furrovine++/Graphics/VertexBufferData.h>
#include <Furrovine++/Graphics/Skeleton.h>

namespace Furrovine { namespace Graphics {

	struct MeshDescription {
		String Name;
		BoundingBox Box;
		Graphics::Skeleton MeshSkeleton;
		std::vector<VertexBufferData> VertexBuffers;
		std::vector<IndexBufferData> IndexBuffers;
		std::vector<String> MaterialNames;
		std::vector<SubMeshDescription> SubMeshes;

		furrovineapi MeshDescription ();

		furrovineapi MeshDescription ( MeshDescription&& mov );

	};

}}
 