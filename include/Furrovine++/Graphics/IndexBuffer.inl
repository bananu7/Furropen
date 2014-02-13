#pragma once

#include <Furrovine++/Graphics/IndexBuffer.h>

namespace Furrovine { namespace Graphics {

	template <typename TIndex> 
	IndexBuffer::IndexBuffer ( GraphicsDevice& graphicsdevice, const buffer_view<TIndex>& indices, ResourceUsage bufferusage, CpuAccessFlags bufferaccess ) 
	: IndexBuffer( graphicsdevice, bufferusage, bufferaccess ) {
		SetData( indices );
	}

	template <typename TIndex> 
	void IndexBuffer::SetData ( const buffer_view<TIndex>& indices ) {
		SetData( indices.data( ), static_cast<uint32>( indices.size( ) ), ToIndexElementFormat<TIndex>( ) );
	}

	template <typename TIndex> 
	void IndexBuffer::SetData( const buffer_view<TIndex>& indices, IndexElementFormat format ) {
		SetData( indices.data(), static_cast<uint32>( indices.size() ), format );
	}

	template <typename TIndex> 
	void IndexBuffer::SetData ( const TIndex* indices, uint32 count ) {
		SetData( indices, count, ToIndexElementFormat<TIndex>( ) );
	}

}}
