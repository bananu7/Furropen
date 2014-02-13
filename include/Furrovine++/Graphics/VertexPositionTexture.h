#pragma once

#include <Furrovine++/Vector2.h>
#include <Furrovine++/Vector3.h>
#include <Furrovine++/Graphics/EmptyVertex.h>

namespace Furrovine { namespace Graphics {

	struct VertexPositionTexture : public EmptyVertex {
	public:
		furrovineapi static const ulword Stride = sizeof(Vector3) + sizeof(Vector2);
		furrovineapi static const VertexDeclaration& Declaration( );

		Vector3 position;
		Vector2 texture;

		furrovineapi VertexPositionTexture ();

		furrovineapi VertexPositionTexture ( const Vector3& pos, const Vector2& tex );
	};

}}
