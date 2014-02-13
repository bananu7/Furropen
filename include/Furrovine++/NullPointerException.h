#ifndef FURROVINENULLPOINTEREXCEPTION_H
#define FURROVINENULLPOINTEREXCEPTION_H

#include <Furrovine++/Exception.h>

namespace Furrovine {

	class NullPointerException : public Exception {
	public:

		NullPointerException () : Exception () {

		}

		NullPointerException ( const String& message ) : Exception ( message ) {

		}

		NullPointerException ( String&& message ) : Exception ( std::forward<String>( message ) ) {

		}
	};

}

#endif // FURROVINENULLPOINTEREXCEPTION_H 