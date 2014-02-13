#pragma once

#include <Furrovine++/std_defines.h>
#include <unordered_map>
#include <Furrovine++/Strings.h>
#include <Furrovine++/Graphics/Texture2D.h>
#include <Furrovine++/Text/RasterGlyph.h>
#include <Furrovine++/Text/RasterFontData.h>
#include <Furrovine++/Matrix.h>
#include <Furrovine++/Graphics/SpriteEffects.h>

namespace Furrovine { namespace Text {

	class RasterFont {
	protected:
		Graphics::Texture2D raster;
		std::unordered_map<codepoint, RasterGlyph> glyphs;
		RasterFontDescription rasterdesc;
		
	public:
		static const RasterGlyph Blank;
		static const RasterGlyph Substitution;
		
		furrovineapi RasterFont( Graphics::GraphicsDevice& graphicsdevice, RasterFontData rasterfontdesc );

		furrovineapi RasterFont( Graphics::Texture2D GlyphsTexture, std::unordered_map<codepoint, RasterGlyph> Glyphs, RasterFontDescription rasterdesc );

		furrovineapi RasterFont( Graphics::Texture2D GlyphsTexture, std::unordered_map<codepoint, RasterGlyph> Glyphs, optional<codepoint> DefaultGlyph, String Name, float Size, float LineSpacing, float CharacterSpacing, FontStyle Style, FontWeight weight, FontTraits traits );

		furrovineapi const RasterFontDescription& Description( ) const;

		furrovineapi FontStyle Style( ) const;

		furrovineapi const Graphics::Texture2D& Texture( ) const;

		furrovineapi float LineSpacing( ) const;

		furrovineapi float CharacterSpacing( ) const;

		furrovineapi bool TryGetGlyph( codepoint c, RasterGlyph& glyph ) const;

		furrovineapi void Transform( const String& text, Vector2 position, float rotation, Vector2 origin, Vector2 scale, Graphics::SpriteEffects spriteeffects, Matrix& transform ) const;

		furrovineapi void Transform( Vector2 size, Vector2 position, float rotation, Vector2 origin, Vector2 scale, Graphics::SpriteEffects spriteeffect, Matrix& transform ) const;

		furrovineapi void Transform( Vector2 size, Vector2 position, Vector2 alignment, float rotation, Vector2 origin, Vector2 scale, Graphics::SpriteEffects spriteeffect, Matrix& transform ) const;

		furrovineapi void MeasureString( const String& text, Vector2& measure ) const;

		furrovineapi Vector2 MeasureString( const String& text ) const;

		furrovineapi Vector2 MeasureChar( codepoint c ) const;

		furrovineapi void MeasureChar( codepoint c, Vector2& measure, Vector2& linesize ) const;

		furrovineapi void MeasureChar( codepoint c, Vector2& measure, Vector2& linesize, float ratio ) const;

		furrovineapi void MeasureChar( codepoint c, Vector2& measure, Vector2& linesize, float ratio, float characterspacing, float linespacing ) const;

		furrovineapi void MeasureChar( codepoint c, Vector2& measure, float ratio = 1.0f ) const;
	};

}}
