#pragma once

#include <Furrovine++/Graphics/Constants.h>
#include <Furrovine++/Graphics/BlendStateDescription.h>

namespace Furrovine { namespace Graphics {

	struct BlendStateCollectionDescription {

		uint32 multisamplemask;
		bool alphatocoveragemultisampling;
		bool independentblendstates;
		std::array<BlendStateDescription, detail::SimultaneousRenderTargets> BlendStates;

	};

}}