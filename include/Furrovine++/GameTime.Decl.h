#ifndef FURROVINEGAMETIME_DECL_H
#define FURROVINEGAMETIME_DECL_H

#include <Furrovine++/TimeSpan.h>

namespace Furrovine {

	class GameTime {
	private:
		TimeSpan totaltime;
		TimeSpan timeelapsed;
		bool slow;

	public:

		furrovineapi GameTime ( const TimeSpan& TimeElapsed = TimeSpan::Zero, const TimeSpan& TotalTime = TimeSpan::Zero, bool Slow = false);

		furrovineapi const TimeSpan& Elapsed ( );

		furrovineapi const TimeSpan& Total ( );

		furrovineapi bool IsSlow ();

		furrovineapi double ElapsedSeconds ();

		furrovineapi double ElapsedMilliseconds ();

		furrovineapi float ElapsedSecondsf ();

		furrovineapi float ElapsedMillisecondsf ();

	};
}

#endif // FURROVINEGAMETIME_DECL_H