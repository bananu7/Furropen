#pragma once

#include <Furrovine++/PrimitiveTypes.h>
#include <Furrovine++/Comparison.h>
#include <Furrovine++/Graphics/DepthWriteMask.h>
#include <Furrovine++/Graphics/StencilOperationDescription.h>

namespace Furrovine { namespace Graphics {

	struct DepthStencilStateDescription {
		bool depthenabled;
		DepthWriteMask depthwritemask;
		Comparison depthfunc;
		bool stencilenabled;
		uint32 stencilreference;
		byte stencilreadmask;
		byte stencilwritemask;
		StencilOperationDescription front;
		StencilOperationDescription back;

		furrovineapi DepthStencilStateDescription( bool adepthenabled = true, DepthWriteMask adepthwritemask = DepthWriteMask::All, Comparison adepthfunc = Comparison::Less, bool astencilenabled = false, uint astencilreference = 0, byte astencilreadmask = 0xFF, byte astencilwritemask = 0xFF, StencilOperation afrontstencilfail = StencilOperation::Keep, StencilOperation afrontstencilpassdepthfail = StencilOperation::Keep, StencilOperation afrontstencilpassdepthpass = StencilOperation::Keep, Comparison afrontstencilfunc = Comparison::Always, StencilOperation abackstencilfail = StencilOperation::Keep, StencilOperation abackstencilpassdepthfail = StencilOperation::Keep, StencilOperation abackstencilpassdepthpass = StencilOperation::Keep, Comparison abackstencilfunc = Comparison::Always );
	};

}}