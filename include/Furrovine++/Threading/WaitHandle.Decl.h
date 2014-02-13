#pragma once

#include <Furrovine++/handle.h>
#include <Furrovine++/Timeout.h>
#include <Furrovine++/platform_deleters.h>

namespace Furrovine { namespace Threading {

	class WaitHandle {
	protected:
		handle<void*, delete_platform_handle> waitev;

	public:
		furrovineapi WaitHandle( );
		furrovineapi WaitHandle( void* ev );

		furrovineapi WaitHandle( const WaitHandle& nocopy ) = delete;
		furrovineapi WaitHandle& operator= ( const WaitHandle& nocopy ) = delete;

		furrovineapi WaitHandle ( WaitHandle&& mov );
		furrovineapi WaitHandle& operator= ( WaitHandle&& mov );

		furrovineapi operator void* () const;

		furrovineapi void* Handle () const;

		furrovineapi bool Wait ( Timeout timeout /*= Timeout::Infinite*/ );

		furrovineapi bool Wait ( WaitHandle& waitevent, Timeout timeout /*= Timeout::Infinite*/ );

		furrovineapi int32 WaitMultiple ( WaitHandle* waitevents, uint32 count, bool waitall = false, Timeout timeout = Timeout::Infinite );

		template <typename THandleIterator>
		static int32 WaitMultiple ( THandleIterator begin, THandleIterator end, bool waitall = false, Timeout timeout = Timeout::Infinite );

		template <typename ...Tn>
		static int32 WaitMultiple ( Tn&&... handles );

		template <typename ...Tn>
		static int32 WaitMultiple ( bool waitall, Tn&&... handles );

		template <typename ...Tn>
		static int32 WaitMultiple ( bool waitall, Timeout timeout, Tn&&... handles );

		furrovineapi static int32 WaitMultiple ( void** handles, ulword count, bool waitall = false, Timeout timeout = Timeout::Infinite );

	};

}}
