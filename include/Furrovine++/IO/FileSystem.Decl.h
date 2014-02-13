#ifndef FURROVINEFILESYSTEM_DECL_H
#define FURROVINEFILESYSTEM_DECL_H

#include <Furrovine++/Strings.h>

namespace Furrovine { namespace IO {

	class FileSystem {
	private:
		struct Node {
			FileSystemString path;
			std::vector<Node> children;
			furrovineapi Node ();
			furrovineapi Node ( FileSystemString targetpath );

			furrovineapi bool Find ( const FileSystemString& target, FileSystemString& result ) const;
		};

		Node root;

	public:

		furrovineapi FileSystem ( FileSystemString root );
		furrovineapi FileSystemString Find( const FileSystemString& target ) const;
		furrovineapi String Find( const String& target ) const;
		furrovineapi bool Find( const FileSystemString& target, FileSystemString& result ) const;
		furrovineapi bool Find( const String& target, String& result ) const;

	};

}}

#endif // FURROVINEFILESYSTEM_DECL_H