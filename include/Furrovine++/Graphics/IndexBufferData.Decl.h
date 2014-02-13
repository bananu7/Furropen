#ifndef FURROVINEINDEXBUFFERDATA_DECL_H
#define FURROVINEINDEXBUFFERDATA_DECL_H

#include <Furrovine++/BufferData.h>
#include <Furrovine++/Graphics/IndexElementFormat.h>
#include <Furrovine++/Graphics/IndexElementSize.h>

namespace Furrovine { namespace Graphics {

	class IndexBufferData : public BufferData {
	private:
		ulword indexcount;
		IndexElementFormat format;

	public:
		
		template <typename TContainer>
		IndexBufferData ( TContainer&& container, IndexElementFormat format );

		template <typename TContainer>
		IndexBufferData ( TContainer&& container, ulword count );

		template <typename TContainer>
		IndexBufferData ( TContainer&& container, ulword count, IndexElementFormat format );

		furrovineapi IndexBufferData ( IndexBufferData&& mov );
		furrovineapi IndexBufferData& operator= ( IndexBufferData&& mov );

		furrovineapi ulword IndexCount () const;

		furrovineapi IndexElementFormat IndexFormat () const;

	};

}}

#endif // FURROVINEINDEXBUFFERDATA_DECL_H