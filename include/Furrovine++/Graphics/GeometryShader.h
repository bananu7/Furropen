#pragma once

#include <Furrovine++/Graphics/Shader.h>

namespace Furrovine { namespace Graphics {

	class GeometryShader : public Shader {
	public:
		furrovineapi GeometryShader( GraphicsDevice& graphics, const ShaderSource& methoddesc = ShaderSource::Empty );
		furrovineapi GeometryShader( GeometryShader&& mov );
		furrovineapi GeometryShader& operator=( GeometryShader&& mov );

	};

}}
