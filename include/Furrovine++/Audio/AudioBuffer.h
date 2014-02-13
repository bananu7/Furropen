#pragma once

#include <Furrovine++/buffer_view.h>
#include <Furrovine++/FurrovineApi.h>
#include <Furrovine++/Audio/AudioBufferFlags.h>

namespace Furrovine { namespace Audio {

	struct AudioBuffer {
	public:
		buffer_view<const byte> data;
		AudioBufferFlags flags;
		uint32 playsamplestart;
		uint32 playsamplelength;
		uint32 loopregionstart;
		uint32 loopregionlength;
		uint32 loopregionrepeat;
		void* context;

		AudioBuffer( const byte* audiodata, uint32 bytelen, uint32 samplestart = 0,
			uint32 samplelength = 0, uint32 loopstart = 0, uint32 looplen = 0, uint32 looprepeat = 0, 
			AudioBufferFlags flags = AudioBufferFlags::None, void* callbackcontext = null );

	};

}}
