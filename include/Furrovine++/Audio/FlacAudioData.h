#pragma once

#include <Furrovine++/Audio/AudioData.h>
#include <Furrovine++/Audio/Flac/FlacFrameStrategy.h>
#include <Furrovine++/FurrovineApi.h>
#include <array>

namespace Furrovine { namespace Audio {

	class FlacAudioData : public AudioData {
	protected:
		std::array<byte, 16> md5;
		bool constantframesize, checkcrc;
		ulword minframesize, maxframesize,
			minblocksize, maxblocksize;
		int64 samplecount;
		Flac::FlacFrameStrategy strategy;

	public:

		furrovineapi FlacAudioData( IO::FlacReader& reader, bool CheckCrc = true );

		furrovineapi bool CheckCrcData( ) const;
	};

}}
