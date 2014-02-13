#pragma once

#include <Furrovine++/numeric_integer_def.h>
#include <Furrovine++/Declarations.h>
#include <Furrovine++/Export.h>
#include <Furrovine++/Audio/Flac/FlacFrameChannels.h>
#include <Furrovine++/Audio/Flac/FlacSubframePredictor.h>

namespace Furrovine { namespace Audio { namespace Flac {

	struct FlacSubframeHeader {
	private:
		byte zero1type6wasted1;
		int32 kwasted, kused;

	public:

		furrovineapi FlacSubframeHeader( );

		furrovineapi int32 KUsed( );

		furrovineapi int32 KWasted( );

		furrovineapi bool LeadingZero( );

		furrovineapi bool IsKWasted( );

		furrovineapi FlacSubframePredictor Predictor( );

		furrovineapi int32 Order( );

		furrovineapi void Read( IO::FlacReader& reader, int32 channel, int32 bitdepth, FlacFrameChannels channels );

	};

}}}
