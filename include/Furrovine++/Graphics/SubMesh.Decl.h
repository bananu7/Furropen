#pragma once

#include <Furrovine++/BoundingBox.h>
#include <Furrovine++/Graphics/VertexBuffer.h>
#include <Furrovine++/Graphics/IndexBuffer.h>
#include <Furrovine++/Graphics/SkeletalAnimation.h>
#include <Furrovine++/Graphics/Material.h>
#include <Furrovine++/Graphics/SubMeshDescription.h>

namespace Furrovine { namespace Graphics {

	class SubMesh {
	private:
		friend class Mesh;
		friend class Model;
		Mesh* parentmesh;
		Matrix world;
		BoundingBox box;
		String name;
		PrimitiveTopology buffertopology;
		lword vertices, indices;
		std::vector<ulword> materials;
		std::unordered_map<String, ulword> materialindices;
		uint32 vertexcount, vertexoffset, indexcount, basevertex, indexoffset, primitivecount;

	public:
		furrovineapi SubMesh ( );
		furrovineapi SubMesh ( Mesh* parent, SubMeshDescription&& description );
		furrovineapi SubMesh ( Mesh* parent, String name, const BoundingBox& boundingbox,
			PrimitiveTopology vertextopology, lword vertexbufferindex, lword indexbufferindex, 
			uint32 vertexbuffercount, uint32 vertexbufferoffset, uint32 indexbasevertex, uint32 indexbuffercount, uint32 indexbufferoffset, uint32 bufferprimitivecount,
			std::vector<String> materials );		
		furrovineapi SubMesh ( SubMesh&& submesh );
		furrovineapi SubMesh& operator= ( SubMesh&& );

		furrovineapi const String& Name () const;
		furrovineapi const BoundingBox& Bounds () const;

		furrovineapi uint32 VertexOffset () const;
		furrovineapi uint32 BaseVertex () const;
		furrovineapi uint32 VertexCount () const;
		furrovineapi uint32 IndexOffset () const;
		furrovineapi uint32 IndexCount () const;
		furrovineapi uint32 PrimitiveCount () const;
		furrovineapi PrimitiveTopology Topology () const;
		furrovineapi bool HasVertices () const;
		furrovineapi bool HasIndices () const;
		furrovineapi ulword MaterialCount ( ) const;
		furrovineapi Material& MaterialAt ( ulword index );
		furrovineapi Material& MaterialByName ( const String& name );
		furrovineapi const Material& MaterialAt ( ulword index ) const;
		furrovineapi const Material& MaterialByName ( const String& name ) const;

		furrovineapi const IndexBuffer& Indices () const;
		furrovineapi const VertexBuffer& Vertices () const;

		furrovineapi bool Indexed () const;

		furrovineapi void Render ( GraphicsDevice& graphicsdevice );
	};

}}
