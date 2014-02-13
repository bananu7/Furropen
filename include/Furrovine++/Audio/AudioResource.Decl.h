#pragma once

#include <Furrovine++/Event.h>
#include <Furrovine++/Declarations.h>
#include <Furrovine++/null.h>
#include <Furrovine++/Audio/AudioDevice.h>

namespace Furrovine { namespace Audio {

	class AudioResource {
	protected:
		AudioDevice* device;

	public:
		Event<AudioResource&> Disposing;

		AudioResource ();

		AudioResource (AudioDevice* graphicsdevice);

		AudioResource (AudioDevice& graphicsdevice);

		AudioResource ( AudioResource&& resource );

		AudioResource ( const AudioResource& resource );

		AudioDevice& Device ();

		bool HasDevice () const;

		AudioResource& operator=( AudioResource&& resource );

		AudioResource& operator=( const AudioResource& resource );

		virtual ~AudioResource ();

	};


}}
