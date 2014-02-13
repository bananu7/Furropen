#pragma once

#include <Furrovine++/Exception.h>

namespace Furrovine {

	class ErrorCodeException : public TException<std::system_error> {
	public:

		furrovineapi ErrorCodeException( );

		furrovineapi ErrorCodeException( const String& message, int result, bool appendresultcode = true );

		furrovineapi ErrorCodeException( String&& message, int result, bool appendresultcode = true );

	};

}
