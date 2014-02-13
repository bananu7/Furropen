#ifndef FURROVINEBONE_DECL_H
#define FURROVINEBONE_DECL_H

#include <Furrovine++/std_defines.h>
#include <vector>
#include <unordered_map>
#include <Furrovine++/Matrix.h>
#include <Furrovine++/Strings.h>
#include <Furrovine++/raw.h>
#include <Furrovine++/buffer_view.h>

namespace Furrovine { namespace Graphics {

	class Bone {
	protected:
		String name;
		Bone* parent;
		std::vector<Bone> bones;
		std::unordered_map<String, ulword> boneindices;
		
		void UpdateRelationships ();

	public:

		Matrix BindPose, Local, Global;

		Bone ( );
		Bone ( const String& bonename, Bone* parentbone );
		Bone ( const String& bonename, Bone* parentbone, std::vector<Bone> childbones );
		Bone ( const Bone& copy );
		Bone ( Bone&& mov );
		Bone& operator= ( const Bone& copy );
		Bone& operator= ( Bone&& mov );

		std::vector<Matrix> CopyTransforms () const;
		void CopyTransforms ( buffer_view<Matrix>& view ) const;
		void CopyTransforms ( Matrix* data, ulword size ) const;
		void CopyTransforms ( Matrix* data, ulword size, ulword& index ) const;
		template <typename TContainer>
		void CopyTransforms ( TContainer& container ) const;

		void Update ( );
		
		void CalculateTransforms ( );

		ulword Count () const;

		bool IsRoot () const;

		bool IsChild () const;

		bool IsParent () const;

		Bone& Parent ();
		const Bone& Parent () const;

		Bone& ChildAt ( ulword index );
		const Bone& ChildAt ( ulword index ) const;

		Bone& ChildByName ( const String& bonename );
		const Bone& ChildByName ( const String& bonename ) const;		
		
		Bone* TryParent ();
		bool TryParent ( Bone*& parent );

		Bone* TryChildAt ( ulword index );
		bool TryChildAt ( ulword index, Bone*& child );

		Bone* TryChildByName ( const String& bonename );
		bool TryChildByName ( const String& bonename, Bone*& child );
		
		void AddChild ( const Bone& bone );
		void AddChild ( Bone&& bone );

		Bone* Find ( const String& bonename );
		bool Find ( const String& bonename, Bone*& resultbone );

		const String& Name () const;
	};

}}

#endif // FURROVINEBONE_DECL_H 