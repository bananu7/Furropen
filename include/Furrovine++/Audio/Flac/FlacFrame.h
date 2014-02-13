#pragma once

#include <Furrovine++/Declarations.h>
#include <Furrovine++/Audio/Flac/FlacFrameHeader.h>
#include <Furrovine++/Audio/Flac/FlacSubframe.h>
#include <Furrovine++/Checksums/Crc16.h>
#include <vector>

namespace Furrovine { namespace Audio { namespace Flac {

	struct FlacFrame {
		FlacFrameHeader Header;
		fixed_vector<FlacSubframe, 16> Subframes;
		Checksums::Crc16<16, 0x8005> Crc;

		furrovineapi FlacFrame( );

		furrovineapi void Read( IO::FlacReader& reader, int32 flacbitdepth, int32 flacsamplerate, bool checkcrc );

		furrovineapi void Decode( IO::FlacReader& reader );

	};

}}}
