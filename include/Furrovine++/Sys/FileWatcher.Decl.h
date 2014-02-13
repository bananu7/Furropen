#pragma once

#include <Furrovine++/std_defines.h>
#include <atomic>
#include <Furrovine++/buffer_view.h>
#include <Furrovine++/Timeout.h>
#include <Furrovine++/handle.h>
#include <Furrovine++/platform_deleters.h>
#include <Furrovine++/Event.h>
#include <Furrovine++/raw_storage.h>
#include <Furrovine++/Sys/FileDelta.h>
#include <Furrovine++/Sys/FileNotificationFlags.h>

namespace Furrovine { namespace Sys {

	class FileWatcher {
	private:
		handle<void*, delete_platform_handle> eventhandle;
		handle<void*, delete_platform_handle> diehandle;
		handle<void*, delete_platform_handle> fshandle;
		String target, dir, filter;
		String drive;

		FileNotificationFlags notificationflags;
		bool exists, recurse;
		std::atomic<bool> dying, queueread;
		raw_storage<16> raw_readbytesize;

	protected:

		furrovineapi void CreateHandle ( );
		furrovineapi void KillHandle ( );
		furrovineapi void Die ( );
		furrovineapi bool Dying ( );

		furrovineapi void Scan ( FileNotificationFlags notifications, std::vector<byte>& buffer, Timeout timeout );
		furrovineapi void ReadChanges ( buffer_view<byte> buffer );
		furrovineapi void ReadDriveChanges ( buffer_view<byte> buffer );

		furrovineapi virtual void OnPreDelta( const FileDelta& delta );
		furrovineapi virtual void OnDelta ( const FileDelta& delta );
		furrovineapi virtual void OnModified( const FileDelta& delta );
		furrovineapi virtual void OnDeleted( const FileDelta& delta );
		furrovineapi virtual void OnCreated( const FileDelta& delta );
		furrovineapi virtual void OnRenamed( const FileDelta& delta );

	public:

		Event<const FileWatcher&, const FileDelta&> Delta;
		Event<const FileWatcher&, const FileDelta&> Modified;
		Event<const FileWatcher&, const FileDelta&> Deleted;
		Event<const FileWatcher&, const FileDelta&> Created;
		Event<const FileWatcher&, const FileDelta&> Renamed;
		
		furrovineapi FileWatcher ( const String& fileordirectory, const String& filter = "", bool recursive = true, FileNotificationFlags notifications = FileNotificationFlags::All );

		furrovineapi const String& GetFilter ( );
		furrovineapi void SetFilter( const String& filter );

		furrovineapi std::vector<FileDelta> WaitForChanges ( Timeout timeout = Timeout::Infinite );
		furrovineapi std::vector<FileDelta> WaitForChanges ( FileNotificationFlags notifications, Timeout timeout = Timeout::Infinite );
		furrovineapi void WaitForChanges ( std::vector<FileDelta>& changes, Timeout timeout = Timeout::Infinite );
		furrovineapi void WaitForChanges ( std::vector<FileDelta>& changes, FileNotificationFlags notifications, Timeout timeout = Timeout::Infinite );

		furrovineapi ~FileWatcher( );

	};

}}
