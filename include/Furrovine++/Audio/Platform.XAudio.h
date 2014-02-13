#pragma once

#include <Furrovine++/Platform.Audio.h>
#include <Furrovine++/Audio/AudioBufferFlags.h>
#include <Furrovine++/make_array.h>

namespace Furrovine { namespace Audio { namespace XAudio {

#ifdef FURROVINEXAUDIO

	enum class AudioBufferFlags {
		None = 0,
		StreamEnd = XAUDIO2_END_OF_STREAM
	};

	inline furrovineapi AudioBufferFlags ToPlatform( Audio::AudioBufferFlags flags ) {
		const static auto platformlookup = make_array<AudioBufferFlags>(
			AudioBufferFlags::None,
			AudioBufferFlags::StreamEnd
		);
		return accumulate_flags( flags, platformlookup );
	}

	inline furrovineapi XAUDIO2_BUFFER ToPlatform( Audio::AudioBuffer buffer ) {
		XAUDIO2_BUFFER xbuffer;
		xbuffer.pContext = buffer.context;
		xbuffer.AudioBytes = buffer.data.size( );
		xbuffer.pAudioData = buffer.data.data( );
		xbuffer.LoopBegin = buffer.loopregionstart;
		xbuffer.LoopCount = buffer.loopregionrepeat;
		xbuffer.LoopLength = buffer.loopregionlength;
		xbuffer.PlayBegin = buffer.playsamplestart;
		xbuffer.PlayLength = buffer.playsamplelength;
		xbuffer.Flags = static_cast<uint32>( XAudio::ToPlatform( buffer.flags ) );
		return xbuffer;
	}

#endif // XAUDIO

}}}