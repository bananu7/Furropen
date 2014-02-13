#pragma once

#include <Furrovine++/Graphics/VertexBufferData.h>

namespace Furrovine { namespace Graphics {

	template <typename TContainer>
	VertexBufferData::VertexBufferData ( TContainer&& container, ulword count, const VertexDeclaration& declaration ) 
	: BufferData( std::forward<TContainer>( container ), count ), vertexcount(count) vertexdeclaration( declaration ) {

	}

	template <typename TContainer>
	VertexBufferData::VertexBufferData ( TContainer&& container, ulword count ) 
	: BufferData( std::forward<TContainer>( container ), count ), vertexcount(count), vertexdeclaration( &TContainer::value_type::Declaration() ) {

	}

}}
