#pragma once

#include <Furrovine++/Platform.h>

namespace Furrovine {

	class ComInitializer {
	public:
		
		furrovineapi explicit ComInitializer( DWORD coinitstyle = COINIT_MULTITHREADED );

		furrovineapi ~ComInitializer();
	
	private:
		// Flags whether COM was properly initialized. 
		bool _coinitialized;

		// Hide copy constructor and assignment operator.
		furrovineapi ComInitializer( const ComInitializer& );
		furrovineapi ComInitializer( ComInitializer&& );
		furrovineapi ComInitializer& operator=( const ComInitializer& );
		furrovineapi ComInitializer& operator=( ComInitializer&& );
	
	};

}
