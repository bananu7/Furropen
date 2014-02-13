#ifndef FURROVINEMODEL_DECL_H
#define FURROVINEMODEL_DECL_H

#include <Furrovine++/Graphics/ModelMaterialCollection.h>
#include <Furrovine++/Graphics/ModelTextureCollection.h>
#include <Furrovine++/Graphics/ModelBoneCollection.h>
#include <Furrovine++/Graphics/MeshCollection.h>
#include <Furrovine++/Graphics/Mesh.h>
#include <Furrovine++/Graphics/ModelDescription.h>
#include <Furrovine++/Graphics/NamedImage2D.h>

namespace Furrovine { namespace Graphics {

	class Model {
	private:
		friend class Mesh;
		friend class SubMesh;

	public:
		String Name;
		BoundingBox Box;
		ModelMaterialCollection Materials;
		ModelTextureCollection Textures;
		MeshCollection Meshes;

		furrovineapi Model ( );
		furrovineapi Model ( GraphicsDevice& graphicsdevice, ModelDescription description );
		furrovineapi Model ( GraphicsDevice& graphicsdevice, String modelname, const BoundingBox& box, 
			ModelMaterialCollection modelmaterials, 
			std::vector<NamedImage2D> modeltextures, std::vector<MeshDescription> meshdescs );
		furrovineapi Model ( Model&& mov );
		furrovineapi Model& operator= ( Model&& mov );

		furrovineapi ulword MeshCount () const;
		furrovineapi Mesh& MeshAt ( ulword index );
		furrovineapi Mesh& MeshByName ( const String& name );
		furrovineapi const Mesh& MeshAt ( ulword index ) const;
		furrovineapi const Mesh& MeshByName ( const String& name ) const;
		furrovineapi Mesh& operator[] ( ulword index );
		furrovineapi Mesh& operator[] ( const String& name );
		furrovineapi const Mesh& operator[] ( ulword index ) const;
		furrovineapi const Mesh& operator[] ( const String& name ) const;

		furrovineapi void Update ( );
		furrovineapi void Render ( GraphicsDevice& graphicsdevice );
		
		furrovineapi ~Model ();

	};

}}

#endif // FURROVINEMODEL_DECL_H 