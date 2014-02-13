#pragma once

#include <Furrovine++/Graphics/SamplerStateDescription.h>
#include <Furrovine++/Graphics/Constants.h>
#include <array>

namespace Furrovine { namespace Graphics {

	struct SamplerStateCollectionDescription : public std::array<SamplerStateDescription, detail::ShaderSamplerSlots> {
		
	};

}}