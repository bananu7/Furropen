#pragma once

#include <Furrovine++/Graphics/ShaderPassCollection.h>
#include <Furrovine++/Graphics/ShaderTechniqueDescription.h>

namespace Furrovine { namespace Graphics {

	class ShaderTechnique : public ShaderPassCollection {
	protected:
		String techniquename;

	public:

		furrovineapi ShaderTechnique( GraphicsDevice& graphicsdevice, const ShaderTechniqueDescription& techdesc );

		furrovineapi ShaderTechnique( ShaderTechnique&& mov );
		furrovineapi ShaderTechnique& operator= ( ShaderTechnique&& mov );

		furrovineapi const String& TechniqueName( ) const;

	};

}}
