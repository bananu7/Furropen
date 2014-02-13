#pragma once

#include <Furrovine++/Vector2.h>
#include <Furrovine++/Vector3.h>
#include <Furrovine++/Color.h>
#include <Furrovine++/Graphics/EmptyVertex.h>

namespace Furrovine { namespace Graphics {

	struct VertexImageQuad : public EmptyVertex {
	public:
		furrovineapi static const VertexDeclaration& Declaration( );
		furrovineapi static const ulword Stride = sizeof( Vector3 ) + sizeof( Vector2 ) + sizeof( Color );

		Vector3 position;
		Color color;
		Vector2 texture;

	};

}}
