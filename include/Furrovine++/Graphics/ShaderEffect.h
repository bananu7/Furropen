#pragma once

#include <Furrovine++/Graphics/ShaderTechnique.h>
#include <Furrovine++/Graphics/ShaderEffectParameterCollection.h>

namespace Furrovine { namespace Graphics {

	class ShaderEffect : public GraphicsResource {
	private:
		furrovineapi void Create ( const ShaderEffectDescription& description );

	protected:
		String shadername;
		std::unordered_map<String, ulword> techniqueindices;
		std::vector<ShaderTechnique> techniques;
		ShaderEffectParameterCollection parameters;

	public:

		furrovineapi ShaderEffect( GraphicsDevice& graphicsdevice, const String& source );
		furrovineapi ShaderEffect( GraphicsDevice& graphicsdevice, const buffer_view<byte>& bytecode );
		furrovineapi ShaderEffect( GraphicsDevice& graphicsdevice, const ShaderEffectDescription& description );

		furrovineapi ShaderEffect ( ShaderEffect&& mov );
		furrovineapi ShaderEffect& operator= ( ShaderEffect&& mov );

		furrovineapi const String& ShaderName ();

		furrovineapi ulword TechniqueCount () const;

		furrovineapi ShaderTechnique& TechniqueAt ( ulword index );

		furrovineapi ShaderTechnique& TechniqueByName ( const String& name );

		furrovineapi bool TryGetTechniqueByName ( const String& name, ShaderTechnique*& technique );

		furrovineapi bool TryGetTechniqueAt ( ulword index, ShaderTechnique*& technique );

		furrovineapi ShaderTechnique& operator[]( ulword index );
		furrovineapi ShaderTechnique& operator[]( String name );
	};

}}
