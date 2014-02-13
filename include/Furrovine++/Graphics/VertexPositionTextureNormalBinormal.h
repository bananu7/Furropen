#pragma once

#include <Furrovine++/Vector2.h>
#include <Furrovine++/Vector3.h>
#include <Furrovine++/Graphics/EmptyVertex.h>

namespace Furrovine { namespace Graphics {

	struct VertexPositionTextureNormalBinormal : public EmptyVertex {
	public:
		furrovineapi static const ulword Stride = sizeof(Vector3) * 3 + sizeof( Vector2 );
		furrovineapi static const VertexDeclaration& Declaration( );

		Vector3 position;
		Vector2 texture;
		Vector3 normal;
		Vector3 binormal;

		furrovineapi VertexPositionTextureNormalBinormal ();
	};

}}
