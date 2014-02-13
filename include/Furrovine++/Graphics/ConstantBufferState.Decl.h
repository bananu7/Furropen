#pragma once

#include <bitset>
#include <array>
#include <Furrovine++/Declarations.h>
#include <Furrovine++/Graphics/graphics_handle.h>
#include <Furrovine++/Graphics/ShaderStage.h>
#include <Furrovine++/Graphics/GraphicsResource.h>

namespace Furrovine { namespace Graphics {

	class ConstantBufferState : GraphicsResource {
	private:
		std::array<std::array<graphics_handle, detail::ConstantBuffers>, detail::PipelineStages> constantbuffers;
		std::array<std::bitset<detail::ConstantBuffers>, detail::PipelineStages> dirty;
		
	public:

		furrovineapi ConstantBufferState( GraphicsDevice& graphics );

		furrovineapi void SetConstantBuffer( GpuBuffer* buffers, ulword count, ulword startlocation = 0, ShaderStage method = ShaderStage::Vertex );
		furrovineapi void SetConstantBuffer( buffer_view<GpuBuffer> buffers, ulword startlocation = 0, ShaderStage method = ShaderStage::Vertex );
		furrovineapi void SetConstantBuffer( graphics_handle* constantbuffers, ulword count, ulword startlocation = 0, ShaderStage method = ShaderStage::Vertex );
		furrovineapi void SetConstantBuffer( buffer_view<graphics_handle> constantbuffers, ulword startlocation = 0, ShaderStage method = ShaderStage::Vertex );

		furrovineapi void Apply( );
	};

}}
