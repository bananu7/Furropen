#ifndef FURROVINEOUTOFMEMORYEXCEPTION_H
#define FURROVINEOUTOFMEMORYEXCEPTION_H

#include <Furrovine++/Exception.h>

namespace Furrovine {

	class OutofMemoryException : public Exception {
	public:

		OutofMemoryException () : Exception( ) {

		}

		OutofMemoryException ( const String& message ) : Exception( message ) {

		}

		OutofMemoryException ( String&& message ) : Exception( std::move( message ) ) {

		}

	};

}

#endif // FURROVINEOUTOFMEMORYEXCEPTION_H 