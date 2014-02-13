#pragma once

#include <Furrovine++/Vector2.h>
#include <Furrovine++/Vector3.h>
#include <Furrovine++/Vector4.h>
#include <Furrovine++/Color.h>
#include <Furrovine++/Graphics/EmptyVertex.h>

namespace Furrovine { namespace Graphics {

	struct VertexNymph : public EmptyVertex {
		
		furrovineapi static const VertexDeclaration& Declaration( );
		furrovineapi static const ulword Stride = sizeof(Vector3) * 2 + sizeof(Vector4) + sizeof(Color) * 2;
		furrovineapi static const float TextureOnly;

		Vector3 position;
		Vector3 texture;
		Vector4 normal;
		Color color1, color2;

		furrovineapi VertexNymph ( const Vector3& position, const Vector2& texture, const Vector3& normal );

		furrovineapi VertexNymph ( const Vector3& position, const Vector3& normal );

		furrovineapi VertexNymph ( const Vector3& position = Vector3::Zero );

		furrovineapi VertexNymph ( const Vector3& position, const Vector2& texture );

		furrovineapi VertexNymph ( const Vector3& position, const Vector2& texture, bool textureonly );

		furrovineapi VertexNymph ( const Vector3& position, const Vector2& texture, const Color& color );

		furrovineapi VertexNymph ( const Vector3& position, const Vector2& texture, const Color& color, bool textureonly );

		furrovineapi VertexNymph ( const Vector3& position, const Vector2& texture, const Color& colour1, const Color& colour2 );

		furrovineapi VertexNymph ( const Vector3& position, const Vector3& texture, const Vector3& normal, const Color& color );

	};

}}
