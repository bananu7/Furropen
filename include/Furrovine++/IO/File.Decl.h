#pragma once

#include <Furrovine++/std_defines.h>
#include <vector>
#include <Furrovine++/Strings.h>

namespace Furrovine { namespace IO {

	class File {
	public:

		furrovineapi static std::vector<byte> ReadAllBytes( const String& file );

		furrovineapi static String ReadAllText( const String& file );

		furrovineapi static String ReadAll( const String& file );

		furrovineapi static bool Create( const String& file );

		furrovineapi static bool Exists ( const String& file );

	};

}}
