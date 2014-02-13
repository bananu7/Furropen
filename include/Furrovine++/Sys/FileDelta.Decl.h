#pragma once

#include <Furrovine++/Strings.h>
#include <Furrovine++/Sys/FileChangeFlags.h>

namespace Furrovine { namespace Sys {

	struct FileDelta {
	public:
		FileChangeFlags Changes;
		String Name;
		String OldName;
		bool TimedOut;

		furrovineapi FileDelta( );

		furrovineapi FileDelta ( bool timeout );

		furrovineapi FileDelta( FileChangeFlags changes, const String& name );

		furrovineapi FileDelta( FileChangeFlags changes, const String& name, const String& oldname );

		furrovineapi FileDelta( FileChangeFlags changes, String&& name );

		furrovineapi FileDelta( FileChangeFlags changes, String&& name, String&& oldname );

		furrovineapi FileDelta( FileDelta&& mov );

		furrovineapi FileDelta( const FileDelta& copy );

	};

}}
