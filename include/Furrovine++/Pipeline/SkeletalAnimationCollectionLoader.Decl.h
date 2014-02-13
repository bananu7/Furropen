#pragma once

#include <Furrovine++/ptr.h>
#include <Furrovine++/Graphics/SkeletalAnimationCollection.h>

namespace Furrovine { namespace Pipeline {

	struct SkeletalAnimationCollectionLoader {

		furrovineapi ptr<Graphics::SkeletalAnimationCollection> Load ( IO::Stream& path );

		furrovineapi ptr<Graphics::SkeletalAnimationCollection> operator() ( IO::Stream& path );

		furrovineapi ptr<Graphics::SkeletalAnimationCollection> Load ( const String& path );

		furrovineapi ptr<Graphics::SkeletalAnimationCollection> operator() ( const String& path );

	};

}}
