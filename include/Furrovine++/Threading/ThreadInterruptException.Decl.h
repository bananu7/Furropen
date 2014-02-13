#pragma once

#include <Furrovine++/Exception.h>

namespace Furrovine { namespace Threading {

	class ThreadInterruptException : public TException<std::system_error> {
	public:

		furrovineapi ThreadInterruptException ();

		furrovineapi ThreadInterruptException ( String message );
	};

}}
