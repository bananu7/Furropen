#pragma once

#include <Furrovine++/Enums.h>

namespace Furrovine { namespace Sys {

	enum class FileNotificationFlags {
		None = 0x00,
		// Any file name change in the watched directory or subtree causes a change notification wait operation to return. Changes include renaming, creating, or deleting a file name.
		FileName = 0x01,	
		// Any file name change in the watched directory or subtree causes a change notification wait operation to return. Changes include renaming, creating, or deleting a file name.
		DirectoryName = 0x02,
		// Any directory-name change in the watched directory or subtree causes a change notification wait operation to return. Changes include creating or deleting a directory.
		Attributes = 0x04,
		// Any attribute change in the watched directory or subtree causes a change notification wait operation to return.
		Size = 0x08,
		// Any file-size change in the watched directory or subtree causes a change notification wait operation to return. The operating system detects a change in file size only when the file is written to the disk. For operating systems that use extensive caching, detection occurs only when the cache is sufficiently flushed.
		LastWriteTime = 0x10,
		// Any change to the last write-time of files in the watched directory or subtree causes a change notification wait operation to return. The operating system detects a change to the last write-time only when the file is written to the disk. For operating systems that use extensive caching, detection occurs only when the cache is sufficiently flushed.
		LastAccessTime = 0x20,
		CreationTime = 0x40,
		// Any security-descriptor change in the watched directory or subtree causes a change notification wait operation to return.
		Security = 0x80,
		// Any change to the creation time of files in the watched directory or subtree causes a change notification wait operation to return.
		BasicFileChanges = FileName | Size | LastWriteTime | CreationTime,
		FileChanges = FileName | Attributes | Size | LastWriteTime | LastAccessTime | CreationTime | Security,
		All = FileName | Attributes | Size | LastWriteTime | LastAccessTime | CreationTime | Security | DirectoryName,
	};

	enumflagoperators( FileNotificationFlags );

}}
