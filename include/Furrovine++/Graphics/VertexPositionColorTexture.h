#pragma once

#include <Furrovine++/Color.h>
#include <Furrovine++/Vector2.h>
#include <Furrovine++/Vector3.h>
#include <Furrovine++/Graphics/EmptyVertex.h>

namespace Furrovine { namespace Graphics {

	struct VertexPositionColorTexture : public EmptyVertex {
	public:
		furrovineapi static const ulword Stride = sizeof(Vector3) + sizeof(Vector2) + sizeof(Color);
		furrovineapi static const VertexDeclaration& Declaration( );

		Vector3 position;
		Color color;
		Vector2 texture;

		furrovineapi VertexPositionColorTexture ();
	};

}}
