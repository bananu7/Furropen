#pragma once

#include <Furrovine++/Declarations.h>
#include <Furrovine++/Strings.h>

namespace Furrovine { namespace IO {

	class Path {
	public:
		furrovineapi static bool IsAbsolutePath( const String& path );

		furrovineapi static bool IsValidPath( const String& path );

		furrovineapi static bool Exists ( const String& path );

		furrovineapi static String Resolve( const String& path, const FileSystem& filesystem );

		furrovineapi static bool Resolve( const String& path, String& result );

		furrovineapi static bool Resolve ( const String& path, const FileSystem& filesystem, String& result );

		furrovineapi static String GetParentName (const String& path);

		furrovineapi static String GetDirectoryName ( const String& path );

		furrovineapi static String GetFileName ( const String& path, bool noextension = false );

		furrovineapi static String GetExtension (const String& file, bool RemoveDot = false);

		furrovineapi static String StripExtension (const String& f, bool RemoveDot = true);

		furrovineapi static String GetFullPath ( const String& path );

		furrovineapi static String GetFullDirectoryPath ( const String& path );

		furrovineapi static String Combine ( const String& path1, const String& path2 );

	};

}}
