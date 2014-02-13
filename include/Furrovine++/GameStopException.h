#pragma once

#include <Furrovine++/Exception.h>

namespace Furrovine {

	class GameStopException : public Exception {
	public:
		furrovineapi GameStopException( );

		furrovineapi GameStopException( const String& message );

		furrovineapi GameStopException( String&& message );

	};

}
