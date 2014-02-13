#pragma once

#include <Furrovine++/Vector2.h>
#include <Furrovine++/Vector3.h>
#include <Furrovine++/Colors.h>
#include <Furrovine++/Graphics/EmptyVertex.h>

namespace Furrovine { namespace Graphics {

	struct VertexPositionColorTextureNormalBinormalTangent : public EmptyVertex {
	public:
		furrovineapi static const ulword Stride = sizeof(Vector3) * 4 + sizeof(Vector2) + sizeof(Color);
		furrovineapi static const VertexDeclaration& Declaration( );

		Vector3 position;
		Color color;
		Vector2 texture;
		Vector3 normal;
		Vector3 binormal;
		Vector3 tangent;

		furrovineapi VertexPositionColorTextureNormalBinormalTangent ();
	};

}}
