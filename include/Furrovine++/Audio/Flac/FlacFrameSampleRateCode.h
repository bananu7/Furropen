#ifndef FURROVINEFLACFRAMESAMPLERATECODE_H
#define FURROVINEFLACFRAMESAMPLERATECODE_H

namespace Furrovine { namespace Audio { namespace Flac {

	enum class FlacFrameSampleRateCode {
		StreamInfo,
		Hz88200,
		Hz176400,
		Hz192000,
		Hz8000,
		Hz16000,
		Hz22050,
		Hz24000,
		Hz32000,
		Hz44100,
		Hz48000,
		Hz96000,
		EightBitkHzFrame,
		SixteenBitHzFrame,
		SixteenBit10HzFrame,
		Invalid
	};

}}}

#endif // FURROVINEFLACFRAMESAMPLERATECODE_H 