#pragma once

#include <Furrovine++/Enums.h>

namespace Furrovine { namespace Graphics {

	enum class DepthStencilViewFlags {
		None = 0x0,
		ReadOnlyDepth = 0x01,
		ReadOnlyStencil = 0x02,
		ReadOnlyDepthStencil = ReadOnlyDepth | ReadOnlyStencil
	};

}}