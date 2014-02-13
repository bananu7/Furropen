#pragma once

#include <Furrovine++/ArgumentException.h>

namespace Furrovine {

	class ArgumentOutOfRangeException : public TException<std::out_of_range> {
	public:

		furrovineapi ArgumentOutOfRangeException( );

		furrovineapi ArgumentOutOfRangeException( const String& message );

		furrovineapi ArgumentOutOfRangeException( String&& message );

	};

}