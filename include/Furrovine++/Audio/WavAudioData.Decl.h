#ifndef FURROVINEWAVAUDIODATA_DECL_H
#define FURROVINEWAVAUDIODATA_DECL_H

#include <Furrovine++/Audio/AudioData.h>
#include <Furrovine++/Audio/Wav/WavIdentifiers.h>
#include <Furrovine++/Sys/RuntimeByteOrder.h>
#include <Furrovine++/IO/FileStream.h>
#include <Furrovine++/IO/ByteReader.h>

namespace Furrovine { namespace Audio {

	struct WavAudioData : public AudioData {
	protected:
		Wav::WavFormat format;
		int32 memsize,
			headerid,
			riffstyle, formatsize, formatblockalign;

	public:

		WavAudioData ( );

		WavAudioData ( const String& file );

		WavAudioData ( IO::Stream& wavstream );

		WavAudioData ( IO::ByteReader& reader );

	protected:

		void Read ( IO::ByteReader& reader );

		Wav::WavFormat Format ();

	};

}}

#endif // FURROVINEWAVAUDIODATA_DECL_H