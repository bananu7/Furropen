#pragma once

#include <Furrovine++/Mathema.h>
#include <Furrovine++/Hashers.h>
#include <Furrovine++/Strings.h>

namespace Furrovine {

	struct Single {

		furrovineapi static const single MaxValue;
		furrovineapi static const single MinValue;
		furrovineapi static const single InverseInt8Max;
		furrovineapi static const single InverseUInt8Max;
		furrovineapi static const single InverseInt16Max;
		furrovineapi static const single InverseUInt16Max;
		furrovineapi static const single InverseInt32Max;
		furrovineapi static const single InverseUInt32Max;
		furrovineapi static const single InverseInt64Max;
		furrovineapi static const single InverseUInt64Max;

		furrovineapi static bool AlmostZero( single value, single tolerance = FLT_EPSILON * 100 );

		furrovineapi static bool AlmostEquals( single left, single right, single tolerance = FLT_EPSILON * 100 );

		furrovineapi static single Decimals( single value );

		furrovineapi static single InvDecimals( single value );

		furrovineapi static ulword HashCode( single hashee );

		furrovineapi static bool TryParse( const String& string, single& value );

	};

}
