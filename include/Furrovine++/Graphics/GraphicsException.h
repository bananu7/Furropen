#pragma once

#include <Furrovine++/Exception.h>

namespace Furrovine { namespace Graphics {

	class GraphicsException : public Exception {
	public:
		furrovineapi GraphicsException( );

		furrovineapi GraphicsException( const String& message );

		furrovineapi GraphicsException( String&& message );

	};

}}
