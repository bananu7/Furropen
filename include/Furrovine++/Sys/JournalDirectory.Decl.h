#pragma once

#include <Furrovine++/FurrovineApi.h>
#include <Furrovine++/Strings.h>

namespace Furrovine { namespace Sys {

	struct JournalDirectory {
	public:
		int64 Parent;
		String Name;

		furrovineapi JournalDirectory( );

		furrovineapi JournalDirectory( int64 parent, const String& name );

		furrovineapi JournalDirectory( int64 parent, String&& name );

		furrovineapi JournalDirectory( const JournalDirectory& copy );

		furrovineapi JournalDirectory( JournalDirectory&& mov );

		furrovineapi JournalDirectory& operator=( const JournalDirectory& copy );

		furrovineapi JournalDirectory& operator=( JournalDirectory&& mov );

	};

}}
