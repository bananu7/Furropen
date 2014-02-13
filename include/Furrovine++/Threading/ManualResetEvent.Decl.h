#pragma once

#include <Furrovine++/Threading/WaitHandle.h>

namespace Furrovine { namespace Threading {

	class ManualResetEvent : public WaitHandle {
	private:
		bool initial;
		
		furrovineapi ManualResetEvent ( const ManualResetEvent& nocopy );

		furrovineapi ManualResetEvent& operator= ( const ManualResetEvent& nocopy );


	public:

		furrovineapi ManualResetEvent ( bool initialstate = false );

		furrovineapi ManualResetEvent ( ManualResetEvent&& mov );

		furrovineapi ManualResetEvent& operator= ( ManualResetEvent&& mov );

		furrovineapi void Set ();

		furrovineapi void Reset ();

		furrovineapi static int32 WaitMultiple ( ManualResetEvent* events, ulword eventcount, bool waitall = true, Timeout timeout = Timeout::Infinite );

	};

}}
