#pragma once

#include <Furrovine++/BufferData.h>

namespace Furrovine {

	template <typename TContainer>
	BufferData::BufferData( TContainer&& container, ulword count ) : bufferpreserve( new ContainerPreserver<TContainer>( std::forward<TContainer>( container ) ) ) {

	}

}
