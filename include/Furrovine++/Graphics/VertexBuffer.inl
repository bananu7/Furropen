#pragma once

#include <Furrovine++/Graphics/VertexBuffer.h>

namespace Furrovine { namespace Graphics {

	template <typename TVertex>
	VertexBuffer::VertexBuffer ( GraphicsDevice& graphicsdevice, const buffer_view<TVertex>& vertices, ResourceUsage bufferusage, CpuAccessFlags bufferaccess, ulword streamcount ) 
	: VertexBuffer( graphicsdevice, bufferusage, bufferaccess, streamcount ) {
		SetData( vertices );
	}

	template <typename TVertex>
	void VertexBuffer::SetData ( const buffer_view<TVertex>& vertices, ulword streamindex ) {
		SetData( vertices.data(), static_cast<uint32>( vertices.size() ), vertices.data()->Declaration(), streamindex );
	}

	template <typename TVertex>
	void VertexBuffer::SetData ( const buffer_view<TVertex>& vertices, const VertexDeclaration& declaration, ulword streamindex ) {
		SetData( vertices.data(), static_cast<uint32>( vertices.size() ), declaration, streamindex );
	}

	template <typename TVertex> 
	void VertexBuffer::SetData ( const TVertex* const verticesbegin, const TVertex* const verticesend, ulword streamindex ) {
		SetData( verticesbegin, static_cast<uint32>(verticesend - verticesbegin), vertices->Declaration(), streamindex );
	}

	template <typename TVertex> 
	void VertexBuffer::SetData ( const TVertex* const verticesbegin, const TVertex* const verticesend, const VertexDeclaration& declaration, ulword streamindex ) {
		SetData( verticesbegin, static_cast<uint32>(verticesend - verticesbegin), declaration, streamindex );
	}

	template <typename TVertex> 
	void VertexBuffer::SetData ( const TVertex* const vertices, uint32 count, ulword streamindex ) {
		SetData( vertices, count, vertices->Declaration(), streamindex );
	}

	template <typename TVertex> 
	void VertexBuffer::SetData ( const TVertex* const vertices, uint32 count, const VertexDeclaration& vertexdeclaration, ulword streamindex ) {
		SetData( static_cast<const void* const>( vertices ), count, vertexdeclaration, streamindex );
	}

}}
