#pragma once

#include <Furrovine++/Exception.h>

namespace Furrovine {

	class CriticalFailureException : public Exception {
	public:

		furrovineapi CriticalFailureException ();

		furrovineapi CriticalFailureException ( const String& message );

	};

}
