#pragma once

#include <Furrovine++/Vector3.h>
#include <Furrovine++/Graphics/EmptyVertex.h>

namespace Furrovine { namespace Graphics {

	struct VertexPositionNormal : public EmptyVertex {
	public:
		furrovineapi static const ulword Stride = sizeof(Vector3) * 2;
		furrovineapi static const VertexDeclaration& Declaration( );

		Vector3 position;
		Vector3 normal;

		furrovineapi VertexPositionNormal ();
	};

}}
