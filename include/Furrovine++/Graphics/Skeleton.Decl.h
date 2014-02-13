#pragma once

#include <Furrovine++/std_defines.h>
#include <vector>
#include <unordered_map>
#include <Furrovine++/Graphics/Bone.h>

namespace Furrovine { namespace Graphics {

	class Skeleton {
	private:
		std::vector<Bone*> bones;
		std::unordered_map<String, ulword> boneindices;
		Bone root;
		String name;

		furrovineapi std::vector<String> GetNames() const;
		furrovineapi void UpdateNames ( std::vector<String> bonenames );

	public:

		furrovineapi Skeleton ( );
		furrovineapi Skeleton ( const String& name );
		furrovineapi Skeleton ( const String& name, raw<Bone> rootbone, std::vector<String> bonenames );

		furrovineapi Skeleton ( const Skeleton& copy );
		furrovineapi Skeleton ( Skeleton&& mov );
		furrovineapi Skeleton& operator= ( const Skeleton& copy );
		furrovineapi Skeleton& operator= ( Skeleton&& mov );

		template <typename TContainer>
		void CopyTransforms ( TContainer& container ) const;
		furrovineapi std::vector<Matrix> CopyTransforms () const;
		furrovineapi void CopyTransforms ( buffer_view<Matrix>& view ) const;
		furrovineapi void CopyTransforms ( Matrix* data, ulword size ) const;
		furrovineapi void CopyTransforms ( Matrix* data, ulword size, ulword& index ) const;
		
		furrovineapi const std::vector<Bone*>& Bones () const;
		furrovineapi lword BoneIndex ( const String& bonename ) const;

		furrovineapi ulword Count () const;

		furrovineapi void Update ();
		furrovineapi void CalculateTransforms ();
		furrovineapi void UpdateLocal ( const String& bonename, const Matrix& local );

		furrovineapi bool IsRoot () const;
		furrovineapi bool IsChild () const;
		furrovineapi bool IsParent () const;

		furrovineapi Bone& Parent ();
		furrovineapi const Bone& Parent () const;

		furrovineapi Bone& ChildAt ( ulword index );
		furrovineapi const Bone& ChildAt ( ulword index ) const;
		furrovineapi Bone& ChildByName ( const String& name );
		furrovineapi const Bone& ChildByName ( const String& name ) const;
		furrovineapi Bone& operator[] ( ulword index );
		furrovineapi const Bone& operator[] ( ulword index ) const;
		furrovineapi Bone& operator[] ( const String& name );
		furrovineapi const Bone& operator[] ( const String& name ) const;

		furrovineapi Bone* TryParent ();
		furrovineapi bool TryParent ( Bone*& parent );

		furrovineapi Bone* TryChildAt ( ulword index );
		furrovineapi bool TryChildAt ( ulword index, Bone*& child );

		furrovineapi Bone* TryChildByName ( const String& bonename );
		furrovineapi bool TryChildByName ( const String& bonename, Bone*& child );

		furrovineapi void AddChild ( const Bone& bone );
		furrovineapi void AddChild ( Bone&& bone );

		furrovineapi Bone* Find ( const String& bonename );
		furrovineapi bool Find ( const String& bonename, Bone*& resultbone );
		
		furrovineapi const String& Name () const;

	};

}}
