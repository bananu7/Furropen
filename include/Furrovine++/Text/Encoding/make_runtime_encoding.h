#pragma once

#include <Furrovine++/Text/Encoding/TextEncoding.h>
#include <Furrovine++/make_ptr.h>

namespace Furrovine { namespace Text { namespace Encoding {

	template <typename T>
	ptr<RuntimeTextEncoding<T>> make_runtime_encoding ( T encoding = T() ) {
		return make_ptr<RuntimeTextEncoding<T>>( std::move( encoding ) );
	}

}}}
 