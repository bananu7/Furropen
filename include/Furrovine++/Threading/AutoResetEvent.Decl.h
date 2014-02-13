#pragma once

#include <Furrovine++/Threading/WaitHandle.h>

namespace Furrovine { namespace Threading {

	class AutoResetEvent : public WaitHandle {
	private:
		bool intial;
		
		furrovineapi AutoResetEvent ( const AutoResetEvent& nocopy );

		furrovineapi AutoResetEvent& operator= ( const AutoResetEvent& nocopy );

	public:

		furrovineapi AutoResetEvent ( bool initalstate = false );

		furrovineapi AutoResetEvent ( AutoResetEvent&& mov );

		furrovineapi AutoResetEvent& operator= ( AutoResetEvent&& mov );

		furrovineapi void Set ();

		furrovineapi void Reset ();

		furrovineapi static int32 WaitMultiple ( AutoResetEvent* waitevent, ulword eventcount, bool waitall = true, Timeout timeout = Timeout::Infinite );

	};

}}
