#ifndef FURROVINEMESH_DECL_H
#define FURROVINEMESH_DECL_H

#include <Furrovine++/Graphics/SubMesh.h>
#include <Furrovine++/Graphics/SubMeshCollection.h>
#include <Furrovine++/Graphics/MeshDescription.h>

namespace Furrovine { namespace Graphics {

	class Mesh {
	private:
		friend class SubMesh;
		friend class Model;
		Model* parentmodel;
		std::vector<ptr<VertexBuffer>> vertexbuffers;
		std::vector<ptr<IndexBuffer>> indexbuffers;
		SubMeshCollection submeshes;
		std::vector<ulword> materials;
		std::unordered_map<String, ulword> materialindices;
		String name;
		BoundingBox box;

		furrovineapi Mesh& operator= ( const Mesh& nocopy );
		furrovineapi Mesh ( const Mesh& nocopy );

	public:
		Graphics::Skeleton Skeleton;

		furrovineapi Mesh ( );
		furrovineapi Mesh ( GraphicsDevice& graphicsdevice, Model* parent, MeshDescription&& desc );
		furrovineapi Mesh ( GraphicsDevice& graphicsdevice, Model* parent, String meshname, const BoundingBox& boundingbox, 
			std::vector<VertexBufferData> vertices, std::vector<IndexBufferData> indices, 
			raw<Graphics::Skeleton> bones, std::vector<String> materialnames, 
			std::vector<SubMeshDescription> submeshes );
		furrovineapi Mesh ( Mesh&& );
		furrovineapi Mesh& operator= ( Mesh&& );

		furrovineapi const String& Name () const;
		furrovineapi const BoundingBox& Bounds () const;

		furrovineapi ulword SubMeshCount ( ) const;
		furrovineapi SubMesh& SubMeshAt ( ulword index );
		furrovineapi SubMesh& SubMeshByName ( const String& name );
		furrovineapi const SubMesh& SubMeshAt ( ulword index ) const;
		furrovineapi const SubMesh& SubMeshByName ( const String& name ) const;
		furrovineapi SubMesh& operator[] ( ulword index );
		furrovineapi SubMesh& operator[] ( const String& name );
		furrovineapi const SubMesh& operator[] ( ulword index ) const;
		furrovineapi const SubMesh& operator[] ( const String& name ) const;
		
		furrovineapi ulword MaterialCount ( ) const;
		furrovineapi Material& MaterialAt ( ulword index );
		furrovineapi Material& MaterialByName ( const String& name );
		furrovineapi const Material& MaterialAt ( ulword index ) const;
		furrovineapi const Material& MaterialByName ( const String& name ) const;
		
		furrovineapi void UpdateTransforms ( );
		furrovineapi void Update ( );

		furrovineapi void Render ( GraphicsDevice& graphicsdevice );

		furrovineapi ~Mesh();
	};

}}

#endif // FURROVINEMESH_DECL_H 