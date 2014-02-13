#ifndef FURROVINEINDEXBUFFERDATA_INL
#define FURROVINEINDEXBUFFERDATA_INL

#include <Furrovine++/Graphics/IndexBufferData.h>

namespace Furrovine { namespace Graphics {

	template <typename TContainer>
	IndexBufferData::IndexBufferData ( TContainer&& container, ulword count ) 
	: BufferData( std::forward<TContainer>( container ), count ), indexcount(count), format( ToIndexElementFormat<TContainer::value_type>() ) {

	}

	template <typename TContainer>
	IndexBufferData::IndexBufferData ( TContainer&& container, IndexElementFormat indexformat ) 
		: BufferData( std::forward<TContainer>( container ), container.size() ), indexcount(container.size()), format( indexformat ) {

	}

	template <typename TContainer>
	IndexBufferData::IndexBufferData ( TContainer&& container, ulword count, IndexElementFormat indexformat ) 
		: BufferData( std::forward<TContainer>( container ), container.size() ), indexcount(count), format( indexformat ) {

	}

}}

#endif // FURROVINEINDEXBUFFERDATA_INL 