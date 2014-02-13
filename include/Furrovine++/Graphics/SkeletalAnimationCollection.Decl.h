#pragma once

#include <Furrovine++/Graphics/SkeletalAnimation.h>
#include <Furrovine++/Collections/IndexableDictionary.h>

namespace Furrovine { namespace Graphics {

	class SkeletalAnimationCollection : public Collections::IndexableDictionary<String, SkeletalAnimation> {
	public:
		furrovineapi SkeletalAnimationCollection( );

		furrovineapi SkeletalAnimationCollection( const SkeletalAnimationCollection& copy ) = delete;
		furrovineapi SkeletalAnimationCollection& operator= ( const SkeletalAnimationCollection& copy ) = delete;

		furrovineapi SkeletalAnimationCollection ( SkeletalAnimationCollection&& mov );
		furrovineapi SkeletalAnimationCollection& operator= ( SkeletalAnimationCollection&& mov );

	};

}}
