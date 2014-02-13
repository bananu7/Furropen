#ifndef FURROVINENOTSUPPORTEDEXCEPTION_H
#define FURROVINENOTSUPPORTEDEXCEPTION_H

#include <Furrovine++/Exception.h>

namespace Furrovine {

	class NotSupportedException : public Exception {
    public:

        NotSupportedException () {

        }

        NotSupportedException ( const String& message ) : Exception( message ) {
        
        }

    };

}

#endif // FURROVINENOTSUPPORTEDEXCEPTION_H 