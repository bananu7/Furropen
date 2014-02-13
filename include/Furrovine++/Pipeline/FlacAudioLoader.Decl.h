#pragma once

#include <Furrovine++/Audio/FlacAudioData.h>

namespace Furrovine { namespace Pipeline {

	class FlacAudioLoader {
	public:

		furrovineapi Audio::FlacAudioData Load ( IO::Stream& stream );

		furrovineapi Audio::FlacAudioData Load ( IO::FlacReader& reader );

	};

}}
