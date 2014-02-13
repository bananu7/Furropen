#pragma once

#include <Furrovine++/PrimitiveTypes.h>

namespace Furrovine { namespace Graphics {

	struct SubresourceData {
		furrovineapi static const SubresourceData None;

		const void* Memory;
		uint MemoryPitch;
		uint MemorySlicePitch;

		furrovineapi bool IsNone( ) const;
	};

}}