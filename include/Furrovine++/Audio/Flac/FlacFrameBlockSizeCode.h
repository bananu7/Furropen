#ifndef FURROVINEFLACFRAMEBLOCKSIZECODE_H
#define FURROVINEFLACFRAMEBLOCKSIZECODE_H

namespace Furrovine { namespace Audio { namespace Flac {

	enum class FlacFrameBlockSizeCode {
		Reserved0,
		Samples192,
		Samples576,
		Samples1152,
		Samples2304,
		Samples4608,
		EightBitFrame,
		SixteenBitFrame,
		Samples256,
		Samples512,
		Samples1024,
		Samples2048,
		Samples4096,
		Samples8192,
		Samples16384,
		Samples32768,
	};

}}}

#endif // FURROVINEFLACFRAMEBLOCKSIZECODE_H 