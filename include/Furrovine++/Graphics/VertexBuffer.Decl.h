#pragma once

#include <Furrovine++/Graphics/PrimitiveTopology.h>
#include <Furrovine++/Graphics/GpuMultiBuffer.h>
#include <Furrovine++/buffer_view.h>

namespace Furrovine { namespace Graphics {
	
	class VertexBuffer : public GpuMultiBuffer {
	public:
		furrovineapi static const ulword MaxVertexBufferStreams;

	private:
		std::vector<const VertexDeclaration*> vertexdeclarations;
		std::vector<uint32> vertexcounts;
		std::vector<uint32> vertexstrides;
		ulword vertexstreamcount;

	protected:
		furrovineapi void EnsureVertexIndexable ( ulword bufferindex );

	public:

		furrovineapi VertexBuffer( VertexBuffer&& mov );
		furrovineapi VertexBuffer( GraphicsDevice& graphicsdevice, ResourceUsage bufferusage = ResourceUsage::Default, ulword streamcount = 1 );
		furrovineapi VertexBuffer ( GraphicsDevice& graphicsdevice, ResourceUsage bufferusage, CpuAccessFlags bufferbinding, ulword streamcount = 1 );
		furrovineapi VertexBuffer ( GraphicsDevice& graphicsdevice, const VertexBufferData& vertices, ResourceUsage bufferusage = ResourceUsage::Default, CpuAccessFlags bufferbinding = CpuAccessFlags::None, ulword streamcount = 1 );
		template <typename TVertex>
		VertexBuffer ( GraphicsDevice& graphicsdevice, const buffer_view<TVertex>& vertices, ResourceUsage bufferusage = ResourceUsage::Default, CpuAccessFlags bufferbinding = CpuAccessFlags::None, ulword streamcount = 1 );

		furrovineapi uint32 StreamCount ( ) const;
		furrovineapi uint32 VertexStride ( ulword streamindex = 0 ) const;
		furrovineapi uint32 VertexCount ( ulword streamindex = 0 ) const;
		furrovineapi const VertexDeclaration& Declaration ( ulword streamindex = 0 ) const;
		furrovineapi const std::vector<uint32>& VertexStrides () const;
		furrovineapi const std::vector<uint32>& VertexCounts () const;
		furrovineapi const std::vector<const VertexDeclaration*>& Declarations () const;
		
		furrovineapi void SetData ( const VertexBufferData& data, ulword streamindex = 0 );
		template <typename TVertex>
		void SetData ( const buffer_view<TVertex>& vertices, ulword streamindex = 0 );
		template <typename TVertex>
		void SetData ( const buffer_view<TVertex>& vertices, const VertexDeclaration& declaration, ulword streamindex = 0 );
		template <typename TVertex> 
		void SetData ( const TVertex* const verticesbegin, const TVertex* const verticesend, ulword streamindex = 0 );
		template <typename TVertex> 
		void SetData ( const TVertex* const verticesbegin, const TVertex* const verticesend, const VertexDeclaration& declaration, ulword streamindex = 0 );
		template <typename TVertex> 
		void SetData ( const TVertex* const vertices, uint32 count, ulword streamindex = 0 );
		template <typename TVertex> 
		void SetData ( const TVertex* const vertices, uint32 count, const VertexDeclaration& declaration, ulword streamindex = 0 );
		furrovineapi void SetData( const void* const vertices, uint32 count, const VertexDeclaration& declaration, ulword streamindex = 0 );

		furrovineapi ~VertexBuffer ();

	};
	
}}
 