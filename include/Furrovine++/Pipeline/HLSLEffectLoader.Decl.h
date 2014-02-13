#pragma once

#include <Furrovine++/Pipeline/HLSLEffectDescriptionLoader.h>
#include <Furrovine++/Graphics/ShaderEffect.h>

namespace Furrovine { namespace Pipeline {

	class HLSLEffectLoader {
	protected:
		Graphics::GraphicsDevice& device;

	public:

		furrovineapi HLSLEffectLoader ( Graphics::GraphicsDevice& graphicsdevice );

		furrovineapi Graphics::ShaderEffect operator() ( const String& path );
		furrovineapi Graphics::ShaderEffect operator() ( IO::Stream& stream );
		furrovineapi Graphics::ShaderEffect operator() ( IO::TextReader& reader );

	};

}}
