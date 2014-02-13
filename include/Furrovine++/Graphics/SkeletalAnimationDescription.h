#pragma once

#include <Furrovine++/Graphics/SkeletalAnimationChannel.h>
#include <Furrovine++/Graphics/Skeleton.h>

namespace Furrovine { namespace Graphics {

	struct SkeletalAnimationDescription {
		String Name;
		double Duration;
		Graphics::Skeleton AnimationSkeleton;
		std::vector<SkeletalAnimationChannel> Channels;

		furrovineapi SkeletalAnimationDescription ();

		furrovineapi SkeletalAnimationDescription( SkeletalAnimationDescription&& mov );
		furrovineapi SkeletalAnimationDescription& operator=( SkeletalAnimationDescription&& mov );

		furrovineapi SkeletalAnimationDescription( const SkeletalAnimationDescription& ) = delete;
		furrovineapi SkeletalAnimationDescription& operator=( const SkeletalAnimationDescription& ) = delete;
	};

}}
