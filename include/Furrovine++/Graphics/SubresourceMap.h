#pragma once

#include <Furrovine++/PrimitiveTypes.h>

namespace Furrovine { namespace Graphics {


	struct SubresourceMap {
		void* Data;
		uint RowPitch;
		uint DepthPitch;
	};


}}