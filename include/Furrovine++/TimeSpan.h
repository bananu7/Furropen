#pragma once

#include <Furrovine++/PrimitiveTypes.h>
#include <Furrovine++/raw_storage.h>

namespace Furrovine {

	class TimeSpan {
	private:
		friend furrovineapi bool operator<( const TimeSpan& left, const TimeSpan& right );
		friend furrovineapi bool operator>( const TimeSpan& left, const TimeSpan& right );
		friend furrovineapi bool operator==( const TimeSpan& left, const TimeSpan& right );
		raw_storage<8> span;

	public:
		furrovineapi static const TimeSpan Zero;
		furrovineapi static const TimeSpan Max;
		furrovineapi static const TimeSpan Min;

		furrovineapi static double TicksPerDay;
		furrovineapi static double TicksPerHour;
		furrovineapi static double TicksPerMinute;
		furrovineapi static double TicksPerSecond;
		furrovineapi static double TicksPerMillisecond;
		furrovineapi static double InverseFrequency;

		furrovineapi static TimeSpan FromMilliseconds( double milliseconds );

		furrovineapi static TimeSpan FromSeconds( double seconds );

		furrovineapi static TimeSpan FromMinutes( double minutes );

		furrovineapi static TimeSpan FromHours( double hours );

		furrovineapi static TimeSpan FromDays( double days );

		furrovineapi TimeSpan();

		furrovineapi TimeSpan( llong ticks );

		furrovineapi TimeSpan( llong days, llong hours, llong minutes, llong seconds, llong milliseconds );

		furrovineapi TimeSpan( int days, int hours, int minutes, int seconds, int milliseconds );

		furrovineapi ulword HashCode ( ) const;

		furrovineapi double Time ( ) const;

		furrovineapi double Seconds() const;

		furrovineapi double Milliseconds() const;

		furrovineapi double Microseconds() const;
	};

	furrovineapi bool operator> ( const TimeSpan& left, const TimeSpan& right );

	furrovineapi bool operator< ( const TimeSpan& left, const TimeSpan& right );

	furrovineapi bool operator== ( const TimeSpan& left, const TimeSpan& right );

}