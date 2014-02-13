#pragma once

#include <Furrovine++/Graphics/ShaderEffect.h>
#include <Furrovine++/Graphics/Texture2D.h>

namespace Furrovine { namespace Graphics {

	class ShaderEffect2D : public ShaderEffect {
	protected:
		ShaderParameter* texture0parameter;
		ShaderParameter* texture0sizeparameter;
		ShaderParameter* texture0pixelsizeparameter;

	public:
		
		furrovineapi ShaderEffect2D( GraphicsDevice& graphicsdevice, const buffer_view<byte>& bytecode, const String& texture0paramname = "Texture0", const String& texture0sizeparamname = "Texture0Size", const String& texture0pixelsizeparamname = "Texture0PixelSize" );
		furrovineapi ShaderEffect2D( GraphicsDevice& graphicsdevice, const String& source, const String& texture0paramname = "Texture0", const String& texture0sizeparamname = "Texture0Size", const String& texture0pixelsizeparamname = "Texture0PixelSize" );
		
		furrovineapi Texture2D& GetTexture0( );

		furrovineapi void SetTexture0( Texture2D& value );

		furrovineapi Vector2 GetTexture0Size( );

		furrovineapi void SetTexture0Size( const Vector2& value );

		furrovineapi Vector2 GetTexture0PixelSize( );

		furrovineapi void SetTexture0PixelSize( const Vector2& value );

	};

}}
