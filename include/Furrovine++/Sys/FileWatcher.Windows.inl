#include <unordered_map>
#include <regex>
#include <Furrovine++/Sys/Platform.Windows.h>
#include <Furrovine++/ErrorCodeException.h>
#include <Furrovine++/NullPointerException.h>
#include <Furrovine++/IO/File.h>
#include <Furrovine++/IO/Directory.h>
#include <Furrovine++/IO/Path.h>
#include <Furrovine++/Strings.h>
#include <Furrovine++/Format.h>

namespace Furrovine { namespace Sys {

	FileWatcher::FileWatcher( const String& directory, const String& dirfilter, bool recursive /*= true*/, FileNotificationFlags notifications /*= FileSystemNotifications::All*/ ) :
	target( IO::Path::GetFullPath( directory ) ), 
	notificationflags( notifications ), 
	recurse( recursive ), exists( false ), queueread( false ), dying(false),
	fshandle( null ), eventhandle(null), diehandle( null ) {

		target.Replace( '\\', '/' );
		static const ulword defaultfilenamesize = 32768;
		static const ulword defaultdirnamesize = 32768;
		static const ulword defaultdrivenamesize = 64;
		static const ulword defaultextnamesize = 256;

		std::vector<wchar_t, uninitialized_allocator<wchar_t>> filenamepart( defaultfilenamesize );
		std::vector<wchar_t, uninitialized_allocator<wchar_t>> dirpart( defaultdirnamesize );
		charfs drivepart[ defaultdrivenamesize ];
		ulword drivepartsize;
		charfs extensionpart[ defaultextnamesize ];
		ulword extensionpartsize;
		FileSystemString fstarget = target;
		_wsplitpath_s( fstarget.data(), drivepart, defaultdrivenamesize, dirpart.data(), defaultdirnamesize, filenamepart.data(), defaultfilenamesize, extensionpart, defaultextnamesize );	
		filenamepart.resize( std::char_traits<charfs>::length( filenamepart.data( ) ) );
		dirpart.resize( std::char_traits<charfs>::length( dirpart.data( ) ) );
		extensionpartsize = std::char_traits<charfs>::length( extensionpart );
		drivepartsize = std::char_traits<charfs>::length( drivepart );
		drive.Append( make_buffer_view( drivepart, drivepartsize ), Text::Encoding::filesystem_encoding( ) );
		dir.Append( drive );
		drive += '/';
		dir.Append( make_buffer_view( dirpart.data( ), dirpart.size( ) ), Text::Encoding::filesystem_encoding( ) );
		if ( dirfilter.IsEmpty( ) ) {
			if ( directory.EndsWith( '/' ) ) {
				SetFilter( "" );
			}
			else {
				String targetfilter( make_buffer_view( filenamepart ), Text::Encoding::filesystem_encoding( ) );
				targetfilter.Append( make_buffer_view( extensionpart, extensionpartsize ), Text::Encoding::filesystem_encoding( ) );
				SetFilter( std::move( targetfilter ) );
			}
		}
		else {
			SetFilter( dirfilter );
		}

		CreateHandle();
	}

	void FileWatcher::OnPreDelta ( const FileDelta& delta ) {

	}

	void FileWatcher::OnDelta ( const FileDelta& delta ) {
		Delta( *this, delta );
		if ( HasFlags( FileChangeFlags::Created, delta.Changes ) ) {
			OnCreated( delta );
		}
		if ( HasFlags( FileChangeFlags::Renamed, delta.Changes ) ) {
			OnRenamed( delta );
		}
		if ( HasFlags( FileChangeFlags::Deleted, delta.Changes ) ) {
			OnDeleted( delta );
		}
		if ( HasFlags( FileChangeFlags::Modified, delta.Changes ) ) {
			OnModified( delta );
		}
	}

	void FileWatcher::OnModified ( const FileDelta& delta ) {
		Modified( *this, delta );
	}

	void FileWatcher::OnDeleted ( const FileDelta& delta ) {
		Deleted( *this, delta );
	}

	void FileWatcher::OnCreated ( const FileDelta& delta ) {
		Created( *this, delta );
	}

	void FileWatcher::OnRenamed ( const FileDelta& delta ) {
		Renamed( *this, delta );
	}

	const String& FileWatcher::GetFilter( ) {
		return filter;
	}

	void FileWatcher::SetFilter( const String& targetfilter ) {
		filter = targetfilter;
		filter.Replace( ".", "\\." );
		filter.Replace( "*", ".*" );
	}

	std::vector<FileDelta> FileWatcher::WaitForChanges ( Timeout timeout ) {
		return WaitForChanges( notificationflags, timeout );
	}

	std::vector<FileDelta> FileWatcher::WaitForChanges ( FileNotificationFlags notifications, Timeout timeout ) {
		std::vector<FileDelta> changes;
		WaitForChanges( changes, notifications, timeout );
		return changes;
	}

	void FileWatcher::WaitForChanges ( std::vector<FileDelta>& changes, Timeout timeout ) {
		WaitForChanges( changes, notificationflags, timeout );
	}

