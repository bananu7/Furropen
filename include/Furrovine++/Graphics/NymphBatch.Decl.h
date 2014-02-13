#pragma once

#include <Furrovine++/Matrix.h>
#include <Furrovine++/Colors.h>
#include <Furrovine++/Graphics/VertexNymph.h>
#include <Furrovine++/Graphics/ShaderPass.h>
#include <Furrovine++/Graphics/ShaderPassCollection.h>
#include <Furrovine++/Graphics/NymphBatchRender.h>
#include <Furrovine++/Graphics/SpriteEffects.h>
#include <Furrovine++/Graphics/GraphicsDevice.h>
#include <Furrovine++/Text/RasterFont.h>
#include <Furrovine++/Shaders/NymphShaderEffect.h>

namespace Furrovine { namespace Graphics {

	class NymphBatch : public GraphicsResource {
	public:
		typedef uint16 ishort;

	private:
		Shaders::NymphShaderEffect basicshader;
		bool hasbegun;
		Matrix projection, view, viewprojection, world;
		std::vector<ishort> indices;
		std::vector<VertexNymph> vertices;
		std::vector<NymphBatchRender> renders;
		uint32 vertexcount, indexcount, rendercount;
		uint switches;

	public:
		furrovineapi static const uint32 MaximumVertices = 16384;
		furrovineapi static const uint32 MaximumIndices = 16384;
		furrovineapi static const uint32 MaximumBatchSize = MaximumIndices / 4;
		
		furrovineapi NymphBatch ( GraphicsDevice& graphicsdevice );

		furrovineapi void Begin( );
		furrovineapi void Begin( const Matrix& View, const Matrix& Projection );

		furrovineapi void Rebegin ( );
		furrovineapi void Rebegin ( const Matrix& View, const Matrix& Projection );

		furrovineapi void End ( );

		furrovineapi void Flush ( );

	private:
		
		furrovineapi void CustomFlush ( );

