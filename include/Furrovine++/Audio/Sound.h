#pragma once

#include <Furrovine++/Audio/DynamicSound.h>

namespace Furrovine { namespace Audio {

	class Sound : private DynamicSound {
	protected:
		
	public:

		void Play () {

		}

		void Pause () {

		}

		void Stop () {
			Rewind();
			Pause();
		}

		void Rewind () {

		}

	protected:

	};

}}

#endif // FURROVINESOUND_H 