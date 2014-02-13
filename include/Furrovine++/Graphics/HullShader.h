#pragma once

#include <Furrovine++/Graphics/Shader.h>

namespace Furrovine { namespace Graphics {

	class HullShader : public Shader {
	public:
		furrovineapi HullShader( GraphicsDevice& graphics, const ShaderSource& methoddesc = ShaderSource::Empty );
		furrovineapi HullShader( HullShader&& methoddesc );
		furrovineapi HullShader& operator=( HullShader&& methoddesc );

	};

}}
