#pragma once

#include <Furrovine++/std_defines.h>
#include <vector>
#include <Furrovine++/Graphics/ShaderPassDescription.h>

namespace Furrovine { namespace Graphics {

	struct ShaderTechniqueDescription {
	public:
		String TechniqueName;
		std::vector<ShaderPassDescription> PassDescriptions;

		furrovineapi ShaderTechniqueDescription ( );

		furrovineapi ulword PassCount () const;

		furrovineapi void Add( const ShaderPassDescription& desc );

		furrovineapi void Add( ShaderPassDescription&& desc );

		furrovineapi ShaderPassDescription& operator[] ( ulword index );

		furrovineapi const ShaderPassDescription& operator[] ( ulword index ) const;

	};

}}