	void FileWatcher::WaitForChanges ( std::vector<FileDelta>& changes, FileNotificationFlags notifications, Timeout timeout ) {
		// buffer must be DWORD aligned
		std::vector<byte> buffer( 2048 * sizeof( DWORD ) );
		auto waiting = [ &changes ] ( const FileWatcher& watcher, const FileDelta& delta ) {
			changes.push_back( delta );
		};
		auto token = Delta += waiting;
		Scan( notifications, buffer, timeout );
		Delta -= token;
	}

	void FileWatcher::Scan( FileNotificationFlags notifications, std::vector<byte>& buffer, Timeout scantime ) {
		if ( !exists || fshandle == null || eventhandle == null ) {
			CreateHandle();
			if ( !exists || fshandle == null || eventhandle == null ) {
				return;	
			}
		}

		HANDLE rawhandles[2] = { };
		OVERLAPPED overlapped = { };
		DWORD waitstatus = WAIT_TIMEOUT;
		DWORD overlapstatus = 0;
		DWORD& readbytesize = raw_readbytesize.get<DWORD>( );

		if ( queueread ) {
			overlapped.hEvent = eventhandle;
			bool readchanges = ReadDirectoryChangesW(
				fshandle, /* handle to directory */
				buffer.data(), /* read results buffer */
				(DWORD)buffer.size() * sizeof(byte), /* length of buffer */
				recurse, /* monitoring option */           
				(DWORD)notificationflags, /* filter conditions */
				null, /* bytes returned */
				&overlapped, /* overlapped buffer */
				null ) != 0;

			if ( !readchanges ) {
				printf( "ERROR: Unable to ReadDirectoryChangesW ( Win32: %x ).\n", GetLastError() );
				return;
			}
			queueread = false;
		}

		rawhandles[0] = eventhandle;
		rawhandles[1] = diehandle;

		waitstatus = WaitForMultipleObjects( 2, &rawhandles[ 0 ], false, (DWORD)scantime.count( ) );
		if ( dying )
			return;

		switch ( waitstatus ) { 
		case WAIT_OBJECT_0:
			overlapped.hEvent = eventhandle;
			overlapstatus = GetOverlappedResult( fshandle, &overlapped, &readbytesize, true );
			if ( overlapstatus == 0 ) {
				printf( "ERROR: Failure after WaitForMultipleObjects in GetOverlappedResult %x ( Win32: %x ).\n", overlapped.Internal, GetLastError() );
				return;
			}
			
			if ( dying )
				return;

			ReadChanges( { buffer.data( ), readbytesize } );
			
			queueread = true;
			readbytesize = 0;
			break;
		case WAIT_OBJECT_0 + 1:
			printf( "Terminating Watcher.\n" );
			return;
		case WAIT_TIMEOUT:
			break;
		default: 
			printf( "ERROR: Unhandled wait status %x ( Win32: %x ).\n", waitstatus, GetLastError() );
			return;
		}
	}

	void FileWatcher::ReadChanges ( buffer_view<byte> buffer ) {
		using namespace Furrovine::Sys::Windows;
		if ( buffer.size() < 1 || dying )
			return;
		
		FILE_NOTIFY_INFORMATION* current = null;
		byte* currentbytes = null;
		DWORD currentbytesize = 0;
		
		FileSystemString path, oldpath;
		std::unordered_map<String, FileDelta> deltas;
		bool renaming = false, matched = false, lastmatched = false, reading = true;
		FileDelta* renametarget = null;
		FileAction action = FileAction::None;
		WideString wfilter = filter;
		std::wregex regex( wfilter );
		std::wcmatch match;

		currentbytes = buffer.data();
		
		while ( currentbytesize < buffer.size() && reading ) {
			if ( dying )
				return;
			
			current = reinterpret_cast<FILE_NOTIFY_INFORMATION*>( currentbytes );
			currentbytes += current->NextEntryOffset;
			currentbytesize += current->NextEntryOffset;
			reading = current->NextEntryOffset > 0;
			lastmatched = matched;

			//oldpath = path;
			path.Clear();
			path.Append( dir );
			path.Append( make_buffer_view( static_cast<const charfs*>( current->FileName ), size_as<WCHAR>( current->FileNameLength ) ), Text::Encoding::filesystem_encoding() );
			path.Replace( '\\', '/' );

			action = static_cast<FileAction>( current->Action );
			
			if ( filter.IsNotEmpty() ) {
				std::wcregex_iterator it( path.Data(), path.Data() + path.Length(), regex );
				matched = it != std::wcregex_iterator();
				//matched = std::regex_match( path.Data(), match, regex );
				if ( !matched ) {
					switch ( action ) {
					case FileAction::RenameOld:
						oldpath = path;
						renaming = true;
						break;
					case FileAction::RenameNew:
						if ( renaming ) {
							matched = lastmatched;
						}
						renaming = false;
						break;
					default:
						continue;
					}
				}
			}
			else {
				matched = true;
			}

			if ( !matched )
				continue;

			auto deltacapture = deltas.find( path );
			if ( deltacapture == deltas.end( ) ) {
				renaming = action == FileAction::RenameOld;
				if ( renaming ) {
					oldpath = path;
				}
				else if ( action == FileAction::RenameNew ) {
					deltas.emplace( path, FileDelta( ToFileSystemChange( action ), path, oldpath ) );
				}
				else {
					deltas.emplace( path, FileDelta( ToFileSystemChange( action ), path ) );
				}
			}
			else {
				renaming = action == FileAction::RenameOld;
				if ( renaming ) {
					
				}
				else if ( action == FileAction::RenameNew ) {
					deltacapture->second.Changes |= ToFileSystemChange( action );
					deltacapture->second.Name = path;
					deltacapture->second.OldName = oldpath;
				}
				else {
					deltacapture->second.Changes |= ToFileSystemChange( action );
				}
			}
		}

		for ( auto& deltakv : deltas ) {
			if ( dying )
				return;

			OnPreDelta( deltakv.second );
		}

		for ( auto& deltakv : deltas ) {
			if ( dying )
				return;

			OnDelta( deltakv.second );
		}

	}

