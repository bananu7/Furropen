#pragma once

#include <Furrovine++/Exception.h>

namespace Furrovine {

	class InvalidOperationException : public Exception {
	public:
		furrovineapi InvalidOperationException( );

		furrovineapi InvalidOperationException( const String& message );

		furrovineapi InvalidOperationException( String&& message );

	};

}
