#pragma once

#include <Furrovine++/Vector3.h>
#include <Furrovine++/Graphics/WindingOrder.h>
#include <Furrovine++/Graphics/PrimitiveTopology.h>

namespace Furrovine { namespace Graphics {

	struct Primitives {

		furrovineapi static WindingOrder TriangleWinding ( Vector3 v1, Vector3 v2, Vector3 v3, Vector3 normal );

		furrovineapi static void TriangleWinding ( Vector3& v1, Vector3& v2, Vector3& v3, Vector3& normal, WindingOrder& winding );

		furrovineapi static uint32 VertexCount ( PrimitiveTopology primitive, uint32 primitivecount );

		furrovineapi static void VertexCount ( PrimitiveTopology primitive, uint32 primitivecount, uint32& vertexcount );

		furrovineapi static uint32 PrimitiveCount ( PrimitiveTopology primitive, uint32 vertexcount );

		furrovineapi static void PrimitiveCount ( PrimitiveTopology primitive, uint32 vertexcount, uint32& primitivecount );
	};

}}
