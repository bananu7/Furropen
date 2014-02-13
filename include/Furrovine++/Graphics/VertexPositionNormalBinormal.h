#pragma once

#include <Furrovine++/Vector3.h>
#include <Furrovine++/Graphics/EmptyVertex.h>

namespace Furrovine { namespace Graphics {

	struct VertexPositionNormalBinormal : public EmptyVertex {
	public:
		furrovineapi static const ulword Stride = sizeof(Vector3) * 3;
		furrovineapi static const VertexDeclaration& Declaration( );

		Vector3 position;
		Vector3 normal;
		Vector3 binormal;

		furrovineapi VertexPositionNormalBinormal ();
	};

}}
