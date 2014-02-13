#pragma once

#include <Furrovine++/Audio/Flac/FlacSubframeHeader.h>
#include <Furrovine++/Audio/RicePartitions.h>
#include <memory>

namespace Furrovine { namespace Audio { namespace Flac {

	struct FlacSubframe {
	public:
		furrovineapi static const int32 MaxSize = 65535;
		furrovineapi static const int32 MaxLPCOrder = 32;
		FlacSubframeHeader Header;
		RicePartitions Rice;
		int32 PartitionOrder, PartitionSize, Precision, Shift;
		std::unique_ptr<int[]> Samples;
		std::unique_ptr<int[]> Residual;
		std::unique_ptr<int[]> Coefficients;

		furrovineapi FlacSubframe( );
		
		furrovineapi ~FlacSubframe( );

		furrovineapi void Read( IO::FlacReader& reader, int32 channel, int32 bitdepth, int32 framesamplecount, FlacFrameChannels channels );

		furrovineapi void Decode( IO::FlacReader& reader, int32 channel, int32 framesamplecount );

		furrovineapi void ConstantPredictorRead( IO::FlacReader& reader, int32 framesamplecount );

		furrovineapi void VerbatimPredictorRead( IO::FlacReader& reader, int32 framesamplecount );

		furrovineapi void FixedLinearPredictorRead( IO::FlacReader& reader, int32 framesamplecount );

		furrovineapi void LinearPredictiveCodingPredictorRead( IO::FlacReader& reader, int32 framesamplecount );

		furrovineapi void ResidualRead( IO::FlacReader& reader, int32 framesamplecount );

		furrovineapi void FixedLinearPredictorDecode( int32 framesamplecount );

		furrovineapi void LinearPredictiveCodingDecode( int32 framesamplecount );

	};

}}}
