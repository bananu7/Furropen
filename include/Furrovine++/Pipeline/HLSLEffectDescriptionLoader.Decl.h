#pragma once

#include <Furrovine++/Lexical/HLSLLexer.h>
#include <Furrovine++/Graphics/ShaderEffectDescription.h>

namespace Furrovine { namespace Pipeline {

	class HLSLEffectDescriptionLoader {
	public:

		furrovineapi Graphics::ShaderEffectDescription Load ( const String& file );
		furrovineapi Graphics::ShaderEffectDescription Load ( IO::Stream& stream );
		furrovineapi Graphics::ShaderEffectDescription Load ( IO::TextReader& reader );
	};

}}
