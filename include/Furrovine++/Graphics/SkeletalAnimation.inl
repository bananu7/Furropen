#pragma once

#include <Furrovine++/Graphics/SkeletalAnimation.h>

namespace Furrovine { namespace Graphics {

	template <typename TContainer>
	void SkeletalAnimation::CopyTransforms ( TContainer& container ) const {
		buffer_view<Matrix> view( container );
		CopyTransforms( view );
	}

}}
