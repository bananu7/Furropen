#pragma once

#include <Furrovine++/Audio/Channels.h>
#include <Furrovine++/Audio/PCMAudioFormat.h>
#include <Furrovine++/TimeSpan.h>

namespace Furrovine { namespace Audio {

	struct PCMAudio {
	public:
		static const PCMAudio RedBookAudio;

		int32 BitsPerSample, ChannelCount, SampleRate;
		int32 Floating;
		double SampleTime;

		PCMAudio ( int32 bitsPerSample, int32 channelCount, int32 sampleRate );

		PCMAudio ( int32 bitsPerSample, int32 channelCount, int32 sampleRate, bool isfloating );

		int32 BytesPerSecond () const;

		int32 BytesPerSample ( ) const;

		Channels AudioChannels () const;

		PCMAudioFormat Format () const;

		int32 BlockAlign () const;

		bool IsRedBook () const;

		int32 SampleSize ( TimeSpan duration );

		int32 SampleByteSize ( TimeSpan duration );

		TimeSpan SampleDuration ( int32 samples );

		TimeSpan SampleDurationBytes ( int32 bytes );

		bool operator== ( const PCMAudio& right ) const;

		static int32 AlignedSampleSize ( TimeSpan duration, int32 samplerate, int32 channelcount );

		static int32 AlignedSampleByteSize ( TimeSpan duration, int32 samplerate, int32 channelcount, int32 samplebytesize );

		static int32 SampleSize ( TimeSpan duration, int32 samplerate, int32 channelcount );

		static int32 SampleByteSize ( TimeSpan duration, int32 samplerate, int32 channelcount, int32 samplebytesize );

		static TimeSpan SampleDuration ( int32 samples, int32 samplerate, int32 channelcount );

		static TimeSpan SampleDurationBytes ( int32 bytes, int32 samplerate, int32 channelcount, int32 samplebytesize );
	};

}}
