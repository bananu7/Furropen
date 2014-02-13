#pragma once

#include <Furrovine++/Exception.h>

namespace Furrovine {

	class FileNotFoundException : public Exception {
	public:

		furrovineapi FileNotFoundException ();

		furrovineapi FileNotFoundException ( const String& message );

	};

}
