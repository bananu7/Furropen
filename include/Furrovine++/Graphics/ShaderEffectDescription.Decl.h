#pragma once

#include <Furrovine++/Graphics/ShaderTechniqueDescription.h>
#include <Furrovine++/Graphics/ShaderPassDescription.h>

namespace Furrovine { namespace Graphics {

	struct ShaderEffectDescription {
	public:
		String Name;
		std::vector<ShaderTechniqueDescription> TechniqueDescriptions;

		furrovineapi ShaderEffectDescription( );

		furrovineapi ulword TechniqueCount( ) const;
		
		furrovineapi void Add( ShaderTechniqueDescription& desc );
		
		furrovineapi ShaderTechniqueDescription& TechniqueAt( ulword index );
		furrovineapi const ShaderTechniqueDescription& TechniqueAt( ulword index ) const;
		furrovineapi ShaderTechniqueDescription& operator[] ( ulword index );
		furrovineapi const ShaderTechniqueDescription& operator[] ( ulword index ) const;
	};	

}}
