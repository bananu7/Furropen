#pragma once

#include <Furrovine++/Exception.h>

namespace Furrovine { namespace Audio {

	class AudioException : public Exception {
	public:

		furrovineapi AudioException ();
		furrovineapi AudioException( const String& message );
		furrovineapi AudioException( String&& message );

	};

}}
