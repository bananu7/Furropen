#pragma once

#include <Furrovine++/handle.h>
#include <Furrovine++/Graphics/graphics_handle.h>
#include <Furrovine++/Graphics/ResourceMapping.h>
#include <Furrovine++/Graphics/ResourceOptionFlags.h>
#include <Furrovine++/Graphics/BindFlags.h>
#include <Furrovine++/Graphics/IndexElementFormat.h>
#include <Furrovine++/Graphics/IndexElementSize.h>
#include <Furrovine++/Graphics/CpuAccessFlags.h>
#include <Furrovine++/Graphics/ResourceUsage.h>
#include <Furrovine++/Graphics/GraphicsResource.h>
#include <Furrovine++/Graphics/GpuBufferDescription.h>
#include <Furrovine++/Graphics/SubresourceData.h>

namespace Furrovine { namespace Graphics {

	class GpuBuffer : public GraphicsResource {
	protected:
		struct deleter {
			furrovineapi void operator() ( graphics_handle p );
		};
		handle<graphics_handle, deleter>  gpubuffer;
		GpuBufferDescription gpubufferdesc;

	public:
		
		furrovineapi GpuBuffer( GpuBuffer&& gpubuffer );
		furrovineapi GpuBuffer& operator=( GpuBuffer&& gpubuffer );

		furrovineapi GpuBuffer ( GraphicsDevice* graphicsdevice = null,
			BindFlags bufferbinding = BindFlags::None,
			ResourceUsage bufferusage = ResourceUsage::Default,
			CpuAccessFlags bufferaccess = CpuAccessFlags::None,
			ResourceOptionFlags options = ResourceOptionFlags::None,
			uint32 bufferstructurestride = 0,
			uint32 bytewidth = 0 );

		furrovineapi GpuBuffer ( GraphicsDevice& graphicsdevice,
			BindFlags bufferbinding = BindFlags::None,
			ResourceUsage bufferusage = ResourceUsage::Default,
			CpuAccessFlags bufferaccess = CpuAccessFlags::None,
			ResourceOptionFlags options = ResourceOptionFlags::None,
			uint32 bufferstructurestride = 0,
			uint32 bytewidth = 0 );
		
		furrovineapi graphics_handle GpuBufferResource () const;

	protected:

		furrovineapi void Create ( const SubresourceData& initialdata = SubresourceData::None, bool overwrite = false );
	};

}}
