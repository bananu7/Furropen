#pragma once

#include <vector>
#include <Furrovine++/handle.h>
#include <Furrovine++/Graphics/graphics_handle.h>
#include <Furrovine++/Graphics/ResourceMapping.h>
#include <Furrovine++/Graphics/ResourceOptionFlags.h>
#include <Furrovine++/Graphics/BindFlags.h>
#include <Furrovine++/Graphics/IndexElementFormat.h>
#include <Furrovine++/Graphics/IndexElementSize.h>
#include <Furrovine++/Graphics/CpuAccessFlags.h>
#include <Furrovine++/Graphics/ResourceUsage.h>
#include <Furrovine++/Graphics/GpuBufferDescription.h>
#include <Furrovine++/Graphics/SubresourceData.h>
#include <Furrovine++/Graphics/GraphicsResource.h>

namespace Furrovine { namespace Graphics {

	class GpuMultiBuffer : public GraphicsResource {
	protected:
		struct deleter {
			furrovineapi void operator()( graphics_handle p );
		};
		GpuBufferDescription defaultgpubufferdesc;
		std::vector<handle<graphics_handle, deleter>> gpubuffers;
		std::vector<GpuBufferDescription> gpubufferdescs;
	
	public:

		furrovineapi GpuMultiBuffer( GpuMultiBuffer&& mov );

		furrovineapi GpuMultiBuffer( GraphicsDevice* graphicsdevice = null,
			BindFlags bufferbinding = BindFlags::None,
			ResourceUsage bufferusage = ResourceUsage::Default,
			CpuAccessFlags bufferaccess = CpuAccessFlags::None,
			ResourceOptionFlags options = ResourceOptionFlags::None,
			uint32 bufferstructurestride = 0,
			uint32 bytewidth = 0, uint32 expectedbuffers = 1 );

		furrovineapi GpuMultiBuffer( GraphicsDevice& graphicsdevice,
			BindFlags bufferbinding = BindFlags::None,
			ResourceUsage bufferusage = ResourceUsage::Default,
			CpuAccessFlags bufferaccess = CpuAccessFlags::None,
			ResourceOptionFlags options = ResourceOptionFlags::None,
			uint32 bufferstructurestride = 0,
			uint32 bytewidth = 0, uint32 expectedbuffers = 1 );

		furrovineapi ulword GpuBufferCount( ) const;

		furrovineapi graphics_handle GpuBufferResource( ulword bufferindex = 0 ) const;

	protected:

		furrovineapi void EnsureGpuBuffersIndexable( ulword bufferindex );

		furrovineapi void Create( ulword bufferindex, const SubresourceData& initialdata = SubresourceData::None, bool overwrite = false );
		furrovineapi void Create( ulword bufferindex, const GpuBufferDescription& gpubufferdesc, const SubresourceData& initialdata = SubresourceData::None, bool overwrite = false );

	};

}}
