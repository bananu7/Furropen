#ifndef FURROVINEFLACFRAMEBITSPERSAMPLECODE_H
#define FURROVINEFLACFRAMEBITSPERSAMPLECODE_H

namespace Furrovine { namespace Audio { namespace Flac {

	enum class FlacFrameBitsPerSampleCode {
		StreamInfo,
		EightBits,
		TwelveBits,
		Reserved0,
		SixteenBits,
		TwentyBits,
		TwentyFourBits,
		Reserved1
	};

}}}

#endif // FURROVINEFLACFRAMEBITSPERSAMPLECODE_H 