#pragma once

#include <Furrovine++/Graphics/Texture.h>
#include <Furrovine++/Graphics/SamplerState.h>
#include <Furrovine++/Graphics/Constants.h>
#include <Furrovine++/Graphics/ShaderStage.h>

namespace Furrovine { namespace Graphics {
	
	class ShaderResourceViewCollection : GraphicsResource {	
	private:
		typedef std::array<ShaderResourceView*, detail::ShaderSamplerSlots> Resources;
		typedef std::array<graphics_handle, detail::ShaderSamplerSlots> RawResources;
		std::array<Resources, detail::PipelineStages> resources;
		std::array<RawResources, detail::PipelineStages> rawresources;

	public:
		furrovineapi ShaderResourceViewCollection ( );

		furrovineapi ShaderResourceView* ResourceAt( ulword index, ShaderStage method = ShaderStage::Pixel );
		furrovineapi graphics_handle RawResourceAt( ulword index, ShaderStage method = ShaderStage::Pixel );
		furrovineapi void SetResourceAt( ShaderResourceView* resource, ulword index, ShaderStage method = ShaderStage::Pixel );
		furrovineapi void SetRawResourceAt( graphics_handle resource, ulword index, ShaderStage method = ShaderStage::Pixel );
		furrovineapi Resources& operator [] ( ShaderStage method );
		furrovineapi const Resources& operator [] ( ShaderStage method ) const;

		furrovineapi ~ShaderResourceViewCollection ();
	
	};
	
}}
