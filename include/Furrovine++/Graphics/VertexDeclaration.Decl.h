#pragma once

#include <Furrovine++/Graphics/VertexElement.h>

namespace Furrovine { namespace Graphics {

	struct VertexDeclaration {
	protected:
		std::vector<VertexElement> elements;
		uint stride;

		template <ulword n, typename T, typename ...Tn >
		void DeduceElement ( uint vertexstride, uint& byteoffset, T&& t, Tn&&... elemn );

		template <ulword n>
		void DeduceElement ( uint vertexstride, uint& byteoffset );

	public:

		furrovineapi VertexDeclaration( );

		furrovineapi VertexDeclaration( VertexDeclaration&& mov );
		furrovineapi VertexDeclaration& operator=( VertexDeclaration&& mov );
		furrovineapi VertexDeclaration& operator=( const VertexDeclaration& mov ) = default;
		furrovineapi VertexDeclaration( const VertexDeclaration& mov ) = default;

		template <typename ... Tn>
		VertexDeclaration ( uint vertexstride, Tn&&... elemn );

		furrovineapi VertexDeclaration( std::pair<uint, std::vector<VertexElement>> elems );
		furrovineapi VertexDeclaration( uint vertexstride, const std::initializer_list<VertexElement>& elems );
		furrovineapi VertexDeclaration( uint vertexstride, std::vector<VertexElement> elems );
		
		furrovineapi const std::vector<VertexElement>& Elements ( ) const;

		furrovineapi ulword ElementCount () const;

		furrovineapi ulword Stride () const;

		furrovineapi bool Compatible ( const VertexDeclaration& right ) const;

		furrovineapi bool Compatible ( const VertexDeclaration& right, bool& fudged ) const;

		furrovineapi void EnsureCompatible ( const VertexDeclaration& right ) const;

		furrovineapi void EnsureCompatible ( const VertexDeclaration& right, bool& fudged ) const;

		furrovineapi ~VertexDeclaration();

	};



	struct VertexDeclarationCompatible {

		furrovineapi bool operator () ( const VertexDeclaration* left, const VertexDeclaration* right ) const;

	};

}}
