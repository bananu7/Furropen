#ifndef FURROVINEFLACFRAMECHANNELS_H
#define FURROVINEFLACFRAMECHANNELS_H

namespace Furrovine { namespace Audio { namespace Flac {

	enum class FlacFrameChannels {
		Mono,
		Stereo,
		LeftRightCenter,
		LeftRightBackleftBackright,
		Surround,
		Surround51,
		Theater,
		Theater51,
		LeftSideStereo,
		RightSideStereo,
		MidSideStereo,
		Reserved,
	};

}}}

#endif // FURROVINEFLACFRAMECHANNELS_H 