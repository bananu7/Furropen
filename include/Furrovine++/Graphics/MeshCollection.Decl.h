#pragma once

#include <Furrovine++/Graphics/Mesh.Decl.h>
#include <Furrovine++/Collections/IndexableDictionary.h>

namespace Furrovine { namespace Graphics {

	class MeshCollection : public Collections::IndexableDictionary<String, Mesh> {
	public:
		furrovineapi MeshCollection (  );

		furrovineapi MeshCollection( MeshCollection&& mov );
		furrovineapi MeshCollection& operator= ( MeshCollection&& mov );
		furrovineapi MeshCollection( const MeshCollection& nocopy ) = delete;
		furrovineapi MeshCollection& operator= ( const MeshCollection& nocopy ) = delete;

	};

}}
