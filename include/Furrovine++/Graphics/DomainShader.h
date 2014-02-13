#pragma once

#include <Furrovine++/Graphics/Shader.h>

namespace Furrovine { namespace Graphics {

	class DomainShader : public Shader {
	public:
		furrovineapi DomainShader( GraphicsDevice& graphics, const ShaderSource& methoddesc = ShaderSource::Empty );
		furrovineapi DomainShader( DomainShader&& methoddesc );
		furrovineapi DomainShader& operator=( DomainShader&& methoddesc );

	};

}}
