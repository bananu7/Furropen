#pragma once

#include <Furrovine++/BufferData.h>
#include <Furrovine++/Graphics/Declarations.Graphics.h>

namespace Furrovine { namespace Graphics {

	class VertexBufferData : public BufferData {
	private:
		ulword vertexcount;
		const VertexDeclaration* vertexdeclaration;

	public:
		template <typename TContainer>
		VertexBufferData ( TContainer&& container, ulword vertexcount );

		template <typename TContainer>
		VertexBufferData ( TContainer&& container, ulword vertexcount, const VertexDeclaration& declaration );

		furrovineapi VertexBufferData ( VertexBufferData&& mov );
		furrovineapi VertexBufferData& operator= ( VertexBufferData&& mov );

		furrovineapi ulword VertexCount( ) const;
		furrovineapi const VertexDeclaration& Declaration( ) const;

	};

}}
