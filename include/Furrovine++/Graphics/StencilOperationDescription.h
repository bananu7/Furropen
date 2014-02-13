#pragma once

#include <Furrovine++/Comparison.h>
#include <Furrovine++/Graphics/StencilOperation.h>

namespace Furrovine { namespace Graphics {

	struct StencilOperationDescription {
		StencilOperation stencilfail;
		StencilOperation stencilpassdepthfail;
		StencilOperation stencilpassdepthpass;
		Comparison stencilfunc;
	};

}}