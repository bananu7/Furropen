#ifndef FURROVINESUBMESHDESCRIPTION_DECL_H
#define FURROVINESUBMESHDESCRIPTION_DECL_H

#include <Furrovine++/Strings.h>
#include <Furrovine++/BoundingBox.h>
#include <Furrovine++/Graphics/PrimitiveTopology.h>

namespace Furrovine { namespace Graphics {

	struct SubMeshDescription {

		String Name;
		BoundingBox Box;
		PrimitiveTopology VertexTopology;
		lword VertexBufferIndex;
		lword IndexBufferIndex;
		uint32 VertexOffset;
		uint32 VertexCount;
		uint32 IndexOffset;
		uint32 BaseVertex;
		uint32 IndexCount;
		uint32 PrimitiveCount;
		std::vector<String> MaterialNames;

		furrovineapi SubMeshDescription ();

		furrovineapi SubMeshDescription ( SubMeshDescription&& mov );

	};

}}

#endif // FURROVINESUBMESHDESCRIPTION_DECL_H 