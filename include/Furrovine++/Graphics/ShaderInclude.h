#pragma once

#include <Furrovine++/std_defines.h>
#include <vector>
#include <list>
#include <unordered_map>
#include <Furrovine++/PrimitiveTypes.h>
#include <Furrovine++/Strings.h>
#include <Furrovine++/any.h>
#include <Furrovine++/Graphics/ShaderIncludeMode.h>

namespace Furrovine { namespace Graphics {

	struct ShaderInclude {
	private:
		typedef std::list<std::vector<byte>> TIncludeList;
		typedef TIncludeList::iterator TIncludeListToken;
		std::unordered_map<const void*, TIncludeListToken> includeindices;
		TIncludeList includes;
		any inclusioncallback;

	public:

		furrovineapi ShaderInclude( );

		furrovineapi uint32 Open( ShaderIncludeMode includemode, String filename, const void* parentdata, const void*& outputdata, ulword& outputbytesize );

		furrovineapi uint32 Close( const void* data );

		furrovineapi void* CallbackResource( ) const;
		
	};

}}
