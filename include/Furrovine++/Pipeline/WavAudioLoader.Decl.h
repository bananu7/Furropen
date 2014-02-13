#ifndef FURROVINEWAVAUDIOLOADER_DECL_H
#define FURROVINEWAVAUDIOLOADER_DECL_H

#include <Furrovine++/Audio/WavAudioData.h>

namespace Furrovine { namespace Pipeline {

	class WavAudioLoader {
	public:

		furrovineapi ptr<Audio::WavAudioData> Load ( IO::Stream& stream );

		furrovineapi ptr<Audio::WavAudioData> Load ( IO::ByteReader& reader );
	};

}}

#endif // FURROVINEWAVAUDIOLOADER_DECL_H