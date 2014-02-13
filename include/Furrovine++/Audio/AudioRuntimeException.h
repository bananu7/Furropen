#pragma once

#include <Furrovine++/ErrorCodeException.h>
#include <Furrovine++/Audio/AudioRuntime.h>

namespace Furrovine { namespace Audio {

	class AudioRuntimeException : public ErrorCodeException {
	public:

		AudioRuntimeException( const String& message, int errorcode, AudioRuntime runtime );

	};

}}