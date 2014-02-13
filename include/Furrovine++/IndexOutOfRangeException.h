#pragma once

#include <Furrovine++/Exception.h>

namespace Furrovine {

	class IndexOutOfRangeException : public TException<std::out_of_range> {
	public:

		furrovineapi IndexOutOfRangeException( );

		furrovineapi IndexOutOfRangeException( const String& message );

		furrovineapi IndexOutOfRangeException( String&& message );

	};

}
