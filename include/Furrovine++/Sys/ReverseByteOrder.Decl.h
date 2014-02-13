#pragma once

#include <Furrovine++/Sys/ByteOrder.h>

namespace Furrovine { namespace Sys {

	struct ReverseByteOrder : public ByteOrder {
	public:

		furrovineapi ReverseByteOrder ();

	};

}}
