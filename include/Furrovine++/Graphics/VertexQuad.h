#pragma once

#include <Furrovine++/Vector2.h>
#include <Furrovine++/Vector3.h>
#include <Furrovine++/Color.h>
#include <Furrovine++/Graphics/EmptyVertex.h>

namespace Furrovine { namespace Graphics {

	struct VertexQuad : public EmptyVertex {
	public:
		/// <summary>
		/// Vertex Declaration type contained within the Structure.
		/// </summary>
		furrovineapi static const VertexDeclaration& Declaration( );
		furrovineapi static const ulword Stride = sizeof( Vector3 ) + sizeof( Vector2 ) + sizeof( Color );

		Vector3 position;
		Color color;
		Vector2 texture;

		furrovineapi VertexQuad ( );

		furrovineapi VertexQuad ( float x, float y, float z );

		furrovineapi VertexQuad ( float x, float y, float z, const Color& color );

		furrovineapi VertexQuad ( float x, float y, float z, float tx, float ty, const Color& color );

		furrovineapi VertexQuad ( const Vector3& position, const Vector2& texture, const Color& color );

		furrovineapi VertexQuad ( const Vector3& position, const Vector2& texture );

		furrovineapi VertexQuad ( const Vector3& position );
	};

}}
