#pragma once

#include <Furrovine++/Graphics/Shader.h>

namespace Furrovine { namespace Graphics {

	class PixelShader : public Shader {
	public:
		furrovineapi PixelShader( GraphicsDevice& graphics, const ShaderSource& methoddesc = ShaderSource::Empty );
		furrovineapi PixelShader( PixelShader&& mov );
		furrovineapi PixelShader& operator=( PixelShader&& mov );

	};

}}
