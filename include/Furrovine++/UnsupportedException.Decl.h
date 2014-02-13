#pragma once

#include <Furrovine++/Exception.h>

namespace Furrovine {

	class UnsupportedException : public TException<std::runtime_error> {
	public:

		furrovineapi UnsupportedException( );
		furrovineapi UnsupportedException( const String& message );

	};

}
