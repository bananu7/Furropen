#pragma once

#include <Furrovine++/FurrovineApi.h>
#include <Furrovine++/Sys/JournalDirectory.h>

namespace Furrovine { namespace Sys {

	class DirectoryDatabase {
	private:
		furrovineapi static const ulword HopRange = sizeof( ulword ) * CHAR_BIT;
		// Hey, maybe we can descrease this a bit? Who knows!
		furrovineapi static const ulword AddRange = sizeof( ulword ) * 64;

		std::vector<int64> keypool;
		std::vector<int64*> keys;
		std::vector<ulword> hash;
		std::vector<ulword> hop;
		std::vector<JournalDirectory> values;

		ulword count;
		ulword capacity;
		ulword capacitymask;

	private:
		furrovineapi bool GetCloser( ulword& freebucket, ulword& freedistance );
	
	public:

		furrovineapi DirectoryDatabase ( ulword reservedsize = 262143 );

		furrovineapi bool Contains ( int64 key );

		furrovineapi bool Add ( const int64& key, const JournalDirectory& value );

		furrovineapi bool TryGetValue ( int64 key, JournalDirectory& out ) const;

		furrovineapi bool Remove ( int64 key );

		furrovineapi bool Remove ( int64 key, JournalDirectory& value );

	};

}}
