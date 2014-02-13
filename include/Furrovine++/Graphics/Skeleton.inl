#pragma once

#include <Furrovine++/Graphics/Skeleton.h>

namespace Furrovine { namespace Graphics {

	template <typename TContainer>
	void Skeleton::CopyTransforms ( TContainer& container ) const {
		root.CopyTransforms( container );
	}

}}
