#pragma once

#include <atomic>
#include <Furrovine++/ptr.h>
#include <Furrovine++/Audio/PCMAudio.h>
#include <Furrovine++/Audio/AudioData.h>
#include <Furrovine++/Audio/AudioBuffer.h>
#include <Furrovine++/Audio/audio_deleters.h>
#include <Furrovine++/any.h>

namespace Furrovine { namespace Audio {

	class AudioDevice {
	public:
		friend struct AudioDeviceCallbacks;
		static const PCMAudioFormat DefaultAudioDeviceFormat = PCMAudioFormat::Short;

		static const int32 DefaultBitsPerSample = ((int)DefaultAudioDeviceFormat & 0xF) * 8;
		static const int32 DefaultBytesPerSample = ((int)DefaultAudioDeviceFormat & 0xF);

		/// <summary>
		/// By default, Dynamically generated sounds will be stereo sounds
		/// </summary>
		static const Channels DefaultChannels = Channels::Stereo;

		/// <summary>
		/// By default, Dynamically generated sounds will be stereo sounds
		/// </summary>
		static const int32 DefaultChannelCount = (int)DefaultChannels;

		/// <summary>
		/// The universal amount of time a dynamic audio buffer will represent.
		/// </summary>
		static const int32 DefaultSoundBufferDuration = 25;

		/// <summary>
		/// The universal amount of samples a dynamic sound audio buffer will take to make a single second of sound.
		/// </summary>
		static const int32 DefaultSampleRate = 48000;

		static const PCMAudio DefaultDeviceAudio;

	private:
		ptr<void, audio_engine_deleter> audiodeviceengine;
		ptr<void, audio_voice_deleter> audiodevicesource;
		ptr<void, audio_voice_deleter> audiodevicemaster;
		any callbacks;
		std::atomic<uint32> buffercount;
		std::atomic<uint32> bytesrequired;
		PCMAudio config;
		float volume;
		bool enabled;

	public:

		AudioDevice ();

		AudioDevice ( int32 bitspersample, int32 channelcount, int32 samplerate );
			
		AudioDevice ( const PCMAudio& deviceconfig );

		void* EngineImpl( ) const;

		const PCMAudio& PCMConfig( ) const;

		Channels AudioChannels () const;

		int32 ChannelCount () const;

		int32 BitsPerSample () const;

		uint32 BufferCount () const;

		uint32 BytesRequired () const;

		PCMAudioFormat Format () const;

		float GetVolume () const;

		void SetVolume ( float volume );

		void SubmitBuffer ( const byte* data, uint32 start, uint32 len );

		void SubmitBuffer ( const byte* data, uint32 start, uint32 len, uint32 samplestart, uint32 sampleend );

		void SubmitBuffer ( const byte* data, uint32 len );

		void SubmitBuffer ( const byte* data, uint32 len, uint32 samplestart, uint32 sampleend );

		void SubmitBuffer( const AudioBuffer& buffer );

		~AudioDevice ( );

	protected:

		void OnCriticalError( uint64 errorcode );

		void OnProcessingPassStart( );

		void OnProcessingPassEnd( );

		void OnVoiceProcessingPassStart( uint32 bytes );

		void OnVoiceProcessingPassEnd( );

		void OnVoiceError( void* context, uint64 errorcode );

		void OnStreamEnd( );

		void OnLoopEnd( void* context );

		void OnBufferStart( void* context );

		void OnBufferEnd( void* context );

	};

}}
