#pragma once

#include <Furrovine++/Matrix.h>
#include <Furrovine++/Graphics/ShaderParameter.h>
#include <Furrovine++/Graphics/ShaderEffect2D.h>

namespace Furrovine { namespace Shaders {

	class NymphShaderEffect : public Graphics::ShaderEffect2D {
	protected:
		Graphics::ShaderParameter* viewprojparameter;

	public:
		furrovineapi NymphShaderEffect( Graphics::GraphicsDevice& graphicsdevice );
		
		furrovineapi Matrix GetViewProjection( );

		furrovineapi void SetViewProjection ( const Matrix& value );

	};

}}
