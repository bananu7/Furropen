#pragma once

#include <Furrovine++/Vector2.h>
#include <Furrovine++/Vector3.h>
#include <Furrovine++/Vector4.h>
#include <Furrovine++/Graphics/EmptyVertex.h>

namespace Furrovine { namespace Graphics {

	struct VertexSkeletal {
		furrovineapi static const ulword Stride = sizeof( Vector3 ) * 2 + sizeof(Vector2) + sizeof(Vector4) + sizeof(Vector4i) + sizeof(int);
		furrovineapi static const VertexDeclaration& Declaration( );

		Vector3 position;
		Vector2 texture;
		Vector3 normal;
		Vector4i boneindices;
		Vector4 boneweights;
		int bonecount;
	};

}}
