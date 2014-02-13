#pragma once

#include <Furrovine++/buffer_view.h>
#include <vector>
#include <Furrovine++/Audio/PCMAudio.h>

namespace Furrovine { namespace Audio {

	struct AudioData {
	protected:
		Channels channels;
		bool vbr, streaming, initialized;
		int32 alignedpcmdatasize, pcmdatasize,
			datasize, aligneddatasize,
			samplerate, channelcount, bitdepth, bitspersecond, floating, 
			samplecount;

		std::vector<byte> pcmdata;

	public:

		AudioData ( );

		bool Initialized () const;

		TimeSpan Duration () const;

		int32 SampleRate () const;

		Channels AudioChannels () const;

		int32 ChannelCount () const;

		int32 BitsPerSample () const;

		int32 BytesPerSample () const;

		int32 BitsPerSecond () const;

		int32 BytesPerSecond () const;

		bool VariableBitRate () const;

		bool ConstantBitRate () const;

		bool Streaming () const;

		buffer_view<byte> Data () const;

		int32 DataSize () const;

		int32 SampleSize ( TimeSpan duration ) const;

		int32 SampleByteSize ( TimeSpan duration ) const;

		int32 AlignedSampleByteSize ( int32 bytes ) const;

		TimeSpan SampleDuration ( int32 samples ) const;

		TimeSpan SampleDurationBytes ( int32 bytes ) const;

		bool Equals ( const AudioData& other ) const;

		~AudioData ();

	};

}}
