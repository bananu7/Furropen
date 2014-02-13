#pragma once

#include <Furrovine++/Exception.h>

namespace Furrovine {

	class NotImplementedException : public Exception {
	private:

	public:

		furrovineapi NotImplementedException( );

		furrovineapi NotImplementedException( String message );

	};

	inline furrovineapi void NotImplemented( ) {
		throw NotImplementedException( );
	}

}
 