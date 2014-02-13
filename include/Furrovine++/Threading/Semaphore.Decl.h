#pragma once

#include <Furrovine++/Threading/WaitHandle.h>

namespace Furrovine { namespace Threading {

	class Semaphore : public WaitHandle {
	private:
		int32 initial, max;
		
		furrovineapi Semaphore ( const Semaphore& nocopy );

		furrovineapi Semaphore& operator= ( const Semaphore& nocopy );

	public:

		furrovineapi Semaphore ( int32 initialcount = 0, int32 maxcount = 0x7FFFFFFF );

		furrovineapi Semaphore ( Semaphore&& mov );

		furrovineapi Semaphore& operator= ( Semaphore&& mov );

		furrovineapi void Set ( uint32 incrementby = 1 );

		furrovineapi static int32 WaitMultiple ( Semaphore* semaphore, ulword count, bool waitall = false, Timeout timeout = Timeout::Infinite );
	};

}}
