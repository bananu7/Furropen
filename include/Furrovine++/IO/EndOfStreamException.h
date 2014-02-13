#ifndef FURROVINEENDOFSTREAMEXCEPTION_H
#define FURROVINEENDOFSTREAMEXCEPTION_H

#include <Furrovine++/Exception.h>

namespace Furrovine { namespace IO {
	
	class EndOfStreamException : public Exception {
	public:

		EndOfStreamException () : Exception( ) {

		}

		EndOfStreamException ( const String& message ) : Exception( message ) {

		}

	};


}}

#endif // FURROVINEENDOFSTREAMEXCEPTION_H 