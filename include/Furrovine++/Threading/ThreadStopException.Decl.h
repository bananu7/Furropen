#pragma once

#include <Furrovine++/Exception.h>

namespace Furrovine { namespace Threading {

	class ThreadStopException : public TException<std::system_error> {
	public:

		furrovineapi ThreadStopException ();

	};

}}