		furrovineapi void StandardFlush ( );
/*
#pragma region Polygon Rendering

#pragma region Base Polygon RenderPolygon Call

	private:
		void RenderPolygon ( PrimitiveType primitive, VertexPositionNormalTexture[ ] data, const Texture2D& texture, bool textureonly, const Matrix& world, const Color& tint, float outline, const Color& outlinecolor ) {
			if ( !hasbegun )
				throw Exception( "You cannot RenderPolygon with this Nymphbatch: it has never begun" );

			if ( data.size() > MaximumVertices ) {
				throw Exception(
					String.Format( "You are trying to draw a polygon with {0} vertices. This exceeds the {1} Vertex Limit. Consider drawing this shape using less vertices or just drawing something this big as a regular model.",
					data.size(), MaximumVertices ) );
			}

			if ( data.size() > MaximumIndices ) {
				throw Exception(
					String.Format( "You are trying to draw a polygon with {0} indices. This exceeds the {1} Index Limit. Consider drawing this shape using less indices or just drawing something this big as a regular model.",
					data.size(), MaximumIndices ) );
			}

			if ( primitive != Primitives.Triangles ) {
				throw Exception(
					String.Format( "You are attempting to use NymphBatch to draw a {0} primitive. The only Nymphbatchable primitive type is {1}",
					primitive, Primitives.Triangles ) );
			}

			if ( data.size() < 1 )
				return;

			int indexskew = 0;
			bool batch = false;

			// If the data is long enough to overrun our vertex array...
			if ( vertexcount + data.size() > vertices.size() ||
				indexcount + data.size() > indices.size() ||
				rendercount == MaximumBatchSize ) {
					// Then flush our current contents to the Graphics Card
					Flush( );
			}

			batch = rendercount > 0;
			if ( batch ) {
				batch = renders[ rendercount - 1 ].Texture0 == texture;
				if ( batch )
					indexskew = renders[ rendercount - 1 ].VertexStart;
				else
					indexskew = renders[ rendercount - 1 ].VertexStart + renders[ rendercount - 1 ].VertexCount;
			}

			for ( int i = 0; i < data.size(); ++i, ++vertexcount, ++indexcount ) {
				Vector3::Transform( ref data[ i ].normal, world, out temp.position );
				temp.position -= world.Translation;
				temp.position.Normalize( );
				temp.normal.x = temp.position.x;
				temp.normal.y = temp.position.y;
				temp.normal.z = temp.position.z;
				temp.normal.w = outline;
				Vector3::Transform( ref data[ i ].position, world, out temp.position );
				temp.texture.x = data[ i ].texture.x;
				temp.texture.y = data[ i ].texture.y;
				temp.texture.z = textureonly ? VertexNymph::TextureOnly : 0;
				temp.color1 = tint;
				temp.const Color&2 = outlinecolor;
				vertices[ vertexcount ] = temp;
				indices[ indexcount ] = (ishort)( vertexcount - indexskew );
			}

			if ( batch ) {
				renders[ rendercount - 1 ].VertexCount += data.size();
				renders[ rendercount - 1 ].IndexCount += data.size();
				renders[ rendercount - 1 ].Outlineable |= outline != 0.0f;
			}
			else {
				renders[ rendercount ].IndexStart = indexcount - data.size();
				renders[ rendercount ].IndexCount = data.size();
				renders[ rendercount ].VertexStart = vertexcount - data.size();
				renders[ rendercount ].Texture0 = texture;
				renders[ rendercount ].VertexCount = data.size();
				renders[ rendercount ].Outlineable = outline != 0.0f;
				rendercount++;
			}
		}

#pragma endregion
	public:
		furrovineapi void RenderPolygon ( Polygon poly, const Texture2D& texture, const Color& tint, float outline, const Color& outlinecolor, const Matrix& world ) {
			RenderPolygon( poly.Primitive, poly.Vertices, texture, false, world, tint, outline, ref outlinecolor );
		}

		furrovineapi void RenderPolygon ( Polygon poly, const Texture2D& texture, const Color& tint, const Matrix& world ) {
			RenderPolygon( poly.Primitive, poly.Vertices, texture, false, world, tint, 0.0f, const Color&s.DefaultAnticonst Color& );
		}

		furrovineapi void RenderPolygon ( Polygon poly, const Color& tint, float outline, const Color& outlinecolor, const Matrix& world ) {
			RenderPolygon( poly.Primitive, poly.Vertices, null, false, world, tint, outline, ref outlinecolor );
		}

		furrovineapi void RenderPolygon ( Polygon poly, const Color& tint, const Matrix& world ) {
			RenderPolygon( poly.Primitive, poly.Vertices, null, false, world, tint, 0.0f, const Color&s.DefaultAnticonst Color& );
		}

		furrovineapi void RenderPolygon ( Polygon poly, const Texture2D& texture, const Color& tint, const Vector2& position ) {
			RenderPolygon( poly, texture, false, tint, 0.0f, const Color&s.DefaultAnticonst Color&, position, 0.0f, Vector2::One, Vector2::Zero );
		}

		furrovineapi void RenderPolygon ( Polygon poly, const Texture2D& texture, const Color& tint, const Vector2& position, float rotation ) {
			RenderPolygon( poly, texture, false, tint, 0.0f, const Color&s.DefaultAnticonst Color&, position, rotation, Vector2::One, Vector2::Zero );
		}

		furrovineapi void RenderPolygon ( Polygon poly, const Texture2D& texture, const Color& tint, const Vector2& position, float rotation, float scale ) {
			RenderPolygon( poly, texture, false, tint, 0.0f, const Color&s.DefaultAnticonst Color&, position, rotation, Vector2( scale ), Vector2::Zero );
		}

		furrovineapi void RenderPolygon ( Polygon poly, const Texture2D& texture, const Color& tint, const Vector2& position, float rotation, const Vector2& scale ) {
			RenderPolygon( poly, texture, false, tint, 0.0f, const Color&s.DefaultAnticonst Color&, position, rotation, scale, Vector2::Zero );
		}

		furrovineapi void RenderPolygon ( Polygon poly, const Texture2D& texture, const Color& tint, const Vector2& position, const Vector2& scale ) {
			RenderPolygon( poly, texture, false, tint, 0.0f, const Color&s.DefaultAnticonst Color&, position, 0.0f, scale, Vector2::Zero );
		}

		furrovineapi void RenderPolygon ( Polygon poly, const Texture2D& texture, const Color& tint, float outline, const Color& outlinecolor, const Vector2& position ) {
			RenderPolygon( poly, texture, false, tint, outline, outlinecolor, position, 0.0f, Vector2::One, Vector2::Zero );
		}

		furrovineapi void RenderPolygon ( Polygon poly, const Texture2D& texture, const Color& tint, float outline, const Color& outlinecolor, const Vector2& position, float rotation ) {
			RenderPolygon( poly, texture, false, tint, outline, outlinecolor, position, rotation, Vector2::One, Vector2::Zero );
		}

		furrovineapi void RenderPolygon ( Polygon poly, const Texture2D& texture, const Color& tint, float outline, const Color& outlinecolor, const Vector2& position, float rotation, float scale ) {
			RenderPolygon( poly, texture, false, tint, outline, outlinecolor, position, rotation, Vector2( scale ), Vector2::Zero );
		}

		furrovineapi void RenderPolygon ( Polygon poly, const Texture2D& texture, const Color& tint, float outline, const Color& outlinecolor, const Vector2& position, float rotation, const Vector2& scale ) {
			RenderPolygon( poly, texture, false, tint, outline, outlinecolor, position, rotation, scale, Vector2::Zero );
		}

		furrovineapi void RenderPolygon ( Polygon poly, const Texture2D& texture, const Color& tint, float outline, const Color& outlinecolor, const Vector2& position, const Vector2& scale ) {
			RenderPolygon( poly, texture, false, tint, outline, outlinecolor, position, 0.0f, scale, Vector2::Zero );
		}

		furrovineapi void RenderPolygon ( Polygon poly, const Color& tint, const Vector2& position ) {
			RenderPolygon( poly, null, false, tint, 0.0f, const Color&s.DefaultAnticonst Color&, position, 0.0f, Vector2::One, Vector2::Zero );
		}

		furrovineapi void RenderPolygon ( Polygon poly, const Color& tint, const Vector2& position, float rotation ) {
			RenderPolygon( poly, null, false, tint, 0.0f, const Color&s.DefaultAnticonst Color&, position, rotation, Vector2::One, Vector2::Zero );
		}

		furrovineapi void RenderPolygon ( Polygon poly, const Color& tint, const Vector2& position, float rotation, float scale ) {
			RenderPolygon( poly, null, false, tint, 0.0f, const Color&s.DefaultAnticonst Color&, position, rotation, Vector2( scale ), Vector2::Zero );
		}

		furrovineapi void RenderPolygon ( Polygon poly, const Color& tint, const Vector2& position, float rotation, const Vector2& scale ) {
			RenderPolygon( poly, null, false, tint, 0.0f, const Color&s.DefaultAnticonst Color&, position, rotation, scale, Vector2::Zero );
		}

		furrovineapi void RenderPolygon ( Polygon poly, const Color& tint, const Vector2& position, const Vector2& scale ) {
			RenderPolygon( poly, null, false, tint, 0.0f, const Color&s.DefaultAnticonst Color&, position, 0.0f, scale, Vector2::Zero );
		}

		furrovineapi void RenderPolygon ( Polygon poly, const Color& tint, float outline, const Color& outlinecolor, const Vector2& position ) {
			RenderPolygon( poly, null, false, tint, outline, outlinecolor, position, 0.0f, Vector2::One, Vector2::Zero );
		}

		furrovineapi void RenderPolygon ( Polygon poly, const Color& tint, float outline, const Color& outlinecolor, const Vector2& position, float rotation ) {
			RenderPolygon( poly, null, false, tint, outline, outlinecolor, position, rotation, Vector2::One, Vector2::Zero );
		}

		furrovineapi void RenderPolygon ( Polygon poly, const Color& tint, float outline, const Color& outlinecolor, const Vector2& position, float rotation, float scale ) {
			RenderPolygon( poly, null, false, tint, outline, outlinecolor, position, rotation, Vector2( scale ), Vector2::Zero );
		}

		furrovineapi void RenderPolygon ( Polygon poly, const Color& tint, float outline, const Color& outlinecolor, const Vector2& position, float rotation, float scale, const Vector2& origin ) {
			RenderPolygon( poly, null, false, tint, outline, outlinecolor, position, rotation, Vector2( scale ), origin );
		}

		furrovineapi void RenderPolygon ( Polygon poly, const Color& tint, float outline, const Color& outlinecolor, const Vector2& position, float rotation, const Vector2& scale ) {
			RenderPolygon( poly, null, false, tint, outline, outlinecolor, position, rotation, scale, Vector2::Zero );
		}

		furrovineapi void RenderPolygon ( Polygon poly, const Color& tint, float outline, const Color& outlinecolor, const Vector2& position, const Vector2& scale ) {
			RenderPolygon( poly, null, false, tint, outline, outlinecolor, position, 0.0f, scale, Vector2::Zero );
		}

		furrovineapi void RenderPolygon ( Polygon poly, const Color& tint, float outline, const Color& outlinecolor, const Vector2& position, float rotation, const Vector2& scale, const Vector2& origin ) {
			RenderPolygon( poly, null, false, tint, outline, outlinecolor, position, rotation, scale, origin );
		}

		furrovineapi void RenderPolygon ( Polygon poly, const Texture2D& texture, bool usetexturealpha, const Color& tint, float outline, const Color& outlinecolor, const Matrix& world ) {
			RenderPolygon( poly.Primitive, poly.Vertices, texture, usetexturealpha, world, tint, outline, ref outlinecolor );
		}

		furrovineapi void RenderPolygon ( Polygon poly, const Texture2D& texture, bool usetexturealpha, const Color& tint, const Matrix& world ) {
			RenderPolygon( poly.Primitive, poly.Vertices, texture, usetexturealpha, world, tint, 0.0f, const Color&s.DefaultAnticonst Color& );
		}

		furrovineapi void RenderPolygon ( Polygon poly, const Texture2D& texture, bool usetexturealpha, const Color& tint, const Vector2& position ) {
			RenderPolygon( poly, texture, usetexturealpha, tint, 0.0f, const Color&s.DefaultAnticonst Color&, position, 0.0f, Vector2::One, Vector2::Zero );
		}

		furrovineapi void RenderPolygon ( Polygon poly, const Texture2D& texture, bool usetexturealpha, const Color& tint, const Vector2& position, float rotation ) {
			RenderPolygon( poly, texture, usetexturealpha, tint, 0.0f, const Color&s.DefaultAnticonst Color&, position, rotation, Vector2::One, Vector2::Zero );
		}

		furrovineapi void RenderPolygon ( Polygon poly, const Texture2D& texture, bool usetexturealpha, const Color& tint, const Vector2& position, float rotation, float scale ) {
			RenderPolygon( poly, texture, usetexturealpha, tint, 0.0f, const Color&s.DefaultAnticonst Color&, position, rotation, Vector2( scale ), Vector2::Zero );
		}

		furrovineapi void RenderPolygon ( Polygon poly, const Texture2D& texture, bool usetexturealpha, const Color& tint, const Vector2& position, float rotation, const Vector2& scale ) {
			RenderPolygon( poly, texture, usetexturealpha, tint, 0.0f, const Color&s.DefaultAnticonst Color&, position, rotation, scale, Vector2::Zero );
		}

		furrovineapi void RenderPolygon ( Polygon poly, const Texture2D& texture, bool usetexturealpha, const Color& tint, const Vector2& position, const Vector2& scale ) {
			RenderPolygon( poly, texture, usetexturealpha, tint, 0.0f, const Color&s.DefaultAnticonst Color&, position, 0.0f, scale, Vector2::Zero );
		}

		furrovineapi void RenderPolygon ( Polygon poly, const Texture2D& texture, bool usetexturealpha, const Color& tint, float outline, const Color& outlinecolor, const Vector2& position ) {
			RenderPolygon( poly, texture, usetexturealpha, tint, outline, outlinecolor, position, 0.0f, Vector2::One, Vector2::Zero );
		}

		furrovineapi void RenderPolygon ( Polygon poly, const Texture2D& texture, bool usetexturealpha, const Color& tint, float outline, const Color& outlinecolor, const Vector2& position, float rotation ) {
			RenderPolygon( poly, texture, usetexturealpha, tint, outline, outlinecolor, position, rotation, Vector2::One, Vector2::Zero );
		}

		furrovineapi void RenderPolygon ( Polygon poly, const Texture2D& texture, bool usetexturealpha, const Color& tint, float outline, const Color& outlinecolor, const Vector2& position, float rotation, float scale ) {
			RenderPolygon( poly, texture, usetexturealpha, tint, outline, outlinecolor, position, rotation, Vector2( scale ), Vector2::Zero );
		}

		furrovineapi void RenderPolygon ( Polygon poly, const Texture2D& texture, bool usetexturealpha, const Color& tint, float outline, const Color& outlinecolor, const Vector2& position, float rotation, const Vector2& scale ) {
			RenderPolygon( poly, texture, usetexturealpha, tint, outline, outlinecolor, position, rotation, scale, Vector2::Zero );
		}

		furrovineapi void RenderPolygon ( Polygon poly, const Texture2D& texture, bool usetexturealpha, const Color& tint, float outline, const Color& outlinecolor, const Vector2& position, const Vector2& scale ) {
			RenderPolygon( poly, texture, usetexturealpha, tint, outline, outlinecolor, position, 0.0f, scale, Vector2::Zero );
		}

		furrovineapi void RenderPolygon ( Polygon poly, const Texture2D& texture, bool usetexturealpha, const Color& tint, float outline, const Color& outlinecolor, const Vector2& position, float rotation, const Vector2& scale, const Vector2& origin ) {
			if ( poly == null )
				return;

			Matrix temp;
			Matrix::CreateScale( scale.x, scale.y, 1.0f, out world );

			Matrix::CreateTranslation( -origin.x, -origin.y, 0.0f, out temp );
			Matrix::Multiply( world, ref temp, out world );

			Matrix::CreateRotationZ( rotation, out temp );
			Matrix::Multiply( world, ref temp, out world );

			Matrix::CreateTranslation( position.x, position.y, 0.0f, out temp );
			Matrix::Multiply( world, ref temp, out world );

			RenderPolygon( poly.Primitive, poly.Vertices, texture, usetexturealpha, world, tint, outline, ref outlinecolor );
		}

#pragma endregion
*/
/*
#pragma region Render 3D Polygon

		furrovineapi void Render3DPolygon ( Polygon poly, const Texture2D& texture, const Color& tint, float outline, const Color& outlinecolor, const Matrix& world ) {
			RenderPolygon( poly.Primitive, poly.Vertices, texture, false, world, tint, outline, ref outlinecolor );
		}

		furrovineapi void Render3DPolygon ( Polygon poly, const Texture2D& texture, const Color& tint, const Matrix& world ) {
			RenderPolygon( poly.Primitive, poly.Vertices, texture, false, world, tint, 0.0f, const Color&s.DefaultAnticonst Color& );
		}

		furrovineapi void Render3DPolygon ( Polygon poly, const Color& tint, float outline, const Color& outlinecolor, const Matrix& world ) {
			RenderPolygon( poly.Primitive, poly.Vertices, null, false, world, tint, outline, ref outlinecolor );
		}

		furrovineapi void Render3DPolygon ( Polygon poly, const Color& tint, const Matrix& world ) {
			RenderPolygon( poly.Primitive, poly.Vertices, null, false, world, tint, 0.0f, const Color&s.DefaultAnticonst Color& );
		}

		furrovineapi void Render3DPolygon ( Polygon poly, const Texture2D& texture, const Color& tint, const Vector3& position ) {
			Render3DPolygon( poly, texture, false, tint, 0.0f, const Color&s.DefaultAnticonst Color&, position, Vector3::Zero, Vector3::One, Vector3::Zero );
		}

		furrovineapi void Render3DPolygon ( Polygon poly, const Texture2D& texture, const Color& tint, const Vector3& position, const Vector3& rotation ) {
			Render3DPolygon( poly, texture, false, tint, 0.0f, const Color&s.DefaultAnticonst Color&, position, rotation, Vector3::One, Vector3::Zero );
		}

		furrovineapi void Render3DPolygon ( Polygon poly, const Texture2D& texture, const Color& tint, const Vector3& position, const Vector3& rotation, float scale ) {
			Render3DPolygon( poly, texture, false, tint, 0.0f, const Color&s.DefaultAnticonst Color&, position, rotation, new Vector3( scale ), Vector3::Zero );
		}

		furrovineapi void Render3DPolygon ( Polygon poly, const Texture2D& texture, const Color& tint, const Vector3& position, const Vector3& rotation, const Vector3& scale ) {
			Render3DPolygon( poly, texture, false, tint, 0.0f, const Color&s.DefaultAnticonst Color&, position, rotation, scale, Vector3::Zero );
		}

		furrovineapi void Render3DPolygon ( Polygon poly, const Texture2D& texture, const Color& tint, float outline, const Color& outlinecolor, const Vector3& position ) {
			Render3DPolygon( poly, texture, false, tint, outline, outlinecolor, position, Vector3::Zero, Vector3::One, Vector3::Zero );
		}

		furrovineapi void Render3DPolygon ( Polygon poly, const Texture2D& texture, const Color& tint, float outline, const Color& outlinecolor, const Vector3& position, const Vector3& rotation ) {
			Render3DPolygon( poly, texture, false, tint, outline, outlinecolor, position, rotation, Vector3::One, Vector3::Zero );
		}

		furrovineapi void Render3DPolygon ( Polygon poly, const Texture2D& texture, const Color& tint, float outline, const Color& outlinecolor, const Vector3& position, const Vector3& rotation, float scale ) {
			Render3DPolygon( poly, texture, false, tint, outline, outlinecolor, position, rotation, new Vector3( scale ), Vector3::Zero );
		}

		furrovineapi void Render3DPolygon ( Polygon poly, const Texture2D& texture, const Color& tint, float outline, const Color& outlinecolor, const Vector3& position, const Vector3& rotation, const Vector3& scale ) {
			Render3DPolygon( poly, texture, false, tint, outline, outlinecolor, position, rotation, scale, Vector3::Zero );
		}

		furrovineapi void Render3DPolygon ( Polygon poly, const Color& tint, const Vector3& position ) {
			Render3DPolygon( poly, null, false, tint, 0.0f, const Color&s.DefaultAnticonst Color&, position, Vector3::Zero, Vector3::One, Vector3::Zero );
		}

		furrovineapi void Render3DPolygon ( Polygon poly, const Color& tint, const Vector3& position, const Vector3& rotation ) {
			Render3DPolygon( poly, null, false, tint, 0.0f, const Color&s.DefaultAnticonst Color&, position, rotation, Vector3::One, Vector3::Zero );
		}

		furrovineapi void Render3DPolygon ( Polygon poly, const Color& tint, const Vector3& position, const Vector3& rotation, float scale ) {
			Render3DPolygon( poly, null, false, tint, 0.0f, const Color&s.DefaultAnticonst Color&, position, rotation, new Vector3( scale ), Vector3::Zero );
		}

		furrovineapi void Render3DPolygon ( Polygon poly, const Color& tint, const Vector3& position, const Vector3& rotation, const Vector3& scale ) {
			Render3DPolygon( poly, null, false, tint, 0.0f, const Color&s.DefaultAnticonst Color&, position, rotation, scale, Vector3::Zero );
		}

		furrovineapi void Render3DPolygon ( Polygon poly, const Color& tint, float outline, const Color& outlinecolor, const Vector3& position ) {
			Render3DPolygon( poly, null, false, tint, outline, outlinecolor, position, Vector3::Zero, Vector3::One, Vector3::Zero );
		}

		furrovineapi void Render3DPolygon ( Polygon poly, const Color& tint, float outline, const Color& outlinecolor, const Vector3& position, const Vector3& rotation ) {
			Render3DPolygon( poly, null, false, tint, outline, outlinecolor, position, rotation, Vector3::One, Vector3::Zero );
		}

		furrovineapi void Render3DPolygon ( Polygon poly, const Color& tint, float outline, const Color& outlinecolor, const Vector3& position, const Vector3& rotation, float scale ) {
			Render3DPolygon( poly, null, false, tint, outline, outlinecolor, position, rotation, new Vector3( scale ), Vector3::Zero );
		}

		furrovineapi void Render3DPolygon ( Polygon poly, const Color& tint, float outline, const Color& outlinecolor, const Vector3& position, const Vector3& rotation, float scale, const Vector3& origin ) {
			Render3DPolygon( poly, null, false, tint, outline, outlinecolor, position, rotation, new Vector3( scale ), origin );
		}

		furrovineapi void Render3DPolygon ( Polygon poly, const Color& tint, float outline, const Color& outlinecolor, const Vector3& position, const Vector3& rotation, const Vector3& scale ) {
			Render3DPolygon( poly, null, false, tint, outline, outlinecolor, position, rotation, scale, Vector3::Zero );
		}

		furrovineapi void Render3DPolygon ( Polygon poly, const Texture2D& texture, bool usetexturealpha, const Color& tint, float outline, const Color& outlinecolor, const Matrix& world ) {
			RenderPolygon( poly.Primitive, poly.Vertices, texture, usetexturealpha, world, tint, outline, ref outlinecolor );
		}

		furrovineapi void Render3DPolygon ( Polygon poly, const Texture2D& texture, bool usetexturealpha, const Color& tint, const Matrix& world ) {
			RenderPolygon( poly.Primitive, poly.Vertices, texture, usetexturealpha, world, tint, 0.0f, const Color&s.DefaultAnticonst Color& );
		}

		furrovineapi void Render3DPolygon ( Polygon poly, const Color& tint, float outline, const Color& outlinecolor, const Vector3& position, const Vector3& rotation, const Vector3& scale, const Vector3& origin ) {
			Render3DPolygon( poly, null, false, tint, outline, outlinecolor, position, Vector3::Zero, scale, origin );
		}

		furrovineapi void Render3DPolygon ( Polygon poly, const Texture2D& texture, bool usetexturealpha, const Color& tint, const Vector3& position ) {
			Render3DPolygon( poly, texture, usetexturealpha, tint, 0.0f, const Color&s.DefaultAnticonst Color&, Vector3::Zero, Vector3::Zero, Vector3::One, Vector3::Zero );
		}

		furrovineapi void Render3DPolygon ( Polygon poly, const Texture2D& texture, bool usetexturealpha, const Color& tint, const Vector3& position, const Vector3& rotation ) {
			Render3DPolygon( poly, texture, usetexturealpha, tint, 0.0f, const Color&s.DefaultAnticonst Color&, position, rotation, Vector3::One, Vector3::Zero );
		}

		furrovineapi void Render3DPolygon ( Polygon poly, const Texture2D& texture, bool usetexturealpha, const Color& tint, const Vector3& position, const Vector3& rotation, float scale ) {
			Render3DPolygon( poly, texture, usetexturealpha, tint, 0.0f, const Color&s.DefaultAnticonst Color&, position, rotation, new Vector3( scale ), Vector3::Zero );
		}

		furrovineapi void Render3DPolygon ( Polygon poly, const Texture2D& texture, bool usetexturealpha, const Color& tint, const Vector3& position, const Vector3& rotation, const Vector3& scale ) {
			Render3DPolygon( poly, texture, usetexturealpha, tint, 0.0f, const Color&s.DefaultAnticonst Color&, position, rotation, scale, Vector3::Zero );
		}

		furrovineapi void Render3DPolygon ( Polygon poly, const Texture2D& texture, bool usetexturealpha, const Color& tint, float outline, const Color& outlinecolor, const Vector3& position ) {
			Render3DPolygon( poly, texture, usetexturealpha, tint, outline, outlinecolor, position, Vector3::Zero, Vector3::One, Vector3::Zero );
		}

		furrovineapi void Render3DPolygon ( Polygon poly, const Texture2D& texture, bool usetexturealpha, const Color& tint, float outline, const Color& outlinecolor, const Vector3& position, const Vector3& rotation ) {
			Render3DPolygon( poly, texture, usetexturealpha, tint, outline, outlinecolor, position, rotation, Vector3::One, Vector3::Zero );
		}

		furrovineapi void Render3DPolygon ( Polygon poly, const Texture2D& texture, bool usetexturealpha, const Color& tint, float outline, const Color& outlinecolor, const Vector3& position, const Vector3& rotation, float scale ) {
			Render3DPolygon( poly, texture, usetexturealpha, tint, outline, outlinecolor, position, rotation, new Vector3( scale ), Vector3::Zero );
		}

		furrovineapi void Render3DPolygon ( Polygon poly, const Texture2D& texture, bool usetexturealpha, const Color& tint, float outline, const Color& outlinecolor, const Vector3& position, const Vector3& rotation, const Vector3& scale ) {
			Render3DPolygon( poly, texture, usetexturealpha, tint, outline, outlinecolor, position, rotation, scale, Vector3::Zero );
		}

		furrovineapi void Render3DPolygon ( Polygon poly, const Texture2D& texture, bool usetexturealpha, const Color& tint, float outline, const Color& outlinecolor, const Vector3& position, const Vector3& rotation, const Vector3& scale, const Vector3& origin ) {
			if ( poly == null )
				return;

			Matrix temp;
			Matrix::CreateScale( scale.x, scale.y, 1.0f, out world );

			Matrix::CreateTranslation( -origin.x, -origin.y, -origin.z, out temp );
			Matrix::Multiply( world, ref temp, out world );

			Matrix::CreateFromYawPitchRoll( rotation.y, rotation.x, rotation.z, out temp );
			Matrix::Multiply( world, ref temp, out world );

			Matrix::CreateTranslation( ref position, out temp );
			Matrix::Multiply( world, ref temp, out world );

			RenderPolygon( poly.Primitive, poly.Vertices, texture, usetexturealpha, world, tint, outline, ref outlinecolor );
		}

#pragma endregion
*/

