#pragma once

#include <Furrovine++/IO/Stream.h>
#include <Furrovine++/Strings.h>

namespace Furrovine { namespace IO {
	
	class FileBasedStream : public Stream {
	public:

		furrovineapi virtual String Name () = 0;
		
	};
	
}}
