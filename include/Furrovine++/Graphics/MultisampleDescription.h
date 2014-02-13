#pragma once

#include <Furrovine++/PrimitiveTypes.h>

namespace Furrovine { namespace Graphics {

	struct MultisampleDescription {
		uint32 Count = 1;
		uint32 Quality = 0;

		MultisampleDescription( uint32 count = 1, uint32 quality = 0 )
			: Count( count ), Quality( quality ) {

		}
	};

}}