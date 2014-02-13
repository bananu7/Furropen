#pragma once

#include <Furrovine++/Declarations.h>
#include <Furrovine++/Audio/Flac/FlacFrameStrategy.h>
#include <Furrovine++/Audio/Flac/FlacFrameChannels.h>
#include <Furrovine++/Checksums/Crc8.h>

namespace Furrovine { namespace Audio { namespace Flac {

	struct FlacFrameHeader {
	public:
		furrovineapi static const ulword SyncCode = 0x3FFE;
		
	private:
		int32 lastsamplecount;

	public:
		FlacFrameStrategy FrameStrategy;
		FlacFrameChannels Channels;
		int32 ChannelCount;
		int64 SampleFrameNumber;
		int32 SampleCount;
		int32 SampleRate;
		int32 BitDepth;
		Checksums::Crc8<8, 0x07> Crc;

		furrovineapi FlacFrameHeader( );
		
		furrovineapi int64 StartingSample( );

		furrovineapi void Read( IO::FlacReader& reader, int32 flacbitdepth, int32 flacsamplerate, bool checkcrc = true );
	};

}}}
