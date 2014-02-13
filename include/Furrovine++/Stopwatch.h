#pragma once

#include <Furrovine++/TimeSpan.h>
#include <Furrovine++/raw_storage.h>

namespace Furrovine { 	

	struct Stopwatch {
	private:
		raw_storage<8> countstart;
		raw_storage<8> countend;
		raw_storage<8> frequency;
		bool stopped;

	public:
		
		furrovineapi Stopwatch( );

		furrovineapi void Start( );

		furrovineapi void Restart( );
		
		furrovineapi void Stop( bool queryifstarted = true );

		furrovineapi bool Running( ) const;

		furrovineapi bool Stopped( ) const;

		furrovineapi int64 ElapsedTicks( );

		furrovineapi double ElapsedSeconds( );

		furrovineapi double ElapsedMilliseconds( );

		furrovineapi double ElapsedMicroseconds( );

		furrovineapi TimeSpan ElapsedTime( );

	};	

}
