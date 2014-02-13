#pragma once

#include <bitset>
#include <Furrovine++/Graphics/Constants.h>
#include <Furrovine++/Graphics/GraphicsResource.h>
#include <Furrovine++/Graphics/SamplerState.h>
#include <Furrovine++/Graphics/ShaderStage.h>
#include <Furrovine++/Graphics/SamplerStateCollectionDescription.h>
#include <Furrovine++/uninitialized.h>

namespace Furrovine { namespace Graphics {
	
	class SamplerStateCollection : GraphicsResource {
	protected:
		bool applied;
		std::array<std::array<uninitialized<SamplerState>, detail::ShaderSamplerSlots>, detail::PipelineStages> samplers;
		std::array<std::array<graphics_handle, detail::ShaderSamplerSlots>, detail::PipelineStages> rawsamplers;
		std::array<std::bitset<detail::ShaderSamplerSlots>, detail::PipelineStages> dirty;

	public:

		furrovineapi SamplerStateCollection( GraphicsDevice& graphicsdevice );

		furrovineapi void Apply( );

		furrovineapi void SetSampler( ulword textureindex, const SamplerState& value );
		furrovineapi void SetSampler ( ulword textureindex, ShaderStage shader, const SamplerState& value );
		furrovineapi const SamplerState& GetSampler ( ulword textureindex, ShaderStage shader = ShaderStage::Pixel );

		furrovineapi const SamplerState& SamplerStateCollection::operator[] ( ulword textureindex );
		furrovineapi const SamplerState& SamplerStateCollection::operator() ( ulword textureindex, ShaderStage shader = ShaderStage::Pixel );

		furrovineapi ~SamplerStateCollection ();

	};
	
}}
