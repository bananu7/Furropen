#pragma once

#include <Furrovine++/numeric_integer_def.h>
#include <Furrovine++/MessageId.h>
#include <Furrovine++/Export.h>

namespace Furrovine {

	struct MessageHeader {
		MessageId id;
		uint32 custom;

		furrovineapi MessageHeader( );

		furrovineapi MessageHeader( MessageId id );

		furrovineapi MessageHeader( uint32 id );

	};

}