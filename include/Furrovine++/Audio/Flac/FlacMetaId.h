#pragma once

#include <Furrovine++/atc.h>

namespace Furrovine { namespace Audio { namespace Flac {

	enum class FlacMetaId {
		FlacHeader = charcc4( C, a, L, f ),
		StreamInfo = 0,
		Padding,
		Application,
		Seektable,
		VorbisComment,
		Cuesheet,
		Picture,
		Reserved,
		Invalid = 127,
	};

}}}
