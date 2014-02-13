#pragma once

#include <Furrovine++/TimeSpan.h>
#include <Furrovine++/raw_storage.h>

namespace Furrovine {

	class DateTime {
	private:
		raw_storage<8> storage;

	public:

		furrovineapi static DateTime Now( );

		furrovineapi static DateTime MinValue( );

		furrovineapi DateTime( );

		furrovineapi TimeSpan operator- ( const DateTime& right );

		furrovineapi bool operator< ( const DateTime& right ) const;

		furrovineapi bool operator> ( const DateTime& right ) const;

		furrovineapi bool operator== ( const DateTime& right ) const;

		furrovineapi ~DateTime( );
	};

}
