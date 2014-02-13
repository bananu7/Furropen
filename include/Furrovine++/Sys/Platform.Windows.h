#pragma once

#include <Furrovine++/Platform.h>
#include <Furrovine++/make_array.h>
#include <Furrovine++/Sys/FileChangeFlags.h>
#include <Furrovine++/IO/Platform.Windows.h>

namespace Furrovine { namespace Sys { namespace Windows {

#ifdef FURROVINEWIN
	
	enum class FileAction {
		None = 0x0,
		Added = FILE_ACTION_ADDED,
		Removed = FILE_ACTION_REMOVED,
		Modified = FILE_ACTION_MODIFIED,
		RenameOld = FILE_ACTION_RENAMED_OLD_NAME,
		RenameNew = FILE_ACTION_RENAMED_NEW_NAME,
	};

	enum class JournalReasons : uint {
		DataOverwrite = USN_REASON_DATA_OVERWRITE,
		DataExtend = USN_REASON_DATA_EXTEND,
		DataTruncation = USN_REASON_DATA_TRUNCATION,
		NamedDataOverwrite = USN_REASON_NAMED_DATA_OVERWRITE,
		NamedDataExtend = USN_REASON_NAMED_DATA_EXTEND,
		NamedDataTrucation = USN_REASON_NAMED_DATA_TRUNCATION,
		Creation = USN_REASON_FILE_CREATE,
		Deletion = USN_REASON_FILE_DELETE,
		Change = USN_REASON_EA_CHANGE,
		SecurityChange = USN_REASON_SECURITY_CHANGE,
		RenameOldName = USN_REASON_RENAME_OLD_NAME,
		RenameNewName = USN_REASON_RENAME_NEW_NAME,
		IndexableChange = USN_REASON_INDEXABLE_CHANGE,
		BasicInfoChange = USN_REASON_BASIC_INFO_CHANGE,
		HardLinkChange = USN_REASON_HARD_LINK_CHANGE,
		CompressionChange = USN_REASON_COMPRESSION_CHANGE,
		EncryptionChange = USN_REASON_ENCRYPTION_CHANGE,
		ObjectIdChange = USN_REASON_OBJECT_ID_CHANGE,
		ReparsePointChange = USN_REASON_REPARSE_POINT_CHANGE,
		StreamChange = USN_REASON_STREAM_CHANGE,
		TransactedChange = USN_REASON_TRANSACTED_CHANGE,
		IntegrityChange = USN_REASON_INTEGRITY_CHANGE,
		Close = USN_REASON_CLOSE,
		All = 0xFFFFFFFF,
	};

	enumflagoperators( JournalReasons );

	struct JournalRecord {
	public:
		union {
			USN_RECORD Record;
			struct {
				ulong RecordLength;
				ushort MajorVersion;
				ushort MinorVersion;
				uint64 FileReferenceNumber;
				uint64 ParentFileReferenceNumber;
				USN Usn;
				LARGE_INTEGER TimeStamp;
				JournalReasons Reason;
				ulong SourceInfo;
				ulong SecurityId;
				IO::Windows::FileAttribute FileAttributes;
				short FileNameLength;
				short FileNameOffset;
				wchar_t FileName[ 1 ];
			};
		};
	};

	FileChangeFlags ToFileSystemChange( JournalReasons reason ) {
		FileChangeFlags c = FileChangeFlags::None;
		if ( AnyFlags( reason, JournalReasons::Creation ) ) {
			c |= FileChangeFlags::Created;
		}
		if ( AnyFlags( reason, JournalReasons::Deletion ) ) {
			c |= FileChangeFlags::Deleted;
		}
		if ( AnyFlags( reason, JournalReasons::Change | JournalReasons::DataTruncation | JournalReasons::DataExtend | JournalReasons::DataOverwrite ) ) {
			c |= FileChangeFlags::Modified;
		}
		if ( AnyFlags( reason, JournalReasons::RenameOldName | JournalReasons::RenameNewName ) ) {
			c |= FileChangeFlags::Renamed;
		}
		return c;
	}

	FileChangeFlags ToFileSystemChange( FileAction action ) {
		FileChangeFlags c = FileChangeFlags::None;
		switch ( action ) {
		case FileAction::Added:
			c |= FileChangeFlags::Created;
			break;
		case FileAction::Modified:
			c |= FileChangeFlags::Modified;
			break;
		case FileAction::Removed:
			c |= FileChangeFlags::Deleted;
			break;
		case FileAction::RenameNew:
		case FileAction::RenameOld:
			c |= FileChangeFlags::Renamed;
			break;
		}

		return c;
	}

	enum class FileNotificationFlags {
		None = 0x0,
		// Any file name change in the watched directory or subtree causes a change notification wait operation to return. Changes include renaming, creating, or deleting a file name.
		FileName = FILE_NOTIFY_CHANGE_FILE_NAME,

		// Any file name change in the watched directory or subtree causes a change notification wait operation to return. Changes include renaming, creating, or deleting a file name.
		DirectoryName = FILE_NOTIFY_CHANGE_DIR_NAME,

		// Any directory-name change in the watched directory or subtree causes a change notification wait operation to return. Changes include creating or deleting a directory.
		Attributes = FILE_NOTIFY_CHANGE_ATTRIBUTES,

		// Any attribute change in the watched directory or subtree causes a change notification wait operation to return.
		Size = FILE_NOTIFY_CHANGE_SIZE,

		// Any file-size change in the watched directory or subtree causes a change notification wait operation to return. The operating system detects a change in file size only when the file is written to the disk. For operating systems that use extensive caching, detection occurs only when the cache is sufficiently flushed.
		LastWriteTime = FILE_NOTIFY_CHANGE_LAST_WRITE,

		// Any change to the last write-time of files in the watched directory or subtree causes a change notification wait operation to return. The operating system detects a change to the last write-time only when the file is written to the disk. For operating systems that use extensive caching, detection occurs only when the cache is sufficiently flushed.
		LastAccessTime = FILE_NOTIFY_CHANGE_LAST_ACCESS,

		CreationTime = FILE_NOTIFY_CHANGE_CREATION,

		// Any security-descriptor change in the watched directory or subtree causes a change notification wait operation to return.
		Security = FILE_NOTIFY_CHANGE_SECURITY,

		// Any change to the creation time of files in the watched directory or subtree causes a change notification wait operation to return.
		BasicFileChanges = FileName | Size | LastWriteTime | CreationTime,

		FileChanges = FileName | Attributes | Size | LastWriteTime | LastAccessTime | CreationTime | Security,

		All = FileName | Attributes | Size | LastWriteTime | LastAccessTime | CreationTime | Security | DirectoryName,
	};

	FileNotificationFlags ToPlatform( Sys::FileNotificationFlags value ) {
		static const auto platformlookup = make_array<FileNotificationFlags>(
			FileNotificationFlags::None,
			FileNotificationFlags::FileName,
			FileNotificationFlags::DirectoryName,
			FileNotificationFlags::Attributes,
			FileNotificationFlags::Size,
			FileNotificationFlags::LastWriteTime,
			FileNotificationFlags::LastAccessTime,
			FileNotificationFlags::CreationTime,
			FileNotificationFlags::Security
		);
		return accumulate_flags( value, platformlookup );
	}

#endif // WIN	

}}}