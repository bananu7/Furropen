#pragma once

#include <Furrovine++/std_defines.h>
#include <vector>
#include <Furrovine++/Strings.h>

namespace Furrovine { namespace IO {

	class Directory {
	public:
		furrovineapi static String CurrentDirectory ();

		furrovineapi static bool Exists (const String& file);

		furrovineapi static std::vector<String> GetDirectories ( const String& dir );

		furrovineapi static std::vector<String> GetFiles ( const String& dir );

		furrovineapi static std::vector<String> GetFilesOrDirectories (const String& dir);
	};

}}
