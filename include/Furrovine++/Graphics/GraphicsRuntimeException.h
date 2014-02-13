#pragma once

#include <Furrovine++/Graphics/GraphicsRuntime.h>
#include <Furrovine++/ErrorCodeException.h>

namespace Furrovine { namespace Graphics {

	class GraphicsRuntimeException : public ErrorCodeException {
	public:

		furrovineapi GraphicsRuntimeException( const String& message, int errorcode );
		furrovineapi GraphicsRuntimeException( const String& message, int errorcode, GraphicsRuntime runtime );

	};

}}