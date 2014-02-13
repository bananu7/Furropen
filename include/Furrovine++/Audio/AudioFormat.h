#pragma once

namespace Furrovine { namespace Audio {

	enum class AudioFormat {
		EightBit,
		SixteenBit,
		TwentyFourBit,
		ThirtyTwoBit,
		ThirtyTwoBitFloating,
		SixtyFourBit,
		SixtyFourBitFloating,
		Byte = EightBit,
		Short = SixteenBit,
		Int24 = TwentyFourBit,
		Int = ThirtyTwoBit,
		Float = ThirtyTwoBitFloating,
		Long = SixtyFourBit,
		Double = SixtyFourBitFloating,
	};

}}

#endif // FURROVINEAUDIOFORMAT_H 