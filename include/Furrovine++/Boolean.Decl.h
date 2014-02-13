#ifndef FURROVINEBOOLEAN_DECL_H
#define FURROVINEBOOLEAN_DECL_H

#include <Furrovine++/Hash.h>
#include <Furrovine++/Strings.h>

namespace Furrovine {

	struct Boolean {

		furrovineapi static bool TryParse ( const String& string, bool& value );
	
	};

}

#endif // FURROVINEBOOLEAN_DECL_H 