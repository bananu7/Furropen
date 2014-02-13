#pragma once

#include <Furrovine++/Vector4.h>
#include <Furrovine++/Graphics/EmptyVertex.h>

namespace Furrovine { namespace Graphics {

	struct VertexPosition4 : public EmptyVertex {
	public:
		furrovineapi static const ulword Stride = sizeof( Vector4 );
		furrovineapi static const VertexDeclaration& Declaration( );

		Vector4 position;

		furrovineapi VertexPosition4 ();
	};

}}