	void FileWatcher::ReadDriveChanges ( buffer_view<byte> buffer ) {
		/*if ( dying || queuereadbytesize < 1 )
			return;

		FILE_NOTIFY_INFORMATION* current = null;
		byte* currentbytes = null;
		DWORD currentbytesize = 0;

		String path;
		std::unordered_map<String, FileSystemDelta> deltas;
		bool renamehalf = false;
		FileSystemDelta* renametarget = null;
		FileAction action = FileAction::None;

		currentbytes = buffer;
		while ( currentbytesize < queuereadbytesize ) {
			current = reinterpret_cast<FILE_NOTIFY_INFORMATION*>( currentbytes );
					
			if ( dying )
				return;

			path.Clear();
			path.Append( drive );
			path.Append( (charfs*)current->FileName, current->FileNameLength / sizeof( current->FileName[0] ) );
			path.Replace( '\\', '/' );
					
			switch ( (FileAction)current->Action ) {
			case FileAction::Added:
				path.Append( '/' );
				for ( auto& watcher : activewatches ) {
					if ( !watcher->exists && 
						watcher->dir == path ) {
						watcher->CreateHandle( );
					}
				}
				break;
			case FileAction::Removed:
				path.Append( '/' );
				for ( auto& watcher : activewatches ) {
					if ( watcher->exists && 
						watcher->dir == path ) {
						watcher->KillHandle( );
					}
				}
				break;
			default:
				break;
			}

			if ( current->NextEntryOfet == 0 )
				break;

			currentbytes += current->NextEntryOfet;
			currentbytesize += current->NextEntryOfet;
		}
		*/
	}

	void FileWatcher::KillHandle ( ) {
		fshandle.reset( null );
		eventhandle.reset( null );
		diehandle.reset( null );
		exists = false;
		queueread = false;
	}

	void FileWatcher::CreateHandle ( ) {
		exists = IO::Directory::Exists( dir );
		if ( exists ) {
			WideString wdir = dir;
			fshandle = CreateFileW( 
				wdir.data(), /* pointer to the file path */
				FILE_LIST_DIRECTORY,                /* (this is important to be FILE_LIST_DIRECTORY!) access (read-write) mode */
				FILE_SHARE_WRITE | FILE_SHARE_READ | FILE_SHARE_DELETE,  /* (file share write is needed, or else user is not able to rename file while you hold it) share mode */
				NULL, /* security descriptor */
				OPEN_EXISTING, /* how to create */
				FILE_FLAG_BACKUP_SEMANTICS | FILE_FLAG_OVERLAPPED, /* file attributes */
				NULL /* file with attributes to copy */
				);

			if ( fshandle == INVALID_HANDLE_VALUE ) {
				fshandle.reset( null );
				throw ErrorCodeException( Format( "Could not monitor the directory '{0}'", dir ), GetLastError() );
			}

			if ( eventhandle == null ) {
				eventhandle = CreateEventW( null, false, false, null );
				if ( eventhandle == INVALID_HANDLE_VALUE ) {
					eventhandle.reset( null );
					throw ErrorCodeException( "Unable to CreateEvent", GetLastError() );
				}
				else if ( eventhandle == null ) {
					throw NullPointerException( "CreateEvent returned unexpected null" );
				}
			}

			diehandle = CreateEventW( null, false, false, null );
			if ( diehandle == INVALID_HANDLE_VALUE ) {
				diehandle.reset( null );
				throw ErrorCodeException( "Unable to CreateEvent.\n", GetLastError() );
			}
			else if ( diehandle == null ) {
				throw NullPointerException( "Unable to CreateEvent: unexpected null return.\n" );
			}
			queueread = true;
		}
		else {
			queueread = false;
			fshandle.reset( null );
			eventhandle.reset( null );
			diehandle.reset( null );
		}
	}

	bool FileWatcher::Dying () {
		return !dying;
	}

	void FileWatcher::Die () {
		queueread = false;
		dying = true;
		SetEvent( diehandle );
	}

	FileWatcher::~FileWatcher() {
		if ( !Dying() ) {
			Die();
		}
	}

}}
