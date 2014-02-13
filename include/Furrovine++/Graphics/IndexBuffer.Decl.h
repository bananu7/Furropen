#pragma once

#include <Furrovine++/Graphics/PrimitiveTopology.h>
#include <Furrovine++/Graphics/GpuBuffer.h>
#include <Furrovine++/Graphics/IndexElementFormat.h>
#include <Furrovine++/Graphics/IndexElementSize.h>
#include <Furrovine++/buffer_view.h>

namespace Furrovine { namespace Graphics {
	
	class IndexBuffer : public GpuBuffer {
	private:
		uint32 indexcount;
		IndexElementSize indexelementsize;
		IndexElementFormat indexelementformat;

	public:
	
		furrovineapi IndexBuffer( IndexBuffer&& mov );
		furrovineapi IndexBuffer( GraphicsDevice& graphicsdevice, ResourceUsage bufferusage = ResourceUsage::Default );
		furrovineapi IndexBuffer ( GraphicsDevice& graphicsdevice, ResourceUsage bufferusage, CpuAccessFlags bufferbinding );
		furrovineapi IndexBuffer ( GraphicsDevice& graphicsdevice, const IndexBufferData& indices, ResourceUsage bufferusage = ResourceUsage::Default, CpuAccessFlags bufferbinding = CpuAccessFlags::None );
		template <typename TIndex> 
		IndexBuffer ( GraphicsDevice& graphicsdevice, const buffer_view<TIndex>& indices, ResourceUsage bufferusage = ResourceUsage::Default, CpuAccessFlags bufferbinding = CpuAccessFlags::None );

		furrovineapi void SetData ( const IndexBufferData& data );
		template <typename TIndex> 
		void SetData ( const buffer_view<TIndex>& indices );
		template <typename TIndex> 
		void SetData ( const buffer_view<TIndex>& indices, IndexElementFormat format );
		template <typename TIndex> 
		void SetData ( const TIndex* indices, uint32 count );
		void SetData( const void* indices, uint32 count, IndexElementFormat format );

		furrovineapi uint32 IndexCount () const;
		furrovineapi IndexElementSize IndexSize () const;
		furrovineapi IndexElementFormat IndexFormat () const;

		furrovineapi ~IndexBuffer ();

	};
	
}}
