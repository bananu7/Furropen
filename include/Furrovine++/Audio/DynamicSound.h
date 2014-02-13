#include <atomic>
#include <Furrovine++/any.h>
#include <Furrovine++/Audio/AudioResource.h>
#include <Furrovine++/Audio/PCMAudio.h>
#include <Furrovine++/Audio/AudioBuffer.h>
#include <Furrovine++/Audio/AudioData.h>

namespace Furrovine { namespace Audio {

	class DynamicSound : public AudioResource {
	private:
		friend struct DynamicSoundCallbacks;
		
		bool started;
		ptr<void, audio_voice_deleter> voiceresource;
		any voicecallback;
		PCMAudio config;
		std::atomic<uint32> buffercount;
		std::atomic<uint32> bytesrequired;
		
	public:

		furrovineapi DynamicSound( AudioDevice& audiodevice );

		furrovineapi DynamicSound( AudioDevice& audiodevice, const PCMAudio& audioconfig );

		furrovineapi DynamicSound( AudioDevice& audiodevice, int32 bitspersample, int32 channelcount, int32 samplerate );

		furrovineapi const PCMAudio& PCMConfig( ) const;

		furrovineapi Channels AudioChannels( ) const;

		furrovineapi int32 ChannelCount( ) const;

		furrovineapi int32 BitsPerSample( ) const;

		furrovineapi uint32 BufferCount( ) const;

		furrovineapi uint32 BytesRequired( ) const;

		furrovineapi PCMAudioFormat Format( ) const;

		furrovineapi bool IsStarted( ) const;

		furrovineapi void Start( );

		furrovineapi void Stop( );

		furrovineapi void SubmitBuffer( const AudioBuffer& buffer );

		furrovineapi void SubmitBuffer( const byte* data, uint32 start, uint32 len );

		furrovineapi void SubmitBuffer( const byte* data, uint32 start, uint32 len, uint32 samplestart, uint32 sampleend );

		furrovineapi void SubmitBuffer( const byte* data, uint32 len );

		furrovineapi void SubmitBuffer( const byte* data, uint32 len, uint32 samplestart, uint32 sampleend );

		furrovineapi ~DynamicSound( );

	protected:

		furrovineapi void OnVoiceProcessingPassStart( uint32 bytes );

		furrovineapi void OnVoiceProcessingPassEnd( );

		furrovineapi void OnVoiceError( void* context, uint64 errorcode );

		furrovineapi void OnStreamEnd( );

		furrovineapi void OnLoopEnd( void* context );

		furrovineapi void OnBufferStart( void* context );

		furrovineapi void OnBufferEnd( void* context );

	};

}}
