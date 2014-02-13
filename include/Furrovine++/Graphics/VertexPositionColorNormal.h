#pragma once

#include <Furrovine++/Vector3.h>
#include <Furrovine++/Color.h>
#include <Furrovine++/Graphics/EmptyVertex.h>

namespace Furrovine { namespace Graphics {

	struct VertexPositionColorNormal : public EmptyVertex {
	public:
		furrovineapi static const ulword Stride = sizeof(Vector3) * 2 + sizeof(Color);
		furrovineapi static const VertexDeclaration& Declaration( );

		Vector3 position;
		Color color;
		Vector3 normal;

		furrovineapi VertexPositionColorNormal ();
	};

}}
