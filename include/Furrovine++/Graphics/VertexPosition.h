#pragma once

#include <Furrovine++/Vector3.h>
#include <Furrovine++/Graphics/EmptyVertex.h>

namespace Furrovine { namespace Graphics {

	struct VertexPosition : public EmptyVertex {
	public:
		furrovineapi static const ulword Stride = sizeof( Vector3 );
		furrovineapi static const VertexDeclaration& Declaration( );

		Vector3 position;

		furrovineapi VertexPosition ();

		furrovineapi VertexPosition ( float x, float y, float z );

		furrovineapi VertexPosition ( const Vector3& pos );
	};

}}
