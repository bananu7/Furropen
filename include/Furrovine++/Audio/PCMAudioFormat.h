#pragma once

namespace Furrovine { namespace Audio {

	enum class PCMAudioFormat {
		EightBits = 1,
		SixteenBits = 2,
		TwentyFourBits = 3,
		ThirtyTwoBits = 4,
		SixtyFourBits = 8,
		ThirtyTwoFloatingBits = 4 | 16,
		SixtyFourFloatingBits = 8 | 16,

		Int8 = EightBits,
		Int16 = SixteenBits,
		Int24 = TwentyFourBits,
		Int32 = ThirtyTwoBits,
		Int64 = SixtyFourBits,
		SinglePrecision = ThirtyTwoFloatingBits,
		DoublePrecision = SixtyFourFloatingBits,

		SByte = Int8,
		Short = Int16,
		Int = Int32,
		Long = Int64,
		Float = SinglePrecision,
		Double = DoublePrecision,
	};

}}
