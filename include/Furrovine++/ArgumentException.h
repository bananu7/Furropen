#pragma once

#include <Furrovine++/Exception.h>

namespace Furrovine {

	class ArgumentException : Exception {
		
		furrovineapi ArgumentException( );

		furrovineapi ArgumentException( const String& message );

		furrovineapi ArgumentException( String&& message );

	};

}