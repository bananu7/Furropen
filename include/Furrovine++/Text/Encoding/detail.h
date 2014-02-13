#pragma once

#include <Furrovine++/PrimitiveTypes.h>

namespace Furrovine { namespace Text { namespace Encoding { namespace detail {

	template <typename T8>
	uint8 mask8 ( T8 value ) {
		return static_cast<uint8>( 0xff & value );
	}

	template <typename T16>
	uint16 mask16 ( T16 value ) {
		return static_cast<uint16>( 0xffff & value );
	}

}}}}