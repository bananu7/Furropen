#pragma once

#include <Furrovine++/Graphics/VertexDeclaration.h>

namespace Furrovine { namespace Graphics {

	template <ulword n>
	void VertexDeclaration::DeduceElement( uint vertexstride, uint& byteoffset ) {

	}

	template <ulword n, typename T, typename ... TElemn>
	void VertexDeclaration::DeduceElement( uint vertexstride, uint& byteoffset, T&& t, TElemn&&... elemn ) {
		static_assert( std::is_same<T, VertexElement>::value, "Elements can only be VertexElements" );
		VertexElement& e = elements[ (elements.size() - n) ];
		e = t;
		if ( e.offset == 0xFFFFFFFF ) {
			e.offset = byteoffset;
		}
		e.inputslot = 0;
		e.datausage = VertexDataUsage::PerVertex;
		byteoffset += e.Size( );
		DeduceElement< n - 1, TElemn...>( vertexstride, byteoffset, std::forward<TElemn>( elemn )... );
	}

	template <typename ... TElemn>
	VertexDeclaration::VertexDeclaration( uint vertexstride, TElemn&&... elemn ) : elements( sizeof...( elemn ) ), stride(vertexstride) {
		uint byteoffset = 0;
		DeduceElement< sizeof...(elemn), TElemn...>( vertexstride, byteoffset, std::forward<TElemn>( elemn )... );
		furrovineassert( byteoffset == stride, "ByteStride is not equal to the calculated byte offset of the elements" );
	}

}}
