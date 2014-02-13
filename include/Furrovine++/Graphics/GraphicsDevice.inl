#pragma once

#include <Furrovine++/Graphics/GraphicsDevice.h>
#include <Furrovine++/Graphics/VertexBuffer.h>
#include <Furrovine++/Graphics/IndexBuffer.h>

namespace Furrovine { namespace Graphics {

	template <typename TVertex> 
	void GraphicsDevice::RenderUserPrimitives ( PrimitiveTopology primitive, TVertex* vertices, uint32 vertexoffset, uint32 primitivecount ) {
		RenderUserPrimitives( primitive, vertices->Declaration(), vertices, vertexoffset, primitivecount );
	}

	template <typename TVertex> 
	void GraphicsDevice::RenderUserPrimitives ( PrimitiveTopology primitive, const VertexDeclaration& declaration, TVertex* vertices, uint32 vertexoffset, uint32 primitivecount ) {
		ulword ivindex;
		runtime_type vtype = typeof<TVertex>( );

		auto instantindidicesit = instantindices.find( vtype );
		if ( instantindidicesit == instantindices.end( ) ) {
			ivindex = instantvtxbuffers.size( );
			instantvtxbuffers.emplace_back( *this, ResourceUsage::Dynamic, CpuAccessFlags::Writable );
			instantidxbuffers.emplace_back( *this, ResourceUsage::Dynamic, CpuAccessFlags::Writable );
			instantindidicesit = instantindices.emplace_hint( instantindidicesit, vtype, ivindex );
		}

		ivindex = instantindidicesit->second;
		VertexBuffer& vbuffer = instantvtxbuffers[ ivindex ];
		IndexBuffer& ibuffer = instantidxbuffers[ ivindex ];
		
		uint32 vertexcount = Primitives::VertexCount( primitive, primitivecount );
		vbuffer.SetData( vertices, vertexoffset + vertexcount );
		
		RenderUserPrimitives( primitive, declaration, vbuffer, 0, vertexoffset, primitivecount );
	}

	template <typename TVertex, typename TIndex> 
	void GraphicsDevice::RenderUserIndexedPrimitives ( PrimitiveTopology primitive, TVertex* vertices, uint32 vertexoffset, uint32 vertexcount, TIndex* indices, uint32 startindex, uint32 primitivecount ) {
		RenderUserIndexedPrimitives(primitive, vertices->Declaration(), vertices, 0, vertexoffset, vertexcount, indices, startindex, primitivecount );
	}

	template <typename TVertex, typename TIndex> 
	void GraphicsDevice::RenderUserIndexedPrimitives ( PrimitiveTopology primitive, TVertex* vertices, uint32 basevertex, uint32 vertexoffset, uint32 vertexcount, TIndex* indices, uint32 startindex, uint32 primitivecount ) {
		RenderUserIndexedPrimitives(primitive, vertices->Declaration(), vertices, basevertex, vertexoffset, vertexcount, indices, startindex, primitivecount );
	}

	template <typename TVertex, typename TIndex> 
	void GraphicsDevice::RenderUserIndexedPrimitives ( PrimitiveTopology primitive, const VertexDeclaration& declaration, TVertex* vertices, uint32 basevertex, uint32 vertexoffset, uint32 vertexcount, TIndex* indices, uint32 startindex, uint32 primitivecount ) {
		ulword ivindex;		
		runtime_type vtype = typeof<TVertex>( );
		auto instantindidicesit = instantindices.find( vtype );
		if ( instantindidicesit == instantindices.end() ) {
			ivindex = instantvtxbuffers.size();
			instantvtxbuffers.emplace_back( *this, ResourceUsage::Dynamic, CpuAccessFlags::Writable );
			instantidxbuffers.emplace_back( *this, ResourceUsage::Dynamic, CpuAccessFlags::Writable );
			instantindidicesit = instantindices.emplace_hint( instantindidicesit, vtype, ivindex );
		}
		
		ivindex = instantindidicesit->second;
		VertexBuffer& vbuffer = instantvtxbuffers[ ivindex ];
		IndexBuffer& ibuffer = instantidxbuffers[ ivindex ];
		
		uint32 indexcount = Primitives::VertexCount( primitive, primitivecount );

		vbuffer.SetData( vertices, basevertex + vertexoffset + vertexcount, declaration );
		ibuffer.SetData( indices, startindex + indexcount, ToIndexElementFormat<TIndex>( ) );

		RenderUserIndexedPrimitives( primitive, declaration, vbuffer, basevertex, vertexoffset, vertexcount, ibuffer, startindex, primitivecount );
	}

}}
