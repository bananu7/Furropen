#ifndef FURROVINEFLACFRAMESTRATEGY_H
#define FURROVINEFLACFRAMESTRATEGY_H

namespace Furrovine { namespace Audio { namespace Flac {

	enum class FlacFrameStrategy {
		FixedSizeStream,
		VariableSizeStream,
		Unknown
	};

}}}

#endif // FURROVINEFLACFRAMESTRATEGY_H 