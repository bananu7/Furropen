#ifndef FURROVINEBONE_INL
#define FURROVINEBONE_INL

#include <Furrovine++/Graphics/Bone.h>

namespace Furrovine { namespace Graphics {

	template <typename TContainer>
	void Bone::CopyTransforms ( TContainer& container ) const {
		buffer_view<Matrix> view( container.data(), container.size() );
		CopyTransforms( view );
	}

}}

#endif // FURROVINEBONE_INL 