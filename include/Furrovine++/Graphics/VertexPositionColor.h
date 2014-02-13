#pragma once

#include <Furrovine++/Vector3.h>
#include <Furrovine++/Color.h>
#include <Furrovine++/Graphics/EmptyVertex.h>

namespace Furrovine { namespace Graphics {

	struct VertexPositionColor : public EmptyVertex {
	public:
		furrovineapi static const ulword Stride = sizeof(Vector3) + sizeof(Color);
		furrovineapi static const VertexDeclaration& Declaration( );

		Vector3 position;
		Color color;

		furrovineapi VertexPositionColor ();
	};

}}
