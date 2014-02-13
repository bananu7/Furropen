#pragma once

#include <Furrovine++/FurrovineApi.h>
#include <chrono>

namespace Furrovine {

	struct Timeout : public std::chrono::milliseconds {
	public:
		furrovineapi static const Timeout Infinite;

		furrovineapi Timeout ();

		furrovineapi Timeout ( int32 milliseconds );

		furrovineapi Timeout ( int64 milliseconds );
	};
}
