#pragma once

namespace Furrovine { namespace Audio { namespace Flac {

	enum class FlacSubframePredictor {
		ConstantPredictor = 0x0,
		VerbatimPredictor = 0x1,
		Reserved0 = 0x2,
		Reserved1= 0x4,
		FixedLinearPredictor = 0x8,
		Reserved2 = 0x10,
		LinearPredictiveCodingPredictor = 0x20
	};

}}}
