#pragma once

#include <Furrovine++/Graphics/ShaderEffect2D.h>
#include <Furrovine++/Matrix.h>

namespace Furrovine { namespace Shaders {

	class QuadShaderEffect : public Graphics::ShaderEffect2D {
	private:
		Graphics::ShaderParameter* viewprojparameter;

	public:
		furrovineapi Matrix GetViewProjection ();

		furrovineapi void SetViewProjection ( const Matrix& value );

		furrovineapi QuadShaderEffect( Graphics::GraphicsDevice& graphicsdevice, const String& viewprojectionname = "ViewProjection", const String& texture0name = "Texture0", const String& texture0sizeparamname = "Texture0Size", const String& texture0pixelsizeparamname = "Texture0PixelSize" );
	};

}}
