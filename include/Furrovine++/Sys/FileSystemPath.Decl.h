#ifndef FURROVINEFILESYSTEMPATH_DECL_H
#define FURROVINEFILESYSTEMPATH_DECL_H

#include <Furrovine++/Strings.h>

namespace Furrovine { namespace Sys {

	class FileSystemPath {
	private:
		FileSystemString path;

	public:

		FileSystemPath ( const String& path );

		FileSystemPath ( String&& path );

		FileSystemPath ( const FileSystemString& path );

		FileSystemPath ( FileSystemString&& path );

		FileSystemPath ( const FileSystemPath& copy );

		FileSystemPath ( FileSystemPath&& mov );

		String GetExtension () const;

		String ParentDirectory () const;

	};

}}

#endif // FURROVINEFILESYSTEMPATH_DECL_H 