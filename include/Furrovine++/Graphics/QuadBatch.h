#pragma once

#include <Furrovine++/Matrix.h>
#include <Furrovine++/Colors.h>
#include <Furrovine++/Graphics/VertexQuad.h>
#include <Furrovine++/Graphics/ShaderPass.h>
#include <Furrovine++/Graphics/ShaderPassCollection.h>
#include <Furrovine++/Graphics/QuadBatchRender.h>
#include <Furrovine++/Graphics/SpriteEffects.h>
#include <Furrovine++/Graphics/GraphicsDevice.h>
#include <Furrovine++/Text/RasterFont.h>
#include <Furrovine++/Shaders/QuadShaderEffect.h>

namespace Furrovine { namespace Graphics {

	class QuadBatch : public GraphicsResource {
	public:
		typedef uint16 ishort;

	private:
		Shaders::QuadShaderEffect basicshader;
		bool hasbegun;
		Matrix projection, view, viewprojection, world;
		std::vector<ishort> indices;
		std::vector<VertexQuad> vertices;
		std::vector<QuadBatchRender> renders;
		uint32 vertexcount, rendercount;
		uint switches;

		furrovineapi void CustomFlush( );

		furrovineapi void StandardFlush( );

		furrovineapi void Render( const Texture2D& texture, float x, float y, float width, float height, const Matrix& world, const Color& tint );

		furrovineapi void Render3D( const Texture2D& texture, float x, float y, float width, float height, const Matrix& world, const Color& tint );

	public:
		furrovineapi static const uint32 MaximumVertices = 16384;
		furrovineapi static const uint32 MaximumIndices = 16384;
		furrovineapi static const uint32 MaximumBatchSize = MaximumIndices / 4;
		
		furrovineapi QuadBatch ( GraphicsDevice& graphicsdevice );

		furrovineapi void Begin( );
		furrovineapi void Begin( const Matrix& View, const Matrix& Projection );

		furrovineapi void Rebegin ( );
		furrovineapi void Rebegin ( const Matrix& View, const Matrix& Projection );

		furrovineapi void End ( );

		furrovineapi void Flush ( );

		furrovineapi void Render ( const Texture2D& texture, const Color& tint, const Region& bounds );

		furrovineapi void Render ( const Texture2D& texture, const Color& tint, const Region& bounds, const Region& source );

		furrovineapi void Render ( const Texture2D& texture, const Color& tint, const Region& source, const Matrix& world );

		furrovineapi void Render ( const Texture2D& texture, const Region& source, const Color& tint = Colors::White, const Vector2& position = Vector2::Zero, float rotation = 0.0f, const Vector2& scale = Vector2::One, const Vector2& origin = Vector2::Zero, SpriteEffects spriteeffects = SpriteEffects::None );

		furrovineapi void Render3D( const Texture2D& texture, const Region& bounds, const Color& tint = Colors::White );

		furrovineapi void Render3D( const Texture2D& texture, const Region& bounds, const Region& source, const Color& tint = Colors::White );

		furrovineapi void Render3D( const Texture2D& texture, const Matrix& world, const Color& tint = Colors::White );

		furrovineapi void Render3D( const Texture2D& texture, const Region& source, const Matrix& world, const Color& tint = Colors::White );

		furrovineapi void Render3D( const Texture2D& texture, const Vector3& position, const Color& tint = Colors::White, const Vector3& rotation = Vector3::Zero, const Vector2& scale = Vector2::One, const Vector3& origin = Vector3::Zero, SpriteEffects spriteeffects = SpriteEffects::None );

		furrovineapi void Render3D( const Texture2D& texture, const Region& source, const Vector3& position, const Color& tint = Colors::White, const Vector3& rotation = Vector3::Zero, const Vector2& scale = Vector2::One, const Vector3& origin = Vector3::Zero, SpriteEffects spriteeffects = SpriteEffects::None );

		furrovineapi void RenderString( const Text::RasterFont& font, const String& text, const Vector2& position, const Color& tint = Colors::White, float rotation = 0.0f, const Vector2& scale = Vector2::One, const Vector2& origin = Vector2::Zero, SpriteEffects spriteeffects = SpriteEffects::None );

		furrovineapi void RenderString( const Text::RasterFont& font, const String& text, const Vector2& measuredtextsize, const Vector2& position, const Color& tint = Colors::White, float rotation = 0.0f, const Vector2& scale = Vector2::One, const Vector2& origin = Vector2::Zero, SpriteEffects spriteeffects = SpriteEffects::None );

	};

}}
