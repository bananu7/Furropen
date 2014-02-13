#pragma once

#include <Furrovine++/Graphics/Shader.h>

namespace Furrovine { namespace Graphics {

	class ComputeShader : public Shader {
	public:
		ComputeShader( GraphicsDevice& graphics );

		ComputeShader( GraphicsDevice& graphics, const ShaderSource& methoddesc );

		~ComputeShader ();

	};

}}
