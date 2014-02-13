#pragma once

#include <Furrovine++/Graphics/SubMesh.h>
#include <Furrovine++/Collections/IndexableDictionary.h>

namespace Furrovine { namespace Graphics {

	class SubMeshCollection : public Collections::IndexableDictionary<String, SubMesh> {
	private:
		furrovineapi SubMeshCollection ( const SubMeshCollection& nocopy );

		furrovineapi SubMeshCollection& operator= ( const SubMeshCollection& nocopy );
	
	public:
		
		furrovineapi SubMeshCollection ( );

		furrovineapi SubMeshCollection ( SubMeshCollection&& mov );

		furrovineapi SubMeshCollection& operator= ( SubMeshCollection&& mov );

	};

}}