	private:
		furrovineapi void RenderGradient ( const Color& topleft, const Color& topright, const Color& bottomleft, const Color& bottomright, float right, float bottom, const Matrix& world );

	public:
		
		furrovineapi void RenderGradient ( const Rectangle& bounds, const Color& one, const Color& two );

		furrovineapi void RenderGradient ( const Rectangle& bounds, const Color& topleft, const Color& topright, const Color& bottomleft, const Color& bottomright );

		furrovineapi void RenderGradient ( const Vector2& size, const Color& one, const Color& two, const Vector2& position, float rotation, const Vector2& scale, const Vector2& origin, SpriteEffects spriteeffects );

		furrovineapi void RenderGradient ( const Vector2& size, const Color& topleft, const Color& topright, const Color& bottomleft, const Color& bottomright, const Vector2& position, float rotation, const Vector2& scale, const Vector2& origin, SpriteEffects spriteeffects );

	private:
		furrovineapi void Render ( const Texture2D& texture, float x, float y, float width, float height, const Matrix& world, const Color& tint );

	public:
		furrovineapi void Render ( const Texture2D& texture, const Color& tint, const Region& bounds );

		furrovineapi void Render ( const Texture2D& texture, const Color& tint, const Region& bounds, const Region& source );

		furrovineapi void Render ( const Texture2D& texture, const Color& tint, const Region& source, const Matrix& world );

