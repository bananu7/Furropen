#ifndef FURROVINEAUTODESKFBXANIMATIONLOADER_DECL_H
#define FURROVINEAUTODESKFBXANIMATIONLOADER_DECL_H

#include <Furrovine++/std_defines.h>
#include <vector>
#include <Furrovine++/Graphics/SkeletalAnimation.h>

namespace Furrovine { namespace Pipeline {

	struct AutodeskFBXAnimationLoader {

		furrovineapi std::vector<Graphics::SkeletalAnimation> Load ( const String& path );

		furrovineapi std::vector<Graphics::SkeletalAnimation> Load ( IO::Stream& stream );

		furrovineapi std::vector<Graphics::SkeletalAnimation> operator() ( const String& path );

		furrovineapi std::vector<Graphics::SkeletalAnimation> operator() ( IO::Stream& stream );

	};

}}

#endif // FURROVINEAUTODESKFBXANIMATIONLOADER_DECL_H 