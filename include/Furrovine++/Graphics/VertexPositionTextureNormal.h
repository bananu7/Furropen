#pragma once

#include <Furrovine++/Vector2.h>
#include <Furrovine++/Vector3.h>
#include <Furrovine++/Graphics/EmptyVertex.h>

namespace Furrovine { namespace Graphics {

	struct VertexPositionTextureNormal : public EmptyVertex {
	public:
		furrovineapi static const ulword Stride = sizeof(Vector3) * 2 + sizeof(Vector2);
		furrovineapi static const VertexDeclaration& Declaration( );

		Vector3 position;
		Vector2 texture;
		Vector3 normal;

		furrovineapi VertexPositionTextureNormal ();

		furrovineapi VertexPositionTextureNormal ( const Vector3& pos, const Vector2& tex, const Vector3& norm );
	};

}}
