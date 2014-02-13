#pragma once

#include <Furrovine++/Vector2.h>
#include <Furrovine++/Vector3.h>
#include <Furrovine++/Graphics/EmptyVertex.h>
#include <Furrovine++/Graphics/VertexDeclaration.h>

namespace Furrovine { namespace Graphics {

	struct VertexPositionTextureNormalBinormalTangent : public EmptyVertex {
	public:
		furrovineapi static const ulword Stride = sizeof(Vector3) * 4 + sizeof(Vector2);
		furrovineapi static const VertexDeclaration& Declaration( );

		Vector3 position;
		Vector2 texture;
		Vector3 normal;
		Vector3 binormal;
		Vector3 tangent;

		furrovineapi VertexPositionTextureNormalBinormalTangent ();
	};

}}