		furrovineapi void Render ( const Texture2D& texture, const Region& source, const Color& tint = Colors::White, const Vector2& position = Vector2::Zero, float rotation = 0.0f, const Vector2& scale = Vector2::One, const Vector2& origin = Vector2::Zero, SpriteEffects spriteeffects = SpriteEffects::None );

	private:
		furrovineapi void Render3D( const Texture2D& texture, float x, float y, float width, float height, const Matrix& world, const Color& tint );

	public:
		furrovineapi void Render3D( const Texture2D& texture, const Region& bounds, const Color& tint = Colors::White );

		furrovineapi void Render3D( const Texture2D& texture, const Region& bounds, const Region& source, const Color& tint = Colors::White );

		furrovineapi void Render3D( const Texture2D& texture, const Matrix& world, const Color& tint = Colors::White );

		furrovineapi void Render3D( const Texture2D& texture, const Region& source, const Matrix& world, const Color& tint = Colors::White );

		furrovineapi void Render3D( const Texture2D& texture, const Vector3& position, const Color& tint = Colors::White, const Vector3& rotation = Vector3::Zero, const Vector2& scale = Vector2::One, const Vector3& origin = Vector3::Zero, SpriteEffects spriteeffects = SpriteEffects::None );

		furrovineapi void Render3D( const Texture2D& texture, const Region& source, const Vector3& position, const Color& tint = Colors::White, const Vector3& rotation = Vector3::Zero, const Vector2& scale = Vector2::One, const Vector3& origin = Vector3::Zero, SpriteEffects spriteeffects = SpriteEffects::None );

		furrovineapi void RenderString( const Text::RasterFont& font, const String& text, const Vector2& position, const Color& tint = Colors::White, float rotation = 0.0f, const Vector2& scale = Vector2::One, const Vector2& origin = Vector2::Zero, SpriteEffects spriteeffects = SpriteEffects::None );

		furrovineapi void RenderString( const Text::RasterFont& font, const String& text, const Vector2& measuredtextsize, const Vector2& position, const Color& tint = Colors::White, float rotation = 0.0f, const Vector2& scale = Vector2::One, const Vector2& origin = Vector2::Zero, SpriteEffects spriteeffects = SpriteEffects::None );

		furrovineapi ~NymphBatch ( );
	};

}}
